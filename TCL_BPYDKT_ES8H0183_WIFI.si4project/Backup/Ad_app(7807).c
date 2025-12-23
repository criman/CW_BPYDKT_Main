/*===================================================================================================
                		Copyright(C) 2011-2099.  SunRam. Co., Ltd.
-----------------------------------------------------------------------------------------------------
Project Name  		: Ad_app.c
Description   		: C
Author        		: Wuhaiming
Start Date    		: 2022/04/25
Version       		: V1.0
Revision History   1:
                   2:
===================================================================================================*/ 

#include	"main.h"

//此处顺序是按照已有传感器通道从通道号低到高，0开始排序							  冯锐辉 2025年7月26日15:26:13
#define C_ADC_T1_CH 3
#define C_ADC_T2_CH 2
#define C_ADC_T3_CH 1
//#define C_ADC_T4_CH 2
#define C_ADC_TP_CH 0

#if 1
//热敏电阻NTC AD温度对照表(室温) 15K
const	U16  U16_adc_temproom_table[126]__attribute__((at(0x00007600))) =
{
	C_AD_TEMPR_M20,		//-20℃对应AD值
    C_AD_TEMPR_M19,		//-19℃对应AD值
    C_AD_TEMPR_M18,		//-18℃对应AD值	
    C_AD_TEMPR_M17,		//-17℃对应AD值
    C_AD_TEMPR_M16,		//-16℃对应AD值	
    C_AD_TEMPR_M15,		//-15℃对应AD值
    C_AD_TEMPR_M14,		//-14℃对应AD值
    C_AD_TEMPR_M13,		//-13℃对应AD值
    C_AD_TEMPR_M12,		//-12℃对应AD值
    C_AD_TEMPR_M11,		//-11℃对应AD值
    C_AD_TEMPR_M10,		//-10℃对应AD值
    C_AD_TEMPR_M09,		//- 9℃对应AD值
    C_AD_TEMPR_M08,		//- 8℃对应AD值
    C_AD_TEMPR_M07,		//- 7℃对应AD值
    C_AD_TEMPR_M06,		//- 6℃对应AD值
    C_AD_TEMPR_M05,		//- 5℃对应AD值
    C_AD_TEMPR_M04,		//- 4℃对应AD值
    C_AD_TEMPR_M03,		//- 3℃对应AD值
    C_AD_TEMPR_M02,		//- 2℃对应AD值
    C_AD_TEMPR_M01,		//- 1℃对应AD值
    C_AD_TEMPR_P00,		//  0℃对应AD值
    C_AD_TEMPR_P01,		//  1℃对应AD值
    C_AD_TEMPR_P02,		//  2℃对应AD值
    C_AD_TEMPR_P03,		//  3℃对应AD值
    C_AD_TEMPR_P04,		//  4℃对应AD值
    C_AD_TEMPR_P05,		//  5℃对应AD值
    C_AD_TEMPR_P06,		//  6℃对应AD值
    C_AD_TEMPR_P07,		//  7℃对应AD值
    C_AD_TEMPR_P08,		//  8℃对应AD值
    C_AD_TEMPR_P09,		//  9℃对应AD值
    C_AD_TEMPR_P10,		// 10℃对应AD值
    C_AD_TEMPR_P11,		// 11℃对应AD值
    C_AD_TEMPR_P12,		// 12℃对应AD值
    C_AD_TEMPR_P13,		// 13℃对应AD值
    C_AD_TEMPR_P14,		// 14℃对应AD值
    C_AD_TEMPR_P15,		// 15℃对应AD值
    C_AD_TEMPR_P16,		// 16℃对应AD值
    C_AD_TEMPR_P17,		// 17℃对应AD值
    C_AD_TEMPR_P18,		// 18℃对应AD值
    C_AD_TEMPR_P19,		// 19℃对应AD值
    C_AD_TEMPR_P20,		// 20℃对应AD值
    C_AD_TEMPR_P21,		// 21℃对应AD值
    C_AD_TEMPR_P22,		// 22℃对应AD值
    C_AD_TEMPR_P23,		// 23℃对应AD值
    C_AD_TEMPR_P24,		// 24℃对应AD值
    C_AD_TEMPR_P25,		// 25℃对应AD值
    C_AD_TEMPR_P26,		// 26℃对应AD值
    C_AD_TEMPR_P27,		// 27℃对应AD值
    C_AD_TEMPR_P28,		// 28℃对应AD值
    C_AD_TEMPR_P29,		// 29℃对应AD值
    C_AD_TEMPR_P30,		// 30℃对应AD值
    C_AD_TEMPR_P31,		// 31℃对应AD值
    C_AD_TEMPR_P32,		// 32℃对应AD值
    C_AD_TEMPR_P33,		// 33℃对应AD值
    C_AD_TEMPR_P34,		// 34℃对应AD值
    C_AD_TEMPR_P35,		// 35℃对应AD值
    C_AD_TEMPR_P36,		// 36℃对应AD值
    C_AD_TEMPR_P37,		// 37℃对应AD值
    C_AD_TEMPR_P38,		// 38℃对应AD值
    C_AD_TEMPR_P39,		// 39℃对应AD值
    C_AD_TEMPR_P40,		// 40℃对应AD值
    C_AD_TEMPR_P41,		// 41℃对应AD值
    C_AD_TEMPR_P42,		// 42℃对应AD值
    C_AD_TEMPR_P43,		// 43℃对应AD值
    C_AD_TEMPR_P44,		// 44℃对应AD值
    C_AD_TEMPR_P45,		// 45℃对应AD值
    C_AD_TEMPR_P46,		// 46℃对应AD值
    C_AD_TEMPR_P47,		// 47℃对应AD值
    C_AD_TEMPR_P48,		// 48℃对应AD值
    C_AD_TEMPR_P49,		// 49℃对应AD值
    C_AD_TEMPR_P50,		// 50℃对应AD值
    C_AD_TEMPR_P51,		// 51℃对应AD值
    C_AD_TEMPR_P52,		// 52℃对应AD值
    C_AD_TEMPR_P53,		// 53℃对应AD值
    C_AD_TEMPR_P54,		// 54℃对应AD值
    C_AD_TEMPR_P55,		// 55℃对应AD值
    C_AD_TEMPR_P56,		// 56℃对应AD值
    C_AD_TEMPR_P57,		// 57℃对应AD值
    C_AD_TEMPR_P58,		// 58℃对应AD值
    C_AD_TEMPR_P59,		// 59℃对应AD值
    C_AD_TEMPR_P60,		// 60℃对应AD值
	C_AD_TEMPR_P61, 	// 61℃对应AD值
	C_AD_TEMPR_P62, 	// 62℃对应AD值
	C_AD_TEMPR_P63, 	// 63℃对应AD值
	C_AD_TEMPR_P64, 	// 64℃对应AD值
	C_AD_TEMPR_P65, 	// 65℃对应AD值
	C_AD_TEMPR_P66,		// 66℃对应AD值
	C_AD_TEMPR_P67, 	// 67℃对应AD值
	C_AD_TEMPR_P68, 	// 68℃对应AD值
	C_AD_TEMPR_P69, 	// 69℃对应AD值
	C_AD_TEMPR_P70, 	// 70℃对应AD值
	C_AD_TEMPR_P71, 	// 71℃对应AD值
	C_AD_TEMPR_P72, 	// 72℃对应AD值
	C_AD_TEMPR_P73, 	// 73℃对应AD值
	C_AD_TEMPR_P74, 	// 74℃对应AD值
	C_AD_TEMPR_P75, 	// 75℃对应AD值
	C_AD_TEMPR_P76, 	// 76℃对应AD值
	C_AD_TEMPR_P77, 	// 77℃对应AD值
	C_AD_TEMPR_P78, 	// 78℃对应AD值
	C_AD_TEMPR_P79, 	// 79℃对应AD值
	C_AD_TEMPR_P80, 	// 80℃对应AD值
	C_AD_TEMPR_P81, 	// 81℃对应AD值
	C_AD_TEMPR_P82, 	// 82℃对应AD值
	C_AD_TEMPR_P83, 	// 83℃对应AD值
	C_AD_TEMPR_P84,		// 84℃对应AD值
	C_AD_TEMPR_P85, 	// 85℃对应AD值
	C_AD_TEMPR_P86, 	// 86℃对应AD值
	C_AD_TEMPR_P87, 	// 87℃对应AD值
	C_AD_TEMPR_P88, 	// 88℃对应AD值
	C_AD_TEMPR_P89, 	// 89℃对应AD值
	C_AD_TEMPR_P90, 	// 90℃对应AD值
	C_AD_TEMPR_P91, 	// 91℃对应AD值
	C_AD_TEMPR_P92, 	// 92℃对应AD值
	C_AD_TEMPR_P93, 	// 93℃对应AD值
	C_AD_TEMPR_P94, 	// 94℃对应AD值
	C_AD_TEMPR_P95, 	// 95℃对应AD值
	C_AD_TEMPR_P96, 	// 96℃对应AD值
	C_AD_TEMPR_P97, 	// 97℃对应AD值
	C_AD_TEMPR_P98, 	// 98℃对应AD值
	C_AD_TEMPR_P99, 	// 99℃对应AD值
	C_AD_TEMPR_P100,	//100℃对应AD值
	C_AD_TEMPR_P101,	//101℃对应AD值
	C_AD_TEMPR_P102,	//102℃对应AD值
	C_AD_TEMPR_P103,	//103℃对应AD值
	C_AD_TEMPR_P104,	//104℃对应AD值
	C_AD_TEMPR_P105,	//105℃对应AD值
};
#endif

