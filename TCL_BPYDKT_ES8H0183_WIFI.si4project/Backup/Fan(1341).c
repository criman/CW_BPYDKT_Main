/*===================================================================================================
                		Copyright(C) 2011-2099.  SUNRAM. Co., Ltd.
-----------------------------------------------------------------------------------------------------
Project Name  		: Fan.c
Description   		: C
Author        		: Wuhaiming
Start Date    		: 2023/09/12
Version       		: V1.0
Revision History   1:
                   2:
===================================================================================================*/ 

#include	"main.h"

STRUCT_FAN    Fan;


/****************************************************************************************************
Function Name       :void    App_Fan_InDoor(void)
Description         :上风机/内风机应用处理
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    App_Fan_InDoor(void)
{
	S16  s16_TempSetMul10;	//设定值乘以10
	
	if (System.Mode == ENUM_SYSMODE_HUM)	//除湿按设定值T1-2℃
	{
		s16_TempSetMul10 = TempValueMul10(Tempr.u8_HumiCSet);
	}
	else
	{
		s16_TempSetMul10 = TempValueMul10(Tempr.u8_TempCSet);
	}	

	//---------------------------------------------------------------------	
	if (SystemMode.f_Heat == 1 && Defrost.f_Enable == 0) //lcx add 20240620 不管开机还是在关机途中都防冷风
	{
		if(T2.s16_ValueMul10 >= 350) //IPT>=35℃，运行正常风
		{
			Fan.Indoor.f_ForceLow = 0;	
		}
		else
		{
			Fan.Indoor.f_ForceLow = 1;	//强制低风    //30℃＜IPT＜35℃
			if(T2.s16_ValueMul10 < 300) 
			{
				Fan.Indoor.f_AppOn = OFF; //去到OFF后，要在后面控制Fan.Indoor.f_ForceLow
				Fan.Indoor.u16_Delay = 0; //不延时20s，直接关掉，防止冷风
			}	
		}		
	}
	//---------------------------------------------------------------------

	//内风机	
	if (System.Enum_Status == ENUM_STATUS_BUSSCHK)		//商检运行高风
	{
		Fan.Indoor.Level = ENUM_FANLEVEL_HIGH;	
	}
	else if (SystemMode.f_Sleep)
	{
		Fan.Indoor.Level = ENUM_FANLEVEL_LOW_S;
		Fan.Indoor.f_AppOn = ON; //lcx add 20240626  睡眠模式达温停机有效（达温停压机，上风机一直以微风运行，不执行停10开1达温逻辑）
	}	
	else if (Defrost.f_Enable == 1)	 //进入化霜，内风机关闭 lcx add 20240621
	{
		Fan.Indoor.f_AppOn = OFF;
	}
	else if ((Fan.f_DeMold == 1) || (System.Mode == ENUM_SYSMODE_HUM) || (Fan.Indoor.f_ForceLow == 1))
	{
		Fan.Indoor.Level = ENUM_FANLEVEL_LOW;	//除霉、除湿、制热IPT温度符合 低风运行
		
		if (System.Mode == ENUM_SYSMODE_HUM) 
		{
			if (T2.f_Error || T3.f_Error || Tp.f_Error)	//除湿时T2/T3故障 //增加TP故障除湿时也运行 lcx 20240622
			{
				Fan.Indoor.f_AppOn = ON;
			}
			else if (SystemMode.f_TempCEC)
			{
				if (Fan.Indoor.u16_Count < 6000)	//首次开10分钟(P40)
				{
					Fan.Indoor.f_AppOn = ON;			
				}
				else if (Fan.Indoor.u16_Count < (6000 + 6000))	//10分钟关(P41)
				{
					Fan.Indoor.f_AppOn = OFF;
				}
				else if (Fan.Indoor.u16_Count < (6000 + 6000 + 600))		//1分钟开(P42)
				{
					Fan.Indoor.f_AppOn = ON;
					
					if (Fan.ModeCECBak == ENUM_FANMODE_INIT)	  //初始化不确定
					{
						Fan.ModeCECBak = Fan.Mode;
	//					SystemMode.f_CECSync = 1;  
						SystemMode.f_CECSync = 1;  //lcx add 开1分钟低风停10分钟期间，档位显示同步低风
					}				
				}
				else
				{
					Fan.Indoor.f_AppOn = OFF;
					Fan.Indoor.u16_Count = 6000;				//重新一个循环
				}			
			}
		}
	}
	else if ((SystemMode.f_Silence) && (Comp.u8_RealHZ <= (Comp.u8_Cold_TargetHZ[4] + 1)))
	{
		Fan.Indoor.Level = ENUM_FANLEVEL_LOW_S; //风速强力档
	}
	else if (SystemMode.f_Force)
	{
		Fan.Indoor.Level = ENUM_FANLEVEL_HIGH_S; //风速强力档
		
		if(WaterBox.f_Full == 0) //水满后上风机关（规格书最后描述水满故障负载全关）
		{
			Fan.Indoor.f_AppOn = ON; //lcx add 强力模式保持开 20240704
		}
	}
	//else if ((SystemMode.f_Cold == 1) && (T2.f_Error || T3.f_Error))	//T2/T3故障制冷时运行
	else if ((SystemMode.f_Cold == 1) && (T2.f_Error || T3.f_Error || Tp.f_Error))	//T2/T3/TP故障制冷时运行 lcx 20240425
	{
		Fan.Indoor.f_AppOn = ON;
	}
	else if ((SystemMode.f_Heat == 1) && (T1.f_Error || T2.f_Error || T3.f_Error || T4.f_Error || Tp.f_Error))	//T1/T2/T3/T4/Tp故障制热时按通风处理
	{		
		if (Fan.Indoor.u16_Count >= 6000)	//制热时连续内风机停止10分钟 (P260)
		{
			if (Fan.Indoor.u16_Count < (6000 + 300))	//P265
			{
				Fan.Indoor.Level = ENUM_FANLEVEL_LOW;	//低风运行
				
				Fan.Indoor.f_AppOn = ON;
			}
			else 
			{
				Fan.Indoor.f_AppOn = OFF;
			}
		}
		else
		{
			if (Fan.Indoor.u16_Delay == 0)	//延时完毕才能关
			{
				Fan.Indoor.f_AppOn = OFF;
			}
		}
		
		if (Fan.Indoor.u16_Count >= (6000 + 6000))	//P260
		{
			Fan.Indoor.u16_Count = 6000;
		}		
	}
	else if (SystemMode.f_TempCEC)	//5.2.2.4.2  达温
	{
		
		
		if (SystemMode.f_Cold == 1)
		{
			Fan.Indoor.Level = ENUM_FANLEVEL_LOW;	//低风运行
			
			if (Fan.Indoor.u16_Count < 6000)	//首次开10分钟(P40)
			{
				Fan.Indoor.f_AppOn = ON;			
			}
			else if (Fan.Indoor.u16_Count < (6000 + 6000))	//10分钟关(P41)
			{
				Fan.Indoor.f_AppOn = OFF;
			}
			else if (Fan.Indoor.u16_Count < (6000 + 6000 + 600))		//1分钟开(P42)
			{
				Fan.Indoor.f_AppOn = ON;
				
				if (Fan.ModeCECBak == ENUM_FANMODE_INIT)	  //初始化不确定
				{
					Fan.ModeCECBak = Fan.Mode;
//					SystemMode.f_CECSync = 1;  
					SystemMode.f_CECSync = 1;  //lcx add 开1分钟低风停10分钟期间，档位显示同步低风

				}				
			}
			else
			{
				Fan.Indoor.f_AppOn = OFF;
				Fan.Indoor.u16_Count = 6000;				//重新一个循环
			}
		}
		else if (SystemMode.f_Heat == 1)
		{
			if (Fan.Indoor.u16_Count >= 6000)	//制热时连续内风机停止10分钟 (P260)
			{
				Fan.Indoor.Level = ENUM_FANLEVEL_LOW;	//低风运行
				
				if (Fan.Indoor.u16_Count < (6000 + 300))	//P265
				{
					Fan.Indoor.f_AppOn = ON;
				}
				else 
				{
					Fan.Indoor.f_AppOn = OFF;
				}
			}
			else
			{
				//制热达温还需考虑停机吹余热
				if (Comp.f_DrvOn == ON)
				{
					if (T2.s16_ValueMul10 > 300)	
					{
						Fan.Indoor.u16_Delay = 200;		//(P26) 压缩机停止后20s上风机关闭(吹余热)
					}
				}
				else
				{
					if (Fan.Indoor.u16_Delay == 0)	//延时完毕才能关
					{
						Fan.Indoor.f_AppOn = OFF;
					}
					
					if (T2.s16_ValueMul10 <= 300)	//lcx add 20240521 3. T2<= 30℃时，强制关闭上电机，无需等待20S，T2温度判断优先；
					{
						Fan.Indoor.u16_Delay = 0;
						Fan.Indoor.f_AppOn = OFF;
					}

				}
			}
			
			if (Fan.Indoor.u16_Count >= (6000 + 6000))	//P260
			{
				Fan.Indoor.u16_Count = 6000;
			}		
		}
	}
	else
	{
		if (Fan.Mode == ENUM_FANMODE_AUTO)	//自动风运行
		{
			if (SystemMode.f_Cold == 1) 		//制冷模式
			{
				if ((Fan.ModeBak != Fan.Mode) || (Fan.Indoor.Level < ENUM_FANLEVEL_MED))		//初始切换时(自动风没有低风)
				{
					if (T1.s16_ValueMul10 >= s16_TempSetMul10 + 30)			//RT-ST≥3℃
					{
						Fan.Indoor.Level = ENUM_FANLEVEL_HIGH;				//上电机(内风机)高档
					}
					else
					{
						Fan.Indoor.Level = ENUM_FANLEVEL_MED;				//上电机(内风机)中档
					}
				}
				else														//初始已过
				{
					if (Fan.Indoor.Level == ENUM_FANLEVEL_HIGH)				//当上电机(内风机)高档时
					{
						if (T1.s16_ValueMul10 <= s16_TempSetMul10 + 10)		//RT-ST≤1℃时
						{
							Fan.Indoor.Level = ENUM_FANLEVEL_MED;			//转换为中档
						}
					}
					else
					{
						if (T1.s16_ValueMul10 >= s16_TempSetMul10 + 30)		//RT-ST≥3℃
						{
							Fan.Indoor.Level = ENUM_FANLEVEL_HIGH;			//上电机(内风机)高档
						}				
					}
				}				
			}
			else if (SystemMode.f_Heat == 1) 		//制热模式
			{
				if ((Fan.ModeBak != Fan.Mode) || (Fan.Indoor.Level < ENUM_FANLEVEL_MED) || (Fan.u2_AutoInitFdCount < 2))	//初始切换时(自动风没有低风)
				{
									
					if (++Fan.u2_AutoInitFdCount >= 2)
					{
						Fan.u2_AutoInitFdCount = 2;
						
						if (T1.s16_ValueMul10 >= 250)			//P370 RT≥25℃
						{
							Fan.Indoor.Level = ENUM_FANLEVEL_HIGH;				//上电机(内风机)高档
						}
						else
						{
							Fan.Indoor.Level = ENUM_FANLEVEL_MED;				//上电机(内风机)中档
						}
					}
				}
				else
				{
					if (Fan.Indoor.Level == ENUM_FANLEVEL_HIGH)				//当上电机(内风机)高档时
					{
						if (T1.s16_ValueMul10 < 230)						//P360  RT小于23℃时
						{
							Fan.Indoor.Level = ENUM_FANLEVEL_MED;			//转换为中档
						}
					}
					else
					{
						if (T1.s16_ValueMul10 > 250)							//P370   RT＞25℃
						{
							Fan.Indoor.Level = ENUM_FANLEVEL_HIGH;			//上电机(内风机)高档
						}				
					}

				}
			}
			else	//处于不是制冷又不是制热按中风执行
			{
				Fan.Indoor.Level = ENUM_FANLEVEL_MED;
			}
		}
		else
		{
			if (Fan.Mode == ENUM_FANMODE_INIT)				//初始不确定状态
			{
				switch (CommDisp.Rx.Byte5.var.FanSpeed)
				{
					case	ENUM_FANSPEED_AUTO	 : Fan.Mode = ENUM_FANMODE_AUTO; break;			//自动风
					case	ENUM_FANSPEED_LOW    : Fan.Mode = ENUM_FANMODE_LOW;  break;			//低风
					case	ENUM_FANSPEED_MED    : Fan.Mode = ENUM_FANMODE_MED;  break;			//中风
					case	ENUM_FANSPEED_HIGH   : Fan.Mode = ENUM_FANMODE_HIGH; break;			//高风
					case	ENUM_FANSPEED_SILENCE: Fan.Mode = ENUM_FANMODE_LOW;  break;			//静音	

					default: break;
				}			
			}
			else if (Fan.Mode == ENUM_FANMODE_HIGH)    			//高风
			{
				Fan.Indoor.Level = ENUM_FANLEVEL_HIGH;		//上电机(内风机)高档
			}
			else if (Fan.Mode == ENUM_FANMODE_MED)    		//中风 
			{
				Fan.Indoor.Level = ENUM_FANLEVEL_MED;		//上电机(内风机)中档
			}
			else
			{
				Fan.Indoor.Level = ENUM_FANLEVEL_LOW;		//上电机(内风机)低档
			}
		}	

		//--------------------------------------------------------------------- //（规格书描述水满后负载全关）
		if(System.Enum_Status == ENUM_STATUS_ON && Defrost.f_Enable == 0 && WaterBox.f_Full == 0) 
		{
			Fan.Indoor.f_AppOn = ON; 	//lcx add 20240612 退出达温停机后要按照设置的风速模式开启风机  
		}
		//---------------------------------------------------------------------
	}	
	
	if (Fan.ModeBak != Fan.Mode) 
	{	
	    if (Fan.Indoor.Level < ENUM_FANLEVEL_MED)	//风速改变后低于中风，自动风判断风速防抖清0
		{
			Fan.u2_AutoInitFdCount = 0;
		}
	}
	
	Fan.ModeBak = Fan.Mode;		//风速模式备份更新
}
/****************************************************************************************************
Function Name       :void    Log_Fan_InDoor(void)
Description         :上风机/内风机逻辑处理
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Log_Fan_InDoor(void)
{
	if (Fan.Indoor.f_DrvOn == OFF)
	{
	
		if (Fan.Indoor.f_Error == 0)
		{
			if (((Fan.Indoor.f_AppOn == ON) && (Fan.Indoor.u16_Delay == 0)) || Fan.f_DeMold)
			{
				if ((StepMotor.var.u8_status >= ENUM_STEPMOTOR_STATUS_RUN) && (StepMotor.var.u8_run >= ENUM_STEPMOTOR_POSITION_ONOK))	//保证风门打开完成才能驱动
				{
					//上风机/内风机启动刹那
					
					Fan.Indoor.f_DrvOn = ON;
				}
			}
		}
	}
	else
	{
		if (((Fan.Indoor.f_AppOn == OFF) && (Fan.Indoor.u16_Delay == 0) && (Fan.f_DeMold == 0)) || (Fan.Indoor.f_Error == 1))
		{
			//上风机/内风机关闭刹那
			
			Fan.Indoor.f_DrvOn = OFF;
		}
	}
}
/****************************************************************************************************
Function Name       :void    Drv_Fan_InDoor(void)
Description         :上风机/内风机驱动处理
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Drv_Fan_InDoor(void)
{
	if (Fan.Indoor.f_DrvOn)
	{		
		if (System.Enum_Status == ENUM_STATUS_BUSSCHK)
		{
			// EE.PARA. 	C_REMEMBER_PARA01_00;        //125 			//测试-商检			
			Fan.Indoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[17]);
		}
		else if ((SystemMode.f_PerTest == 1) && (SystemMode.f_Cold == 1) && ((Tempr.u8_TempCSet == 30) || (Tempr.u8_TempCSet == 29)))
		{
			if (Tempr.u8_TempCSet == 30)	//额定制冷
			{
				// EE.PARA. C_REMEMBER_PARA01_01;        //115			//测试-额定制冷
				Fan.Indoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[18]);			
			}
			else							//最小制冷
			{
				// EE.PARA. C_REMEMBER_PARA01_02;        //80			//测试-最小制冷
				Fan.Indoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[19]);
			}
			
		}
		else if ((SystemMode.f_PerTest == 1) && (SystemMode.f_Heat == 1) && (Tempr.u8_TempCSet == 17))
		{
			// EE.PARA. C_REMEMBER_PARA01_03;        //120			//测试-额定制热
			Fan.Indoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[20]);
		}	
		else if (Fan.Indoor.Level == ENUM_FANLEVEL_HIGH_S)
		{
			if ((SystemMode.f_Cold == 1) || (SystemMode.f_Fan == 1))
			{
				// EE.PARA. C_REMEMBER_PARA01_04;        //115			//常规-制冷-强力风
				Fan.Indoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[21]);
			}
			else if ((Fan.Indoor.u16_Delay == 0) && (Fan.f_DeMold == 0) && (Fan.Indoor.f_AppOn == 0))
			{
				//异常情况给定常数0
				Fan.Indoor.u16_TargetRPM = 0;
			}
		}
		else if (Fan.Indoor.Level == ENUM_FANLEVEL_HIGH)
		{
			if ((SystemMode.f_Cold == 1) || (SystemMode.f_Fan == 1))
			{
				// EE.PARA. C_REMEMBER_PARA01_05;        //105			//常规-制冷-高风
				Fan.Indoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[22]);
			}	
			else if (SystemMode.f_Heat == 1)
			{
				// EE. PARA. C_REMEMBER_PARA01_09;		  //115 		//常规-制热-高风
				Fan.Indoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[26]);
			}
			else if ((Fan.Indoor.u16_Delay == 0) && (Fan.f_DeMold == 0) && (Fan.Indoor.f_AppOn == 0))
			{
				//异常情况给定常数0
				Fan.Indoor.u16_TargetRPM = 0;
			}
		}
		else if (Fan.Indoor.Level == ENUM_FANLEVEL_MED)
		{
			if ((SystemMode.f_Cold == 1) || (SystemMode.f_Fan == 1))
			{
				// EE.PARA. C_REMEMBER_PARA01_06;        //90			//常规-制冷-中风
				Fan.Indoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[23]);
			}	
			else if (SystemMode.f_Heat == 1)
			{
				// EE.PARA. C_REMEMBER_PARA01_10;        //100			//常规-制热-中风
				Fan.Indoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[27]);
			}
			else if ((Fan.Indoor.u16_Delay == 0) && (Fan.f_DeMold == 0) && (Fan.Indoor.f_AppOn == 0))
			{
				//异常情况给定常数0
				Fan.Indoor.u16_TargetRPM = 0;
			}
		}
		else if (Fan.Indoor.Level == ENUM_FANLEVEL_LOW)
		{
			if ((SystemMode.f_Cold == 1) || (SystemMode.f_Fan == 1) || Fan.f_DeMold)
			{
				// EE.PARA. C_REMEMBER_PARA01_07;        //80			//常规-制冷-低风
				Fan.Indoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[24]);
			}	
			else if (SystemMode.f_Heat == 1)
			{
				// EE.PARA. C_REMEMBER_PARA01_11;        //90			//常规-制热-低风
				Fan.Indoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[28]);
			}
			else if ((Fan.Indoor.u16_Delay == 0) && (Fan.f_DeMold == 0) && (Fan.Indoor.f_AppOn == 0))
			{
				//异常情况给定常数0
				Fan.Indoor.u16_TargetRPM = 0;
			}
			else	//20231124 制热关机T2温度散热情况
			{
				if (SystemMode.f_HeatBak == 1)
				{
					Fan.Indoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[28]);
				}
				else
				{
					Fan.Indoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[24]);
				}
			}
		}
		else if (Fan.Indoor.Level == ENUM_FANLEVEL_LOW_S)
		{
			if ((SystemMode.f_Cold == 1) || (SystemMode.f_Fan == 1))
			{
				// EE.PARA. C_REMEMBER_PARA01_08;        //70			//常规-制冷-微风
				Fan.Indoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[25]);
			}	
			else if (SystemMode.f_Heat == 1)
			{
				// EE.PARA. C_REMEMBER_PARA01_12;        //70			//常规-制热-微风
				Fan.Indoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[29]);
			}
			else if ((Fan.Indoor.u16_Delay == 0) && (Fan.f_DeMold == 0) && (Fan.Indoor.f_AppOn == 0))
			{
				//异常情况给定常数0
				Fan.Indoor.u16_TargetRPM = 0;
			}
		}

	}
	else
	{
		Fan.Indoor.f_ForceLow = 0;
		
		Fan.Indoor.u16_TargetRPM = 0;
	}
}
/****************************************************************************************************
Function Name       :void    App_Fan_OutDoor(void)
Description         :下风机/外风机应用处理
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    App_Fan_OutDoor(void)
{
	//外风机
	
	if (Defrost.f_Enable == 1)	//化霜外风机强制高档运行
	{
		Fan.Outdoor.Level = ENUM_FANLEVEL_HIGH;
	}		
	else if (SystemMode.f_Sleep || WaterBox.f_WatLow)	//睡眠或水位低时微风
	{
		Fan.Outdoor.Level = ENUM_FANLEVEL_LOW_S;
	}
	else if (SystemMode.f_Heat == 1)	//制热
	{
		if (T4.s16_ValueMul10 >= 50)						//T4≥5℃
		{
			if (Comp.u8_RealHZ <= 40)						//压缩机运行频率≤40HZ
			{
				//下电机(外电机)低档  
				Fan.Outdoor.Level = ENUM_FANLEVEL_LOW;
			}
			else if (Comp.u8_RealHZ < 60)					//40HZ＜压缩机运行频率＜60HZ
			{
				//下电机(外电机)中档  
				Fan.Outdoor.Level = ENUM_FANLEVEL_MED;
			}
			else											//压缩机运行频率≥60HZ
			{
				//下电机(外电机)中档  
				Fan.Outdoor.Level = ENUM_FANLEVEL_MED;
			}
		}
		else												//T4＜5℃
		{
			if (Comp.u8_RealHZ <= 40)						//压缩机运行频率≤40HZ
			{
				//下电机(外电机)中档
				Fan.Outdoor.Level = ENUM_FANLEVEL_MED;	
			}
			else if (Comp.u8_RealHZ < 60)					//40HZ＜压缩机运行频率＜60HZ
			{
				//下电机(外电机)中档
				Fan.Outdoor.Level = ENUM_FANLEVEL_MED;	
			}
			else											//压缩机运行频率≥60HZ
			{
				//下电机(外电机)高档  
				Fan.Outdoor.Level = ENUM_FANLEVEL_HIGH;
			}		
		}
	}
	else if (SystemMode.f_Cold == 1)	//制冷
	{
		if (SystemMode.f_AntiDew == 1)	//防凝露
		{
			if (Fan.Outdoor.Level != ENUM_FANLEVEL_LOW_S)
			{
				Fan.Outdoor.Level = ENUM_FANLEVEL_LOW;
			}
		}
		else if (SystemMode.f_Force)
		{
			Fan.Outdoor.Level = ENUM_FANLEVEL_HIGH_S; //风速强力档
		}
		else
		{
			if (T4.s16_ValueMul10 >= 430)						//T4≥43℃
			{
				if (Comp.u8_RealHZ <= 40)						//压缩机运行频率≤40HZ
				{
					//下电机(外电机)高档	
					Fan.Outdoor.Level = ENUM_FANLEVEL_HIGH;	
				}
				else if (Comp.u8_RealHZ < 60)					//40HZ＜压缩机运行频率＜60HZ
				{
					//下电机(外电机)高档   
					Fan.Outdoor.Level = ENUM_FANLEVEL_HIGH;	
				}
				else											//压缩机运行频率≥60HZ
				{
					//下电机(外电机)高档
					Fan.Outdoor.Level = ENUM_FANLEVEL_HIGH;	
				}		
			}
			else if (T4.s16_ValueMul10 >= 350)					//35℃≤T4＜43℃
			{
				if (Comp.u8_RealHZ <= 40)						//压缩机运行频率≤40HZ
				{
					//下电机(外电机)中档
					Fan.Outdoor.Level = ENUM_FANLEVEL_MED;
				}
				else if (Comp.u8_RealHZ < 60)					//40HZ＜压缩机运行频率＜60HZ
				{
					//下电机(外电机)中档  
					Fan.Outdoor.Level = ENUM_FANLEVEL_MED;
				}
				else											//压缩机运行频率≥60HZ
				{
					//下电机(外电机)高档  
					Fan.Outdoor.Level = ENUM_FANLEVEL_HIGH;	
				}			
			}
			else if (T4.s16_ValueMul10 >= 200)					//20℃≤T4＜35℃
			{
				if (Comp.u8_RealHZ <= 40)						//压缩机运行频率≤40HZ
				{
					//下电机(外电机)低档  
					Fan.Outdoor.Level = ENUM_FANLEVEL_LOW;
				}
				else if (Comp.u8_RealHZ < 60)					//40HZ＜压缩机运行频率＜60HZ
				{
					//下电机(外电机)中档  
					Fan.Outdoor.Level = ENUM_FANLEVEL_MED;
				}
				else											//压缩机运行频率≥60HZ
				{
					//下电机(外电机)中档  
					Fan.Outdoor.Level = ENUM_FANLEVEL_MED;
				}			
			}
			else												//T4＜20℃
			{
				if (Comp.u8_RealHZ <= 40)						//压缩机运行频率≤40HZ
				{
					//下电机(外电机)低档  
					Fan.Outdoor.Level = ENUM_FANLEVEL_LOW;	
				}
				else if (Comp.u8_RealHZ < 60)					//40HZ＜压缩机运行频率＜60HZ
				{
					//下电机(外电机)低档 
					Fan.Outdoor.Level = ENUM_FANLEVEL_LOW;
				}
				else											//压缩机运行频率≥60HZ
				{
					//下电机(外电机)低档 
					Fan.Outdoor.Level = ENUM_FANLEVEL_LOW;
				}		
			}
		}
	}
}
/****************************************************************************************************
Function Name       :void    Log_Fan_OutDoor(void)
Description         :下风机/外风机逻辑处理
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Log_Fan_OutDoor(void)
{
	if (Fan.Outdoor.f_DrvOn == OFF)
	{
		if (Fan.Outdoor.f_AppOn == ON)
		{
			//下风机/外风机启动刹那
			if (SystemMode.f_PerTest == 1)		//性能测试时
			{
				Comp.u8_SelTestDelay = 200;		//压缩机延后外风机20s后开启
				Comp.u16_RestartDelay = 0;
			}
			
			Fan.Outdoor.f_DrvOn = ON;
		}
	}
	else
	{
		if ((Fan.Outdoor.f_AppOn == OFF) && (Fan.Outdoor.u16_Delay == 0))
		{
			//下风机/外风机关闭刹那
			
			Fan.Outdoor.f_DrvOn = OFF;
		}
	}
}
/****************************************************************************************************
Function Name       :void    Drv_Fan_OutDoor(void)
Description         :下风机/外风机驱动处理
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void    Drv_Fan_OutDoor(void)
{}
//{
//	if (Fan.Outdoor.f_DrvOn)
//	{
//		if ((SystemMode.f_PerTest == 1) && (SystemMode.f_Cold == 1) && ((Tempr.u8_TempCSet == 30) || (Tempr.u8_TempCSet == 29)))
//		{
//			if (Tempr.u8_TempCSet == 30)	//额定制冷
//			{
//				// EE.PARA. C_REMEMBER_PARA02_00;		//105	        //测试-额定制冷	
//				Fan.Outdoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[30]);				
//			}
//			else							//最小制冷
//			{
//				// EE.PARA. C_REMEMBER_PARA02_01;		//80	        //测试-最小制冷	
//				Fan.Outdoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[31]);	
//			}		
//		}
//		else if ((SystemMode.f_PerTest == 1) && (SystemMode.f_Heat == 1) && (Tempr.u8_TempCSet == 17))
//		{
//			// EE.PARA. C_REMEMBER_PARA02_02;		//100	        //测试-额定制热	
//			Fan.Outdoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[32]);
//		}					
//		else if (Fan.Outdoor.Level == ENUM_FANLEVEL_HIGH_S)
//		{
//			if (SystemMode.f_Cold == 1)
//			{
//				// EE.PARA. C_REMEMBER_PARA02_03;		//105	        //常规-制冷-强力风
//				Fan.Outdoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[33]);
//			}
//			else
//			{
//				//异常给定常数0
//				Fan.Outdoor.u16_TargetRPM = 0;
//			}
//		}
//		else if (Fan.Outdoor.Level == ENUM_FANLEVEL_HIGH)
//		{
//			if ((SystemMode.f_Cold == 1) || (SystemMode.f_Fan == 1))
//			{
//				// EE.PARA. C_REMEMBER_PARA02_04;		//105	        //常规-制冷-高风	
//				Fan.Outdoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[34]);
//			}	
//			else if (SystemMode.f_Heat == 1)
//			{
//				// EE.PARA. C_REMEMBER_PARA02_08;		//100	        //常规-制热-高风	
//				Fan.Outdoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[38]);
//			}
//			else
//			{
//				//异常给定常数0
//				Fan.Outdoor.u16_TargetRPM = 0;
//			}
//		}
//		else if (Fan.Outdoor.Level == ENUM_FANLEVEL_MED)
//		{
//			if ((SystemMode.f_Cold == 1) || (SystemMode.f_Fan == 1))
//			{
//				// EE.PARA. C_REMEMBER_PARA02_05;		//105	        //常规-制冷-中风	
//				Fan.Outdoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[35]);
//			}	
//			else if (SystemMode.f_Heat == 1)
//			{
//				// EE.PARA. C_REMEMBER_PARA02_09;		//100	        //常规-制热-中风	
//				Fan.Outdoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[39]);
//			}
//			else
//			{
//				//异常给定常数0
//				Fan.Outdoor.u16_TargetRPM = 0;
//			}
//		}
//		else if (Fan.Outdoor.Level == ENUM_FANLEVEL_LOW)
//		{
//			if ((SystemMode.f_Cold == 1) || (SystemMode.f_Fan == 1))
//			{
//				// EE.PARA. C_REMEMBER_PARA02_06;		//105	        //常规-制冷-低风	
//				Fan.Outdoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[36]);
//			}	
//			else if (SystemMode.f_Heat == 1)
//			{
//				// EE.PARA. C_REMEMBER_PARA02_10;		//100	        //常规-制热-低风	
//				Fan.Outdoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[40]);
//			}
//			else
//			{
//				//异常给定常数0
//				Fan.Outdoor.u16_TargetRPM = 0;
//			}
//		}
//		else if (Fan.Outdoor.Level == ENUM_FANLEVEL_LOW_S)
//		{
//			if ((SystemMode.f_Cold == 1) || (SystemMode.f_Fan == 1))
//			{
//				// EE.PARA. C_REMEMBER_PARA02_07;		//70	        //常规-制冷-微风	
//				Fan.Outdoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[37]);
//			}	
//			else if (SystemMode.f_Heat == 1)
//			{
//				// EE.PARA. C_REMEMBER_PARA02_11;		//70	        //常规-制热-微风	
//				Fan.Outdoor.u16_TargetRPM = TempValueMul10(EEP.u8_rdBuf[41]);
//			}
//			else
//			{
//				//异常给定常数0
//				Fan.Outdoor.u16_TargetRPM = 0;
//			}
//		}		
//	}
//	else
//	{
//		Fan.Outdoor.u16_TargetRPM = 0;
//	}
//}
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
void    Func_Fan(void)
{
	App_Fan_InDoor();
	App_Fan_OutDoor();
	
	Log_Fan_InDoor();
	Log_Fan_OutDoor();
	
	Drv_Fan_InDoor();
	Drv_Fan_OutDoor();
}
