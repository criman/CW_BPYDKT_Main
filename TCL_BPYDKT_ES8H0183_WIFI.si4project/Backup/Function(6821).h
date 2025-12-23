/*===================================================================================================
                		Copyright(C) 2011-2099.  SUNRAM. Co., Ltd.
-----------------------------------------------------------------------------------------------------
Project Name  		: Function.h
Description   		: H
Author        		: Wuhaiming
Start Date    		: 2023/03/06
Version       		: V1.0
Revision History   1:
                   2:
===================================================================================================*/ 

#ifndef    _FUNCTION_H_

#define    _FUNCTION_H_ 


//--------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------//
//引用标准化模块头文件
#include    "EEP24C02.h"
#include    "Ad.h"
#include    "Switch.h"
#include    "Stepmotor.h"
#include    "Uart.h"

//--------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------//
//引用功能相关头文件
#include    "Remember.h"
#include    "Protect.h"
#include    "Defrost.h"
#include    "CommMotDrv.h"
#include    "CommDisp.h"
#include    "CmdIn.h"
#include    "CmdOut.h"
#include    "Comp.h"
#include    "Fan.h"
#include    "Timer.h"
#include    "Tempr.h"
#include    "WaterBox.h"
#include    "FourWay.h"
#include    "WPMotor.h"
#include    "UVC.h"
#include    "ExpValve.h"
#include    "LowPower.h"
#include    "EAHeater.h"
#include    "DCFan.h"
#include    "tWiFi.h"
//#include    "wifi.h"

//--------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------//
//功能相关参数宏定义
#define     C_FUNC_SOFT_VERSION_A        1        //版本号(大)-A
#define     C_FUNC_SOFT_VERSION_B        0        //版本号(小)-B

//--------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------//

typedef    enum
{
    ENUM_STATUS_INIT,                   //上电初始化
    ENUM_STATUS_OFF,                    //待机
    ENUM_STATUS_ON,                     //工作
    ENUM_STATUS_BUSSCHK,				//商检
	ENUM_STATUS_SELCHK,                 //自检
}ENUM_STATUS;                           //系统状态机

//--------------------------------------------------------------------------------------------------//

typedef    enum
{
	ENUM_SYSMODE_COLD,       //制冷
	ENUM_SYSMODE_HUM,	     //除湿
	ENUM_SYSMODE_FAN,        //送风
	ENUM_SYSMODE_INTE,       //智能
	ENUM_SYSMODE_HEAT,       //制热

}ENUM_SYSMODE;

//--------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------//
typedef    struct
{
    U8    f_Lock    	      :1;		//童锁
	U8    f_Sense   	      :1;		//随身感
	U8    f_VoltLowPro        :1;		//电压过低保护
	U8    f_CurrentProtect    :1;		//过电流保护
	U8	  f_InOutCommErr	  :1;		//室内外通信故障
	U8    f_OutEEpromErr	  :1;		//室外E方故障
	U8    f_InEEpromErr	  	  :1;		//室内E方故障
	U8    f_T4Limit   	      :1;		//T4限频作用下限频标志
	U8    f_T4LimitOff		  :1;		//T4限频引起停机标志
	U8    f_HumiCSetInitOK	  :1;		//除湿设定值初始化完成标志 //lcx add 20240705
	U8	  Reserve     		  :22;		//预留
	
	ENUM_STATUS     Enum_Status;        //系统状态机
	ENUM_SYSMODE    Mode;				//系统模式
    ENUM_SYSMODE    ModeBak;			//系统模式备份
	
	U8    u8_PowerOn_Count;				//上电计时
	U16   u16_OffCount;					//待机计时
	U16   u16_BussChkCount;				//商检经历计时
	U32   u32_ForceRunCount;			//强力运行时间计时
	U32   u32_SleepCount;				//睡眠持续计时
	U32   u32_SleepTimCount;			//睡眠最长时间(定时时间)计时
//	U16   u16_SenseCount;				//随身感功能连续25分钟没有收到修订值自动退出
	U16	  u16_ACVoltValue;				//系统电压
	U16   u16_DCVoltValue;				//直流电压
	U8    u8_OutDoorCurrentMul8;		//系统室外机电流值(*8)
	U8	  u8_InteFdCount[6];			//智能模式下温度区间功能需求切换防抖计时	
	U8    u8_IPMTemp;					//IPM温度
}STRUCT_SYSTEM;
extern    STRUCT_SYSTEM        System; //系统相关变量 

//--------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------//

typedef    struct
{
    U8    f_Cold       	   :1;		//制冷状态		0:退出  1：进入
	U8    f_Heat       	   :1;		//制热状态		0:退出  1：进入
    U8    f_ColdBak        :1;		//制冷状态		0:退出  1：进入
	U8    f_HeatBak        :1;		//制热状态		0:退出  1：进入	
	U8    f_Fan			   :1;		//送风状态      0:无风  1：送风
	U8    f_Auto           :1;		//自动状态      0:退出  1: 进入
	U8    f_Sleep	   	   :1;		//睡眠状态		0:退出  1：进入
	U8    f_Slience	   	   :1;		//静音状态		0:退出  1：进入
	U8    f_Force	   	   :1;		//强力状态      0:退出  1：进入
	U8    f_ConTemp    	   :1;		//恒温状态		0:退出  1：进入
	U8    f_RoughCon   	   :1;		//粗略控制      0:精细  1：粗略
	U8    f_TempCEC	   	   :1;		//CEC达温       0:无    1：达温
	U8    f_CECSync		   :1;		//CEC达温       0:退出	1：达温风机循环启停同步显示档位
	U8    f_T2HeatLimit    :1;		//制热T2限频    0:退出  1：进入
	U8    f_AntiDew		   :1;		//防凝露        0:无效  1：生效
	U8	  f_AntiDewMark	   :1;		//防凝露		0:未曾	1：已进入不能再重复进入
	U8    f_PerTest		   :1;		//能力测试		0:退出  1: 进入
	U8    f_Error		   :1;		//故障

}
STRUCT_SYSTEMMODE;

extern    STRUCT_SYSTEMMODE    SystemMode;

//--------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------//

/****************************************************************************************************
Function Name       :void App_Event_10ms(void)
Description         :10ms运行一次函数
Input               :无
Return              :无
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void 	App_Event_10ms(void);
/****************************************************************************************************
Function Name       :void App_Event_100ms(void)
Description         :100ms运行一次函数
Input               :无
Return              :无
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void 	App_Event_100ms(void);
/****************************************************************************************************
Function Name       :void App_Function(void)
Description         :功能函数
Input               :无
Return              :无
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void 	App_Function(void);

#endif
