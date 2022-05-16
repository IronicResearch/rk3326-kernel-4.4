#include <dt-bindings/gpio/gpio.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/fb.h>
#include <linux/backlight.h>
#include <linux/err.h>
#include <linux/pwm.h>
#include <linux/pwm_backlight.h>
#include <linux/slab.h>
#include <linux/proc_fs.h>
#include <linux/termios.h>
#include <linux/mutex.h>
#include <linux/workqueue.h>
#include <linux/input.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/hrtimer.h>
#include <linux/i2c.h>
#include <linux/io.h>
#include <linux/async.h>
#include <linux/input/mt.h>
#include <linux/wakelock.h>


//#define INVALID_GPIO -1

struct proc_dir_entry *gpio_extend_dir;
static struct class *rk_gpio_class = NULL;
static struct input_dev *sinput_dev;
static struct timer_list gpio_timer;
static struct timer_list gpio_timer_body;
static unsigned int time_delay = HZ * 1;

//extern void rk_send_power_key(int state);
extern int lcd_enable ;
extern void rk_send_wakeup_key(void);
static unsigned int gpio_state = 0;
static int gpio0_b3;
static int gpio0_b4;
static int gpio3_d3;
static int gpio8_a3;
static int gpio8_a6;
static int gl_value;
static int gl_switch = 0;
static int irq_gpio3_d3;

struct		delayed_work read_io_work;
static struct of_device_id gpio_of_match[] = {
	{ .compatible = "gpio_ctrl" },
	{ }
};


MODULE_DEVICE_TABLE(of, gpio_of_match);

#define EYEMODE_FILENAME "/data/data/com.idwell.cloudframe/sleepmode.txt"
static int count = 0;

static int StrToInt2(const char* str)
{
            int i;
      int temp_num,num,temp_num2 = 0;
      if(str != NULL)//?¨¢¨¦¨´¡À¡ê?¡è¡Á?¡¤?¡ä?2??a??
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
		count = count++;
		if(count == 1000)
		{
			count = 0 ;
        	printk("open file error\n");
		}
        return -1;
    }

    fs =get_fs();
    set_fs(KERNEL_DS);
    //pos =0;
    //vfs_write(fp,buf, sizeof(buf), &pos);
    pos =0;
    vfs_read(fp,buf, sizeof(buf), &pos);
    //printk("read: %s,atoi(buf):%d\n",buf,StrToInt2(buf));
    filp_close(fp,NULL);
    set_fs(fs);

        return StrToInt2(buf);
}

#if 0
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

#endif

static int gpio_statu_new = 1;
static int gpio_statu_pre = 1;
static void gpio_timer_func(unsigned long data)
{
	
	#if 0
	gpio_state = gpio_get_value(gpio3_d3);
	if(gl_switch == 1 && gpio_state == 0 )
	{
		input_event(sinput_dev, EV_KEY, KEY_WAKEUP, 1);
		input_sync(sinput_dev);
		input_event(sinput_dev, EV_KEY, KEY_WAKEUP, 0);
		input_sync(sinput_dev);
	}
	printk("cjc gpio_timer_func = %d\n",gpio_state);
	#endif


	gpio_state = gpio_get_value(gpio3_d3);
	gpio_statu_new = gpio_state;
	//printk("start timer ==== gl_switch = %d, gpio_state \n", gl_switch, gpio_state);

	//printk("gpio_statu_new  = %d,gpio_statu_pre = %d\n",gpio_statu_new,gpio_statu_pre);
	if(gl_switch == 1 && gpio_state == 0)
	{
		if(lcd_enable == 0)
		{
			//rk_send_power_key(1);
			//rk_send_power_key(0);
			//rk_send_ykq_key(KEY_POWER);

			input_event(sinput_dev, EV_KEY, KEY_WAKEUP, 1);
			input_sync(sinput_dev);
			input_event(sinput_dev, EV_KEY, KEY_WAKEUP, 0);
			input_sync(sinput_dev);

			lcd_enable = 1;
			//input_sync(input_gl);
			//return ;
		} 
		else
		{
			input_event(sinput_dev, EV_KEY, KEY_F1, 1);
			input_event(sinput_dev, EV_KEY, KEY_F1, 0);
			input_sync(sinput_dev);
		}
		
	}

	#if 0
	else if (gl_switch == 1 && gpio_state == 1)
	{
		if(gpio_statu_new != gpio_statu_pre)
		{
			gpio_statu_pre = gpio_statu_new;
			input_event(sinput_dev, EV_KEY, KEY_F2, 1);
			input_event(sinput_dev, EV_KEY, KEY_F2, 0);
			input_sync(sinput_dev);
		}
	}
	#endif

    mod_timer(&gpio_timer, jiffies +  time_delay);
	
}



static irqreturn_t gpio_detect_status(int irq, void *dev_id)
{
	//gpio_state = gpio_get_value(gpio2_a4);
	//printk("hxl gpio_detect_status = %d\n",gpio_state);
	//mod_timer(&gpio_timer, jiffies  +  HZ * 60);
	return IRQ_HANDLED;
}


static int init_timer_gpio(void) 
{
	init_timer(&gpio_timer);
	gpio_timer.function = gpio_timer_func;
	mod_timer(&gpio_timer, jiffies +   HZ * 20 );
	return 0;
}


static ssize_t gpio3d3_switch_show(struct class *cls,struct class_attribute *attr, char *_buf)
{
	 
       printk("%s>>>>>>>> gl_switch = %d\n",__func__, gl_switch);
	   ssize_t len = 0;
	  
	   	//int value = 0;
	   	//value = gpio_get_value(gpio0_b4);
		
	    len += snprintf(_buf + len, PAGE_SIZE - len, "%d \r\n", gl_switch);


	   	return 0;
}

