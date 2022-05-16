/* drivers/misc/ykq_control.c
 *
 * Copyright (C) 2012-2015 ROCKCHIP.
 * Author: luowei <lw@rock-chips.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
 
 
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/irq.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <asm/uaccess.h>
#include <asm/atomic.h>
#include <linux/delay.h>
#include <linux/input.h>
#include <linux/workqueue.h>
#include <linux/freezer.h>
#include <linux/of_gpio.h>
#include <linux/ktime.h>
#include <linux/of.h>
#include <linux/wakelock.h>
#ifdef CONFIG_HAS_EARLYSUSPEND
#include <linux/earlysuspend.h>
#endif
#include <dt-bindings/pinctrl/rockchip-rk312x.h>



struct mutex yj_mutex_lock[1];	
struct delayed_work yj_work;
struct delayed_work yj_jl_work;

#define YKQ_SUSPEND_LOCK_NAME "yjykq" 
static struct wake_lock ykq_suspend_lock; 
struct wake_lock ykq_wake_lock;


static int data_gpio,data_flags;

static unsigned int gpio_state = 0;
struct timer_list gpio_timer;
static unsigned int time_delay = HZ/4000;
int input_gpio;
int int_gpio;
int jl_int_gpio;
static struct kobject *ykq_kobj;

struct sw_gpio{
    struct work_struct irq_work;
    u32 irq_hd;                         /* 中断句柄     */
	int gpio;
	
	u32 jl_irq_hd;                         /* 中断句柄     */
	int jl_gpio;
    unsigned long trig_type;  /* 中断触发方式 */
    //struct input_dev *key;
#if defined(CONFIG_HAS_EARLYSUSPEND)
	struct early_suspend gpio_early_suspend;
#endif
};

int count = 0;

static int read_gpio(int gpio)
{
	int i,level;
	for(i=0; i<3; i++)
	{
		level = gpio_get_value(gpio);
		if(level < 0)
		{
			printk("%s:get pin level again,pin=%d,i=%d\n",__FUNCTION__,gpio,i);
			msleep(1);
			continue;
		}
		else
		break;
	}
	if(level < 0)
		printk("%s:get pin level  err!\n",__FUNCTION__);

	return level;
}
static int report_data,report_count;
static void yj_work_func(struct work_struct *work)
{
	
			report_count = 0;
			report_data = 0;
  printk("yj_work_func clear:\n");
}



int power(int m, int n)
{
	  if (m == 0)
	  	  return 0;
    if (n == 0)
        return 1;
    else    
        return power(m, n-1) * m;
}


#define EYEMODE_FILENAME "/data/data/com.idwell.cloudframe/sleepmode.txt"///data/data/com.android.systemui/eyemode.txt
///data/data/com.android.settings/yujian.txt
///////////////////////////////////////////////////////////////////////
// Convert a string into an integer
///////////////////////////////////////////////////////////////////////
int StrToInt2(const char* str)
{
	    int i;
      int temp_num,num,temp_num2 = 0;
      if(str != NULL)//至少保证字符串不为空
       {          
            num = 0;
            temp_num = 0;

             	for(i=0;i<4;i++)
             	{
                  if(str[i] >= '0' && str[i] <= '9')
                   {                                     
                         num ++;
                   }
                  // if the char is not a digit, invalid input
                  else
                   {          
                   	    temp_num = num;           
                        break;
                   }
             }
           if(str[0] == '1')
           	  temp_num2 = 2;
           else if(str[0] == '2')
           	  temp_num2 = 3;  	  
           else if(str[0] == '3')  
           	  temp_num2 = 3; 
           else
           	  temp_num2 = 0;
           	  
           if(temp_num2 == temp_num)
           	{ 	  
             	if(temp_num == 3)
             	{
             		num = (str[0] - '0')*100+(str[1] - '0')*10+(str[2] - '0'); 
             	}else if(temp_num == 2)
             	{
             		num = (str[0] - '0')*10+(str[1] - '0'); 
             	}
             }else
             	{
             		num = 400;
             	}
           
       }
       return num;
}
static int load_jl_value(void)
{

	struct file *fp;
    mm_segment_t fs;
    loff_t pos;
    char buf[4];
   // return 1;
    //printk("hello enter\n");
    fp =filp_open(EYEMODE_FILENAME,O_RDONLY,0);
    if (IS_ERR(fp)){
        printk("open file error\n");
        return -1;
    }
    
    fs =get_fs();
    set_fs(KERNEL_DS);
    //pos =0;
    //vfs_write(fp,buf, sizeof(buf), &pos);
    pos =0;
    vfs_read(fp,buf, sizeof(buf), &pos);
    printk("read: %s,atoi(buf):%d\n",buf,StrToInt2(buf));
    filp_close(fp,NULL);
    set_fs(fs);

	return StrToInt2(buf);
}


