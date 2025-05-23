//V1.0.0 Kavie 20141021 RK3126 SP0A19 k71


//#include <linux/gpio.h>
#include "generic_sensor.h"
/*
*      Driver Version Note
*v0.0.1: this driver is compatible with generic_sensor
*v0.1.1:
*        add sensor_focus_af_const_pause_usr_cb;
*/
static int version = KERNEL_VERSION(0,1,1);
module_param(version, int, S_IRUGO);



static int debug;
module_param(debug, int, S_IRUGO|S_IWUSR);

#define dprintk(level, fmt, arg...) do {			\
	if (debug > level) 					\
	printk(KERN_WARNING fmt , ## arg); } while (0)

/* Sensor Driver Configuration Begin */
#define SENSOR_NAME RK29_CAM_SENSOR_SP0A19
#define SENSOR_V4L2_IDENT V4L2_IDENT_SP0A19
#define SENSOR_ID 0xa6
#define SENSOR_BUS_PARAM                     (V4L2_MBUS_MASTER |\
                                             V4L2_MBUS_PCLK_SAMPLE_RISING|V4L2_MBUS_HSYNC_ACTIVE_HIGH| V4L2_MBUS_VSYNC_ACTIVE_HIGH|\
                                             V4L2_MBUS_DATA_ACTIVE_HIGH   | SOCAM_MCLK_24MHZ)
#define SENSOR_PREVIEW_W                     640
#define SENSOR_PREVIEW_H                     480
#define SENSOR_PREVIEW_FPS                   15000     // 15fps 
#define SENSOR_FULLRES_L_FPS                 7500      // 7.5fps
#define SENSOR_FULLRES_H_FPS                 7500      // 7.5fps
#define SENSOR_720P_FPS                      0
#define SENSOR_1080P_FPS                     0

#define SENSOR_REGISTER_LEN                  1         // sensor register address bytes
#define SENSOR_VALUE_LEN                     1         // sensor register value bytes

static unsigned int SensorConfiguration = (CFG_WhiteBalance|CFG_Effect|CFG_Scene);
static unsigned int SensorChipID[] = {SENSOR_ID};
/* Sensor Driver Configuration End */


#define SENSOR_NAME_STRING(a) STR(CONS(SENSOR_NAME, a))
#define SENSOR_NAME_VARFUN(a) CONS(SENSOR_NAME, a)

#define SensorRegVal(a,b) CONS4(SensorReg,SENSOR_REGISTER_LEN,Val,SENSOR_VALUE_LEN)(a,b)
#define sensor_write(client,reg,v) CONS4(sensor_write_reg,SENSOR_REGISTER_LEN,val,SENSOR_VALUE_LEN)(client,(reg),(v))
#define sensor_read(client,reg,v) CONS4(sensor_read_reg,SENSOR_REGISTER_LEN,val,SENSOR_VALUE_LEN)(client,(reg),(v))
#define sensor_write_array generic_sensor_write_array

struct sensor_parameter
{
	unsigned int PreviewDummyPixels;
	unsigned int CaptureDummyPixels;
	unsigned int preview_exposure;
	unsigned short int preview_line_width;
	unsigned short int preview_gain;

	unsigned short int PreviewPclk;
	unsigned short int CapturePclk;
	char awb[6];
};

struct specific_sensor{
	struct generic_sensor common_sensor;
	//define user data below
	struct sensor_parameter parameter;

};


//HEQ
#define  Pre_Value_P0_0xdd  0x68
#define  Pre_Value_P0_0xde  0xa8

/*
*  The follow setting need been filled.
*  
*  Must Filled:
*  sensor_init_data :               Sensor initial setting;
*  sensor_fullres_lowfps_data :     Sensor full resolution setting with best auality, recommand for video;
*  sensor_preview_data :            Sensor preview resolution setting, recommand it is vga or svga;
*  sensor_softreset_data :          Sensor software reset register;
*  sensor_check_id_data :           Sensir chip id register;
*
*  Optional filled:
*  sensor_fullres_highfps_data:     Sensor full resolution setting with high framerate, recommand for video;
*  sensor_720p:                     Sensor 720p setting, it is for video;
*  sensor_1080p:                    Sensor 1080p setting, it is for video;
*
*  :::::WARNING:::::
*  The SensorEnd which is the setting end flag must be filled int the last of each setting;
*/

