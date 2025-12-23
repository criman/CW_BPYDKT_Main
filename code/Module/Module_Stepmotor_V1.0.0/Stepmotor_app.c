/*===================================================================================================
                		Copyright(C) 2011-2099.  SONG RESEARCH. Co., Ltd.
-----------------------------------------------------------------------------------------------------
Project Name  		: Stepmotor_app.c
Description   		: C
Author        		: Wuhaiming
Start Date    		: 2022/05/07
Version       		: V1.0
Revision History   1:
                   2:
===================================================================================================*/ 

#include		"main.h"


/****************************************************************************************************
Function Name       :U8	Case_StepMotor_StepTime(void)
Description         :步进电机选择速度选择
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/ 
U8	Case_StepMotor_StepTime(void)
{
    //add code if necessary....

    if ((StepMotor.var.u8_status == ENUM_STEPMOTOR_STATUS_RUN)	&& (StepMotor.var.u8_run > ENUM_STEPMOTOR_POSITION_OFFOK))
    {
        if (StepMotor.var.u8_run != ENUM_STEPMOTOR_POSITION_SWEEP)
        {
            return 0;	//速度较快
        }
        else
        {
            return 1;	//速度较慢-//正常工作
        }
    }
    else		
    {	
        return 0;	    //速度较快-//上电初始化或关机关风门
    }
	
}
/****************************************************************************************************
Function Name       :U8	Case_StepMotor_Pause(void)
Description         :步进电机停止旋转条件
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/ 
U8	Case_StepMotor_Pause(void)
{
    //add code if necessary....

    if (F_stepmotor_pause || (StepMotor.var.u16_agcurrent == StepMotor.var.u16_agtarget))
    {		
        return	1;
    }
    else
    {
        return	0;
    }
	
}
/****************************************************************************************************
Function Name       :void App_StepMotor_Run(void)
Description         :系统状态处理步进电机
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void	App_StepMotor_Run(void)
{
    switch (StepMotor.var.u8_status)
    {
        case	ENUM_STEPMOTOR_STATUS_INITFORMAX:		//先把风门打开到最大
        {
            F_stepmotor_forceoff = CF_ENABLE;										//强制关风门(上电已有效不用重复)
            StepMotor.var.u16_agcurrent = 0;										//起点
            StepMotor.var.u16_agtarget  = C_STEPMOTOR_ANGLE_INITOPEN;			    //上电校准风门先打开的角度
        
            if ((PowEnPTCB.f_DrvOn == ON) && (PowEn12V.f_DrvOn == ON))				//add 20231218 等待12V光耦打开和PTCB打开后才进行复位动作
			{
				StepMotor.var.u8_status += 1;
			}
        }break;
        
        case	ENUM_STEPMOTOR_STATUS_WAITFORMAX:		//等待风门达到最大
        {
            if (StepMotor.var.u16_agcurrent == StepMotor.var.u16_agtarget)
            {
                StepMotor.var.u16_agcurrent = C_STEPMOTOR_ANGLE_MAX;		        //风门最大角度
                StepMotor.var.u16_agtarget  = 0;							        //起点
            
                StepMotor.var.u8_status += 1;
            }
        }break;
        
        case	ENUM_STEPMOTOR_STATUS_WAITFOROFF:		//等待风门关闭闭合
        {
            if (StepMotor.var.u16_agcurrent == StepMotor.var.u16_agtarget)
            {
                StepMotor.var.u16_agcurrent = 0;									//起点
                StepMotor.var.u16_agtarget = 0;										//起点
                StepMotor.var.u8_run = ENUM_STEPMOTOR_POSITION_OFFINIT;			    //功能运行默认关闭等待命令
            
                StepMotor.var.u8_status += 1;
            }
        }break;
        
        case	ENUM_STEPMOTOR_STATUS_RUN:				//扫风功能运行
        {
            switch (StepMotor.var.u8_run)
            {
                case	ENUM_STEPMOTOR_POSITION_OFFINIT:	//关风门
                {
                    if ((StepMotor.var.u16_agcurrent == 0) && (StepMotor.var.u16_agtarget == 0))
                    {
                        if (StepMotor.var.f_forceinit == 0)
                        {
                            StepMotor.var.f_forceinit = 1;
                            StepMotor.var.u16_agcurrent = C_STEPMOTOR_ANGLE_FORCEINIT;		//强加角度确保关闭(上电)
                        
                        } 
                        else
                        {
                            StepMotor.var.u16_agcurrent = C_STEPMOTOR_ANGLE_FORCEOFF;		//强加角度确保关闭(待机)
                        }
                        
                        StepMotor.var.u8_run += 1;
                    }
                }break;
                
                case	ENUM_STEPMOTOR_POSITION_WAITOFFOK:	//等待强加角度完成								
                {
                    if ((StepMotor.var.u16_agcurrent == 0) && (StepMotor.var.u16_agtarget == 0))
                    {
                        StepMotor.var.u8_run += 1;
                    }
                }break;
                
                case	ENUM_STEPMOTOR_POSITION_OFFOK:		//关风门强加角度确保关紧
                {
                    ;
                }break;
                
                case	ENUM_STEPMOTOR_POSITION_ON:			//开风门-某角度定住
                {
                    if (SystemMode.f_AntiDew == 0)                 
                    {	
						StepMotor.var.u16_agtarget = Swing.u16_anglebak;			        //风门默认角度 						
					}
					else	//防凝露摆最大角度
					{
						StepMotor.var.u16_agtarget = C_STEPMOTOR_ANGLE_MAX;
						F_stepmotor_pause = CF_DISABLE;
					}
					                   
                    
                    if (StepMotor.var.u16_agcurrent == StepMotor.var.u16_agtarget)
                    {
                        StepMotor.var.u8_run = ENUM_STEPMOTOR_POSITION_ONOK;
                    }
                }break;
                
                case	ENUM_STEPMOTOR_POSITION_ONOK:
                {
					if ((SystemMode.f_AntiDew == 0) && (Swing.u16_angledew != 0))
					{
						StepMotor.var.u16_agtarget = Swing.u16_angledew;
						if (StepMotor.var.u16_agcurrent == StepMotor.var.u16_agtarget)
						{
							Swing.u16_angledew = 0;
						}
						StepMotor.var.u8_run = ENUM_STEPMOTOR_POSITION_ANTIDEW;
						F_stepmotor_pause = CF_DISABLE;											//摆风情况清除停止标志
					} 
                }break;
                
                case	ENUM_STEPMOTOR_POSITION_SWEEP:		//开风门-扫风
                {
                    Swing_Sweep();
                }break;
                
				case	ENUM_STEPMOTOR_POSITION_ANTIDEW:
				{
                    if (StepMotor.var.u16_agcurrent == StepMotor.var.u16_agtarget)
                    {
                        StepMotor.var.u8_run = ENUM_STEPMOTOR_POSITION_ONOK;
						Swing.u16_angledew = 0;
                    }				
				}break;
				
                case	ENUM_STEPMOTOR_POSITION_SELFCHK:		//自检风门	
                {
                    StepMotor.var.u16_agtarget  = C_STEPMOTOR_ANGLE_SELCHK;							//风门自检角度
                }break;

                default: break;
            }
                
        }break;
        
        default: break;
    }
    
    //add code...       //通过功能改变角度
    Swing_Con();		//风门控制
		
}