extern void rk_send_ykq_key(int keycode);
void yj_report_key(int report_data)
{
	if(report_data == 0x1e)
	{
	 rk_send_ykq_key(KEY_MUTE);
	}else if(report_data == 0x2d)
	{
		rk_send_ykq_key(KEY_PREVIOUSSONG);		
		//load_jl_value();
	}else if(report_data == 0x3c)
	{
		rk_send_ykq_key(KEY_VOLUMEUP);		
	}else if(report_data == 0x4b)
	{
		rk_send_ykq_key(KEY_NEXTSONG);		
	}else if(report_data == 0x5a)
	{
		rk_send_ykq_key(KEY_VOLUMEDOWN);		
	}else if(report_data == 0x69)
	{
		rk_send_ykq_key(KEY_PLAYPAUSE);		
	}else if(report_data == 0x78)
	{
		rk_send_ykq_key(KEY_BACK);		
	}else if(report_data == 0x87)
	{
		rk_send_ykq_key(KEY_HOMEPAGE);		
	}else if(report_data == 0x96)
	{
		rk_send_ykq_key(KEY_F8);		
	}else if(report_data == 0xa5)
	{
		rk_send_ykq_key(KEY_MENU);		
	}else
		{
				schedule_delayed_work(&yj_work, msecs_to_jiffies(30));	
		}
}
static irqreturn_t gpio_irq_interrupt(int irq, void *para)
{
	//struct sw_gpio *gpio = (struct sw_gpio *)para;
	//int ret;
	//schedule_delayed_work(&yj_work, msecs_to_jiffies(150));	
  static unsigned int data_state = 0;

	data_state = gpio_get_value(data_gpio);
	//printk("%s,ykq%d,data_state:%d\n",__func__,__LINE__,data_state);
	if(report_count >= 8)
		{
			printk("%s,ykq%d,report_data:%x\n",__func__,__LINE__,report_data);
			yj_report_key(report_data);
			report_count = 0;
			report_data = 0;
		}else
		{
			report_count++;
			report_data = report_data + power(2 * data_state,(8 - report_count)) ;
		//	printk("%s,ykq%d,one_data:%x,report_data:%x\n",__func__,__LINE__,power(2 * data_state,(8 - report_count)),report_data);			
		}
 
	

	return IRQ_HANDLED;
}

extern int backlight_on;
extern int first_on;
static irqreturn_t jl_gpio_irq_interrupt(int irq, void *para)
{
#if 0
  static unsigned int data_state = 0;
  static int temp_count,level;
  level = gpio_get_value(jl_int_gpio);
  printk("yujian level:%d\n",level);
  if(level == 1)
  schedule_delayed_work(&yj_jl_work, msecs_to_jiffies(30));
  else
  {
  	
  }
  
  if(first_on == 1)
  {
   temp_count = load_jl_value();	
  }
	printk("%s,jl%d,backlight_on:%d,temp_count:%d,first_on:%d\n",__func__,__LINE__,backlight_on,temp_count,first_on);
	if(backlight_on == 0)
	{
	if((temp_count == 300)&&(level == 1))
   rk_send_ykq_key(KEY_POWER);        
  }else
  {
  }
  if((temp_count == 300)&&(level == 1))
   rk_send_ykq_key(KEY_F1);
#endif   
	return IRQ_HANDLED;
}

static void yj_jl_work_func(struct work_struct *work)
{
	  static unsigned int data_state = 0;
  static int temp_count,level;
  level = gpio_get_value(jl_int_gpio);
  //printk("yujian level:%d\n",level);
  //if(level == 1)
 // schedule_delayed_work(&yj_jl_work, msecs_to_jiffies(30));
 // else
 // {
  	
 // }
  
  if(first_on == 1)
  {
   temp_count = load_jl_value();	
  }
	//printk("%s,jl%d,backlight_on:%d,temp_count:%d,first_on:%d\n",__func__,__LINE__,backlight_on,temp_count,first_on);
	if(backlight_on == 0)
	{
	if((temp_count == 300)&&(level == 0))
   rk_send_ykq_key(KEY_POWER);        
  }else
  {
  }
  if((temp_count == 300)&&(level == 0))
   rk_send_ykq_key(KEY_F1);

 // printk("yj_jl_work_func clear:\n");
  schedule_delayed_work(&yj_jl_work, msecs_to_jiffies(1200));
}