/* Sensor initial setting *//* init 640X480 VGA */
static struct rk_sensor_reg sensor_init_data[] =
{
	// 0A19 int
		{0xfd,0x00},
		{0x1c,0x28},
	  {0x32,0x00}, 
	  {0x0f,0x2f}, 
	  {0x10,0x2e}, 
	  {0x11,0x00}, 
	  {0x12,0x18}, 
	  {0x13,0x2f}, 
	  {0x14,0x00}, 
	  {0x15,0x3f}, 
	  {0x16,0x00}, 
	  {0x17,0x18}, 
	  {0x25,0x40}, 
	  {0x1a,0x0b}, 
	  {0x1b,0xc }, 
	  {0x1e,0xb }, 
	  {0x20,0x3f}, 
	  {0x21,0x13}, 
	  {0x22,0x19}, 
	  {0x26,0x1a}, 
	  {0x27,0xab}, 
	  {0x28,0xfd}, 
	  {0x30,0x00}, 
	  {0x31,0x60},  //10
	  {0xfb,0x33}, 
	  {0x1f,0x08}, 
	  //{0x20,0x3f}, 
					 
	//Blacklevel	  
	  {0xfd,0x00}, 
	  {0x65,0x00}, 
	  {0x66,0x00}, 
	  {0x67,0x00}, 
	  {0x68,0x00}, 
	  {0x45,0x00}, 
	  {0x46,0xff}, 
	  
	//ae setting   23M 1PLL 50HZ 8-10FPS
	  {0xfd , 0x00}, 
	  {0x03 , 0x00},	
	  {0x04 , 0x99},	
	  {0x06 , 0x00},	
	  {0x09 , 0x05},	
	  {0x0a , 0x7d},	
	  {0xf0 , 0x33},	
	  {0xf1 , 0x00},	
	  {0xfd , 0x01},	
	  {0x90 , 0x0c},	
	  {0x92 , 0x01},	
	  {0x98 , 0x33},	
	  {0x99 , 0x00},	
	  {0x9a , 0x01},	
	  {0x9b , 0x00},	
	//Status		 
	  {0xfd , 0x01},	
	  {0xce , 0x64},	
	  {0xcf , 0x02},	
	  {0xd0 , 0x64},	
	  {0xd1 , 0x02},	
	  {0xfd , 0x00},	
	  
	  {0xfd , 0x01},	
	  {0xc4 , 0x56},	
	  {0xc5 , 0x80},	
	  {0xca , 0x30},	
	  {0xcb , 0x45},	
	  {0xcc , 0x68},	
	  {0xcd , 0x48},	
	  {0xfd , 0x00},	
	  
	 //lsc	for 	
	  {0xfd , 0x01},	
	  {0x35 , 0x15},	
	  {0x36 , 0x15},	
	  {0x37 , 0x15},	
	  {0x38 , 0x15},	
	  {0x39 , 0x15},	
	  {0x3a , 0x15},	
	  {0x3b , 0x13},	
	  {0x3c , 0x15},	
	  {0x3d , 0x15},	
	  {0x3e , 0x15},	
	  {0x3f , 0x15},	
	  {0x40 , 0x18},	
	  {0x41 , 0x00},	
	  {0x42 , 0x04},	
	  {0x43 , 0x04},	
	  {0x44 , 0x00},	
	  {0x45 , 0x00},	
	  {0x46 , 0x00},	
	  {0x47 , 0x00},	
	  {0x48 , 0x00},	
	  {0x49 , 0xfd},	
	  {0x4a , 0x00},	
	  {0x4b , 0x00},	
	  {0x4c , 0xfd},	
	  {0xfd , 0x00},	
	 
	 
	//awb 1 		  
	  {0xfd , 0x01},	
	  {0x28 , 0xc5},	
	  {0x29 , 0x9b},	
	  {0x10 , 0x0 },	
	  {0x11 , 0x1 },	
	  {0x12 , 0x1 },	
	  {0x2e , 0x02},	
	  {0x2f , 0x16},	
	  {0x17 , 0x17},	
	  {0x18 , 0x19},	
	  {0x19 , 0x45},	
	   
	  {0x1a , 0x9},    
	  {0x1b , 0xa},    
	  {0x33 , 0xe},    
	  {0x2a , 0xef},	
	  {0x2b , 0x15},	
	   
	 //awb2 		 
	  {0xfd , 0x01},	
	  {0x73 , 0x80},	
	  {0x1a , 0x80},	
	  {0x1b , 0x80},	
	//d65		   
	  {0x65 , 0xd5},	
	  {0x66 , 0xfa},	
	  {0x67 , 0x72},	
	  {0x68 , 0x8a},	
	//indoor		  
	  {0x69 , 0xc6},	
	  {0x6a , 0xee},	
	  {0x6b , 0x94},	
	  {0x6c , 0xab},	
	//f 			  
	  {0x61 , 0x7a},	
	  {0x62 , 0x98},	
	  {0x63 , 0xc5},	
	  {0x64 , 0xe6},	
	//cwf		   
	  {0x6d , 0xb9},	
	  {0x6e , 0xde},	
	  {0x6f , 0xb2},	
	  {0x70 , 0xd5},	
	  
