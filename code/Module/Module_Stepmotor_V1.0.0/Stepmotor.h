/*===================================================================================================
                		Copyright(C) 2011-2099.  SONG RESEARCH. Co., Ltd.
-----------------------------------------------------------------------------------------------------
Project Name  		: Stepmotor.h
Description   		: H
Author        		: Wuhaiming
Start Date    		: 2022/05/06
Version       		: V1.0
Revision History   1:
                   2:
===================================================================================================*/ 

#ifndef			_STEPMOTOR_H_

#define			_STEPMOTOR_H_

#include		"Stepmotor_app.h"
#include		"Swing.h"

/*******************************************步进电机a相接口配置*****************************************/
//橙色线
#define			Pin_stepmotora								PortPin_Read(GPIOB, GPIO_Pin_23)
#define			P_StepmotorA_Hi()							DEFINE_PB23_HI
#define			P_StepmotorA_Low()							DEFINE_PB23_LOW
#define			P_StepmotorA_Output()						DEFINE_PB23_OUTPUT
#define			P_StepmotorA_Input()						DEFINE_PB23_INPUT
#define			P_StepmotorA_Enpull()						DEFINE_PB23_ENPULLUP
#define			P_StepmotorA_Dispull()					    DEFINE_PB23_DISPULLUP
/*******************************************步进电机b相接口配置*****************************************/
//黄色线
#define			Pin_stepmotorb								PortPin_Read(GPIOB, GPIO_Pin_26)
#define			P_StepmotorB_Hi()							DEFINE_PB26_HI
#define			P_StepmotorB_Low()							DEFINE_PB26_LOW
#define			P_StepmotorB_Output()						DEFINE_PB26_OUTPUT
#define			P_StepmotorB_Input()						DEFINE_PB26_INPUT
#define			P_StepmotorB_Enpull()						DEFINE_PB26_ENPULLUP
#define			P_StepmotorB_Dispull()					    DEFINE_PB26_DISPULLUP
/*******************************************步进电机c相接口配置*****************************************/
//粉色线
#define			Pin_stepmotorc								PortPin_Read(GPIOB, GPIO_Pin_27)
#define			P_StepmotorC_Hi()							DEFINE_PB27_HI
#define			P_StepmotorC_Low()							DEFINE_PB27_LOW
#define			P_StepmotorC_Output()						DEFINE_PB27_OUTPUT
#define			P_StepmotorC_Input()						DEFINE_PB27_INPUT
#define			P_StepmotorC_Enpull()						DEFINE_PB27_ENPULLUP
#define			P_StepmotorC_Dispull()					    DEFINE_PB27_DISPULLUP
/*******************************************步进电机d相接口配置*****************************************/
//蓝色线
#define			Pin_stepmotord								PortPin_Read(GPIOA, GPIO_Pin_13)
#define			P_StepmotorD_Hi()							DEFINE_PA13_HI
#define			P_StepmotorD_Low()							DEFINE_PA13_LOW
#define			P_StepmotorD_Output()						DEFINE_PA13_OUTPUT
#define			P_StepmotorD_Input()						DEFINE_PA13_INPUT
#define			P_StepmotorD_Enpull()						DEFINE_PA13_ENPULLUP
#define			P_StepmotorD_Dispull()					    DEFINE_PA13_DISPULLUP

//-------------------------------------------------------------------------------------------//
typedef struct 	   			/*定义字节、位寻址结构*/
{		
	unsigned char b0:1;
	unsigned char b1:1;
	unsigned char b2:1;
	unsigned char b3:1;
	unsigned char b4:1;
	unsigned char b5:1;
	unsigned char b6:1;
	unsigned char b7:1;
}STRUCT_STEPMOTORBYTE;
extern	STRUCT_STEPMOTORBYTE		StepMotorFlag;

#define		F_stepmotor_pina					StepMotorFlag.b0		//A端口(蓝色)驱动电平				0:低电平		1:高电平
#define		F_stepmotor_pinb					StepMotorFlag.b1		//B端口(粉色)驱动电平				0:低电平		1:高电平
#define		F_stepmotor_pinc					StepMotorFlag.b2		//C端口(黄色)驱动电平				0:低电平		1:高电平
#define		F_stepmotor_pind					StepMotorFlag.b3		//D端口(橙色)驱动电平				0:低电平		1:高电平
#define		F_stepmotor_pause					StepMotorFlag.b4		//旋转暂停							0:旋转中		1:旋转暂停
#define		F_stepmotor_autodirect			    StepMotorFlag.b5		//扫风旋转方向						0:逆时针		1:顺时针
#define		F_stepmotor_autoadd					StepMotorFlag.b6		//扫风到最大角度再走3个脉冲			0:标志清0		1:有效
#define		F_stepmotor_forceoff				StepMotorFlag.b7		//进行一次强制关风门(再走角度)	    0:未执行		1：已执行

//-------------------------------------------------------------------------------------------//
typedef		struct
{
    unsigned char	u8_steptime;				//步进电机转速基准计时
    unsigned char	u8_steptime_base;			//步进电机转速基准
    unsigned char	u8_stepcount;				//步进电机的拍子	
    unsigned int	u16_agcurrent;				//当前角度
    unsigned int	u16_agtarget;				//目标角度
    unsigned char	u8_status;					//步进电机状态机
    unsigned char   u8_run;						//功能运行阶段运行命令
    unsigned char   f_forceinit;                //强制关闭角度
    unsigned char	u8_remaintime;				//步进电机达到最大最小角度时停留时间
}STRUCT_STEPMOTOR;

typedef		union
{
    unsigned char		variable[11]; //10->11 lcx 20240617
    STRUCT_STEPMOTOR	var;
}UNION_STEPMOTOR;
extern	UNION_STEPMOTOR		StepMotor;

/****************************************************************************************************
Function Name       :void Module_Init_StepMotor(void)
Description         :步进电机四相 IO初始化
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/ 
extern	void	Module_Init_StepMotor(void);
/****************************************************************************************************
Function Name       :void Log_StepMotor(void)
Description         :步进电机逻辑处理
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/ 
extern	void	Log_StepMotor(void);
/****************************************************************************************************
Function Name       :void Log_StepMotor_SweepAuto(U16	u16_target1, U16	u16_target2)
Description         :自动扫风控制
Input               :U16	u16_target1, U16	u16_target2
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
extern	void	Log_StepMotor_SweepAuto(U16	u16_target1, U16	u16_target2);

#endif
