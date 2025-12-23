/*===================================================================================================
                		Copyright(C) 2011-2099.  SUNRAM. Co., Ltd.
-----------------------------------------------------------------------------------------------------
Project Name  		: DCFan.h
Description   		: H
Author        		: Wuhaiming
Start Date    		: 2023/09/18
Version       		: V1.0
Revision History   1:
                   2:
===================================================================================================*/ 

#ifndef    _DCFAN_H_

#define    _DCFAN_H_

//===================================================================================================//
//选择电辅热_控制端口
//---------------------------------------------------------------------------------------------------//
#define		DCFan_SigValid							1//DCFan工作端口电平		例子:高电平有效1/低电平有效0
//---------------------------------------------------------------------------------------------------//
#define		Pin_DCFan								PortPin_Read(GPIOA, GPIO_Pin_15)//SWITCH1 IO端口选择			例子:P00/P0_0										
#define		P_DCFan_Hi()							DEFINE_PA15_HI					//例子:DEFINE_P00_HI
#define		P_DCFan_Low()							DEFINE_PA15_LOW					//例子:DEFINE_P00_LOW
#define		P_DCFan_Output()						DEFINE_PA15_OUTPUT				//例子:DEFINE_P00_OUTPUT
#define		P_DCFan_Input()							DEFINE_PA15_INPUT				//例子:DEFINE_P00_INPUT
#define		P_DCFan_Enpull()						DEFINE_PA15_ENPULLUP				//例子:DEFINE_P00_ENPULL
#define		P_DCFan_Dispull()						DEFINE_PA15_DISPULLUP			//例子:DEFINE_P00_DISPULL
//---------------------------------------------------------------------------------------------------//
#if (DCFan_SigValid == 1)
#define		P_DCFan_On()							P_DCFan_Hi()
#define		P_DCFan_Off()							P_DCFan_Low()
#else
#define		P_DCFan_On()							P_DCFan_Low()
#define		P_DCFan_Off()							P_DCFan_Hi()
#endif
//===================================================================================================//

#define    C_DCFAN_DELAY        300        //30s

typedef    struct
{
    U8    f_AppOn    :1;
	U8    f_DrvOn    :1;
	U8    Reserve    :6;
	U16	  u16_Delay;
}STRUCT_COMPDCFAN;

extern    STRUCT_COMPDCFAN    DCFan;
/****************************************************************************************************
Function Name       :void    Init_DCFan(void)
Description         :散热风扇始化
Input               :无
Return              :无
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Init_DCFan(void);
/****************************************************************************************************
Function Name       :void    Func_DCFan(void)
Description         :散热风扇功能
Input               :无
Return              :无
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Func_DCFan(void);

#endif