	//skin	  
	  {0xfd , 0x01},	
	  {0x08 , 0x15},	
	  {0x09 , 0x04},	
	  {0x0a , 0x20},	
	  {0x0b , 0x12},	
	  {0x0c , 0x27},	
	  {0x0d , 0x06},	
	  {0x0f , 0x63},	
					
					
					
	//BPC_grad		  
	  {0xfd , 0x00},	
	  {0x79 , 0xf0},	
	  {0x7a , 0x80},	  
	  {0x7b , 0x80},	  
	  {0x7c , 0x20},		
	   
	//smooth		  
	  {0xfd , 0x00},	
	//单通道间平滑阈值	
	  {0x57 , 0x0a},	
	  {0x58 , 0x10},	
	  {0x56 , 0x14},	
	  {0x59 , 0x18},	
		//GrGb平滑阈	
	  {0x89 , 0x0a},	
	  {0x8a , 0x10},	
	  {0x9c , 0x14},	
	  {0x9d , 0x18},	
	   
		//Gr\Gb    
	  {0x81 , 0xa0},	
	  {0x82 , 0x80},	
	  {0x83 , 0x60},	
	  {0x84 , 0x40},	
		//Gr、Gb单通	
	  {0x85 , 0xa0},	
	  {0x86 , 0x80},	
	  {0x87 , 0x60},	
	  {0x88 , 0x40},	
		//R、B平滑强	
	  {0x5a , 0xff},	
	  {0x5b , 0x80},	
	  {0x5c , 0x60},	
	  {0x5d , 0x00},	
		
	//sharpen		  
	  {0xfd , 0x01},	
	  {0xe2 , 0x30},	
	  {0xe4 , 0xa0},	
	   
	  {0xe5 , 0x0a},	
	  {0xd3 , 0x0a},	   
	  {0xd7 , 0x0a},	   
		  
	  {0xe6 , 0x0d},	
	  {0xd4 , 0x0d},	
	  {0xd8 , 0x0d},	 
	   
	  {0xe7 , 0x12},	
	  {0xd5 , 0x12},	
	  {0xd9 , 0x12},	
		  
	  {0xd2 , 0x15},   
	  {0xd6 , 0x15},   
	  {0xda , 0x15},   
	  
	  {0xe8 , 0x20},   
	  {0xec , 0x2c},   
	  {0xe9 , 0x20},   
	  {0xed , 0x28},	
	  {0xea , 0x20},	
	  {0xef , 0x24},	
	  {0xeb , 0x10},	
	  {0xf0 , 0x20},	
#if 0		 
	//CCM			 
	{0xfd , 0x01},	
	{0xa0 , 0x80},   
	{0xa1 , 0x0 },	
	{0xa2 , 0x0 },	
	{0xa3 , 0xf3},	
	{0xa4 , 0x8e},	
	{0xa5 , 0x0 },	
	{0xa6 , 0x0 },	
	{0xa7 , 0xe6},	
	{0xa8 , 0x9a},	
	{0xa9 , 0x0 },	
	{0xaa , 0x3 },	
	{0xab , 0xc },	
	{0xfd , 0x00},	

//#else

	{0xa0,0xb3},//80(红色接近，肤色不理想) 
	{0xa1,0xca},//0                        
	{0xa2,0x00},//0                        
	{0xa3,0x1e},//f0                       
	{0xa4,0x70},//a6                       
	{0xa5,0xf2},//ea                       
	{0xa6,0x18},//0                        
	{0xa7,0xbc},//e6                       
	{0xa8,0xab},//9a                       
	{0xa9,0x0c},//0                        
	{0xaa,0x30},//33                       
	{0xab,0x0c},//c                        
	{0xfd,0x00},  
	#else
	{0xa0,0xae},//0x80
	{0xa1,0xcf},//0x0000
	{0xa2,0x00},//0x0000
	{0xa3,0x19},//0x0006
	{0xa4,0x70},//0x8c8c
	{0xa5,0xf7},//0xf4ed
	{0xa6,0x18},//0x0c0c
	{0xa7,0xc1},//0xf4f4
	{0xa8,0xa6},//0x8080
	{0xa9,0x0c},//0x0000
	{0xaa,0x30},//0x3030
	{0xab,0x0c},//0x0c0c 

#endif
	//gamma 		 
		
	  {0xfd , 0x00},	
	  {0x8b , 0x0 },	
	  {0x8c , 0xC },	
	  {0x8d , 0x19},	
	  {0x8e , 0x2C},	
	  {0x8f , 0x49},	
	  {0x90 , 0x61},	
	  {0x91 , 0x77},	
	  {0x92 , 0x8A},	
	  {0x93 , 0x9B},	
	  {0x94 , 0xA9},	
	  {0x95 , 0xB5},	
	  {0x96 , 0xC0},	
	  {0x97 , 0xCA},	
	  {0x98 , 0xD0},	
	  {0x99 , 0xDa},	
	  {0x9a , 0xE2},	
	  {0x9b , 0xEc},	
	  {0xfd , 0x01},	
	  {0x8d , 0xF0},	
	  {0x8e , 0xF2},	
					