//热敏电阻NTC AD温度对照表(盘管)--移动空调T1,T4也是用此表
const	U16  U16_adc_tempcoil_table[126]__attribute__((at(0x00007880))) =
{
	C_AD_TEMPC_M20,		//-20℃对应AD值
    C_AD_TEMPC_M19,		//-19℃对应AD值
    C_AD_TEMPC_M18,		//-18℃对应AD值	
    C_AD_TEMPC_M17,		//-17℃对应AD值
    C_AD_TEMPC_M16,		//-16℃对应AD值	
    C_AD_TEMPC_M15,		//-15℃对应AD值
    C_AD_TEMPC_M14,		//-14℃对应AD值
    C_AD_TEMPC_M13,		//-13℃对应AD值
    C_AD_TEMPC_M12,		//-12℃对应AD值
    C_AD_TEMPC_M11,		//-11℃对应AD值
    C_AD_TEMPC_M10,		//-10℃对应AD值
    C_AD_TEMPC_M09,		//- 9℃对应AD值
    C_AD_TEMPC_M08,		//- 8℃对应AD值
    C_AD_TEMPC_M07,		//- 7℃对应AD值
    C_AD_TEMPC_M06,		//- 6℃对应AD值
    C_AD_TEMPC_M05,		//- 5℃对应AD值
    C_AD_TEMPC_M04,		//- 4℃对应AD值
    C_AD_TEMPC_M03,		//- 3℃对应AD值
    C_AD_TEMPC_M02,		//- 2℃对应AD值
    C_AD_TEMPC_M01,		//- 1℃对应AD值
    C_AD_TEMPC_P00,		//  0℃对应AD值
    C_AD_TEMPC_P01,		//  1℃对应AD值
    C_AD_TEMPC_P02,		//  2℃对应AD值
    C_AD_TEMPC_P03,		//  3℃对应AD值
    C_AD_TEMPC_P04,		//  4℃对应AD值
    C_AD_TEMPC_P05,		//  5℃对应AD值
    C_AD_TEMPC_P06,		//  6℃对应AD值
    C_AD_TEMPC_P07,		//  7℃对应AD值
    C_AD_TEMPC_P08,		//  8℃对应AD值
    C_AD_TEMPC_P09,		//  9℃对应AD值
    C_AD_TEMPC_P10,		// 10℃对应AD值
    C_AD_TEMPC_P11,		// 11℃对应AD值
    C_AD_TEMPC_P12,		// 12℃对应AD值
    C_AD_TEMPC_P13,		// 13℃对应AD值
    C_AD_TEMPC_P14,		// 14℃对应AD值
    C_AD_TEMPC_P15,		// 15℃对应AD值
    C_AD_TEMPC_P16,		// 16℃对应AD值
    C_AD_TEMPC_P17,		// 17℃对应AD值
    C_AD_TEMPC_P18,		// 18℃对应AD值
    C_AD_TEMPC_P19,		// 19℃对应AD值
    C_AD_TEMPC_P20,		// 20℃对应AD值
    C_AD_TEMPC_P21,		// 21℃对应AD值
    C_AD_TEMPC_P22,		// 22℃对应AD值
    C_AD_TEMPC_P23,		// 23℃对应AD值
    C_AD_TEMPC_P24,		// 24℃对应AD值
    C_AD_TEMPC_P25,		// 25℃对应AD值
    C_AD_TEMPC_P26,		// 26℃对应AD值
    C_AD_TEMPC_P27,		// 27℃对应AD值
    C_AD_TEMPC_P28,		// 28℃对应AD值
    C_AD_TEMPC_P29,		// 29℃对应AD值
    C_AD_TEMPC_P30,		// 30℃对应AD值
    C_AD_TEMPC_P31,		// 31℃对应AD值
    C_AD_TEMPC_P32,		// 32℃对应AD值
    C_AD_TEMPC_P33,		// 33℃对应AD值
    C_AD_TEMPC_P34,		// 34℃对应AD值
    C_AD_TEMPC_P35,		// 35℃对应AD值
    C_AD_TEMPC_P36,		// 36℃对应AD值
    C_AD_TEMPC_P37,		// 37℃对应AD值
    C_AD_TEMPC_P38,		// 38℃对应AD值
    C_AD_TEMPC_P39,		// 39℃对应AD值
    C_AD_TEMPC_P40,		// 40℃对应AD值
    C_AD_TEMPC_P41,		// 41℃对应AD值
    C_AD_TEMPC_P42,		// 42℃对应AD值
    C_AD_TEMPC_P43,		// 43℃对应AD值
    C_AD_TEMPC_P44,		// 44℃对应AD值
    C_AD_TEMPC_P45,		// 45℃对应AD值
    C_AD_TEMPC_P46,		// 46℃对应AD值
    C_AD_TEMPC_P47,		// 47℃对应AD值
    C_AD_TEMPC_P48,		// 48℃对应AD值
    C_AD_TEMPC_P49,		// 49℃对应AD值
    C_AD_TEMPC_P50,		// 50℃对应AD值
    C_AD_TEMPC_P51,		// 51℃对应AD值
    C_AD_TEMPC_P52,		// 52℃对应AD值
    C_AD_TEMPC_P53,		// 53℃对应AD值
    C_AD_TEMPC_P54,		// 54℃对应AD值
    C_AD_TEMPC_P55,		// 55℃对应AD值
    C_AD_TEMPC_P56,		// 56℃对应AD值
    C_AD_TEMPC_P57,		// 57℃对应AD值
    C_AD_TEMPC_P58,		// 58℃对应AD值
    C_AD_TEMPC_P59,		// 59℃对应AD值
    C_AD_TEMPC_P60,		// 60℃对应AD值
	C_AD_TEMPC_P61, 	// 61℃对应AD值
	C_AD_TEMPC_P62, 	// 62℃对应AD值
	C_AD_TEMPC_P63, 	// 63℃对应AD值
	C_AD_TEMPC_P64, 	// 64℃对应AD值
	C_AD_TEMPC_P65, 	// 65℃对应AD值
	C_AD_TEMPC_P66,		// 66℃对应AD值
	C_AD_TEMPC_P67, 	// 67℃对应AD值
	C_AD_TEMPC_P68, 	// 68℃对应AD值
	C_AD_TEMPC_P69, 	// 69℃对应AD值
	C_AD_TEMPC_P70, 	// 70℃对应AD值
	C_AD_TEMPC_P71, 	// 71℃对应AD值
	C_AD_TEMPC_P72, 	// 72℃对应AD值
	C_AD_TEMPC_P73, 	// 73℃对应AD值
	C_AD_TEMPC_P74, 	// 74℃对应AD值
	C_AD_TEMPC_P75, 	// 75℃对应AD值
	C_AD_TEMPC_P76, 	// 76℃对应AD值
	C_AD_TEMPC_P77, 	// 77℃对应AD值
	C_AD_TEMPC_P78, 	// 78℃对应AD值
	C_AD_TEMPC_P79, 	// 79℃对应AD值
	C_AD_TEMPC_P80, 	// 80℃对应AD值
	C_AD_TEMPC_P81, 	// 81℃对应AD值
	C_AD_TEMPC_P82, 	// 82℃对应AD值
	C_AD_TEMPC_P83, 	// 83℃对应AD值
	C_AD_TEMPC_P84,		// 84℃对应AD值
	C_AD_TEMPC_P85, 	// 85℃对应AD值
	C_AD_TEMPC_P86, 	// 86℃对应AD值
	C_AD_TEMPC_P87, 	// 87℃对应AD值
	C_AD_TEMPC_P88, 	// 88℃对应AD值
	C_AD_TEMPC_P89, 	// 89℃对应AD值
	C_AD_TEMPC_P90, 	// 90℃对应AD值
	C_AD_TEMPC_P91, 	// 91℃对应AD值
	C_AD_TEMPC_P92, 	// 92℃对应AD值
	C_AD_TEMPC_P93, 	// 93℃对应AD值
	C_AD_TEMPC_P94, 	// 94℃对应AD值
	C_AD_TEMPC_P95, 	// 95℃对应AD值
	C_AD_TEMPC_P96, 	// 96℃对应AD值
	C_AD_TEMPC_P97, 	// 97℃对应AD值
	C_AD_TEMPC_P98, 	// 98℃对应AD值
	C_AD_TEMPC_P99, 	// 99℃对应AD值
	C_AD_TEMPC_P100,	//100℃对应AD值
	C_AD_TEMPC_P101,	//101℃对应AD值
	C_AD_TEMPC_P102,	//102℃对应AD值
	C_AD_TEMPC_P103,	//103℃对应AD值
	C_AD_TEMPC_P104,	//104℃对应AD值
	C_AD_TEMPC_P105,	//105℃对应AD值
};