static ssize_t gpio3d3_switch_store(struct class *cls,struct class_attribute *attr, const char *buf, size_t _count)
{
        gl_switch = simple_strtol(buf,NULL,10);
		
        if(gl_switch <= 1 && gl_switch>=  0)
        {
                //Setting_Directions(gl_backlight);
				
				//gpio_direction_output(gpio0_b4, gl_value);				
                printk(KERN_INFO "gl_switch is %d\n",gl_switch);
        }
        else
        {
                //backlight_power_on(0);
                printk(KERN_INFO "gl_switch is not support\n");
        }

    return _count;
}


static CLASS_ATTR(gpio3d3_switch, 0664, gpio3d3_switch_show, gpio3d3_switch_store);

static int gpio_sys_init(void)
{
    int ret ;
    rk_gpio_class = class_create(THIS_MODULE, "rk_gpio");
    ret =  class_create_file(rk_gpio_class, &class_attr_gpio3d3_switch);
    if (ret)
    {
       printk("Fail to creat class gpio5c1.\n");
    }
	
   return 0;
}

static int read_switch_function(void)
{
	int temp_count;
	temp_count = load_jl_value();

	if(temp_count == 300)
	{
		gl_switch = 1;
	}else if (temp_count == 200)
	{
		gl_switch = 0;
	}
}

static void read_io_work_func( struct work_struct *work )
{
       read_switch_function();
       schedule_delayed_work(&read_io_work, 10);
}



static int gpio_control_probe(struct platform_device *pdev)
{
		struct device *dev = &pdev->dev;
        struct device_node *node = pdev->dev.of_node;
        enum of_gpio_flags flags;
        int ret;
        int error;
		struct proc_dir_entry *ent;
		struct input_dev *input = NULL;

        printk("cjc func: %s\n", __func__); 
        if (!node)
                return -ENODEV;

		
		input = devm_input_allocate_device(dev);
		if (!input) {
			error = -ENOMEM;
			return error;
		}


		input->name = "cjc-keypad";	/* pdev->name; */
		input->phys = "gpio-keys/input111";
		input->dev.parent = dev;
		
		input->id.bustype = BUS_HOST;
		input->id.vendor = 0x0001;
		input->id.product = 0x0001;
		input->id.version = 0x0100;
		

		error = input_register_device(input);
		if (error) {
			pr_err("gpio-keys: Unable to register input device, error: %d\n",error);
		}

		sinput_dev = input;
		input_set_capability(input, EV_KEY, KEY_F1);
		input_set_capability(input, EV_KEY, KEY_F2);
		input_set_capability(input, EV_KEY, KEY_WAKEUP);

	printk("gpio_control_prob cjc #####\n");


	gpio3_d3 = of_get_named_gpio_flags(node, "gpio_control_1", 0, &flags);
	//en_value = (flags == GPIO_ACTIVE_HIGH)? 1:0;
	//gpio =  of_get_named_gpio(node, "gpios", 0);
	if(!gpio_is_valid(gpio3_d3)){
		dev_err(&pdev->dev, "invalid gpio_control gpio%d\n", gpio3_d3);
	}
	
	ret = devm_gpio_request(&pdev->dev, gpio3_d3, "gpio3");
	if (ret) {
		dev_err(&pdev->dev,
			"failed to request GPIO%d for otg_drv\n",
			gpio3_d3);
		return -EINVAL;
	}
	printk("set gpio direction_input cjc ###");
	gpio_direction_input(gpio3_d3);


	irq_gpio3_d3 = gpio_to_irq(gpio3_d3);
	if (irq_gpio3_d3 < 0) {
		printk("gpio-keys: Unable to get irq number for GPIO %d\n",
			   gpio3_d3);
		gpio_free(gpio3_d3);
		//goto fail1;
	}

#if 0
	error = devm_request_irq(dev, irq_gpio3_d3, gpio_detect_status,
						 IRQF_TRIGGER_FALLING|IRQ_TYPE_EDGE_RISING,
						 "gpio3_d3",
						 NULL);		
#endif

	init_timer_gpio();
	gpio_sys_init();

     INIT_DELAYED_WORK(&read_io_work, read_io_work_func);
     schedule_delayed_work(&read_io_work, 10);

	return 0;
file:
		printk("func: %s some error\n", __func__); 
        return 0;
}

static int gpio_control_remove(struct platform_device *pdev)
{
        //printk("func: %s\n", __func__); 
	return 0;
}

#ifdef CONFIG_PM_SLEEP
static int gpio_control_suspend(struct device *dev)
{
        //printk("func: %s\n", __func__); 
	return 0;
}

static int gpio_control_resume(struct device *dev)
{
        //printk("func: %s\n", __func__); 
	return 0;
}
#endif

static const struct dev_pm_ops gpio_control_ops = {
#ifdef CONFIG_PM_SLEEP
	.suspend = gpio_control_suspend,
	.resume = gpio_control_resume,
	.poweroff = gpio_control_suspend,
	.restore = gpio_control_resume,
#endif
};

static struct platform_driver gpio_driver = {
	.driver		= {
		.name		= "gpio_control",
		.owner		= THIS_MODULE,
		.pm		= &gpio_control_ops,
		.of_match_table	= of_match_ptr(gpio_of_match),
	},
	.probe		= gpio_control_probe,
	.remove		= gpio_control_remove,
};

module_platform_driver(gpio_driver);

MODULE_DESCRIPTION("gpio_control");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:gpio_control");