	//rpc			  
	  {0xfd , 0x00},	
	  {0xe0 , 0x4c},	
	  {0xe1 , 0x3c},	
	  {0xe2 , 0x34},	
	  {0xe3 , 0x2e},	
	  {0xe4 , 0x2e},	
	  {0xe5 , 0x2c},	
	  {0xe6 , 0x2c},	
	  {0xe8 , 0x2a},	
	  {0xe9 , 0x2a},	
	  {0xea , 0x2a},	
	  {0xeb , 0x28},	
	  {0xf5 , 0x28},	
	  {0xf6 , 0x28},	
	//ae min gain	  
	  {0xfd , 0x01},	
	  {0x94 , 0xa0},	
	  {0x95 , 0x28},	
	  {0x9c , 0xa0},	
	  {0x9d , 0x28},	
	  
	//ae target 	 
	  {0xfd , 0x00},	
	  {0xed , 0x8c},	
	  {0xf7 , 0x88},	
	  {0xf8 , 0x80},	
	  {0xec , 0x7c},	
		
	  {0xef , 0x74},	
	  {0xf9 , 0x70},	
	  {0xfa , 0x68},	
	  {0xee , 0x64},	
		
		
	//gray detect	  
	  {0xfd , 0x01},	
	  {0x30 , 0x40},	
	  {0x31 , 0x70},	
	  {0x32 , 0x40},	
	  {0x33 , 0xef},	
	  {0x34 , 0x05},	
	  {0x4d , 0x2f},	
	  {0x4e , 0x20},	
	  {0x4f , 0x16},	
	  
	//lowlight lum	  
	  {0xfd , 0x00},	
	  {0xb2 , 0x10},	
	  {0xb3 , 0x1f},	
	  {0xb4 , 0x20},	
	  {0xb5 , 0x50},	
	   
	//aturation 	
	  {0xfd , 0x00},	
	  {0xbe , 0xff},	
	  {0xbf , 0x01},	
	  {0xc0 , 0xff},	
	  {0xc1 , 0xd8},	
	  {0xd3 , 0x68},	
	  {0xd4 , 0x68},	
	  {0xd6 , 0x68},	  
	  {0xd7 , 0x50},	
		
	//HEQ		   
	  {0xfd , 0x00},	
	  {0xdc , 0x00},	
	  {0xdd , 0x78},//80	
	  {0xde , 0xb8},//a8	
	  {0xdf , 0x80},	
	   
	//func enable	 
	  {0xfd , 0x00},	
	  {0x32 , 0x15},	
	  {0x34 , 0x76},
	  {0x35 , 0x40},
	  {0x33 , 0xef},	
	  {0x5f , 0x51},
	  
	SensorEnd
};


/* Senor full resolution setting: recommand for capture */
static struct rk_sensor_reg sensor_fullres_lowfps_data[] ={
/*
    {0x47, 0x00},
    {0x48, 0x00},
    {0x49, 0x01},
    {0x4a, 0xe0},
    {0x4b, 0x00},
    {0x4c, 0x00},
    {0x4d, 0x02},
    {0x4e, 0x80},
*/
	SensorEnd
};
/* Senor full resolution setting: recommand for video */
static struct rk_sensor_reg sensor_fullres_highfps_data[] ={
	SensorEnd
};
/* Preview resolution setting*/
static struct rk_sensor_reg sensor_preview_data[] =
{
/*
    {0x47, 0x00},
    {0x48, 0x00},
    {0x49, 0x01},
    {0x4a, 0xe0},
    {0x4b, 0x00},
    {0x4c, 0x00},
    {0x4d, 0x02},
    {0x4e, 0x80},
*/
	SensorEnd
};
/* 1280x720 */
static struct rk_sensor_reg sensor_720p[]={
	SensorEnd
};

/* 1920x1080 */
static struct rk_sensor_reg sensor_1080p[]={
	SensorEnd
};


static struct rk_sensor_reg sensor_softreset_data[]={
	SensorEnd
};

static struct rk_sensor_reg sensor_check_id_data[]={
    SensorRegVal(0x02,0),
	SensorEnd
};

///=========sp0a19-modify by sp_yjp,20120529=================