//热敏电阻NTC AD温度对照表(排气)
const	U16  U16_adc_tempexhaust_table[136]__attribute__((at(0x00007B00))) =
{
	C_AD_TEMPE_M30,		//-30℃对应AD值    
	C_AD_TEMPE_M29,		//-29℃对应AD值	
	C_AD_TEMPE_M28,		//-28℃对应AD值	
	C_AD_TEMPE_M27,		//-27℃对应AD值	
	C_AD_TEMPE_M26,		//-26℃对应AD值	
	C_AD_TEMPE_M25,		//-25℃对应AD值	
	C_AD_TEMPE_M24,		//-24℃对应AD值	
	C_AD_TEMPE_M23,		//-23℃对应AD值	
	C_AD_TEMPE_M22,		//-22℃对应AD值	
	C_AD_TEMPE_M21,		//-21℃对应AD值		
	C_AD_TEMPE_M20,		//-20℃对应AD值
    C_AD_TEMPE_M19,		//-19℃对应AD值
    C_AD_TEMPE_M18,		//-18℃对应AD值	
    C_AD_TEMPE_M17,		//-17℃对应AD值
    C_AD_TEMPE_M16,		//-16℃对应AD值	
    C_AD_TEMPE_M15,		//-15℃对应AD值
    C_AD_TEMPE_M14,		//-14℃对应AD值
    C_AD_TEMPE_M13,		//-13℃对应AD值
    C_AD_TEMPE_M12,		//-12℃对应AD值
    C_AD_TEMPE_M11,		//-11℃对应AD值
    C_AD_TEMPE_M10,		//-10℃对应AD值
    C_AD_TEMPE_M09,		//- 9℃对应AD值
    C_AD_TEMPE_M08,		//- 8℃对应AD值
    C_AD_TEMPE_M07,		//- 7℃对应AD值
    C_AD_TEMPE_M06,		//- 6℃对应AD值
    C_AD_TEMPE_M05,		//- 5℃对应AD值
    C_AD_TEMPE_M04,		//- 4℃对应AD值
    C_AD_TEMPE_M03,		//- 3℃对应AD值
    C_AD_TEMPE_M02,		//- 2℃对应AD值
    C_AD_TEMPE_M01,		//- 1℃对应AD值
    C_AD_TEMPE_P00,		//  0℃对应AD值
    C_AD_TEMPE_P01,		//  1℃对应AD值
    C_AD_TEMPE_P02,		//  2℃对应AD值
    C_AD_TEMPE_P03,		//  3℃对应AD值
    C_AD_TEMPE_P04,		//  4℃对应AD值
    C_AD_TEMPE_P05,		//  5℃对应AD值
    C_AD_TEMPE_P06,		//  6℃对应AD值
    C_AD_TEMPE_P07,		//  7℃对应AD值
    C_AD_TEMPE_P08,		//  8℃对应AD值
    C_AD_TEMPE_P09,		//  9℃对应AD值
    C_AD_TEMPE_P10,		// 10℃对应AD值
    C_AD_TEMPE_P11,		// 11℃对应AD值
    C_AD_TEMPE_P12,		// 12℃对应AD值
    C_AD_TEMPE_P13,		// 13℃对应AD值
    C_AD_TEMPE_P14,		// 14℃对应AD值
    C_AD_TEMPE_P15,		// 15℃对应AD值
    C_AD_TEMPE_P16,		// 16℃对应AD值
    C_AD_TEMPE_P17,		// 17℃对应AD值
    C_AD_TEMPE_P18,		// 18℃对应AD值
    C_AD_TEMPE_P19,		// 19℃对应AD值
    C_AD_TEMPE_P20,		// 20℃对应AD值
    C_AD_TEMPE_P21,		// 21℃对应AD值
    C_AD_TEMPE_P22,		// 22℃对应AD值
    C_AD_TEMPE_P23,		// 23℃对应AD值
    C_AD_TEMPE_P24,		// 24℃对应AD值
    C_AD_TEMPE_P25,		// 25℃对应AD值
    C_AD_TEMPE_P26,		// 26℃对应AD值
    C_AD_TEMPE_P27,		// 27℃对应AD值
    C_AD_TEMPE_P28,		// 28℃对应AD值
    C_AD_TEMPE_P29,		// 29℃对应AD值
    C_AD_TEMPE_P30,		// 30℃对应AD值
    C_AD_TEMPE_P31,		// 31℃对应AD值
    C_AD_TEMPE_P32,		// 32℃对应AD值
    C_AD_TEMPE_P33,		// 33℃对应AD值
    C_AD_TEMPE_P34,		// 34℃对应AD值
    C_AD_TEMPE_P35,		// 35℃对应AD值
    C_AD_TEMPE_P36,		// 36℃对应AD值
    C_AD_TEMPE_P37,		// 37℃对应AD值
    C_AD_TEMPE_P38,		// 38℃对应AD值
    C_AD_TEMPE_P39,		// 39℃对应AD值
    C_AD_TEMPE_P40,		// 40℃对应AD值
    C_AD_TEMPE_P41,		// 41℃对应AD值
    C_AD_TEMPE_P42,		// 42℃对应AD值
    C_AD_TEMPE_P43,		// 43℃对应AD值
    C_AD_TEMPE_P44,		// 44℃对应AD值
    C_AD_TEMPE_P45,		// 45℃对应AD值
    C_AD_TEMPE_P46,		// 46℃对应AD值
    C_AD_TEMPE_P47,		// 47℃对应AD值
    C_AD_TEMPE_P48,		// 48℃对应AD值
    C_AD_TEMPE_P49,		// 49℃对应AD值
    C_AD_TEMPE_P50,		// 50℃对应AD值
    C_AD_TEMPE_P51,		// 51℃对应AD值
    C_AD_TEMPE_P52,		// 52℃对应AD值
    C_AD_TEMPE_P53,		// 53℃对应AD值
    C_AD_TEMPE_P54,		// 54℃对应AD值
    C_AD_TEMPE_P55,		// 55℃对应AD值
    C_AD_TEMPE_P56,		// 56℃对应AD值
    C_AD_TEMPE_P57,		// 57℃对应AD值
    C_AD_TEMPE_P58,		// 58℃对应AD值
    C_AD_TEMPE_P59,		// 59℃对应AD值
    C_AD_TEMPE_P60,		// 60℃对应AD值
	C_AD_TEMPE_P61, 	// 61℃对应AD值
	C_AD_TEMPE_P62, 	// 62℃对应AD值
	C_AD_TEMPE_P63, 	// 63℃对应AD值
	C_AD_TEMPE_P64, 	// 64℃对应AD值
	C_AD_TEMPE_P65, 	// 65℃对应AD值
	C_AD_TEMPE_P66,		// 66℃对应AD值
	C_AD_TEMPE_P67, 	// 67℃对应AD值
	C_AD_TEMPE_P68, 	// 68℃对应AD值
	C_AD_TEMPE_P69, 	// 69℃对应AD值
	C_AD_TEMPE_P70, 	// 70℃对应AD值
	C_AD_TEMPE_P71, 	// 71℃对应AD值
	C_AD_TEMPE_P72, 	// 72℃对应AD值
	C_AD_TEMPE_P73, 	// 73℃对应AD值
	C_AD_TEMPE_P74, 	// 74℃对应AD值
	C_AD_TEMPE_P75, 	// 75℃对应AD值
	C_AD_TEMPE_P76, 	// 76℃对应AD值
	C_AD_TEMPE_P77, 	// 77℃对应AD值
	C_AD_TEMPE_P78, 	// 78℃对应AD值
	C_AD_TEMPE_P79, 	// 79℃对应AD值
	C_AD_TEMPE_P80, 	// 80℃对应AD值
	C_AD_TEMPE_P81, 	// 81℃对应AD值
	C_AD_TEMPE_P82, 	// 82℃对应AD值
	C_AD_TEMPE_P83, 	// 83℃对应AD值
	C_AD_TEMPE_P84,		// 84℃对应AD值
	C_AD_TEMPE_P85, 	// 85℃对应AD值
	C_AD_TEMPE_P86, 	// 86℃对应AD值
	C_AD_TEMPE_P87, 	// 87℃对应AD值
	C_AD_TEMPE_P88, 	// 88℃对应AD值
	C_AD_TEMPE_P89, 	// 89℃对应AD值
	C_AD_TEMPE_P90, 	// 90℃对应AD值
	C_AD_TEMPE_P91, 	// 91℃对应AD值
	C_AD_TEMPE_P92, 	// 92℃对应AD值
	C_AD_TEMPE_P93, 	// 93℃对应AD值
	C_AD_TEMPE_P94, 	// 94℃对应AD值
	C_AD_TEMPE_P95, 	// 95℃对应AD值
	C_AD_TEMPE_P96, 	// 96℃对应AD值
	C_AD_TEMPE_P97, 	// 97℃对应AD值
	C_AD_TEMPE_P98, 	// 98℃对应AD值
	C_AD_TEMPE_P99, 	// 99℃对应AD值
	C_AD_TEMPE_P100,	//100℃对应AD值
	C_AD_TEMPE_P101,	//101℃对应AD值
	C_AD_TEMPE_P102,	//102℃对应AD值
	C_AD_TEMPE_P103,	//103℃对应AD值
	C_AD_TEMPE_P104,	//104℃对应AD值
	C_AD_TEMPE_P105,	//105℃对应AD值
};