static int gpio_register_wake_irq(struct sw_gpio *gpio)
{
	int ret = 0;
	printk("%s,%d\n",__func__,__LINE__);	
	//wake_gpio = 0x2B50;//GPIOA(24);//?GPIO2_B5
	ret = gpio_direction_input(gpio->gpio);
	if (ret < 0) {
		pr_err(": failed to configure input"
			" direction for GPIO %d, error %d\n",
			gpio->gpio, ret);
		gpio_free(gpio->gpio);
		//goto fail1;
	}	
	
	gpio->irq_hd = gpio_to_irq(gpio->gpio);//?
	ret = request_irq(gpio->irq_hd, gpio_irq_interrupt,  IRQ_TYPE_EDGE_RISING/*IRQF_TRIGGER_HIGH*/, "ykq", gpio);
	//ret = request_irq(gpio->irq_hd, gpio_irq_interrupt, IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING | IRQF_TRIGGER_LOW | IRQF_TRIGGER_HIGH, "ykq", gpio);
	
	if(IS_ERR_VALUE(ret)){
		gpio_free(gpio->gpio);
        pr_err("err: request_irq failed\n");
        return -1;
    }
	
    //disable_irq(gpio->irq_hd);
	//enable_irq(gpio->irq_hd);
	return 0;
}


static int jl_gpio_register_wake_irq(struct sw_gpio *gpio)
{
	int ret = 0;
	printk("%s,%d\n",__func__,__LINE__);	

	ret = gpio_direction_input(gpio->jl_gpio);
	if (ret < 0) {
		pr_err(": failed to configure input"
			" direction for GPIO %d, error %d\n",
			gpio->jl_gpio, ret);
		gpio_free(gpio->jl_gpio);
		//goto fail1;
	}	
	
	gpio->jl_irq_hd = gpio_to_irq(gpio->jl_gpio);//?
	ret = request_irq(gpio->jl_irq_hd, jl_gpio_irq_interrupt,  IRQF_TRIGGER_FALLING /*| IRQF_TRIGGER_RISINGIRQF_TRIGGER_FALLING*//*IRQF_TRIGGER_HIGH*/, "jl", gpio);

	if(IS_ERR_VALUE(ret)){
		gpio_free(gpio->jl_gpio);
        pr_err("err: request_irq failed\n");
        return -1;
    }
	

	return 0;
}

static ssize_t show_status(struct device *dev,struct device_attribute *attr, char *buf)
{
    int ret_value = 1;
	
	gpio_state = gpio_get_value(int_gpio);
    ret_value = sprintf(buf, "%u\n", gpio_state); 	
	
	printk("%s,%d,%d\n",__func__,__LINE__,gpio_state);
    return ret_value;
}

static DEVICE_ATTR(ykq_state, 0444, show_status, NULL);

/*static struct platform_device gpio_device = { 
    .name = "ykq", 
};*/

static void gpio_timer_func(unsigned long data)
{
	gpio_state = gpio_get_value(input_gpio);

	//printk("%s,%d,%x\n",__func__,__LINE__,gpio_state);
    mod_timer(&gpio_timer, jiffies +  time_delay);
}

static int ykq_gpio_timer(struct sw_gpio *gpio) 
{
	input_gpio = gpio->gpio;
	gpio_direction_input(input_gpio);
	init_timer(&gpio_timer);
	gpio_timer.function = gpio_timer_func;
	mod_timer(&gpio_timer, jiffies +  time_delay );
	return 0;
}

static ssize_t ykq_gpio_value_value_read(struct device *dev,struct device_attribute *attr, char *buf)
{
		//test_chip(); 
	    int value = 1;//gpio_get_value(81);
        return sprintf(buf, "%d\n", value);
}
static ssize_t ykq_gpio_value_write(struct device *dev,struct device_attribute *attr,const char *buf, size_t count)
{
        u8 val; 
        int ret; 
        ret = kstrtou8(buf, 0, &val);
        printk("==== yujian ==== val = %d\n",val);
        return count;
}

