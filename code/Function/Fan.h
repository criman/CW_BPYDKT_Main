/*===================================================================================================
                		Copyright(C) 2011-2099.  SUNRAM. Co., Ltd.
-----------------------------------------------------------------------------------------------------
Project Name  		: Fan.h
Description   		: H
Author        		: Wuhaiming
Start Date    		: 2023/09/12
Version       		: V1.0
Revision History   1:
                   2:
===================================================================================================*/ 

#ifndef    _FAN_H_

#define    _FAN_H_

//-----------------------------------------------------------------------------------------------------//

typedef    enum
{
	ENUM_FANMODE_INIT,	  //初始化不确定
	ENUM_FANMODE_HIGH,    //高风
	ENUM_FANMODE_MED,     //中风
	ENUM_FANMODE_LOW,     //低风
	ENUM_FANMODE_AUTO,    //自动风
}ENUM_FANMODE;

//-----------------------------------------------------------------------------------------------------//

typedef    enum
{
    ENUM_FANLEVEL_INIT,   //初始化不确定风速档位
	ENUM_FANLEVEL_LOW_S,  //风速微风档
	ENUM_FANLEVEL_LOW,    //风速低档
	ENUM_FANLEVEL_MED,    //风速中档
	ENUM_FANLEVEL_HIGH,   //风速高档
	ENUM_FANLEVEL_HIGH_S, //风速强力档
}ENUM_FANLEVEL;

//-----------------------------------------------------------------------------------------------------//

typedef    struct
{
	U8               f_AppOn    :1;
	U8               f_DrvOn    :1;
	U8               f_ForceLow :1;
	U8				 f_Error	:1;
	U8				 f_ErrorDeal:1; //某次内机故障处理完成，允许回复外机清故障码	    lcx add 20240622
	U8               Reserve	:3;
	
	ENUM_FANLEVEL    Level;            //风速档位
	U16              u16_TargetRPM;    //目标转速
	U16 			 u16_RealRPM;	   //实际转速
	U16              u16_Delay;		   //延时计时
	U16              u16_Count;		   //工作计时
	U16              u16_ErrRunCount;  //带故障运行计时 lcx add 20240622
	U8               u8_ErrRunTimes;   //带故障运行次数 lcx add 20240622
}STRUCT_DCFAN;

//-----------------------------------------------------------------------------------------------------//

typedef    struct
{
	U8              f_SweepLR    	   :1;	//左右摇头
	U8              f_SweepLRChkBak    :1;	//左右摇头-商检检测备份
	U8              f_DeMold	 	   :1;	//除霉
	U8              u2_AutoInitFdCount :2;	//防抖
	U8				Reserved		   :3;
	ENUM_FANMODE    Mode;					//风速模式
	ENUM_FANMODE    ModeBak;				//风速模式备份
	ENUM_FANMODE	ModeCECBak;		    	//达温时刻风速模式备份
	STRUCT_DCFAN    Indoor;					//内风机(上风机)
	STRUCT_DCFAN    Outdoor;				//外风机(下风机)
}STRUCT_FAN;

//-----------------------------------------------------------------------------------------------------//

extern    STRUCT_FAN    Fan;

/****************************************************************************************************
Function Name       :void    Func_Fan(void)
Description         :风机功能处理
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Func_Fan(void);

#endif