U16  U16_adc_temp_table[156];
U16	U16_ad_value_12bit_resultOK[ENUM_AD_ID_NUM];	//已防抖12bit AD值
U16	U16_adbak_value[ENUM_AD_ID_NUM];				//AD值备份-判断是否有变化
U8	U8_adtemp_value[ENUM_AD_ID_NUM];				//查温度表得出温度临时值
U8	U8_adtemp_dotvalue[ENUM_AD_ID_NUM];				//查温度表得出温度临时值(小数点)
U8	U8_adc_channel;									//AD通道选择读取对应温度

/****************************************************************************************************
Function Name       :U8	App_NTC_Check(U8 channel)
Description         :NTC检测
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
U8	App_NTC_Check(U8 channel)
{
    static	U8 		f_temp[ENUM_AD_ID_NUM];					//各通道传感器故障标志								
    static	U8		U8_ntc_open_cnt[ENUM_AD_ID_NUM];		//各通道传感器开路防抖计数
    static	U8		U8_ntc_short_cnt[ENUM_AD_ID_NUM];		//各通道传感器短路防抖计数
    static	U8		U8_ntc_good_cnt[ENUM_AD_ID_NUM];		//各通道传感器恢复正常防抖计数
	
    if (f_temp[channel] == 0)														//未发生故障
    {
        if (U16_ad_value_12bit_resultOK[channel] > C_FUNC_ADAPP_MAX)					//短路AD接近最大
        {
            U8_ntc_open_cnt[channel] = 0;											//开路防抖清0
    
            if (++U8_ntc_short_cnt[channel] >= C_FUNC_ADAPP_SHORT_DLY)				//短路防抖累加到所需次数
            {
                U8_ntc_short_cnt[channel] = 0;

                f_temp[channel] = 1;
            }
        }
        else if (U16_ad_value_12bit_resultOK[channel] < C_FUNC_ADAPP_MIN)				//开路AD接近最小
        {
            U8_ntc_short_cnt[channel] = 0;										    //短路防抖清0
    
            if (++U8_ntc_open_cnt[channel] >= C_FUNC_ADAPP_OPEN_DLY)			    //开路防抖累加到所需次数
            {
                U8_ntc_open_cnt[channel] = 0;

                f_temp[channel] = 1;
            }
        }	
        else
        {
            U8_ntc_open_cnt[channel] = 0;
            U8_ntc_short_cnt[channel] = 0;
        }					
    }	
    else																			//发生故障
    {
        if ((U16_ad_value_12bit_resultOK[channel] >= (C_FUNC_ADAPP_MIN+C_FUNC_ADAPP_RECOVER_DELTA)) && (U16_ad_value_12bit_resultOK[channel] <= (C_FUNC_ADAPP_MAX-C_FUNC_ADAPP_RECOVER_DELTA)))
        {
            if (++U8_ntc_good_cnt[channel] >= C_FUNC_ADAPP_GOOD_DLY)
            {
                U8_ntc_good_cnt[channel] = 0;
                U8_ntc_open_cnt[channel] = 0;
                U8_ntc_short_cnt[channel] = 0;

                f_temp[channel] = 0;
            }
        }
        else
        {
            U8_ntc_good_cnt[channel] = 0;
        }
    }

    return	f_temp[channel];
}
/****************************************************************************************************
Function Name       :U8	pADC_AdValueDiffer_Check(U8 channel)
Description         :温度变化判断
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
U8	App_AdValueDiffer_Check(U8 channel)
{

    if (U16_adbak_value[channel] == 0)											//起始更新
    {
        U16_adbak_value[channel] = U16_ad_value_12bit_resultOK[channel];
        return 1;
    }
    else if (U16_adbak_value[channel] != U16_ad_value_12bit_resultOK[channel])		//数值发生变化更新
    {
        U16_adbak_value[channel] = U16_ad_value_12bit_resultOK[channel];
        return 1;		
    }

    return 0;																																//都不满足没有更新
}
/****************************************************************************************************
Function Name       :U8	App_ADCGetTemperature(U8 channel, U8 mAD_X_T)
Description         :查表获取温度值
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
U8	App_ADCGetTemperature(U8 channel, U8 u8_pstart)
{
	
	U8   u8_range_max;													//确定查表最底边缘, 常量是表地址的一半
    U8   u8_pointer;													//查表指针
    U16  u16_CurrTmp;													//查表指向当前地址
    U16  u16_NextTmp;													//查表预判下一地址
	U8   u8_DotFM; 											            //计算温度小数点使用的分母
	U16  u16_DotFZ;													    //计算温度小数点使用的分子

	if (channel == C_ADC_TP_CH)
	{
		u8_range_max = u8_pstart + C_ADAPP_TABLEINDEX_HALF;
	}
	else 
	{
		u8_range_max = u8_pstart + C_ADAPP_TABLEINDEX_HALF2;
	}
	
    if (U16_adbak_value[channel] <= U16_adc_temp_table[0]) 			//-最小极限温度先检测出来
    {
        u8_pointer = 0;
    }
//    else if (U16_adbak_value[channel] >= U16_adc_temp_table[C_ADAPP_TABLEINDEX_MAX])		            //-最大极限温度先检测出来
//    {
//        u8_pointer = C_ADAPP_TABLEINDEX_MAX;
//    }
    else if ((U16_adbak_value[channel] >= U16_adc_temp_table[C_ADAPP_TABLEINDEX_MAX])
    		&& (channel == C_ADC_TP_CH))//-最大极限温度先检测出来
    {
        u8_pointer = C_ADAPP_TABLEINDEX_MAX;
    }
    else if ((U16_adbak_value[channel] >= U16_adc_temp_table[C_ADAPP_TABLEINDEX_MAX2])
    		&& (channel != C_ADC_TP_CH))
    {
		u8_pointer = C_ADAPP_TABLEINDEX_MAX2;
    }
    else
    {
        for (u8_pointer=u8_pstart; u8_pointer<u8_range_max; u8_pointer++)
        {
            u16_CurrTmp = U16_adc_temp_table[u8_pointer];
            u16_NextTmp = U16_adc_temp_table[u8_pointer+1];

			
            
            if ((U16_adbak_value[channel] >= u16_CurrTmp) && (U16_adbak_value[channel] < u16_NextTmp))	//如果满足AD值是否满足温度表当前地址和下一地址之间退出for循环
            {
                if (u16_NextTmp > u16_CurrTmp)
				{
					u8_DotFM = u16_NextTmp - u16_CurrTmp;
					u16_DotFZ = U16_adbak_value[channel] - u16_CurrTmp;
					u16_DotFZ <<= 3;
					u16_DotFZ += (U16_adbak_value[channel] - u16_CurrTmp)<<1;	//*10
					U8_adtemp_dotvalue[channel] = u16_DotFZ/u8_DotFM;
					if (U8_adtemp_dotvalue[channel] > 9)
					{
						U8_adtemp_dotvalue[channel] = 9;
					}
				}
				else
				{
					U8_adtemp_dotvalue[channel] = 0;
				}
				
				break;
            }
        }
    }
    //--放到循环外层,当在范围内未找到对应的值,其 u8_range_max 值作为当前温度值.
    return(u8_pointer);	
}
/****************************************************************************************************
Function Name       :void	App_ADCLookupTemperatureTable(U8 channel)
Description         :查表获取温度值
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void	App_ADCLookupTemperatureTable(U8 channel)
{
    U8	u8_AdStartPtr, u8_TempBuffer;

	//根据各通道查找不同的温度表进行温度表映射关系	
	if (channel == C_ADC_TP_CH)		//排气
	{
		memcpy(U16_adc_temp_table, U16_adc_tempexhaust_table, sizeof(U16_adc_tempexhaust_table));
	}
	else if (channel == C_ADC_T1_CH)	//室温
	{
		memcpy(U16_adc_temp_table, U16_adc_temproom_table, sizeof(U16_adc_temproom_table));
	}	
	else					//盘管 
	{
		memcpy(U16_adc_temp_table, U16_adc_tempcoil_table, sizeof(U16_adc_tempcoil_table));
	}
	
    //--在Ad值超出范围情况下不进行查表处理。	
    if((U16_ad_value_12bit_resultOK[channel] >= C_FUNC_ADAPP_MIN) && (U16_ad_value_12bit_resultOK[channel] <= C_FUNC_ADAPP_MAX))
    {

        //--当有Ad值有效同时查询时间到的条件下,进入查询.	
        if (App_AdValueDiffer_Check(channel) == 1)  
        {
            if((U16_adbak_value[channel] >= C_ADAPP_TABLEADVALUE_HALF)			//-AD值常量是表的中间值，采用2分法,提高查表速度;		
				&& (channel == C_ADC_TP_CH))
            {
               	 u8_AdStartPtr = C_ADAPP_TABLEINDEX_HALF;						//常量是表地址的中间值
			}
			else if ((U16_adbak_value[channel] >= C_ADAPP_TABLEADVALUE_HALF2)
			&& (channel != C_ADC_TP_CH))
			{
				u8_AdStartPtr = C_ADAPP_TABLEINDEX_HALF2;						//常量是表地址的中间值
			}
            else
            {
                u8_AdStartPtr = 0;												//0为开头
            }

            u8_TempBuffer = App_ADCGetTemperature(channel, u8_AdStartPtr);		//查温度表得出符合当前AD范围内的地址
            if (u8_TempBuffer != U8_adtemp_value[channel])						//发生变化更新
            {
                U8_adtemp_value[channel] = u8_TempBuffer;						//更新
            }
        }
    }
}
/****************************************************************************************************
Function Name       :void	App_LookUpTemperature(void)
Description         :汇总所有温度查表获取
Input               :
Return              :
Author              :wuhaiming
Version             :V1.0
Revision History   1:
                   2:
****************************************************************************************************/
void	App_LookUpTemperature(void)
{
    volatile U8	temp1; 														//当前通道传感器是否故障
    volatile S8	temp2;														//当前通道传感器温度值
	volatile U8 temp3;														//温度值小数
	
    temp1 = App_NTC_Check(U8_adc_channel);									//检测当前通道NTC故障标志
    App_ADCLookupTemperatureTable(U8_adc_channel);						    //查表
    if (U8_adc_channel == C_ADC_TP_CH)
    {
		temp2 = U8_adtemp_value[U8_adc_channel] + C_ADAPP_TABLEFIRST_TEMP1;		//得出当前通道传感器温度值
    }
    else if (U8_adc_channel == C_ADC_T1_CH)
    {
		temp2 = U8_adtemp_value[U8_adc_channel] + C_ADAPP_TABLEFIRST_TEMP2;		//得出当前通道传感器温度值
    }
    else 
    {
		temp2 = U8_adtemp_value[U8_adc_channel] + C_ADAPP_TABLEFIRST_TEMP2;		//得出当前通道传感器温度值
    }
    temp3 = U8_adtemp_dotvalue[U8_adc_channel];
	
    if (U8_adc_channel == C_ADC_TP_CH)	//TP									//第0个打开的AD通道
    {
		Tp.f_Error = temp1;
		
		if (temp1 == 0)
		{
			Tp.s8_ValueRead = temp2;
			Tp.u8_ValueDotRead = temp3;
		}		
    }
//    else if (U8_adc_channel == C_ADC_T4_CH)  //T4									//第1个打开的AD通道
//    {
//		T4.f_Error = temp1;
//		
//		if (temp1 == 0)
//		{
//			T4.s8_ValueRead = temp2;
//			T4.u8_ValueDotRead = temp3;
//		}		
//    }
    else if (U8_adc_channel == C_ADC_T3_CH)  //T3	
	{
		T3.f_Error = temp1;
		
		if (temp1 == 0)
		{
			T3.s8_ValueRead = temp2;
			T3.u8_ValueDotRead = temp3;
		} 
	}
	else if (U8_adc_channel == C_ADC_T1_CH)	//T1
	{
		T1.f_Error = temp1;
		
		if (temp1 == 0)
		{
			T1.s8_ValueRead = temp2;
			T1.u8_ValueDotRead = temp3;
		}	

		T4.f_Error = T1.f_Error;
		
		if (temp1 == 0)
		{
			T4.s8_ValueRead = T1.s8_ValueRead - 2;		//比T1少2℃
			T4.u8_ValueDotRead = T1.u8_ValueDotRead;
		}
	}
	else if (U8_adc_channel == C_ADC_T2_CH)	//T2
	{
		T2.f_Error = temp1;
		
		if (temp1 == 0)
		{
			T2.s8_ValueRead = temp2;
			T2.u8_ValueDotRead = temp3;
		}	
	}	
    
    if (++U8_adc_channel >= ENUM_AD_ID_NUM)
    {
        U8_adc_channel = 0;
//		F_humi_tempok = 1;													//温度平均值计算完成(具备计算湿度条件,没有湿度检测请屏蔽)
    }
}