static  struct rk_sensor_reg sensor_WhiteB_Auto[]=
{
	//sp0a19_reg_WB_auto       
	{0xfd,0x01},                      
	{0x28,0xc5},		                  
	{0x29,0x9b},                      
	{0xfd,0x00}, 		
	{0x32,0x15},   //awb & ae  opened
	{0xfd,0x00},
	SensorEnd
};
/* Cloudy Colour Temperature : 6500K - 8000K  */
static  struct rk_sensor_reg sensor_WhiteB_Cloudy[]=
{
	// sp0a19_reg_WB_auto  
	{0xfd,0x00}, 
	{0x32,0x05},          
	{0xfd,0x01},          
	{0x28,0xbf},	        
	{0x29,0x89},		                                                       
    {0xfd, 0x00},
	SensorEnd
};
/* ClearDay Colour Temperature : 5000K - 6500K  */
static  struct rk_sensor_reg sensor_WhiteB_ClearDay[]=
{
    //Sunny
	// sp0a19_reg_WB_auto  
	{0xfd,0x00}, 
	{0x32,0x05},           
	{0xfd,0x01},           
	{0x28,0xbc},	         
	{0x29,0x5d},	         
	{0xfd,0x00},		                                                       
    {0xfd, 0x00},
	SensorEnd
};
/* Office Colour Temperature : 3500K - 5000K  */
static  struct rk_sensor_reg sensor_WhiteB_TungstenLamp1[]=
{
    {0xfd,0x00},  
	{0x32,0x05},                  
	{0xfd,0x01},                  
	{0x28,0xaf},		              
	{0x29,0x99},		                                                       
    {0xfd, 0x00},
	SensorEnd
};
static	struct rk_sensor_reg sensor_WhiteB_TungstenLamp2[]=
{
	{0xfd,0x00}, 
	{0x32,0x05},                 
	{0xfd,0x01},                 
	{0x28,0x89},		             
	{0x29,0xb8},		             
	{0xfd,0x00}, 
	SensorEnd 
};
static struct rk_sensor_reg *sensor_WhiteBalanceSeqe[] = {sensor_WhiteB_Auto, sensor_WhiteB_TungstenLamp1,sensor_WhiteB_TungstenLamp2,
    sensor_WhiteB_ClearDay, sensor_WhiteB_Cloudy,NULL,
};

///=========sp0a19-modify by sp_yjp,20120529=================
static  struct rk_sensor_reg sensor_Brightness0[]=
{
    // Brightness -2
    {0xfd, 0x00},
	{0xdc, 0xe0},
	{0xfd, 0x00},
	SensorEnd
};

static  struct rk_sensor_reg sensor_Brightness1[]=
{
    // Brightness -1
    {0xfd, 0x00},
	{0xdc, 0xf0},
	{0xfd, 0x00},
	SensorEnd
};

static  struct rk_sensor_reg sensor_Brightness2[]=
{
    //  Brightness 0
    {0xfd, 0x00},
	{0xdc, 0x10},
	{0xfd, 0x00},
	SensorEnd
};

static  struct rk_sensor_reg sensor_Brightness3[]=
{
    // Brightness +1
    {0xfd, 0x00},
	{0xdc, 0x10},
	{0xfd, 0x00},
	SensorEnd
};

static  struct rk_sensor_reg sensor_Brightness4[]=
{
    //  Brightness +2
    {0xfd, 0x00},
	{0xdc, 0x20},
	{0xfd, 0x00},
	SensorEnd
};

static  struct rk_sensor_reg sensor_Brightness5[]=
{
    //  Brightness +3
    {0xfd, 0x00},
	{0xdc, 0x30},
	{0xfd, 0x00},
	SensorEnd
};
static struct rk_sensor_reg *sensor_BrightnessSeqe[] = {sensor_Brightness0, sensor_Brightness1, sensor_Brightness2, sensor_Brightness3,
    sensor_Brightness4, sensor_Brightness5,NULL,
};

///=========sp0a19-modify by sp_yjp,20120529=================
static  struct rk_sensor_reg sensor_Effect_Normal[] =
{
	{0xfd, 0x00},
	{0x62, 0x00},
	{0x63, 0x80},
	{0x64, 0x80},
    {0xfd, 0x00},
	SensorEnd
};

static  struct rk_sensor_reg sensor_Effect_WandB[] =
{
	{0xfd, 0x00},
	{0x62, 0x20},
	{0x63, 0x80},
	{0x64, 0x80},
    {0xfd, 0x00},
	SensorEnd
};

static  struct rk_sensor_reg sensor_Effect_Sepia[] =
{
    {0xfd, 0x00},
	{0x62, 0x10},
	{0x63, 0xc0},
	{0x64, 0x20},
    {0xfd, 0x00},
	SensorEnd
};

static  struct rk_sensor_reg sensor_Effect_Negative[] =
{
    //Negative
	{0xfd, 0x00},
	{0x62, 0x04},
	{0x63, 0x80},
	{0x64, 0x80},
    {0xfd, 0x00},
	SensorEnd
};
static  struct rk_sensor_reg sensor_Effect_Bluish[] =
{
    // Bluish
    {0xfd, 0x00},
	{0x62, 0x10},
	{0x63, 0x20},
	{0x64, 0xf0},
    {0xfd, 0x00},
	SensorEnd
};

