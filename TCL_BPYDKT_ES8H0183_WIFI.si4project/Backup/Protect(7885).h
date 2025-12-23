/*===================================================================================================
                		Copyright(C) 2011-2099.  SUNRAM. Co., Ltd.
-----------------------------------------------------------------------------------------------------
Project Name  		: Protect.h
Description   		: H
Author        		: Wuhaiming
Start Date    		: 2023/09/23
Version       		: V1.0
Revision History   1:
                   2:
===================================================================================================*/ 

#ifndef    _PROTECT_H_

#define    _PROTECT_H_


#define C_INFAN_ERRORRUN_TIMES 5 //带故障运行次数 lcx add 20240622

//-----------------------------------------------------------------------------------------------------//

typedef    enum
{
	ENUM_PROSTATUS_NORMAL,
	ENUM_PROSTATUS_SLOWUP,
	ENUM_PROSTATUS_CONT,
	ENUM_PROSTATUS_SLOWDOWN,
	ENUM_PROSTATUS_FASTDOWN,
	ENUM_PROSTATUS_PROTECT,
}ENUM_PROSTATUS;

//-----------------------------------------------------------------------------------------------------//

typedef    enum
{
	ENUM_T4COLDZONE_INIT,
	ENUM_T4COLDZONE_COOL1,
	ENUM_T4COLDZONE_COOL2,
	ENUM_T4COLDZONE_COOL3,
	ENUM_T4COLDZONE_COOL4,
}ENUM_T4COLDZONE;

//-----------------------------------------------------------------------------------------------------//

typedef    enum
{
	ENUM_T4HEATZONE_INIT,
	ENUM_T4HEATZONE_HOT1,
	ENUM_T4HEATZONE_HOT2,
	ENUM_T4HEATZONE_HOT3,
	ENUM_T4HEATZONE_HOT4,
}ENUM_T4HEATZONE;

//-----------------------------------------------------------------------------------------------------//

typedef    struct
{
	U8    f_Enable    :1;		//保护总标志位
	U8    f_Tp		  :1;		//排气温度保护
	U8    f_T2Cold    :1;		//制冷T2温度防冻结保护
	U8    f_T3Cold    :1;		//制冷T3温度防过热保护
	U8    f_CurrCold  :1;		//制冷电流过大保护
	U8    f_CurrHeat  :1;		//制热电流过大保护
	U8    f_CompCurr  :1;		//压缩机电流过大保护
	U8    f_HumiT1Low :1;		//除湿模式T1过低保护
	
	ENUM_PROSTATUS    TpStatus;			//排气保护阶段
	ENUM_PROSTATUS	  T2ColdStatus;		//制冷T2防冻结保护阶段
	ENUM_PROSTATUS	  T3ColdStatus;		//制冷T3过热保护阶段
	ENUM_T4COLDZONE   T4ColdZone;		//制冷T4温度区间
	ENUM_PROSTATUS	  CurrColdStatus;	//制冷电流过大保护阶段
	ENUM_T4HEATZONE	  T4HeatZone;		//制热电流过大保护阶段
	ENUM_PROSTATUS	  CurrHeatStatus;	//制热电流过大保护阶段
	ENUM_PROSTATUS	  CompCurrStatus;	//压缩机有效电流过大保护阶段
	ENUM_PROSTATUS	  SystemStatus;		//系统整体保护阶段
	
	U16   u16_TpCount;			//持续时间计时
	U16   u16_T2ColdCount;		//持续时间计时
	U16   u16_T3ColdCount;		//持续时间计时

	U16   u16_CompHzLimitCount;  //限频频率计时
	
}STRUCT_PROTECT;

//-----------------------------------------------------------------------------------------------------//

extern    STRUCT_PROTECT    Protect;

/****************************************************************************************************
Function Name       :void    Func_Protect(void)
Description         :保护功能处理
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Func_Protect(void);

#endif