static struct device_attribute ykq_ctl_attr[] = {
		__ATTR(ykq_gpio_value,0664,ykq_gpio_value_value_read,ykq_gpio_value_write),
//		__ATTR(pm2005_instant_value,0666,pm2005_instant_read,pm2005_instant_write),
		
};

static int yuyuan_ykq_sysfs_init(void)
{
	int ret;
	int i;
	ykq_kobj = kobject_create_and_add("yuyuan_ykq",kernel_kobj);
	if(!ykq_kobj)
		return -ENOMEM;
	for(i = 0; i< ARRAY_SIZE(ykq_ctl_attr); i++){
		ret = sysfs_create_file(ykq_kobj,&ykq_ctl_attr[i].attr);
		
		if(ret != 0)
			printk("create damo node(%s) error\n",ykq_ctl_attr[i].attr.name);
	}
}
static int __init ykq_probe(struct platform_device *pdev)
{

	struct device *dev = &pdev->dev;
	int ret = 0,rc =0;
	struct sw_gpio *gpio;
	int ret_device_file = 0;
	int irq_flags,jl_irq_flags;
	int host_gpio,host_flags;
	int irq_gpio,jl_irq_gpio;
	struct device_node *ykq_node = pdev->dev.of_node;
	
	
	gpio = kzalloc(sizeof(struct sw_gpio), GFP_KERNEL);
	if (!gpio) {
		return -ENOMEM;
	}
	//dev_set_drvdata(pdev, gpio);
	printk("%s,%d\n",__func__,__LINE__);	
	
	
	data_gpio = of_get_named_gpio_flags(ykq_node, "data-gpio", 0,
				&data_flags);
	ret = gpio_request(data_gpio,"data_gpio");
  if(ret){
        printk("yujian request data_gpio fail \n");
  }
  
  gpio_direction_input(data_gpio);

	
	
	irq_gpio = of_get_named_gpio_flags(ykq_node, "irp-gpio", 0, &irq_flags);
	if (!gpio_is_valid(irq_gpio)) {	
		printk("ykq invalid irq_gpio:%d\n", irq_gpio);
		return -1;
	}
	else
	printk("yujian ----- ykq ok irq_gpio:%d\n", irq_gpio);
	
	if (gpio_request(irq_gpio, "irp-gpio")){
		if (rc != 0) {
			printk("ykq gpio %d request faild!\n", irq_gpio);
			gpio_free(irq_gpio);
			return -EIO;
		}
	}
	
	gpio->gpio = irq_gpio;
	int_gpio = irq_gpio;
		ret = gpio_register_wake_irq(gpio);

//jl	
		jl_irq_gpio = of_get_named_gpio_flags(ykq_node, "jl-gpio", 0, &jl_irq_flags);
	if (!gpio_is_valid(jl_irq_gpio)) {	
		printk("ykq invalid jl_irq_gpio:%d\n", jl_irq_gpio);
		return -1;
	}
	else
	printk("yujian ----- ykq ok jl_irq_gpio:%d\n", jl_irq_gpio);
	
	if (gpio_request(jl_irq_gpio, "jl-gpio")){
		if (rc != 0) {
			printk("ykq gpio %d request faild!\n", jl_irq_gpio);
			gpio_free(jl_irq_gpio);
			return -EIO;
		}
	}
	
	gpio->jl_gpio = jl_irq_gpio;
  jl_int_gpio = jl_irq_gpio;
	
	ret = jl_gpio_register_wake_irq(gpio);
	
//host
		host_gpio = of_get_named_gpio_flags(ykq_node, "host-gpio", 0, &host_flags);
	if (!gpio_is_valid(host_gpio)) {	
		printk("ykq invalid host_gpio:%d\n", host_gpio);
		return -1;
	}
	else
	printk("yujian ----- ykq ok host_gpio:%d\n", host_gpio);
	
	if (gpio_request(host_gpio, "host-gpio")){
		if (rc != 0) {
			printk("ykq gpio %d request faild!\n", host_gpio);
			gpio_free(host_gpio);
			return -EIO;
		}
	}
	 gpio_direction_output(host_gpio,1);
	

	device_init_wakeup(dev, 1);
	//add by yujian
	yuyuan_ykq_sysfs_init();
	
	gpio_state = gpio_get_value(int_gpio);

INIT_DELAYED_WORK(&yj_work, yj_work_func);
//INIT_DELAYED_WORK(&yj_jl_work, yj_jl_work_func);
//schedule_delayed_work(&yj_jl_work, msecs_to_jiffies(5000));

mutex_init(&yj_mutex_lock[0]);
    wake_lock_init(&ykq_suspend_lock, WAKE_LOCK_SUSPEND, YKQ_SUSPEND_LOCK_NAME);
    wake_lock(&ykq_suspend_lock);

	if((ret_device_file = device_create_file(&(pdev->dev), &dev_attr_ykq_state)) != 0) 
		goto exit_error;	
	return ret;
exit_error:	
	device_init_wakeup(dev, 0);
    return ret_device_file;	
	
}


