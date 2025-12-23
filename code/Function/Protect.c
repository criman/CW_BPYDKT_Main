/*===================================================================================================
                		Copyright(C) 2011-2099.  SUNRAM. Co., Ltd.
-----------------------------------------------------------------------------------------------------
Project Name  		: Protect.c
Description   		: C
Author        		: Wuhaiming
Start Date    		: 2023/09/23
Version       		: V1.0
Revision History   1:
                   2:
===================================================================================================*/ 

#include	"main.h"

STRUCT_PROTECT    Protect;

/****************************************************************************************************
Function Name       :void    Protect_Tp(void)
Description         :排气温度保护
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Protect_Tp(void)
{
	if (Protect.TpStatus == ENUM_PROSTATUS_NORMAL)
	{		
		if (Tp.s16_ValueMul10 > TempValueMul10(EEP.u8_rdBuf[126]))		//EE.PARA. C_REMEMBER_PARA11_00;		//90		    //TP0	
		{
			Protect.TpStatus = ENUM_PROSTATUS_SLOWUP;
		}
	}
	else if (Protect.TpStatus == ENUM_PROSTATUS_SLOWUP)
	{		
		if (Tp.s16_ValueMul10 < TempValueMul10(EEP.u8_rdBuf[126]-1))	//EE.PARA. C_REMEMBER_PARA11_00;		//90		    //TP0	//TP0-delta
		{
			Protect.TpStatus = ENUM_PROSTATUS_NORMAL;
		}
		else if (Tp.s16_ValueMul10 > TempValueMul10(EEP.u8_rdBuf[127]))	//EE.PARA. C_REMEMBER_PARA11_01;		//95		    //TP1
		{
			Protect.TpStatus = ENUM_PROSTATUS_CONT;
		}
	}
	else if (Protect.TpStatus == ENUM_PROSTATUS_CONT)
	{
		if (Tp.s16_ValueMul10 < TempValueMul10(EEP.u8_rdBuf[127]-1))	//EE.PARA. C_REMEMBER_PARA11_01;		//95		    //TP1  //TP1-delta
		{
			Protect.TpStatus = ENUM_PROSTATUS_SLOWUP;
		}
		else if (Tp.s16_ValueMul10 > TempValueMul10(EEP.u8_rdBuf[128]))	//EE.PARA. C_REMEMBER_PARA11_02;		//100		    //TP2
		{
			Protect.TpStatus = ENUM_PROSTATUS_SLOWDOWN;
		}
	}
	else if (Protect.TpStatus == ENUM_PROSTATUS_SLOWDOWN)
	{
		if (Tp.s16_ValueMul10 < TempValueMul10(EEP.u8_rdBuf[128]-1))    //EE.PARA. C_REMEMBER_PARA11_02;		//100		    //TP2  //TP2-delta
		{
			Protect.TpStatus = ENUM_PROSTATUS_CONT;
		}
		else if (Tp.s16_ValueMul10 > TempValueMul10(EEP.u8_rdBuf[129]))	//EE.PARA. C_REMEMBER_PARA11_03;		//105		    //TP3
		{
			Protect.TpStatus = ENUM_PROSTATUS_FASTDOWN;
		}
	}
	else if (Protect.TpStatus == ENUM_PROSTATUS_FASTDOWN)
	{
		if (Tp.s16_ValueMul10 < TempValueMul10(EEP.u8_rdBuf[129]-1))    //EE.PARA. C_REMEMBER_PARA11_03;		//105		    //TP3  //TP3-delta
		{
			Protect.TpStatus = ENUM_PROSTATUS_SLOWDOWN;
		}
	}
	
	//---
	
	if (Protect.f_Tp == 0)				  //正常
	{
		if (Tp.s16_ValueMul10 >= TempValueMul10(EEP.u8_rdBuf[130]))    //EE.PARA. C_REMEMBER_PARA11_04;		   //110		    //TP4
		{
			if (++Protect.u16_TpCount >= 500)
			{
				Protect.u16_TpCount = 0;
				Protect.f_Tp = 1;		  //排气温度保护生效
				Protect.TpStatus = ENUM_PROSTATUS_PROTECT;
			}
		}
		else
		{
			Protect.u16_TpCount = 0;
		}
	}
	else
	{
		if (Tp.s16_ValueMul10 <= TempValueMul10(EEP.u8_rdBuf[128]))	  //EE.PARA. C_REMEMBER_PARA11_02;		//100		    //TP2
		{
			Protect.f_Tp = 0;			//恢复正常
			Protect.TpStatus = ENUM_PROSTATUS_NORMAL;
		}
	}
}
/****************************************************************************************************
Function Name       :void    Protect_T2Cold(void)
Description         :制冷室内换气器防冻结
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Protect_T2Cold(void)
{	
	S16    s16_TempValue;
	S16    s16_TempValue1;	

	if (SystemMode.f_Cold == 1)
	{
		if (Protect.T2ColdStatus == ENUM_PROSTATUS_NORMAL)
		{
			s16_TempValue = (S8)EEP.u8_rdBuf[135];					//EE.PARA. (U8)C_REMEMBER_PARA12_04;		//14(7℃)		    //T2_COLD4
			s16_TempValue = (TempValueMul10(s16_TempValue)>>1);	
			
			if (T2.s16_ValueMul10 < s16_TempValue)		
			{
				Protect.T2ColdStatus = ENUM_PROSTATUS_SLOWUP;
			}
		}
		else if (Protect.T2ColdStatus == ENUM_PROSTATUS_SLOWUP)
		{
			s16_TempValue = (S8)EEP.u8_rdBuf[134];					//EE.PARA. (U8)C_REMEMBER_PARA12_03;		//11(5.5℃)		    //T2_COLD3
			s16_TempValue = (TempValueMul10(s16_TempValue)>>1);

			s16_TempValue1 = (S8)EEP.u8_rdBuf[135];					//EE.PARA. (U8)C_REMEMBER_PARA12_04;		//14(7℃)		    //T2_COLD4
			s16_TempValue1 += 2;
			s16_TempValue1 = (TempValueMul10(s16_TempValue1)>>1); 
			
			if (T2.s16_ValueMul10 < s16_TempValue)	   				//T2_COLD3  5.5℃
			{
				Protect.T2ColdStatus = ENUM_PROSTATUS_CONT;
			}
			else if (T2.s16_ValueMul10 > s16_TempValue1)			//T2_COLD4 7℃ + Delta	
			{
				Protect.T2ColdStatus = ENUM_PROSTATUS_NORMAL;
			}
		}
		else if (Protect.T2ColdStatus == ENUM_PROSTATUS_CONT)
		{
			s16_TempValue = (S8)EEP.u8_rdBuf[133];					//EE.PARA. (U8)C_REMEMBER_PARA12_02;		//8(4℃)		   		//T2_COLD2
			s16_TempValue = (TempValueMul10(s16_TempValue)>>1);			

			s16_TempValue1 = (S8)EEP.u8_rdBuf[134];					//EE.PARA. (U8)C_REMEMBER_PARA12_03;		//11(5.5℃)		    //T2_COLD3
			s16_TempValue1 += 2;
			s16_TempValue1 = (TempValueMul10(s16_TempValue1)>>1); 
			
			if (T2.s16_ValueMul10 < s16_TempValue)					//低于 T2_COLD2  4℃
			{
				Protect.T2ColdStatus = ENUM_PROSTATUS_SLOWDOWN;
			}
			else if (T2.s16_ValueMul10 > s16_TempValue1)			//高于 T2_COLD3 5.5℃ + DELTA
			{
				Protect.T2ColdStatus = ENUM_PROSTATUS_SLOWUP;
			}
		}
		else if (Protect.T2ColdStatus == ENUM_PROSTATUS_SLOWDOWN)
		{
			s16_TempValue = (S8)EEP.u8_rdBuf[132];					//EE.PARA. (U8)C_REMEMBER_PARA12_01;		//4(2℃)		   		//T2_COLD1
			s16_TempValue = (TempValueMul10(s16_TempValue)>>1);	

			s16_TempValue1 = (S8)EEP.u8_rdBuf[133];					//EE.PARA. (U8)C_REMEMBER_PARA12_02;		//8(4℃)		   		//T2_COLD2
			s16_TempValue1 += 2;
			s16_TempValue1 = (TempValueMul10(s16_TempValue1)>>1);			
			
			if (T2.s16_ValueMul10 < s16_TempValue)					//T2_COLD1  2℃
			{
				Protect.T2ColdStatus = ENUM_PROSTATUS_FASTDOWN;
			}
			else if (T2.s16_ValueMul10 > s16_TempValue1)			//T2_COLD2 4℃ + DELTA
			{
				Protect.T2ColdStatus = ENUM_PROSTATUS_CONT;
			}
		}
		else if (Protect.T2ColdStatus == ENUM_PROSTATUS_FASTDOWN)
		{
			s16_TempValue1 = (S8)EEP.u8_rdBuf[132];					//EEP.u8_wrBuf[132] = (U8)C_REMEMBER_PARA12_01;		//4(2℃)		   		//T2_COLD1
			s16_TempValue1 += 2;
			s16_TempValue1 = (TempValueMul10(s16_TempValue1)>>1);			
			
			if (T2.s16_ValueMul10 > s16_TempValue1)					//T2_COLD1 2℃ + DELTA
			{
				Protect.T2ColdStatus = ENUM_PROSTATUS_SLOWDOWN;
			}
		}		
		
		//---
		
		if (Protect.f_T2Cold == 0)
		{
			s16_TempValue = (S8)EEP.u8_rdBuf[131];					//EE.PARA. (U8)C_REMEMBER_PARA12_00;		//0(0℃)		   		//T2_COLD0
			s16_TempValue = (TempValueMul10(s16_TempValue)>>1);				
			
			if (T2.s16_ValueMul10 <= s16_TempValue)		
			{
				if (++Protect.u16_T2ColdCount >= 500)	//5s
				{
					Protect.u16_T2ColdCount = 0;
					Protect.f_T2Cold = 1;		//T2制冷温度过低保护生效
					Protect.T2ColdStatus = ENUM_PROSTATUS_PROTECT;
				}
			}
			else
			{
				Protect.u16_T2ColdCount = 0;
			}
		}
		else
		{
			s16_TempValue = (S8)EEP.u8_rdBuf[133];					//EE.PARA. (U8)C_REMEMBER_PARA12_02;		//8(4℃)		   		//T2_COLD2
			s16_TempValue = (TempValueMul10(s16_TempValue)>>1);				
			
			if (T2.s16_ValueMul10 >= s16_TempValue)	
			{
				Protect.f_T2Cold = 0;
				Protect.T2ColdStatus = ENUM_PROSTATUS_NORMAL;
			}
		}
	}
	else
	{
		Protect.f_T2Cold = 0;
		Protect.T2ColdStatus = ENUM_PROSTATUS_NORMAL;
	}
}
/****************************************************************************************************
Function Name       :void    Protect_T3Cold(void)
Description         :制冷室外换气器防过热
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Protect_T3Cold(void)
{		
	S16    s16_TempValue;
	S16    s16_TempValue1;	
	
	if (SystemMode.f_Cold == 1)
	{
		if (Protect.T3ColdStatus == ENUM_PROSTATUS_NORMAL)
		{
			//参数没有负数可能转U8类型
			s16_TempValue = (U8)EEP.u8_rdBuf[136];					//EE.PARA. C_REMEMBER_PARA13_00;		//104(52℃)		 //T3_COOL0	
			s16_TempValue = (TempValueMul10(s16_TempValue)>>1);				
					
			if (T3.s16_ValueMul10 > s16_TempValue)					//T3_COOL0  52℃
			{
				Protect.T3ColdStatus = ENUM_PROSTATUS_SLOWUP;
			}
		}
		else if (Protect.T3ColdStatus == ENUM_PROSTATUS_SLOWUP)
		{
			s16_TempValue = (U8)EEP.u8_rdBuf[136];					//EE.PARA. C_REMEMBER_PARA13_00;		//104(52℃)		   	//T3_COOL0
			s16_TempValue -= 2;
			s16_TempValue = (TempValueMul10(s16_TempValue)>>1);				
			
			s16_TempValue1 = (U8)EEP.u8_rdBuf[137];					//EE.PARA. C_REMEMBER_PARA13_01;		//116(58℃)		   	//T3_COOL1	
			s16_TempValue1 = (TempValueMul10(s16_TempValue1)>>1);
			
			if (T3.s16_ValueMul10 < s16_TempValue)					//T3_COOL0 52℃ - DELTA
			{
				Protect.T3ColdStatus = ENUM_PROSTATUS_NORMAL;
			}
			else if (T3.s16_ValueMul10 > s16_TempValue1)			//T3_COOL1  58℃
			{
				Protect.T3ColdStatus = ENUM_PROSTATUS_CONT;
			}
		}
		else if (Protect.T3ColdStatus == ENUM_PROSTATUS_CONT)
		{
			s16_TempValue = (U8)EEP.u8_rdBuf[137];					//EE.PARA. C_REMEMBER_PARA13_01;		//116(58℃)		  //T3_COOL1	
			s16_TempValue -= 2;
			s16_TempValue = (TempValueMul10(s16_TempValue)>>1);	

			s16_TempValue1 = (U8)EEP.u8_rdBuf[138];					//EE.PARA. C_REMEMBER_PARA13_02;		//120(60℃)		  //T3_COOL2	
			s16_TempValue1 = (TempValueMul10(s16_TempValue1)>>1);			
			
			if (T3.s16_ValueMul10 < s16_TempValue)					//T3_COOL1 58℃ - DELTA
			{
				Protect.T3ColdStatus = ENUM_PROSTATUS_SLOWUP;
			}
			else if (T3.s16_ValueMul10 > s16_TempValue1)			//T3_COOL2 60℃
			{
				Protect.T3ColdStatus = ENUM_PROSTATUS_SLOWDOWN;
			}
		}
		else if (Protect.T3ColdStatus == ENUM_PROSTATUS_SLOWDOWN)
		{
			s16_TempValue = (U8)EEP.u8_rdBuf[138];					//EE.PARA. C_REMEMBER_PARA13_02;		//120(60℃)		  //T3_COOL2
			s16_TempValue -= 2;
			s16_TempValue = (TempValueMul10(s16_TempValue)>>1);	

			s16_TempValue1 = (U8)EEP.u8_rdBuf[139];					//EE.PARA. C_REMEMBER_PARA13_03;		//124(62℃)		  //T3_COOL3
			s16_TempValue1 = (TempValueMul10(s16_TempValue1)>>1);				
			
			if (T3.s16_ValueMul10 < s16_TempValue)					//T3_COOL2 60℃ - DELTA
			{
				Protect.T3ColdStatus = ENUM_PROSTATUS_CONT;
			}
			else if (T3.s16_ValueMul10 > s16_TempValue1)			//T3_COOL3  62℃
			{
				Protect.T3ColdStatus = ENUM_PROSTATUS_FASTDOWN;
			}
		}
		else if (Protect.T3ColdStatus == ENUM_PROSTATUS_FASTDOWN)
		{
			s16_TempValue = (U8)EEP.u8_rdBuf[139];					//EE.PARA. C_REMEMBER_PARA13_03;		//124(62℃)		 //T3_COOL3
			s16_TempValue -= 2;
			s16_TempValue = (TempValueMul10(s16_TempValue)>>1);				
			
			if (T3.s16_ValueMul10 < s16_TempValue)					//T3_COOL3 62℃ - DELTA
			{
				Protect.T3ColdStatus = ENUM_PROSTATUS_SLOWDOWN;
			}
		}		
		
		//----
		
		if (Protect.f_T3Cold == 0)
		{			
			s16_TempValue = (U8)EEP.u8_rdBuf[140];					//EE.PARA. C_REMEMBER_PARA13_04;		//128(64℃)		//T3_COOL4
			s16_TempValue = (TempValueMul10(s16_TempValue)>>1);			
			
			if (T3.s16_ValueMul10 >= s16_TempValue)					//高于 T3_COOL4   64℃
			{
				if (++Protect.u16_T3ColdCount >= 500)
				{
					Protect.u16_T3ColdCount = 0;
					Protect.f_T3Cold = 1;
					Protect.T3ColdStatus = ENUM_PROSTATUS_PROTECT;
				}
			}
			else
			{
				Protect.u16_T3ColdCount = 0;
			}
		}
		else
		{
			s16_TempValue = (U8)EEP.u8_rdBuf[138];					//EE.PARA. C_REMEMBER_PARA13_02;		//120(60℃)		  //T3_COOL2
			s16_TempValue = (TempValueMul10(s16_TempValue)>>1);				
			
			if (T3.s16_ValueMul10 <= s16_TempValue)					//低于 T3_COOL2   60℃
			{
				Protect.f_T3Cold = 0;
				Protect.T3ColdStatus = ENUM_PROSTATUS_NORMAL;
			}
		}
	}
	else
	{
		Protect.f_T3Cold = 0;
		Protect.T3ColdStatus = ENUM_PROSTATUS_NORMAL;	
	}
}
/****************************************************************************************************
Function Name       :void    Protect_CurrentCold(void)
Description         :制冷电流过大保护
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Protect_CurrentCold(void)
{
	U8     OutDoorCurrentMul8;		//依据通信接收电流*8的数值
	U16    u16_CurrentValueMul10;	//转换电流*10的数值
	U8     CurrentProValueMul10;    //电流保护阈值*10
	
	OutDoorCurrentMul8 = CommMotDrv.BaseRun.Rx.Byte9.OutDoorCurrentMul8;
	u16_CurrentValueMul10 = TempValueMul10(OutDoorCurrentMul8);
	u16_CurrentValueMul10 >>= 3;	//转换电流*10的数值
	
	if ((T4.f_Error == 1) || (SystemMode.f_Cold == 0))		//故障或非制冷回初始化
	{
		Protect.T4ColdZone = ENUM_T4COLDZONE_INIT;
	}
	
	if (SystemMode.f_Cold == 1)
	{
		//计算制冷T4温度区间
		if (Protect.T4ColdZone == ENUM_T4COLDZONE_INIT)
		{
			if (T4.s16_ValueMul10 >= 460)
			{
				Protect.T4ColdZone = ENUM_T4COLDZONE_COOL1;
			}
			else if (T4.s16_ValueMul10 >= 420)
			{
				Protect.T4ColdZone = ENUM_T4COLDZONE_COOL2;
			}
			else if (T4.s16_ValueMul10 >= 380)
			{
				Protect.T4ColdZone = ENUM_T4COLDZONE_COOL3;
			}	
			else
			{
				Protect.T4ColdZone = ENUM_T4COLDZONE_COOL4;
			}
			
			CurrentProValueMul10 = 0xFF;	//初始阶段阈值最大化
		}
		else if (Protect.T4ColdZone == ENUM_T4COLDZONE_COOL1)
		{
			CurrentProValueMul10 = 140;		//ICMAX_AC_COOL1  14A
			
			if (T4.s16_ValueMul10 < 450)
			{
				Protect.T4ColdZone = ENUM_T4COLDZONE_COOL2;
			}
		}
		else if (Protect.T4ColdZone == ENUM_T4COLDZONE_COOL2)
		{
			CurrentProValueMul10 = 135;		//ICMAX_AC_COOL2  13.5A
			
			if (T4.s16_ValueMul10 < 410)
			{
				Protect.T4ColdZone = ENUM_T4COLDZONE_COOL3;
			}
			else if (T4.s16_ValueMul10 > 460)
			{
				Protect.T4ColdZone = ENUM_T4COLDZONE_COOL1;
			}
		}
		else if (Protect.T4ColdZone == ENUM_T4COLDZONE_COOL3)
		{
			CurrentProValueMul10 = 105;		//ICMAX_AC_COOL3  10.5A
			
			if (T4.s16_ValueMul10 < 370)
			{
				Protect.T4ColdZone = ENUM_T4COLDZONE_COOL4;
			}
			else if (T4.s16_ValueMul10 > 420)
			{
				Protect.T4ColdZone = ENUM_T4COLDZONE_COOL2;
			}
		}
		else if (Protect.T4ColdZone == ENUM_T4COLDZONE_COOL4)
		{
			CurrentProValueMul10 =  100;		//ICMAX_AC_COOL4  10A
			
			if (T4.s16_ValueMul10 > 380)
			{
				Protect.T4ColdZone = ENUM_T4COLDZONE_COOL3;
			}
		}
		
		//---
		
		if (Protect.CurrColdStatus == ENUM_PROSTATUS_NORMAL)
		{
			if (u16_CurrentValueMul10 > (CurrentProValueMul10 - 20))		//AcCurLimit_A[0] = ICMAX_AC_COOLx - 2A
			{
				Protect.CurrColdStatus = ENUM_PROSTATUS_SLOWUP;
			}
		}
		else if (Protect.CurrColdStatus == ENUM_PROSTATUS_SLOWUP)
		{
			if (u16_CurrentValueMul10 < ((CurrentProValueMul10 - 20) - 5))	//AcCurLimit_A[0] - 0.5A
			{
				Protect.CurrColdStatus = ENUM_PROSTATUS_NORMAL;
			}
			else if (u16_CurrentValueMul10 > (CurrentProValueMul10 - 10))	//AcCurLimit_A[1] = ICMAX_AC_COOLx - 1A
			{
				Protect.CurrColdStatus = ENUM_PROSTATUS_CONT;
			}
		}
		else if (Protect.CurrColdStatus == ENUM_PROSTATUS_CONT)
		{
			if (u16_CurrentValueMul10 < ((CurrentProValueMul10 - 10) - 5))	//AcCurLimit_A[1] - 0.5A
			{
				Protect.CurrColdStatus = ENUM_PROSTATUS_SLOWUP;
			}
			else if (u16_CurrentValueMul10 > CurrentProValueMul10)			//AcCurLimit_A[2] = ICMAX_AC_COOLx 
			{
				Protect.CurrColdStatus = ENUM_PROSTATUS_SLOWDOWN;
			}
		}
		else if (Protect.CurrColdStatus == ENUM_PROSTATUS_SLOWDOWN)
		{
			if (u16_CurrentValueMul10 < (CurrentProValueMul10 - 5))			//AcCurLimit_A[2] - 0.5A
			{
				Protect.CurrColdStatus = ENUM_PROSTATUS_CONT;
			}
			else if (u16_CurrentValueMul10 > (CurrentProValueMul10 + 10))	//AcCurLimit_A[3] = ICMAX_AC_COOLx + 1A
			{
				Protect.CurrColdStatus = ENUM_PROSTATUS_FASTDOWN;
			}
		}
		else if (Protect.CurrColdStatus == ENUM_PROSTATUS_FASTDOWN)
		{
			if (u16_CurrentValueMul10 < ((CurrentProValueMul10 + 10) - 5))	//AcCurLimit_A[3] - 0.5A
			{
				Protect.CurrColdStatus = ENUM_PROSTATUS_SLOWDOWN;
			}
		}
		
		//---
		
		if (Protect.f_CurrCold == 0)
		{
			if (u16_CurrentValueMul10 >= 160)	//超过异常阈值
			{
				Protect.f_CurrCold = 1;
			}
		}
		else	//压缩机停机恢复
		{
			Protect.f_CurrCold = 0;
			Comp.f_AppOn = OFF;
			Protect.CurrColdStatus = ENUM_PROSTATUS_NORMAL;
		}
	}
}
/****************************************************************************************************
Function Name       :void    Protect_CurrentHeat(void)
Description         :制热电流过大保护
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Protect_CurrentHeat(void)
{
	U8     OutDoorCurrentMul8;		//依据通信接收电流*8的数值
	U16    u16_CurrentValueMul10;	//转换电流*10的数值
	U8     CurrentProValueMul10;    //电流保护阈值*10
	
	OutDoorCurrentMul8 = CommMotDrv.BaseRun.Rx.Byte9.OutDoorCurrentMul8;
	u16_CurrentValueMul10 = TempValueMul10(OutDoorCurrentMul8);
	u16_CurrentValueMul10 >>= 3;	//转换电流*10的数值
	
	if ((T4.f_Error == 1) || (SystemMode.f_Heat == 0))		//故障或非制冷回初始化
	{
		Protect.T4HeatZone = ENUM_T4HEATZONE_INIT;
	}
	
	if (SystemMode.f_Heat == 1)
	{
		//计算制热T4温度区间	
		if (Protect.T4HeatZone == ENUM_T4HEATZONE_INIT)
		{
			if (T4.s16_ValueMul10 <= 50)
			{
				Protect.T4HeatZone = ENUM_T4HEATZONE_HOT1;
			}
			else if (T4.s16_ValueMul10 <= 110)
			{
				Protect.T4HeatZone = ENUM_T4HEATZONE_HOT2;
			}
			else if (T4.s16_ValueMul10 <= 230)
			{
				Protect.T4HeatZone = ENUM_T4HEATZONE_HOT3;
			}	
			else
			{
				Protect.T4HeatZone = ENUM_T4HEATZONE_HOT4;
			}
			
			CurrentProValueMul10 = 0xFF;	//初始阶段阈值最大化
		}
		else if (Protect.T4HeatZone == ENUM_T4HEATZONE_HOT1)
		{
			CurrentProValueMul10 = 98;		//ICMAX_AC_HOT1  9.8A
			
			if (T4.s16_ValueMul10 > 50)
			{
				Protect.T4HeatZone = ENUM_T4HEATZONE_HOT2;
			}
		}
		else if (Protect.T4HeatZone == ENUM_T4HEATZONE_HOT2)
		{
			CurrentProValueMul10 = 83;		//ICMAX_AC_HOT2  8.3A
			
			if (T4.s16_ValueMul10 < 40)
			{
				Protect.T4HeatZone = ENUM_T4HEATZONE_HOT1;
			}
			else if (T4.s16_ValueMul10 > 110)
			{
				Protect.T4HeatZone = ENUM_T4HEATZONE_HOT3;
			}
		}
		else if (Protect.T4HeatZone == ENUM_T4HEATZONE_HOT3)
		{
			CurrentProValueMul10 = 78;		//ICMAX_AC_HOT3  7.8A
			
			if (T4.s16_ValueMul10 < 100)
			{
				Protect.T4HeatZone = ENUM_T4HEATZONE_HOT2;
			}
			else if (T4.s16_ValueMul10 > 230)
			{
				Protect.T4HeatZone = ENUM_T4HEATZONE_HOT4;
			}
		}
		else if (Protect.T4HeatZone == ENUM_T4HEATZONE_HOT4)
		{
			CurrentProValueMul10 = 73;		//ICMAX_AC_HOT4  7.3A
			
			if (T4.s16_ValueMul10 < 220)
			{
				Protect.T4HeatZone = ENUM_T4HEATZONE_HOT3;
			}
		}

		//---
		
		if (Protect.CurrHeatStatus == ENUM_PROSTATUS_NORMAL)
		{
			if (u16_CurrentValueMul10 > (CurrentProValueMul10 - 20))		//AcCurLimit_A[0] = ICMAX_AC_HOTx - 2A
			{
				Protect.CurrHeatStatus = ENUM_PROSTATUS_SLOWUP;
			}
		}
		else if (Protect.CurrHeatStatus == ENUM_PROSTATUS_SLOWUP)
		{
			if (u16_CurrentValueMul10 < ((CurrentProValueMul10 - 20) - 5))	//AcCurLimit_A[0] - 0.5A
			{
				Protect.CurrHeatStatus = ENUM_PROSTATUS_NORMAL;
			}
			else if (u16_CurrentValueMul10 > (CurrentProValueMul10 - 10))	//AcCurLimit_A[1] = ICMAX_AC_HOTx - 1A
			{
				Protect.CurrHeatStatus = ENUM_PROSTATUS_CONT;
			}
		}
		else if (Protect.CurrHeatStatus == ENUM_PROSTATUS_CONT)
		{
			if (u16_CurrentValueMul10 < ((CurrentProValueMul10 - 10) - 5))	//AcCurLimit_A[1] - 0.5A
			{
				Protect.CurrHeatStatus = ENUM_PROSTATUS_SLOWUP;
			}
			else if (u16_CurrentValueMul10 > CurrentProValueMul10)			//AcCurLimit_A[2] = ICMAX_AC_HOTx 
			{
				Protect.CurrHeatStatus = ENUM_PROSTATUS_SLOWDOWN;
			}
		}
		else if (Protect.CurrHeatStatus == ENUM_PROSTATUS_SLOWDOWN)
		{
			if (u16_CurrentValueMul10 < (CurrentProValueMul10 - 5))			//AcCurLimit_A[2] - 0.5A
			{
				Protect.CurrHeatStatus = ENUM_PROSTATUS_CONT;
			}
			else if (u16_CurrentValueMul10 > (CurrentProValueMul10 + 10))	//AcCurLimit_A[3] = ICMAX_AC_HOTx + 1A
			{
				Protect.CurrHeatStatus = ENUM_PROSTATUS_FASTDOWN;
			}
		}
		else if (Protect.CurrHeatStatus == ENUM_PROSTATUS_FASTDOWN)
		{
			if (u16_CurrentValueMul10 < ((CurrentProValueMul10 + 10) - 5))	//AcCurLimit_A[3] - 0.5A
			{
				Protect.CurrHeatStatus = ENUM_PROSTATUS_SLOWDOWN;
			}
		}

		//---
		
		if (Protect.f_CurrHeat == 0)
		{
			if (u16_CurrentValueMul10 >= 170)	//超过异常阈值
			{
				Protect.f_CurrHeat = 1;
			}
		}
		else	//压缩机停机恢复
		{
			Protect.f_CurrHeat = 0;
			Comp.f_AppOn = OFF;
			Protect.CurrHeatStatus = ENUM_PROSTATUS_NORMAL;
		}		
	}
}
/****************************************************************************************************
Function Name       :void    Protect_CompCurr(void)
Description         :室外压缩机电流有效值过大保护
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Protect_CompCurr(void)
{
	U8     OutDoorCurrentMul8;		//依据通信接收电流*8的数值
	U16    u16_CurrentValueMul10;	//转换电流*10的数值
	U8     CurrentProValueMul10;    //电流保护阈值*10
	
	OutDoorCurrentMul8 = 0;//CommMotDrv.BaseRun.Rx.Byte9.OutDoorCurrentMul8;
	u16_CurrentValueMul10 = TempValueMul10(OutDoorCurrentMul8);
	u16_CurrentValueMul10 >>= 3;	//转换电流*10的数值
	
	//---
	
	if (Protect.CompCurrStatus == ENUM_PROSTATUS_NORMAL)
	{
		if (u16_CurrentValueMul10 > 80)		//CompCurLimit[0]	8A
		{
			Protect.CompCurrStatus = ENUM_PROSTATUS_SLOWUP;
		}
	}
	else if (Protect.CompCurrStatus == ENUM_PROSTATUS_SLOWUP)
	{
		if (u16_CurrentValueMul10 < (80-5))		//CompCurLimit[0] - delta
		{
			Protect.CompCurrStatus = ENUM_PROSTATUS_NORMAL;
		}	
		else if (u16_CurrentValueMul10 > 85)		//CompCurLimit[1]	8.5A
		{
			Protect.CompCurrStatus = ENUM_PROSTATUS_CONT;
		}		
	}	
	else if (Protect.CompCurrStatus == ENUM_PROSTATUS_CONT)
	{
		if (u16_CurrentValueMul10 < (85-5))		//CompCurLimit[1] - delta
		{
			Protect.CompCurrStatus = ENUM_PROSTATUS_SLOWUP;
		}
		else if (u16_CurrentValueMul10 > 90)	//CompCurLimit[2]	9A
		{
			Protect.CompCurrStatus = ENUM_PROSTATUS_SLOWDOWN;
		}
	}	
	else if (Protect.CompCurrStatus == ENUM_PROSTATUS_SLOWDOWN)
	{
		if (u16_CurrentValueMul10 < (90-5))		//CompCurLimit[2] - delta
		{
			Protect.CompCurrStatus = ENUM_PROSTATUS_SLOWUP;
		}
		else if (u16_CurrentValueMul10 > 100)	//CompCurLimit[3]	10A
		{
			Protect.CompCurrStatus = ENUM_PROSTATUS_FASTDOWN;
		}	
	}		
	else if (Protect.CompCurrStatus == ENUM_PROSTATUS_FASTDOWN)
	{
		if (u16_CurrentValueMul10 < (100-5))		//CompCurLimit[3] - delta
		{
			Protect.CompCurrStatus = ENUM_PROSTATUS_SLOWUP;
		}		
	}
	
	//---
	
	if (Protect.f_CompCurr == 0)
	{
		if (CurrentProValueMul10 >= 110)		//CompCurLimit[4]	11A
		{
			Protect.f_CompCurr = 1;
		}
	}
	else
	{
		Protect.f_CompCurr = 0;
		Comp.f_AppOn = OFF;	
		Protect.CompCurrStatus = ENUM_PROSTATUS_NORMAL;
	}
}


/****************************************************************************************************
Function Name       :void    Protect_InFan(void)
Description         :内风机失速ED保护
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Protect_InFanErr(void) //内风机失速ED保护
{
	static U16 u16_ErrRunCount = 0;

	/*
		10分钟内出现5次及以上风机故障，则判断风机存在故障，此后风机不再尝试启动，外机按关机处理，
		在故障刚报或者有任何操作时显示面板闪烁3次故障代码Ed，遥控关机或断电可恢复。
	*/
	
	// (CommMotDrv.BaseRun.Rx.Byte11.OutDoorStatus1.f_FanIndoorErr)
	if(Fan.Indoor.f_Error)
	{
		if(++u16_ErrRunCount > 2000) //10ms*2000=20s 约20s重启一次内风机
		{
			u16_ErrRunCount = 0;
			if(Fan.Indoor.f_ErrorDeal == 0) 
			{
				if(Fan.Indoor.u8_ErrRunTimes < C_INFAN_ERRORRUN_TIMES) //
				{
					Fan.Indoor.u8_ErrRunTimes++; //带故障运行次数 lcx add 20240622
					Fan.Indoor.f_ErrorDeal = 1;
				}
			}			
		}
	}
	else
	{
		Fan.Indoor.f_ErrorDeal = 0;
		u16_ErrRunCount = 0;
	}


	if(System.Enum_Status == ENUM_STATUS_INIT || System.Enum_Status == ENUM_STATUS_OFF) //遥控关机或断电可恢复。
	{
		Fan.Indoor.f_ErrorDeal = 0;
		Fan.Indoor.u8_ErrRunTimes = 0;
		u16_ErrRunCount = 0;
	}

	if(Fan.Indoor.u8_ErrRunTimes)
	{
		if(++Fan.Indoor.u16_ErrRunCount > 60000) //每10分钟自减一次
		{
			Fan.Indoor.u16_ErrRunCount = 0;
			if(Fan.Indoor.u8_ErrRunTimes) Fan.Indoor.u8_ErrRunTimes--;
		}
	}
	else
	{
		Fan.Indoor.u16_ErrRunCount = 0;
	}
}
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
void    Func_Protect(void)
{
	Protect_Tp();			//Tp排气温度保护
	Protect_T2Cold();		//T2制冷室内盘管防冻结
	Protect_T3Cold();		//T3制冷室外盘管防过热
//	Protect_CurrentCold();	//制冷电流过大保护
//	Protect_CurrentHeat();	//制热电流过大保护
//	Protect_CompCurr();		//室外压缩机电流有效值过大保护
	Protect_InFanErr(); 	//内风机失速ED保护 lcx add 20240622
	
	if (Protect.f_Tp || Protect.f_T2Cold || Protect.f_T3Cold || Protect.f_CurrCold || Protect.f_CurrHeat || Protect.f_CompCurr)
	{
		Protect.f_Enable = 1;
	}
	else
	{
		Protect.f_Enable = 0;
	}
	
	if (CommDisp.Tx.Byte11.ErrInfo == ENUM_ERRINFO_NULL)
	{
		SystemMode.f_Error = 0;
	}
	else
	{
		SystemMode.f_Error = 1;
	}
}