static  struct rk_sensor_reg sensor_Effect_Green[] =
{
    //  Greenish
    {0xfd, 0x00},
	{0x62, 0x10},
	{0x63, 0x20},
	{0x64, 0x20},
    {0xfd, 0x00},
	SensorEnd
};
static struct rk_sensor_reg *sensor_EffectSeqe[] = {sensor_Effect_Normal, sensor_Effect_WandB, sensor_Effect_Negative,sensor_Effect_Sepia,
    sensor_Effect_Bluish, sensor_Effect_Green,NULL,
};

///=========sp0a19-modify by sp_yjp,20120529=================
static  struct rk_sensor_reg sensor_Exposure0[]=
{
	{0xfd, 0x00},
	{0xdc, 0xd0},
    {0xfd, 0x00},
    SensorEnd
};

static  struct rk_sensor_reg sensor_Exposure1[]=
{
	{0xfd, 0x00},
	{0xdc, 0xe0},
    {0xfd, 0x00},
    SensorEnd
};

static  struct rk_sensor_reg sensor_Exposure2[]=
{
	{0xfd, 0x00},
	{0xdc, 0xf0},
    {0xfd, 0x00},
    SensorEnd
};

static  struct rk_sensor_reg sensor_Exposure3[]=
{
	{0xfd, 0x00},
	{0xdc, 0x10},
    {0xfd, 0x00},
    SensorEnd
};

static  struct rk_sensor_reg sensor_Exposure4[]=
{
	{0xfd, 0x00},
	{0xdc, 0x10},
    {0xfd, 0x00},
    SensorEnd
};

static  struct rk_sensor_reg sensor_Exposure5[]=
{
	{0xfd, 0x00},
	{0xdc, 0x20},
    {0xfd, 0x00},
    SensorEnd
};

static  struct rk_sensor_reg sensor_Exposure6[]=
{
	{0xfd, 0x00},
	{0xdc, 0x30},
    {0xfd, 0x00},
    SensorEnd
};

static struct rk_sensor_reg *sensor_ExposureSeqe[] = {sensor_Exposure0, sensor_Exposure1, sensor_Exposure2, sensor_Exposure3,
    sensor_Exposure4, sensor_Exposure5,sensor_Exposure6,NULL,
};

///=========sp0a19-modify by sp_yjp,20120529=================
static  struct rk_sensor_reg sensor_Saturation0[]=
{
    SensorEnd
};

static  struct rk_sensor_reg sensor_Saturation1[]=
{
    SensorEnd
};

static  struct rk_sensor_reg sensor_Saturation2[]=
{
    SensorEnd
};
static struct rk_sensor_reg *sensor_SaturationSeqe[] = {sensor_Saturation0, sensor_Saturation1, sensor_Saturation2, NULL,};


static  struct rk_sensor_reg sensor_Contrast0[]=
{
	{0xfd, 0x00},
	{0xdd,	Pre_Value_P0_0xdd-0x30},	//level -3
	{0xde,	Pre_Value_P0_0xde-0x30},
    SensorEnd
};

static  struct rk_sensor_reg sensor_Contrast1[]=
{
	{0xfd, 0x00},
	{0xdd,	Pre_Value_P0_0xdd-0x20},	//level -2
    {0xde,	Pre_Value_P0_0xde-0x20},
    SensorEnd
};

static  struct rk_sensor_reg sensor_Contrast2[]=
{
	{0xfd, 0x00},
	{0xdd, Pre_Value_P0_0xdd-0x10},	//level -1
	{0xde, Pre_Value_P0_0xde-0x10},
SensorEnd
};

static  struct rk_sensor_reg sensor_Contrast3[]=
{
	{0xfd, 0x00},
	{0xdd, Pre_Value_P0_0xdd}, //level 0
	{0xde, Pre_Value_P0_0xde},
SensorEnd
};

static  struct rk_sensor_reg sensor_Contrast4[]=
{
	{0xfd, 0x00},
	{0xdd,	Pre_Value_P0_0xdd+0x10},	//level +1
	{0xde,	Pre_Value_P0_0xde+0x10},
SensorEnd
};


static  struct rk_sensor_reg sensor_Contrast5[]=
{
	{0xfd, 0x00},
	{0xdd,	Pre_Value_P0_0xdd+0x20},	//level +2
	{0xde,	Pre_Value_P0_0xde+0x20},
SensorEnd
};

static  struct rk_sensor_reg sensor_Contrast6[]=
{
	{0xfd, 0x00},
	{0xdd,	Pre_Value_P0_0xdd+0x30},	//level +3
	{0xde,	Pre_Value_P0_0xde+0x30},
SensorEnd
};




static struct rk_sensor_reg *sensor_ContrastSeqe[] = {sensor_Contrast0, sensor_Contrast1, sensor_Contrast2, sensor_Contrast3,
    sensor_Contrast4, sensor_Contrast5, sensor_Contrast6, NULL,
};


