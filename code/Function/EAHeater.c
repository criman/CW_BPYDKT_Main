/*===================================================================================================
                		Copyright(C) 2011-2099.  SUNRAM. Co., Ltd.
-----------------------------------------------------------------------------------------------------
Project Name  		: EAHeater.c
Description   		: C
Author        		: Wuhaiming
Start Date    		: 2023/09/18
Version       		: V1.0
Revision History   1:
                   2:
===================================================================================================*/ 

#include	"main.h"

STRUCT_EAHEATER    EAHeater;         //电辅热

/****************************************************************************************************
Function Name       :void    Init_EAHeater(void)
Description         :电辅热初始化
Input               :无
Return              :无
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Init_EAHeater(void)
{
    P_EAHeater_Off();  
    P_EAHeater_Output();	
	P_EAHeater_Dispull();	
}
/****************************************************************************************************
Function Name       :void    Func_EAHeater(void)
Description         :电辅热功能
Input               :无
Return              :无
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Func_EAHeater(void)
{
	if (EAHeater.f_DrvOn == OFF)
	{	
		if ((EAHeater.f_AppOn == ON) && (Fan.Indoor.f_DrvOn == ON))
		{
			EAHeater.f_DrvOn = ON;
		}
	}
	else
	{
		if ((EAHeater.f_AppOn == OFF) || (Fan.Indoor.f_DrvOn == OFF))
		{
			EAHeater.f_DrvOn = OFF;
		}
	}
	
	if (EAHeater.f_DrvOn)	P_EAHeater_On();
	else					P_EAHeater_Off();
}