static int ykq_suspend(struct platform_device *pdev, pm_message_t message)
{
	printk("%s,%d\n",__func__,__LINE__);
    return 0;
}

static int ykq_resume(struct platform_device *pdev)
{
	//struct sw_gpio *gpio = dev_get_drvdata(pdev);
	pr_err("%s,%d\n",__func__,__LINE__);
    return 0;
}

static int ykq_remove(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct sw_gpio *gpio = dev_get_drvdata(pdev);
	
	device_init_wakeup(dev, 0);
	if(pdev == NULL){
        pr_err("err: invalid argment\n");
        return -1;
	}

	//disable_irq(gpio->irq_hd);
	//cancel_work_sync(&gpio->irq_work);
	return 0;
}

static struct of_device_id ykq_dt_ids[] = {
	/*gsensor*/
	{ .compatible = "ykq" },
};

#ifdef CONFIG_PM
static int keys_suspend(struct device *dev)
{
	//struct rk_keys_drvdata *ddata = dev_get_drvdata(dev);
	//int i;
printk("yujian ykq suspend\n");

	//ddata->in_suspend = true;
	if (device_may_wakeup(dev)) {
		//for (i = 0; i < ddata->nbuttons; i++) {
			//struct rk_keys_button *button = ddata->button + i;
			//if (button->wakeup) {
				int irq = gpio_to_irq(int_gpio);
				enable_irq_wake(irq);
			//}
		//}
	}
	return 0;
}

static int keys_resume(struct device *dev)
{
	//struct rk_keys_drvdata *ddata = dev_get_drvdata(dev);
	//int i;
printk("yujian ykq resume\n");
	if (device_may_wakeup(dev)) {
		//for (i = 0; i < ddata->nbuttons; i++) {
			//struct rk_keys_button *button = ddata->button + i;
			//if (button->wakeup) {
				int irq = gpio_to_irq(int_gpio);
				disable_irq_wake(irq);
			//}
		}
		preempt_disable();
		if (local_softirq_pending())
			do_softirq(); // for call resend_irqs, which may call keys_isr
		preempt_enable_no_resched();
		
	gpio_state = gpio_get_value(int_gpio);
		
	//ddata->in_suspend = false;
	return 0;
}

static const struct dev_pm_ops keys_pm_ops = {
	.suspend	= keys_suspend,
	.resume		= keys_resume,
};
#endif

static struct platform_driver ykq_driver = {
	.driver		= {
		.name	= "ykq",
		.owner	= THIS_MODULE,
		.of_match_table = of_match_ptr(ykq_dt_ids),
		#ifdef CONFIG_PM
		.pm	= &keys_pm_ops,
		#endif
	},
    .probe      = ykq_probe,
    .remove     = ykq_remove,
#if defined(CONFIG_PM)
    //.suspend    = ykq_suspend,
   // .resume     = ykq_resume,
#endif 
};

static int __init ykq_control_init(void)
{
	int ret = 0;
	
	printk("%s,%d\n",__func__,__LINE__);
	//ret = platform_device_register(&gpio_device);
	//if (ret == 0) {
		ret = platform_driver_register(&ykq_driver);
	//}
	if(ret){
        pr_err("ERR: platform_driver_probe failed\n");
        return -1;
    }
	return 0;
}

static void __exit ykq_control_exit(void)
{
	platform_driver_unregister(&ykq_driver);
	//platform_device_unregister(&gpio_device);
}
module_init(ykq_control_init);
module_exit(ykq_control_exit);