static  struct rk_sensor_reg sensor_SceneAuto[] =
{
	
	//ae setting
	  {0xfd , 0x00},
	  {0x03 , 0x00},
	  {0x04 , 0x96},
	  {0x06 , 0x00},
	  {0x09 , 0x05},
	  {0x0a , 0xaa},
	  {0xf0 , 0x32},
	  {0xf1 , 0x00},
	  {0xfd , 0x01},
	  {0x90 , 0x10},
	  {0x92 , 0x01},
	  {0x98 , 0x32},
	  {0x99 , 0x00},
	  {0x9a , 0x01},
	  {0x9b , 0x00},
	//Status	  
	  {0xfd , 0x01},
	  {0xce , 0x20},
	  {0xcf , 0x03},
	  {0xd0 , 0x20},
	  {0xd1 , 0x03},
	  {0xfd , 0x00},
	
	SensorEnd
};

static  struct rk_sensor_reg sensor_SceneNight[] =
{
	
	//ae setting
	  {0xfd , 0x00},
	  {0x03 , 0x00},
	  {0x04 , 0x96},
	  {0x06 , 0x00},
	  {0x09 , 0x05},
	  {0x0a , 0xaa},
	  {0xf0 , 0x32},
	  {0xf1 , 0x00},
	  {0xfd , 0x01},
	  {0x90 , 0x10},
	  {0x92 , 0x01},
	  {0x98 , 0x32},
	  {0x99 , 0x00},
	  {0x9a , 0x01},
	  {0x9b , 0x00},
	//Status	  
	  {0xfd , 0x01},
	  {0xce , 0x20},
	  {0xcf , 0x03},
	  {0xd0 , 0x20},
	  {0xd1 , 0x03},
	  {0xfd , 0x00},
	
	SensorEnd
};

static struct rk_sensor_reg *sensor_SceneSeqe[] = {sensor_SceneAuto, sensor_SceneNight,NULL,};

///=========sp0a19-modify by sp_yjp,20120529=================
static struct rk_sensor_reg sensor_Zoom0[] =
{
SensorEnd
};

static struct rk_sensor_reg sensor_Zoom1[] =
{
SensorEnd
};

static struct rk_sensor_reg sensor_Zoom2[] =
{
SensorEnd
};


static struct rk_sensor_reg sensor_Zoom3[] =
{
SensorEnd
};
static struct rk_sensor_reg *sensor_ZoomSeqe[] = {sensor_Zoom0, sensor_Zoom1, sensor_Zoom2, sensor_Zoom3, NULL,};


///=========sp0a19-modify by sp_yjp,20120529=================
static struct v4l2_querymenu sensor_menus[] =
{
};
/*
* User could be add v4l2_queryctrl in sensor_controls by new_user_v4l2ctrl
*/
static struct sensor_v4l2ctrl_usr_s sensor_controls[] =
{
};

//MUST define the current used format as the first item   
static struct rk_sensor_datafmt sensor_colour_fmts[] = {
	{MEDIA_BUS_FMT_YUYV8_2X8, V4L2_COLORSPACE_JPEG} 
};
//static struct soc_camera_ops sensor_ops;

/*
**********************************************************
* Following is local code:
* 
* Please codeing your program here 
**********************************************************
*/

/*
**********************************************************
* Following is callback
* If necessary, you could coding these callback
**********************************************************
*/
/*
* the function is called in open sensor  
*/
static int sensor_activate_cb(struct i2c_client *client)
{

    SENSOR_DG("%s",__FUNCTION__);	

	
	return 0;
}
/*
* the function is called in close sensor
*/
static int sensor_deactivate_cb(struct i2c_client *client)
{
	//struct generic_sensor *sensor = to_generic_sensor(client);

    SENSOR_DG("%s",__FUNCTION__);
    
	return 0;
}
/*
* the function is called before sensor register setting in VIDIOC_S_FMT  
*/
static int sensor_s_fmt_cb_th(struct i2c_client *client,struct v4l2_mbus_framefmt *mf, bool capture)
{
    return 0;
}
/*
* the function is called after sensor register setting finished in VIDIOC_S_FMT  
*/
static int sensor_s_fmt_cb_bh (struct i2c_client *client,struct v4l2_mbus_framefmt *mf, bool capture)
{
    return 0;
}
static int sensor_softrest_usr_cb(struct i2c_client *client,struct rk_sensor_reg *series)
{
	return 0;
}

static int sensor_check_id_usr_cb(struct i2c_client *client,struct rk_sensor_reg *series)
{
	char pid = 0;
	int ret = 0;
	struct generic_sensor *sensor = to_generic_sensor(client);
	
	ret = sensor_write(client, 0xfd, 0x00);  //before read id should write 0xfd
	msleep(20);
	ret = sensor_read(client, 0x02, &pid);
	if (ret != 0) {
		SENSOR_TR("%s read chip id high byte failed\n",SENSOR_NAME_STRING());
		ret = -ENODEV;
	}
	SENSOR_DG("\n %s  pid = 0x%x\n", SENSOR_NAME_STRING(), pid);
	if (pid == SENSOR_ID) {
		sensor->model = SENSOR_V4L2_IDENT;
	} else {
		SENSOR_TR("error: %s mismatched   pid = 0x%x\n", SENSOR_NAME_STRING(), pid);
		ret = -ENODEV;
	}
	return pid;
}
static int sensor_try_fmt_cb_th(struct i2c_client *client,struct v4l2_mbus_framefmt *mf)
{
	return 0;
}
static int sensor_suspend(struct soc_camera_device *icd, pm_message_t pm_msg)
{
	//struct i2c_client *client = to_i2c_client(to_soc_camera_control(icd));

		
	if (pm_msg.event == PM_EVENT_SUSPEND) {
		SENSOR_DG("Suspend");
		
	} else {
		SENSOR_TR("pm_msg.event(0x%x) != PM_EVENT_SUSPEND\n",pm_msg.event);
		return -EINVAL;
	}
	return 0;
}

static int sensor_resume(struct soc_camera_device *icd)
{

	SENSOR_DG("Resume");

	return 0;

}
static int sensor_mirror_cb (struct i2c_client *client, int mirror)
{
	int err = 0;
    
    SENSOR_DG("mirror: %d",mirror);
	

	return err;    
}
/*
* the function is v4l2 control V4L2_CID_HFLIP callback  
*/
static int sensor_v4l2ctrl_mirror_cb(struct soc_camera_device *icd, struct sensor_v4l2ctrl_info_s *ctrl_info, 
                                                     struct v4l2_ext_control *ext_ctrl)
{
	struct i2c_client *client = to_i2c_client(to_soc_camera_control(icd));

    if (sensor_mirror_cb(client,ext_ctrl->value) != 0)
		SENSOR_TR("sensor_mirror failed, value:0x%x",ext_ctrl->value);
	
	SENSOR_DG("sensor_mirror success, value:0x%x",ext_ctrl->value);
	return 0;
}

static int sensor_flip_cb(struct i2c_client *client, int flip)
{
	int err = 0;	

    SENSOR_DG("flip: %d",flip);
	
	return err;    
}
/*
* the function is v4l2 control V4L2_CID_VFLIP callback  
*/
static int sensor_v4l2ctrl_flip_cb(struct soc_camera_device *icd, struct sensor_v4l2ctrl_info_s *ctrl_info, 
                                                     struct v4l2_ext_control *ext_ctrl)
{
	struct i2c_client *client = to_i2c_client(to_soc_camera_control(icd));

    if (sensor_flip_cb(client,ext_ctrl->value) != 0)
		SENSOR_TR("sensor_flip failed, value:0x%x",ext_ctrl->value);
	
	SENSOR_DG("sensor_flip success, value:0x%x",ext_ctrl->value);
	return 0;
}
/*
* the functions are focus callbacks
*/
static int sensor_focus_init_usr_cb(struct i2c_client *client){
	return 0;
}

static int sensor_focus_af_single_usr_cb(struct i2c_client *client){
	return 0;
}

static int sensor_focus_af_near_usr_cb(struct i2c_client *client){
	return 0;
}

static int sensor_focus_af_far_usr_cb(struct i2c_client *client){
	return 0;
}

static int sensor_focus_af_specialpos_usr_cb(struct i2c_client *client,int pos){
	return 0;
}

static int sensor_focus_af_const_usr_cb(struct i2c_client *client){
	return 0;
}
static int sensor_focus_af_const_pause_usr_cb(struct i2c_client *client)
{
    return 0;
}
static int sensor_focus_af_close_usr_cb(struct i2c_client *client){
	return 0;
}

static int sensor_focus_af_zoneupdate_usr_cb(struct i2c_client *client, int *zone_tm_pos)
{
    return 0;
}

/*
face defect call back
*/
static int 	sensor_face_detect_usr_cb(struct i2c_client *client,int on){
	return 0;
}

/*
*   The function can been run in sensor_init_parametres which run in sensor_probe, so user can do some
* initialization in the function. 
*/
static void sensor_init_parameters_user(struct specific_sensor* spsensor,struct soc_camera_device *icd)
{
    return;
}
/*

#define CHIP_NAME   RK29_CAM_SENSOR_NAME_SP0A19
#define DBG_DIR "fcam"
#include "./add-cam-inf.c"

* :::::WARNING:::::
* It is not allowed to modify the following code
*/

sensor_init_parameters_default_code();

sensor_v4l2_struct_initialization();

sensor_probe_default_code();

sensor_remove_default_code();

sensor_driver_default_module_code();

