/*===================================================================================================
                		Copyright(C) 2011-2099.  SunRam. Co., Ltd.
-----------------------------------------------------------------------------------------------------
Project Name  		: Ad_app.h
Description   		: H
Author        		: Wuhaiming
Start Date    		: 2022/04/25
Version       		: V1.0
Revision History   1:
                   2:
===================================================================================================*/ 
#ifndef			_AD_APP_H_

#define			_AD_APP_H_

//--------------------------温度AD异常恢复相关参数----------------------------//
#define			C_FUNC_ADAPP_MIN					15					//AD采样电压小于0.05V-开路
#define			C_FUNC_ADAPP_MAX					4055				//AD采样电压大于4.95V-短路
#define			C_FUNC_ADAPP_RECOVER_DELTA		    20					//故障恢复需要AD间隔值
#define			C_FUNC_ADAPP_OPEN_DLY				1					//开路防抖1次
#define			C_FUNC_ADAPP_SHORT_DLY				1					//开路防抖1次
#define			C_FUNC_ADAPP_GOOD_DLY				5					//故障恢复防抖5次
//----------------------------------------------------------------------------//

//--------------------------温度AD值表信息参数--------------------------------//
#define			C_ADAPP_TABLEFIRST_TEMP1			-30												//表头AD值对应温度值
#define			C_ADAPP_TABLEFIRST_TEMP2			-20												//表头AD值对应温度值
#define			C_ADAPP_TABLEINDEX_NUM1				136												//温度表AD值成员个数
#define			C_ADAPP_TABLEINDEX_HALF1			(C_ADAPP_TABLEINDEX_NUM1>>1)						//温度表中间(查表二分法)	
#define			C_ADAPP_TABLEINDEX_MAX1				(C_ADAPP_TABLEINDEX_NUM1-1)						//温度表AD值成员个数
#define			C_ADAPP_TABLEADVALUE_HALF1			U16_adc_temp_table[C_ADAPP_TABLEINDEX_HALF1]		//温度表中间处的AD值
#define			C_ADAPP_TABLEINDEX_NUM2				126												//温度表AD值成员个数
#define			C_ADAPP_TABLEINDEX_HALF2			(C_ADAPP_TABLEINDEX_NUM2>>1)						//温度表中间(查表二分法)	
#define			C_ADAPP_TABLEINDEX_MAX2				(C_ADAPP_TABLEINDEX_NUM2-1)						//温度表AD值成员个数
#define			C_ADAPP_TABLEADVALUE_HALF2			U16_adc_temp_table[C_ADAPP_TABLEINDEX_HALF2]		//温度表中间处的AD值
#define			C_ADAPP_TABLEINDEX_NUM				136												//温度表AD值成员个数
#define			C_ADAPP_TABLEINDEX_HALF				(C_ADAPP_TABLEINDEX_NUM>>1)						//温度表中间(查表二分法)	
#define			C_ADAPP_TABLEINDEX_MAX				(C_ADAPP_TABLEINDEX_NUM-1)						//温度表AD值成员个数
#define			C_ADAPP_TABLEADVALUE_HALF			U16_adc_temp_table[C_ADAPP_TABLEINDEX_HALF]		//温度表中间处的AD值

//----------------------------------------------------------------------------//
//室内温度
#if 1	//创维
//				宏定义					AD				温度
#define		C_AD_TEMPR_M20			386 		//-20℃对应AD值
#define		C_AD_TEMPR_M19			407 		//-19℃对应AD值
#define		C_AD_TEMPR_M18			428 		//-18℃对应AD值
#define		C_AD_TEMPR_M17			450 		//-17℃对应AD值
#define		C_AD_TEMPR_M16			473 		//-16℃对应AD值
#define		C_AD_TEMPR_M15			497 		//-15℃对应AD值
#define		C_AD_TEMPR_M14			521 		//-14℃对应AD值
#define		C_AD_TEMPR_M13			547 		//-13℃对应AD值
#define		C_AD_TEMPR_M12			573 		//-12℃对应AD值
#define		C_AD_TEMPR_M11			601 		//-11℃对应AD值
#define		C_AD_TEMPR_M10			629 		//-10℃对应AD值
#define		C_AD_TEMPR_M09			658 		//-9℃对应AD值
#define		C_AD_TEMPR_M08			688 		//-8℃对应AD值
#define		C_AD_TEMPR_M07			719 		//-7℃对应AD值
#define		C_AD_TEMPR_M06			751 		//-6℃对应AD值
#define		C_AD_TEMPR_M05			783 		//-5℃对应AD值
#define		C_AD_TEMPR_M04			817 		//-4℃对应AD值
#define		C_AD_TEMPR_M03			851 		//-3℃对应AD值
#define		C_AD_TEMPR_M02			887 		//-2℃对应AD值
#define		C_AD_TEMPR_M01			923 		//-1℃对应AD值
#define		C_AD_TEMPR_P00			960 		//0℃对应AD值
#define		C_AD_TEMPR_P01			997 		//1℃对应AD值
#define		C_AD_TEMPR_P02			1036 		//2℃对应AD值
#define		C_AD_TEMPR_P03			1075 		//3℃对应AD值
#define		C_AD_TEMPR_P04			1115 		//4℃对应AD值
#define		C_AD_TEMPR_P05			1156 		//5℃对应AD值
#define		C_AD_TEMPR_P06			1197 		//6℃对应AD值
#define		C_AD_TEMPR_P07			1239 		//7℃对应AD值
#define		C_AD_TEMPR_P08			1282 		//8℃对应AD值
#define		C_AD_TEMPR_P09			1325 		//9℃对应AD值
#define		C_AD_TEMPR_P10			1368 		//10℃对应AD值
#define		C_AD_TEMPR_P11			1412 		//11℃对应AD值
#define		C_AD_TEMPR_P12			1456 		//12℃对应AD值
#define		C_AD_TEMPR_P13			1501 		//13℃对应AD值
#define		C_AD_TEMPR_P14			1546 		//14℃对应AD值
#define		C_AD_TEMPR_P15			1592 		//15℃对应AD值
#define		C_AD_TEMPR_P16			1637 		//16℃对应AD值
#define		C_AD_TEMPR_P17			1683 		//17℃对应AD值
#define		C_AD_TEMPR_P18			1728 		//18℃对应AD值
#define		C_AD_TEMPR_P19			1774 		//19℃对应AD值
#define		C_AD_TEMPR_P20			1820 		//20℃对应AD值
#define		C_AD_TEMPR_P21			1866 		//21℃对应AD值
#define		C_AD_TEMPR_P22			1912 		//22℃对应AD值
#define		C_AD_TEMPR_P23			1957 		//23℃对应AD值
#define		C_AD_TEMPR_P24			2003 		//24℃对应AD值
#define		C_AD_TEMPR_P25			2048 		//25℃对应AD值
#define		C_AD_TEMPR_P26			2093 		//26℃对应AD值
#define		C_AD_TEMPR_P27			2138 		//27℃对应AD值
#define		C_AD_TEMPR_P28			2182 		//28℃对应AD值
#define		C_AD_TEMPR_P29			2226 		//29℃对应AD值
#define		C_AD_TEMPR_P30			2269 		//30℃对应AD值
#define		C_AD_TEMPR_P31			2312 		//31℃对应AD值
#define		C_AD_TEMPR_P32			2355 		//32℃对应AD值
#define		C_AD_TEMPR_P33			2397 		//33℃对应AD值
#define		C_AD_TEMPR_P34			2439 		//34℃对应AD值
#define		C_AD_TEMPR_P35			2480 		//35℃对应AD值
#define		C_AD_TEMPR_P36			2520 		//36℃对应AD值
#define		C_AD_TEMPR_P37			2560 		//37℃对应AD值
#define		C_AD_TEMPR_P38			2599 		//38℃对应AD值
#define		C_AD_TEMPR_P39			2637 		//39℃对应AD值
#define		C_AD_TEMPR_P40			2675 		//40℃对应AD值
#define		C_AD_TEMPR_P41			2712 		//41℃对应AD值
#define		C_AD_TEMPR_P42			2749 		//42℃对应AD值
#define		C_AD_TEMPR_P43			2785 		//43℃对应AD值
#define		C_AD_TEMPR_P44			2820 		//44℃对应AD值
#define		C_AD_TEMPR_P45			2854 		//45℃对应AD值
#define		C_AD_TEMPR_P46			2887 		//46℃对应AD值
#define		C_AD_TEMPR_P47			2920 		//47℃对应AD值
#define		C_AD_TEMPR_P48			2953 		//48℃对应AD值
#define		C_AD_TEMPR_P49			2984 		//49℃对应AD值
#define		C_AD_TEMPR_P50			3015 		//50℃对应AD值
#define		C_AD_TEMPR_P51			3045 		//51℃对应AD值
#define		C_AD_TEMPR_P52			3074 		//52℃对应AD值
#define		C_AD_TEMPR_P53			3103 		//53℃对应AD值
#define		C_AD_TEMPR_P54			3131 		//54℃对应AD值
#define		C_AD_TEMPR_P55			3158 		//55℃对应AD值
#define		C_AD_TEMPR_P56			3184 		//56℃对应AD值
#define		C_AD_TEMPR_P57			3210 		//57℃对应AD值
#define		C_AD_TEMPR_P58			3235 		//58℃对应AD值
#define		C_AD_TEMPR_P59			3260 		//59℃对应AD值
#define		C_AD_TEMPR_P60			3284 		//60℃对应AD值
#define		C_AD_TEMPR_P61			3307 		//61℃对应AD值
#define		C_AD_TEMPR_P62			3329 		//62℃对应AD值
#define		C_AD_TEMPR_P63			3351 		//63℃对应AD值
#define		C_AD_TEMPR_P64			3373 		//64℃对应AD值
#define		C_AD_TEMPR_P65			3394 		//65℃对应AD值
#define		C_AD_TEMPR_P66			3414 		//66℃对应AD值
#define		C_AD_TEMPR_P67			3433 		//67℃对应AD值
#define		C_AD_TEMPR_P68			3452 		//68℃对应AD值
#define		C_AD_TEMPR_P69			3471 		//69℃对应AD值
#define		C_AD_TEMPR_P70			3489 		//70℃对应AD值
#define		C_AD_TEMPR_P71			3506 		//71℃对应AD值
#define		C_AD_TEMPR_P72			3523 		//72℃对应AD值
#define		C_AD_TEMPR_P73			3540 		//73℃对应AD值
#define		C_AD_TEMPR_P74			3556 		//74℃对应AD值
#define		C_AD_TEMPR_P75			3571 		//75℃对应AD值
#define		C_AD_TEMPR_P76			3586 		//76℃对应AD值
#define		C_AD_TEMPR_P77			3601 		//77℃对应AD值
#define		C_AD_TEMPR_P78			3615 		//78℃对应AD值
#define		C_AD_TEMPR_P79			3629 		//79℃对应AD值
#define		C_AD_TEMPR_P80			3642 		//80℃对应AD值
#define		C_AD_TEMPR_P81			3655 		//81℃对应AD值
#define		C_AD_TEMPR_P82			3667 		//82℃对应AD值
#define		C_AD_TEMPR_P83			3679 		//83℃对应AD值
#define		C_AD_TEMPR_P84			3691 		//84℃对应AD值
#define		C_AD_TEMPR_P85			3703 		//85℃对应AD值
#define		C_AD_TEMPR_P86			3714 		//86℃对应AD值
#define		C_AD_TEMPR_P87			3724 		//87℃对应AD值
#define		C_AD_TEMPR_P88			3735 		//88℃对应AD值
#define		C_AD_TEMPR_P89			3745 		//89℃对应AD值
#define		C_AD_TEMPR_P90			3755 		//90℃对应AD值
#define		C_AD_TEMPR_P91			3764 		//91℃对应AD值
#define		C_AD_TEMPR_P92			3773 		//92℃对应AD值
#define		C_AD_TEMPR_P93			3782 		//93℃对应AD值
#define		C_AD_TEMPR_P94			3791 		//94℃对应AD值
#define		C_AD_TEMPR_P95			3799 		//95℃对应AD值
#define		C_AD_TEMPR_P96			3807 		//96℃对应AD值
#define		C_AD_TEMPR_P97			3815 		//97℃对应AD值
#define		C_AD_TEMPR_P98			3823 		//98℃对应AD值
#define		C_AD_TEMPR_P99			3830 		//99℃对应AD值
#define		C_AD_TEMPR_P100			3838 		//100℃对应AD值
#define		C_AD_TEMPR_P101			3845 		//101℃对应AD值
#define		C_AD_TEMPR_P102			3852 		//102℃对应AD值
#define		C_AD_TEMPR_P103			3858 		//103℃对应AD值
#define		C_AD_TEMPR_P104			3864 		//104℃对应AD值
#define		C_AD_TEMPR_P105			3871 		//105℃对应AD值
#else 	//德龙
//				宏定义					AD				温度
#define			C_AD_TEMPR_M30			271 			//-30℃对应AD值
#define			C_AD_TEMPR_M29       	285 			//-29℃对应AD值
#define			C_AD_TEMPR_M28       	299 			//-28℃对应AD值
#define			C_AD_TEMPR_M27			314 			//-27℃对应AD值
#define			C_AD_TEMPR_M26       	329 			//-26℃对应AD值
#define			C_AD_TEMPR_M25       	345 			//-25℃对应AD值
#define			C_AD_TEMPR_M24       	362 			//-24℃对应AD值
#define			C_AD_TEMPR_M23       	379 			//-23℃对应AD值
#define			C_AD_TEMPR_M22       	397 			//-22℃对应AD值
#define			C_AD_TEMPR_M21       	415 			//-21℃对应AD值
#define			C_AD_TEMPR_M20			434 			//-20℃对应AD值
#define			C_AD_TEMPR_M19			454 			//-19℃对应AD值
#define			C_AD_TEMPR_M18			474 			//-18℃对应AD值	
#define			C_AD_TEMPR_M17			495 			//-17℃对应AD值
#define			C_AD_TEMPR_M16			517 			//-16℃对应AD值	
#define			C_AD_TEMPR_M15			539 			//-15℃对应AD值
#define			C_AD_TEMPR_M14			562 			//-14℃对应AD值
#define			C_AD_TEMPR_M13			585 			//-13℃对应AD值
#define			C_AD_TEMPR_M12			610 			//-12℃对应AD值
#define			C_AD_TEMPR_M11			635 			//-11℃对应AD值
#define			C_AD_TEMPR_M10			660 			//-10℃对应AD值
#define			C_AD_TEMPR_M09			687 			//- 9℃对应AD值
#define			C_AD_TEMPR_M08			714 			//- 8℃对应AD值
#define			C_AD_TEMPR_M07			741 			//- 7℃对应AD值
#define			C_AD_TEMPR_M06			770 			//- 6℃对应AD值
#define			C_AD_TEMPR_M05			799 			//- 5℃对应AD值
#define			C_AD_TEMPR_M04			828 			//- 4℃对应AD值
#define			C_AD_TEMPR_M03			859 			//- 3℃对应AD值
#define			C_AD_TEMPR_M02			890 			//- 2℃对应AD值
#define			C_AD_TEMPR_M01			921 			//- 1℃对应AD值
#define			C_AD_TEMPR_P00			953 			//  0℃对应AD值
#define			C_AD_TEMPR_P01			987 			//  1℃对应AD值
#define			C_AD_TEMPR_P02			1020			//  2℃对应AD值
#define			C_AD_TEMPR_P03			1055			//  3℃对应AD值
#define			C_AD_TEMPR_P04			1090			//  4℃对应AD值
#define			C_AD_TEMPR_P05			1125			//  5℃对应AD值
#define			C_AD_TEMPR_P06			1161			//  6℃对应AD值
#define			C_AD_TEMPR_P07			1197			//  7℃对应AD值
#define			C_AD_TEMPR_P08			1234			//  8℃对应AD值
#define			C_AD_TEMPR_P09			1271			//  9℃对应AD值
#define			C_AD_TEMPR_P10			1308			// 10℃对应AD值
#define			C_AD_TEMPR_P11			1346			// 11℃对应AD值
#define			C_AD_TEMPR_P12			1384			// 12℃对应AD值
#define			C_AD_TEMPR_P13			1422			// 13℃对应AD值
#define			C_AD_TEMPR_P14			1461    		// 14℃对应AD值
#define			C_AD_TEMPR_P15			1500    		// 15℃对应AD值
#define			C_AD_TEMPR_P16			1539    		// 16℃对应AD值
#define			C_AD_TEMPR_P17			1578    		// 17℃对应AD值
#define			C_AD_TEMPR_P18			1618    		// 18℃对应AD值
#define			C_AD_TEMPR_P19			1657    		// 19℃对应AD值
#define			C_AD_TEMPR_P20			1696    		// 20℃对应AD值	
#define			C_AD_TEMPR_P21			1736    		// 21℃对应AD值
#define			C_AD_TEMPR_P22			1776    		// 22℃对应AD值
#define			C_AD_TEMPR_P23			1815    		// 23℃对应AD值
#define			C_AD_TEMPR_P24			1854    		// 24℃对应AD值
#define			C_AD_TEMPR_P25			1894    		// 25℃对应AD值
#define			C_AD_TEMPR_P26			1933    		// 26℃对应AD值
#define			C_AD_TEMPR_P27			1972    		// 27℃对应AD值
#define			C_AD_TEMPR_P28			2011    		// 28℃对应AD值
#define			C_AD_TEMPR_P29			2050    		// 29℃对应AD值
#define			C_AD_TEMPR_P30			2088    		// 30℃对应AD值
#define			C_AD_TEMPR_P31			2127    		// 31℃对应AD值
#define			C_AD_TEMPR_P32			2165    		// 32℃对应AD值
#define			C_AD_TEMPR_P33			2202    		// 33℃对应AD值
#define			C_AD_TEMPR_P34			2240    		// 34℃对应AD值
#define			C_AD_TEMPR_P35			2277    		// 35℃对应AD值
#define			C_AD_TEMPR_P36			2314    		// 36℃对应AD值
#define			C_AD_TEMPR_P37			2350    		// 37℃对应AD值
#define			C_AD_TEMPR_P38			2386    		// 38℃对应AD值
#define			C_AD_TEMPR_P39			2421    		// 39℃对应AD值
#define			C_AD_TEMPR_P40			2456    		// 40℃对应AD值
#define			C_AD_TEMPR_P41			2491    		// 41℃对应AD值
#define			C_AD_TEMPR_P42			2525    		// 42℃对应AD值
#define			C_AD_TEMPR_P43			2559    		// 43℃对应AD值
#define			C_AD_TEMPR_P44			2592    		// 44℃对应AD值
#define			C_AD_TEMPR_P45			2625    		// 45℃对应AD值
#define			C_AD_TEMPR_P46			2657    		// 46℃对应AD值
#define			C_AD_TEMPR_P47			2689    		// 47℃对应AD值
#define			C_AD_TEMPR_P48			2720    		// 48℃对应AD值		---表中间AD值
#define			C_AD_TEMPR_P49			2751    		// 49℃对应AD值
#define			C_AD_TEMPR_P50			2782    		// 50℃对应AD值
#define			C_AD_TEMPR_P51			2812    		// 51℃对应AD值
#define			C_AD_TEMPR_P52			2842    		// 52℃对应AD值
#define			C_AD_TEMPR_P53			2872    		// 53℃对应AD值
#define			C_AD_TEMPR_P54			2901    		// 54℃对应AD值
#define			C_AD_TEMPR_P55			2929    		// 55℃对应AD值
#define			C_AD_TEMPR_P56			2958    		// 56℃对应AD值
#define			C_AD_TEMPR_P57			2985    		// 57℃对应AD值
#define			C_AD_TEMPR_P58			3012    		// 58℃对应AD值
#define			C_AD_TEMPR_P59			3039    		// 59℃对应AD值
#define			C_AD_TEMPR_P60			3065    		// 60℃对应AD值
#define			C_AD_TEMPR_P61       	3090			// 61℃对应AD值
#define			C_AD_TEMPR_P62       	3115			// 62℃对应AD值
#define			C_AD_TEMPR_P63       	3140			// 63℃对应AD值
#define			C_AD_TEMPR_P64       	3164			// 64℃对应AD值
#define			C_AD_TEMPR_P65       	3188			// 65℃对应AD值
#define			C_AD_TEMPR_P66			3211			// 66℃对应AD值
#define			C_AD_TEMPR_P67       	3233			// 67℃对应AD值
#define			C_AD_TEMPR_P68       	3255			// 68℃对应AD值
#define			C_AD_TEMPR_P69       	3277			// 69℃对应AD值
#define			C_AD_TEMPR_P70       	3298			// 70℃对应AD值
#define			C_AD_TEMPR_P71       	3319			// 71℃对应AD值
#define			C_AD_TEMPR_P72       	3339			// 72℃对应AD值
#define			C_AD_TEMPR_P73       	3359			// 73℃对应AD值
#define			C_AD_TEMPR_P74       	3378			// 74℃对应AD值
#define			C_AD_TEMPR_P75       	3397			// 75℃对应AD值
#define			C_AD_TEMPR_P76       	3415			// 76℃对应AD值
#define			C_AD_TEMPR_P77       	3433			// 77℃对应AD值
#define			C_AD_TEMPR_P78       	3450			// 78℃对应AD值
#define			C_AD_TEMPR_P79       	3467			// 79℃对应AD值
#define			C_AD_TEMPR_P80       	3484			// 80℃对应AD值
#define			C_AD_TEMPR_P81       	3499			// 81℃对应AD值
#define			C_AD_TEMPR_P82       	3514			// 82℃对应AD值
#define			C_AD_TEMPR_P83       	3529			// 83℃对应AD值
#define			C_AD_TEMPR_P84			3543			// 84℃对应AD值
#define			C_AD_TEMPR_P85       	3557			// 85℃对应AD值
#define			C_AD_TEMPR_P86       	3571			// 86℃对应AD值
#define			C_AD_TEMPR_P87       	3584			// 87℃对应AD值
#define			C_AD_TEMPR_P88       	3597			// 88℃对应AD值
#define			C_AD_TEMPR_P89       	3609			// 89℃对应AD值
#define			C_AD_TEMPR_P90       	3622			// 90℃对应AD值
#define			C_AD_TEMPR_P91       	3634			// 91℃对应AD值
#define			C_AD_TEMPR_P92       	3645			// 92℃对应AD值
#define			C_AD_TEMPR_P93       	3656			// 93℃对应AD值
#define			C_AD_TEMPR_P94       	3667			// 94℃对应AD值
#define			C_AD_TEMPR_P95       	3678			// 95℃对应AD值
#define			C_AD_TEMPR_P96       	3688			// 96℃对应AD值
#define			C_AD_TEMPR_P97       	3699			// 97℃对应AD值
#define			C_AD_TEMPR_P98       	3708			// 98℃对应AD值
#define			C_AD_TEMPR_P99       	3718			// 99℃对应AD值
#define			C_AD_TEMPR_P100      	3727			// 100℃对应AD值
#define			C_AD_TEMPR_P101      	3736			// 101℃对应AD值
#define			C_AD_TEMPR_P102      	3745			// 102℃对应AD值
#define			C_AD_TEMPR_P103      	3754			// 103℃对应AD值
#define			C_AD_TEMPR_P104      	3762			// 104℃对应AD值
#define			C_AD_TEMPR_P105      	3770			// 105℃对应AD值
#define			C_AD_TEMPR_P106      	3778			// 106℃对应AD值
#define			C_AD_TEMPR_P107      	3786			// 107℃对应AD值
#define			C_AD_TEMPR_P108      	3793			// 108℃对应AD值
#define			C_AD_TEMPR_P109      	3800			// 109℃对应AD值
#define			C_AD_TEMPR_P110      	3807			// 110℃对应AD值
#define			C_AD_TEMPR_P111      	3814			// 111℃对应AD值
#define			C_AD_TEMPR_P112      	3821			// 112℃对应AD值
#define			C_AD_TEMPR_P113      	3827			// 113℃对应AD值
#define			C_AD_TEMPR_P114			3834			// 114℃对应AD值
#define			C_AD_TEMPR_P115      	3840			// 115℃对应AD值
#define			C_AD_TEMPR_P116      	3846			// 116℃对应AD值
#define			C_AD_TEMPR_P117      	3852			// 117℃对应AD值
#define			C_AD_TEMPR_P118      	3857			// 118℃对应AD值
#define			C_AD_TEMPR_P119      	3863			// 119℃对应AD值
#define			C_AD_TEMPR_P120      	3868			// 120℃对应AD值
#define			C_AD_TEMPR_P121      	3874			// 121℃对应AD值
#define			C_AD_TEMPR_P122      	3879			// 122℃对应AD值
#define			C_AD_TEMPR_P123      	3884			// 123℃对应AD值
#define			C_AD_TEMPR_P124      	3889			// 124℃对应AD值
#define			C_AD_TEMPR_P125      	3893			// 125℃对应AD值
#endif 
//----------------------------------------------------------------------------//
//盘管温度
#if 1 //创维
//			宏定义						AD			温度
#define		C_AD_TEMPC_M20			386 		//-20℃对应AD值
#define		C_AD_TEMPC_M19			407 		//-19℃对应AD值
#define		C_AD_TEMPC_M18			428 		//-18℃对应AD值
#define		C_AD_TEMPC_M17			450 		//-17℃对应AD值
#define		C_AD_TEMPC_M16			473 		//-16℃对应AD值
#define		C_AD_TEMPC_M15			497 		//-15℃对应AD值
#define		C_AD_TEMPC_M14			521 		//-14℃对应AD值
#define		C_AD_TEMPC_M13			547 		//-13℃对应AD值
#define		C_AD_TEMPC_M12			573 		//-12℃对应AD值
#define		C_AD_TEMPC_M11			601 		//-11℃对应AD值
#define		C_AD_TEMPC_M10			629 		//-10℃对应AD值
#define		C_AD_TEMPC_M09			658 		//-9℃对应AD值
#define		C_AD_TEMPC_M08			688 		//-8℃对应AD值
#define		C_AD_TEMPC_M07			719 		//-7℃对应AD值
#define		C_AD_TEMPC_M06			750 		//-6℃对应AD值
#define		C_AD_TEMPC_M05			783 		//-5℃对应AD值
#define		C_AD_TEMPC_M04			817 		//-4℃对应AD值
#define		C_AD_TEMPC_M03			851 		//-3℃对应AD值
#define		C_AD_TEMPC_M02			887 		//-2℃对应AD值
#define		C_AD_TEMPC_M01			923 		//-1℃对应AD值
#define		C_AD_TEMPC_P00			960 		//0℃对应AD值
#define		C_AD_TEMPC_P01			997 		//1℃对应AD值
#define		C_AD_TEMPC_P02			1036 		//2℃对应AD值
#define		C_AD_TEMPC_P03			1075 		//3℃对应AD值
#define		C_AD_TEMPC_P04			1115 		//4℃对应AD值
#define		C_AD_TEMPC_P05			1156 		//5℃对应AD值
#define		C_AD_TEMPC_P06			1197 		//6℃对应AD值
#define		C_AD_TEMPC_P07			1239 		//7℃对应AD值
#define		C_AD_TEMPC_P08			1282 		//8℃对应AD值
#define		C_AD_TEMPC_P09			1325 		//9℃对应AD值
#define		C_AD_TEMPC_P10			1368 		//10℃对应AD值
#define		C_AD_TEMPC_P11			1412 		//11℃对应AD值
#define		C_AD_TEMPC_P12			1456 		//12℃对应AD值
#define		C_AD_TEMPC_P13			1501 		//13℃对应AD值
#define		C_AD_TEMPC_P14			1546 		//14℃对应AD值
#define		C_AD_TEMPC_P15			1591 		//15℃对应AD值
#define		C_AD_TEMPC_P16			1637 		//16℃对应AD值
#define		C_AD_TEMPC_P17			1683 		//17℃对应AD值
#define		C_AD_TEMPC_P18			1728 		//18℃对应AD值
#define		C_AD_TEMPC_P19			1774 		//19℃对应AD值
#define		C_AD_TEMPC_P20			1820 		//20℃对应AD值
#define		C_AD_TEMPC_P21			1866 		//21℃对应AD值
#define		C_AD_TEMPC_P22			1912 		//22℃对应AD值
#define		C_AD_TEMPC_P23			1957 		//23℃对应AD值
#define		C_AD_TEMPC_P24			2003 		//24℃对应AD值
#define		C_AD_TEMPC_P25			2048 		//25℃对应AD值
#define		C_AD_TEMPC_P26			2093 		//26℃对应AD值
#define		C_AD_TEMPC_P27			2138 		//27℃对应AD值
#define		C_AD_TEMPC_P28			2182 		//28℃对应AD值
#define		C_AD_TEMPC_P29			2226 		//29℃对应AD值
#define		C_AD_TEMPC_P30			2269 		//30℃对应AD值
#define		C_AD_TEMPC_P31			2312 		//31℃对应AD值
#define		C_AD_TEMPC_P32			2355 		//32℃对应AD值
#define		C_AD_TEMPC_P33			2397 		//33℃对应AD值
#define		C_AD_TEMPC_P34			2439 		//34℃对应AD值
#define		C_AD_TEMPC_P35			2480 		//35℃对应AD值
#define		C_AD_TEMPC_P36			2520 		//36℃对应AD值
#define		C_AD_TEMPC_P37			2560 		//37℃对应AD值
#define		C_AD_TEMPC_P38			2599 		//38℃对应AD值
#define		C_AD_TEMPC_P39			2637 		//39℃对应AD值
#define		C_AD_TEMPC_P40			2675 		//40℃对应AD值
#define		C_AD_TEMPC_P41			2712 		//41℃对应AD值
#define		C_AD_TEMPC_P42			2749 		//42℃对应AD值
#define		C_AD_TEMPC_P43			2785 		//43℃对应AD值
#define		C_AD_TEMPC_P44			2820 		//44℃对应AD值
#define		C_AD_TEMPC_P45			2854 		//45℃对应AD值
#define		C_AD_TEMPC_P46			2887 		//46℃对应AD值
#define		C_AD_TEMPC_P47			2920 		//47℃对应AD值
#define		C_AD_TEMPC_P48			2953 		//48℃对应AD值
#define		C_AD_TEMPC_P49			2984 		//49℃对应AD值
#define		C_AD_TEMPC_P50			3015 		//50℃对应AD值
#define		C_AD_TEMPC_P51			3045 		//51℃对应AD值
#define		C_AD_TEMPC_P52			3074 		//52℃对应AD值
#define		C_AD_TEMPC_P53			3103 		//53℃对应AD值
#define		C_AD_TEMPC_P54			3131 		//54℃对应AD值
#define		C_AD_TEMPC_P55			3158 		//55℃对应AD值
#define		C_AD_TEMPC_P56			3184 		//56℃对应AD值
#define		C_AD_TEMPC_P57			3210 		//57℃对应AD值
#define		C_AD_TEMPC_P58			3235 		//58℃对应AD值
#define		C_AD_TEMPC_P59			3260 		//59℃对应AD值
#define		C_AD_TEMPC_P60			3284 		//60℃对应AD值
#define		C_AD_TEMPC_P61			3307 		//61℃对应AD值
#define		C_AD_TEMPC_P62			3329 		//62℃对应AD值
#define		C_AD_TEMPC_P63			3351 		//63℃对应AD值
#define		C_AD_TEMPC_P64			3373 		//64℃对应AD值
#define		C_AD_TEMPC_P65			3394 		//65℃对应AD值
#define		C_AD_TEMPC_P66			3414 		//66℃对应AD值
#define		C_AD_TEMPC_P67			3433 		//67℃对应AD值
#define		C_AD_TEMPC_P68			3452 		//68℃对应AD值
#define		C_AD_TEMPC_P69			3471 		//69℃对应AD值
#define		C_AD_TEMPC_P70			3489 		//70℃对应AD值
#define		C_AD_TEMPC_P71			3506 		//71℃对应AD值
#define		C_AD_TEMPC_P72			3523 		//72℃对应AD值
#define		C_AD_TEMPC_P73			3540 		//73℃对应AD值
#define		C_AD_TEMPC_P74			3556 		//74℃对应AD值
#define		C_AD_TEMPC_P75			3571 		//75℃对应AD值
#define		C_AD_TEMPC_P76			3586 		//76℃对应AD值
#define		C_AD_TEMPC_P77			3601 		//77℃对应AD值
#define		C_AD_TEMPC_P78			3615 		//78℃对应AD值
#define		C_AD_TEMPC_P79			3628 		//79℃对应AD值
#define		C_AD_TEMPC_P80			3642 		//80℃对应AD值
#define		C_AD_TEMPC_P81			3655 		//81℃对应AD值
#define		C_AD_TEMPC_P82			3667 		//82℃对应AD值
#define		C_AD_TEMPC_P83			3679 		//83℃对应AD值
#define		C_AD_TEMPC_P84			3691 		//84℃对应AD值
#define		C_AD_TEMPC_P85			3703 		//85℃对应AD值
#define		C_AD_TEMPC_P86			3714 		//86℃对应AD值
#define		C_AD_TEMPC_P87			3724 		//87℃对应AD值
#define		C_AD_TEMPC_P88			3735 		//88℃对应AD值
#define		C_AD_TEMPC_P89			3745 		//89℃对应AD值
#define		C_AD_TEMPC_P90			3755 		//90℃对应AD值
#define		C_AD_TEMPC_P91			3764 		//91℃对应AD值
#define		C_AD_TEMPC_P92			3773 		//92℃对应AD值
#define		C_AD_TEMPC_P93			3782 		//93℃对应AD值
#define		C_AD_TEMPC_P94			3791 		//94℃对应AD值
#define		C_AD_TEMPC_P95			3799 		//95℃对应AD值
#define		C_AD_TEMPC_P96			3808 		//96℃对应AD值
#define		C_AD_TEMPC_P97			3815 		//97℃对应AD值
#define		C_AD_TEMPC_P98			3823 		//98℃对应AD值
#define		C_AD_TEMPC_P99			3831 		//99℃对应AD值
#define		C_AD_TEMPC_P100			3838 		//100℃对应AD值
#define		C_AD_TEMPC_P101			3845 		//101℃对应AD值
#define		C_AD_TEMPC_P102			3851 		//102℃对应AD值
#define		C_AD_TEMPC_P103			3858 		//103℃对应AD值
#define		C_AD_TEMPC_P104			3865 		//104℃对应AD值
#define		C_AD_TEMPC_P105			3871 		//105℃对应AD值



#else
//				宏定义					AD				温度
#define			C_AD_TEMPC_M30			257 			//-30℃对应AD值
#define			C_AD_TEMPC_M29       	271 			//-29℃对应AD值
#define			C_AD_TEMPC_M28       	285 			//-28℃对应AD值
#define			C_AD_TEMPC_M27			300 			//-27℃对应AD值
#define			C_AD_TEMPC_M26       	316 			//-26℃对应AD值
#define			C_AD_TEMPC_M25       	332 			//-25℃对应AD值
#define			C_AD_TEMPC_M24       	349 			//-24℃对应AD值
#define			C_AD_TEMPC_M23       	366 			//-23℃对应AD值
#define			C_AD_TEMPC_M22       	384 			//-22℃对应AD值
#define			C_AD_TEMPC_M21       	403 			//-21℃对应AD值
#define			C_AD_TEMPC_M20			422 			//-20℃对应AD值
#define			C_AD_TEMPC_M19			442 			//-19℃对应AD值
#define			C_AD_TEMPC_M18			462 			//-18℃对应AD值	
#define			C_AD_TEMPC_M17			484 			//-17℃对应AD值
#define			C_AD_TEMPC_M16			506 			//-16℃对应AD值	
#define			C_AD_TEMPC_M15			529 			//-15℃对应AD值
#define			C_AD_TEMPC_M14			552 			//-14℃对应AD值
#define			C_AD_TEMPC_M13			576 			//-13℃对应AD值
#define			C_AD_TEMPC_M12			601 			//-12℃对应AD值
#define			C_AD_TEMPC_M11			626 			//-11℃对应AD值
#define			C_AD_TEMPC_M10			653 			//-10℃对应AD值
#define			C_AD_TEMPC_M09			680 			//- 9℃对应AD值
#define			C_AD_TEMPC_M08			707 			//- 8℃对应AD值
#define			C_AD_TEMPC_M07			735 			//- 7℃对应AD值
#define			C_AD_TEMPC_M06			764 			//- 6℃对应AD值
#define			C_AD_TEMPC_M05			794 			//- 5℃对应AD值
#define			C_AD_TEMPC_M04			824 			//- 4℃对应AD值
#define			C_AD_TEMPC_M03			855 			//- 3℃对应AD值
#define			C_AD_TEMPC_M02			887 			//- 2℃对应AD值
#define			C_AD_TEMPC_M01			919 			//- 1℃对应AD值
#define			C_AD_TEMPC_P00			948 			//  0℃对应AD值
#define			C_AD_TEMPC_P01			985 			//  1℃对应AD值
#define			C_AD_TEMPC_P02			1019			//  2℃对应AD值
#define			C_AD_TEMPC_P03			1053			//  3℃对应AD值
#define			C_AD_TEMPC_P04			1088			//  4℃对应AD值
#define			C_AD_TEMPC_P05			1124			//  5℃对应AD值
#define			C_AD_TEMPC_P06			1160			//  6℃对应AD值
#define			C_AD_TEMPC_P07			1196			//  7℃对应AD值
#define			C_AD_TEMPC_P08			1233			//  8℃对应AD值
#define			C_AD_TEMPC_P09			1270			//  9℃对应AD值
#define			C_AD_TEMPC_P10			1307			// 10℃对应AD值
#define			C_AD_TEMPC_P11			1345			// 11℃对应AD值
#define			C_AD_TEMPC_P12			1383			// 12℃对应AD值
#define			C_AD_TEMPC_P13			1422			// 13℃对应AD值
#define			C_AD_TEMPC_P14			1461    		// 14℃对应AD值
#define			C_AD_TEMPC_P15			1500    		// 15℃对应AD值
#define			C_AD_TEMPC_P16			1539    		// 16℃对应AD值
#define			C_AD_TEMPC_P17			1578    		// 17℃对应AD值
#define			C_AD_TEMPC_P18			1617    		// 18℃对应AD值
#define			C_AD_TEMPC_P19			1657    		// 19℃对应AD值
#define			C_AD_TEMPC_P20			1696    		// 20℃对应AD值	
#define			C_AD_TEMPC_P21			1736    		// 21℃对应AD值
#define			C_AD_TEMPC_P22			1775    		// 22℃对应AD值
#define			C_AD_TEMPC_P23			1815    		// 23℃对应AD值
#define			C_AD_TEMPC_P24			1854    		// 24℃对应AD值
#define			C_AD_TEMPC_P25			1894    		// 25℃对应AD值
#define			C_AD_TEMPC_P26			1933    		// 26℃对应AD值
#define			C_AD_TEMPC_P27			1972    		// 27℃对应AD值
#define			C_AD_TEMPC_P28			2011    		// 28℃对应AD值
#define			C_AD_TEMPC_P29			2050    		// 29℃对应AD值
#define			C_AD_TEMPC_P30			2089    		// 30℃对应AD值
#define			C_AD_TEMPC_P31			2127    		// 31℃对应AD值
#define			C_AD_TEMPC_P32			2165    		// 32℃对应AD值
#define			C_AD_TEMPC_P33			2202    		// 33℃对应AD值
#define			C_AD_TEMPC_P34			2240    		// 34℃对应AD值
#define			C_AD_TEMPC_P35			2277    		// 35℃对应AD值
#define			C_AD_TEMPC_P36			2314    		// 36℃对应AD值
#define			C_AD_TEMPC_P37			2350    		// 37℃对应AD值
#define			C_AD_TEMPC_P38			2386    		// 38℃对应AD值
#define			C_AD_TEMPC_P39			2421    		// 39℃对应AD值
#define			C_AD_TEMPC_P40			2456    		// 40℃对应AD值
#define			C_AD_TEMPC_P41			2491    		// 41℃对应AD值
#define			C_AD_TEMPC_P42			2525    		// 42℃对应AD值
#define			C_AD_TEMPC_P43			2559    		// 43℃对应AD值
#define			C_AD_TEMPC_P44			2592    		// 44℃对应AD值
#define			C_AD_TEMPC_P45			2625    		// 45℃对应AD值
#define			C_AD_TEMPC_P46			2657    		// 46℃对应AD值
#define			C_AD_TEMPC_P47			2689    		// 47℃对应AD值
#define			C_AD_TEMPC_P48			2721    		// 48℃对应AD值		---表中间AD值
#define			C_AD_TEMPC_P49			2751    		// 49℃对应AD值
#define			C_AD_TEMPC_P50			2782    		// 50℃对应AD值
#define			C_AD_TEMPC_P51			2811    		// 51℃对应AD值
#define			C_AD_TEMPC_P52			2840    		// 52℃对应AD值
#define			C_AD_TEMPC_P53			2869    		// 53℃对应AD值
#define			C_AD_TEMPC_P54			2897    		// 54℃对应AD值
#define			C_AD_TEMPC_P55			2925    		// 55℃对应AD值
#define			C_AD_TEMPC_P56			2952    		// 56℃对应AD值
#define			C_AD_TEMPC_P57			2979    		// 57℃对应AD值
#define			C_AD_TEMPC_P58			3005    		// 58℃对应AD值
#define			C_AD_TEMPC_P59			3030    		// 59℃对应AD值
#define			C_AD_TEMPC_P60			3055    		// 60℃对应AD值
#define			C_AD_TEMPC_P61       	3080			// 61℃对应AD值
#define			C_AD_TEMPC_P62       	3104			// 62℃对应AD值
#define			C_AD_TEMPC_P63       	3127			// 63℃对应AD值
#define			C_AD_TEMPC_P64       	3150			// 64℃对应AD值
#define			C_AD_TEMPC_P65       	3173			// 65℃对应AD值
#define			C_AD_TEMPC_P66			3195			// 66℃对应AD值
#define			C_AD_TEMPC_P67       	3216			// 67℃对应AD值
#define			C_AD_TEMPC_P68       	3238			// 68℃对应AD值
#define			C_AD_TEMPC_P69       	3258			// 69℃对应AD值
#define			C_AD_TEMPC_P70       	3278			// 70℃对应AD值
#define			C_AD_TEMPC_P71       	3298			// 71℃对应AD值
#define			C_AD_TEMPC_P72       	3317			// 72℃对应AD值
#define			C_AD_TEMPC_P73       	3336			// 73℃对应AD值
#define			C_AD_TEMPC_P74       	3354			// 74℃对应AD值
#define			C_AD_TEMPC_P75       	3372			// 75℃对应AD值
#define			C_AD_TEMPC_P76       	3389			// 76℃对应AD值
#define			C_AD_TEMPC_P77       	3406			// 77℃对应AD值
#define			C_AD_TEMPC_P78       	3423			// 78℃对应AD值
#define			C_AD_TEMPC_P79       	3439			// 79℃对应AD值
#define			C_AD_TEMPC_P80       	3454			// 80℃对应AD值
#define			C_AD_TEMPC_P81       	3470			// 81℃对应AD值
#define			C_AD_TEMPC_P82       	3485			// 82℃对应AD值
#define			C_AD_TEMPC_P83       	3499			// 83℃对应AD值
#define			C_AD_TEMPC_P84			3513			// 84℃对应AD值
#define			C_AD_TEMPC_P85       	3527			// 85℃对应AD值
#define			C_AD_TEMPC_P86       	3541			// 86℃对应AD值
#define			C_AD_TEMPC_P87       	3555			// 87℃对应AD值
#define			C_AD_TEMPC_P88       	3567			// 88℃对应AD值
#define			C_AD_TEMPC_P89       	3580			// 89℃对应AD值
#define			C_AD_TEMPC_P90       	3592			// 90℃对应AD值
#define			C_AD_TEMPC_P91       	3604			// 91℃对应AD值
#define			C_AD_TEMPC_P92       	3615			// 92℃对应AD值
#define			C_AD_TEMPC_P93       	3626			// 93℃对应AD值
#define			C_AD_TEMPC_P94       	3638			// 94℃对应AD值
#define			C_AD_TEMPC_P95       	3648			// 95℃对应AD值
#define			C_AD_TEMPC_P96       	3659			// 96℃对应AD值
#define			C_AD_TEMPC_P97       	3669			// 97℃对应AD值
#define			C_AD_TEMPC_P98       	3679			// 98℃对应AD值
#define			C_AD_TEMPC_P99       	3688			// 99℃对应AD值
#define			C_AD_TEMPC_P100      	3697			// 100℃对应AD值
#define			C_AD_TEMPC_P101      	3706			// 101℃对应AD值
#define			C_AD_TEMPC_P102      	3715			// 102℃对应AD值
#define			C_AD_TEMPC_P103      	3724			// 103℃对应AD值
#define			C_AD_TEMPC_P104      	3732			// 104℃对应AD值
#define			C_AD_TEMPC_P105      	3740			// 105℃对应AD值
#define			C_AD_TEMPC_P106      	3750			// 106℃对应AD值
#define			C_AD_TEMPC_P107      	3760			// 107℃对应AD值
#define			C_AD_TEMPC_P108      	3770			// 108℃对应AD值
#define			C_AD_TEMPC_P109      	3780			// 109℃对应AD值
#define			C_AD_TEMPC_P110      	3790			// 110℃对应AD值
#define			C_AD_TEMPC_P111      	3800			// 111℃对应AD值
#define			C_AD_TEMPC_P112      	3810			// 112℃对应AD值
#define			C_AD_TEMPC_P113      	3820			// 113℃对应AD值
#define			C_AD_TEMPC_P114			3830			// 114℃对应AD值
#define			C_AD_TEMPC_P115      	3840			// 115℃对应AD值
#define			C_AD_TEMPC_P116      	3850			// 116℃对应AD值
#define			C_AD_TEMPC_P117      	3860			// 117℃对应AD值
#define			C_AD_TEMPC_P118      	3870			// 118℃对应AD值
#define			C_AD_TEMPC_P119      	3880			// 119℃对应AD值
#define			C_AD_TEMPC_P120      	3890			// 120℃对应AD值
#define			C_AD_TEMPC_P121      	3900			// 121℃对应AD值
#define			C_AD_TEMPC_P122      	3910			// 122℃对应AD值
#define			C_AD_TEMPC_P123      	3920			// 123℃对应AD值
#define			C_AD_TEMPC_P124      	3930			// 124℃对应AD值
#define			C_AD_TEMPC_P125      	3940			// 125℃对应AD值
#endif
//----------------------------------------------------------------------------//
//排气温度
#if 1 //创维
//				宏定义					AD			温度
#define		C_AD_TEMPE_M30			21 			//-30℃对应AD值
#define		C_AD_TEMPE_M29			23 			//-29℃对应AD值
#define		C_AD_TEMPE_M28			24 			//-28℃对应AD值
#define		C_AD_TEMPE_M27			26 			//-27℃对应AD值
#define		C_AD_TEMPE_M26			27 			//-26℃对应AD值
#define		C_AD_TEMPE_M25			29 			//-25℃对应AD值
#define		C_AD_TEMPE_M24			31 			//-24℃对应AD值
#define		C_AD_TEMPE_M23			33 			//-23℃对应AD值
#define		C_AD_TEMPE_M22			35 			//-22℃对应AD值
#define		C_AD_TEMPE_M21			37 			//-21℃对应AD值
#define		C_AD_TEMPE_M20			39 			//-20℃对应AD值
#define		C_AD_TEMPE_M19			41 			//-19℃对应AD值
#define		C_AD_TEMPE_M18			44 			//-18℃对应AD值
#define		C_AD_TEMPE_M17			46 			//-17℃对应AD值
#define		C_AD_TEMPE_M16			49 			//-16℃对应AD值
#define		C_AD_TEMPE_M15			52 			//-15℃对应AD值
#define		C_AD_TEMPE_M14			55 			//-14℃对应AD值
#define		C_AD_TEMPE_M13			58 			//-13℃对应AD值
#define		C_AD_TEMPE_M12			61 			//-12℃对应AD值
#define		C_AD_TEMPE_M11			64 			//-11℃对应AD值
#define		C_AD_TEMPE_M10			68 			//-10℃对应AD值
#define		C_AD_TEMPE_M09			72 			//-9℃对应AD值
#define		C_AD_TEMPE_M08			76 			//-8℃对应AD值
#define		C_AD_TEMPE_M07			80 			//-7℃对应AD值
#define		C_AD_TEMPE_M06			84 			//-6℃对应AD值
#define		C_AD_TEMPE_M05			89 			//-5℃对应AD值
#define		C_AD_TEMPE_M04			93 			//-4℃对应AD值
#define		C_AD_TEMPE_M03			98 			//-3℃对应AD值
#define		C_AD_TEMPE_M02			103 		//-2℃对应AD值
#define		C_AD_TEMPE_M01			109 		//-1℃对应AD值
#define		C_AD_TEMPE_P00			114 		//0℃对应AD值
#define		C_AD_TEMPE_P01			120 		//1℃对应AD值
#define		C_AD_TEMPE_P02			126 		//2℃对应AD值
#define		C_AD_TEMPE_P03			132 		//3℃对应AD值
#define		C_AD_TEMPE_P04			139 		//4℃对应AD值
#define		C_AD_TEMPE_P05			146 		//5℃对应AD值
#define		C_AD_TEMPE_P06			153 		//6℃对应AD值
#define		C_AD_TEMPE_P07			160 		//7℃对应AD值
#define		C_AD_TEMPE_P08			168 		//8℃对应AD值
#define		C_AD_TEMPE_P09			176 		//9℃对应AD值
#define		C_AD_TEMPE_P10			185 		//10℃对应AD值
#define		C_AD_TEMPE_P11			193 		//11℃对应AD值
#define		C_AD_TEMPE_P12			202 		//12℃对应AD值
#define		C_AD_TEMPE_P13			211 		//13℃对应AD值
#define		C_AD_TEMPE_P14			221 		//14℃对应AD值
#define		C_AD_TEMPE_P15			231 		//15℃对应AD值
#define		C_AD_TEMPE_P16			241 		//16℃对应AD值
#define		C_AD_TEMPE_P17			252 		//17℃对应AD值
#define		C_AD_TEMPE_P18			263 		//18℃对应AD值
#define		C_AD_TEMPE_P19			275 		//19℃对应AD值
#define		C_AD_TEMPE_P20			287 		//20℃对应AD值
#define		C_AD_TEMPE_P21			299 		//21℃对应AD值
#define		C_AD_TEMPE_P22			311 		//22℃对应AD值
#define		C_AD_TEMPE_P23			325 		//23℃对应AD值
#define		C_AD_TEMPE_P24			338 		//24℃对应AD值
#define		C_AD_TEMPE_P25			352 		//25℃对应AD值
#define		C_AD_TEMPE_P26			366 		//26℃对应AD值
#define		C_AD_TEMPE_P27			381 		//27℃对应AD值
#define		C_AD_TEMPE_P28			396 		//28℃对应AD值
#define		C_AD_TEMPE_P29			412 		//29℃对应AD值
#define		C_AD_TEMPE_P30			428 		//30℃对应AD值
#define		C_AD_TEMPE_P31			445 		//31℃对应AD值
#define		C_AD_TEMPE_P32			462 		//32℃对应AD值
#define		C_AD_TEMPE_P33			479 		//33℃对应AD值
#define		C_AD_TEMPE_P34			497 		//34℃对应AD值
#define		C_AD_TEMPE_P35			516 		//35℃对应AD值
#define		C_AD_TEMPE_P36			535 		//36℃对应AD值
#define		C_AD_TEMPE_P37			554 		//37℃对应AD值
#define		C_AD_TEMPE_P38			574 		//38℃对应AD值
#define		C_AD_TEMPE_P39			594 		//39℃对应AD值
#define		C_AD_TEMPE_P40			615 		//40℃对应AD值
#define		C_AD_TEMPE_P41			636 		//41℃对应AD值
#define		C_AD_TEMPE_P42			658 		//42℃对应AD值
#define		C_AD_TEMPE_P43			681 		//43℃对应AD值
#define		C_AD_TEMPE_P44			703 		//44℃对应AD值
#define		C_AD_TEMPE_P45			727 		//45℃对应AD值
#define		C_AD_TEMPE_P46			751 		//46℃对应AD值
#define		C_AD_TEMPE_P47			775 		//47℃对应AD值
#define		C_AD_TEMPE_P48			799 		//48℃对应AD值
#define		C_AD_TEMPE_P49			825 		//49℃对应AD值
#define		C_AD_TEMPE_P50			850 		//50℃对应AD值
#define		C_AD_TEMPE_P51			876 		//51℃对应AD值
#define		C_AD_TEMPE_P52			903 		//52℃对应AD值
#define		C_AD_TEMPE_P53			930 		//53℃对应AD值
#define		C_AD_TEMPE_P54			957 		//54℃对应AD值
#define		C_AD_TEMPE_P55			985 		//55℃对应AD值
#define		C_AD_TEMPE_P56			1013 		//56℃对应AD值
#define		C_AD_TEMPE_P57			1042 		//57℃对应AD值
#define		C_AD_TEMPE_P58			1071 		//58℃对应AD值
#define		C_AD_TEMPE_P59			1101 		//59℃对应AD值
#define		C_AD_TEMPE_P60			1130 		//60℃对应AD值
#define		C_AD_TEMPE_P61			1160 		//61℃对应AD值
#define		C_AD_TEMPE_P62			1191 		//62℃对应AD值
#define		C_AD_TEMPE_P63			1222 		//63℃对应AD值
#define		C_AD_TEMPE_P64			1253 		//64℃对应AD值
#define		C_AD_TEMPE_P65			1284 		//65℃对应AD值
#define		C_AD_TEMPE_P66			1316 		//66℃对应AD值
#define		C_AD_TEMPE_P67			1348 		//67℃对应AD值
#define		C_AD_TEMPE_P68			1380 		//68℃对应AD值
#define		C_AD_TEMPE_P69			1412 		//69℃对应AD值
#define		C_AD_TEMPE_P70			1445 		//70℃对应AD值
#define		C_AD_TEMPE_P71			1477 		//71℃对应AD值
#define		C_AD_TEMPE_P72			1510 		//72℃对应AD值
#define		C_AD_TEMPE_P73			1543 		//73℃对应AD值
#define		C_AD_TEMPE_P74			1576 		//74℃对应AD值
#define		C_AD_TEMPE_P75			1609 		//75℃对应AD值
#define		C_AD_TEMPE_P76			1642 		//76℃对应AD值
#define		C_AD_TEMPE_P77			1676 		//77℃对应AD值
#define		C_AD_TEMPE_P78			1709 		//78℃对应AD值
#define		C_AD_TEMPE_P79			1742 		//79℃对应AD值
#define		C_AD_TEMPE_P80			1775 		//80℃对应AD值
#define		C_AD_TEMPE_P81			1809 		//81℃对应AD值
#define		C_AD_TEMPE_P82			1842 		//82℃对应AD值
#define		C_AD_TEMPE_P83			1875 		//83℃对应AD值
#define		C_AD_TEMPE_P84			1908 		//84℃对应AD值
#define		C_AD_TEMPE_P85			1941 		//85℃对应AD值
#define		C_AD_TEMPE_P86			1973 		//86℃对应AD值
#define		C_AD_TEMPE_P87			2006 		//87℃对应AD值
#define		C_AD_TEMPE_P88			2038 		//88℃对应AD值
#define		C_AD_TEMPE_P89			2070 		//89℃对应AD值
#define		C_AD_TEMPE_P90			2102 		//90℃对应AD值
#define		C_AD_TEMPE_P91			2134 		//91℃对应AD值
#define		C_AD_TEMPE_P92			2165 		//92℃对应AD值
#define		C_AD_TEMPE_P93			2196 		//93℃对应AD值
#define		C_AD_TEMPE_P94			2227 		//94℃对应AD值
#define		C_AD_TEMPE_P95			2257 		//95℃对应AD值
#define		C_AD_TEMPE_P96			2287 		//96℃对应AD值
#define		C_AD_TEMPE_P97			2317 		//97℃对应AD值
#define		C_AD_TEMPE_P98			2346 		//98℃对应AD值
#define		C_AD_TEMPE_P99			2375 		//99℃对应AD值
#define		C_AD_TEMPE_P100			2404 		//100℃对应AD值
#define		C_AD_TEMPE_P101			2432 		//101℃对应AD值
#define		C_AD_TEMPE_P102			2460 		//102℃对应AD值
#define		C_AD_TEMPE_P103			2487 		//103℃对应AD值
#define		C_AD_TEMPE_P104			2514 		//104℃对应AD值
#define		C_AD_TEMPE_P105			2540 		//105℃对应AD值

#else	//德龙排气
//				宏定义					AD			温度
#define			C_AD_TEMPE_M30			24 			//-30℃对应AD值
#define			C_AD_TEMPE_M29      	26 			//-29℃对应AD值
#define			C_AD_TEMPE_M28      	27 			//-28℃对应AD值
#define			C_AD_TEMPE_M27			29 			//-27℃对应AD值
#define			C_AD_TEMPE_M26      	30 			//-26℃对应AD值
#define			C_AD_TEMPE_M25      	32 			//-25℃对应AD值
#define			C_AD_TEMPE_M24      	34 			//-24℃对应AD值
#define			C_AD_TEMPE_M23      	36 			//-23℃对应AD值
#define			C_AD_TEMPE_M22      	38 			//-22℃对应AD值
#define			C_AD_TEMPE_M21      	41 			//-21℃对应AD值
#define			C_AD_TEMPE_M20			43 			//-20℃对应AD值
#define			C_AD_TEMPE_M19			45 			//-19℃对应AD值
#define			C_AD_TEMPE_M18			48 			//-18℃对应AD值	
#define			C_AD_TEMPE_M17			51 			//-17℃对应AD值
#define			C_AD_TEMPE_M16			54 			//-16℃对应AD值	
#define			C_AD_TEMPE_M15			56 			//-15℃对应AD值
#define			C_AD_TEMPE_M14			60 			//-14℃对应AD值
#define			C_AD_TEMPE_M13			58 			//-13℃对应AD值
#define			C_AD_TEMPE_M12			66 			//-12℃对应AD值
#define			C_AD_TEMPE_M11			70 			//-11℃对应AD值
#define			C_AD_TEMPE_M10			74 			//-10℃对应AD值
#define			C_AD_TEMPE_M09			78 			//- 9℃对应AD值
#define			C_AD_TEMPE_M08			82 			//- 8℃对应AD值
#define			C_AD_TEMPE_M07			86 			//- 7℃对应AD值
#define			C_AD_TEMPE_M06			91 			//- 6℃对应AD值
#define			C_AD_TEMPE_M05			95 			//- 5℃对应AD值
#define			C_AD_TEMPE_M04			100 		//- 4℃对应AD值
#define			C_AD_TEMPE_M03			105 		//- 3℃对应AD值
#define			C_AD_TEMPE_M02			111 		//- 2℃对应AD值
#define			C_AD_TEMPE_M01			116 		//- 1℃对应AD值
#define			C_AD_TEMPE_P00			122 		//  0℃对应AD值
#define			C_AD_TEMPE_P01			128 		//  1℃对应AD值
#define			C_AD_TEMPE_P02			135 		//  2℃对应AD值
#define			C_AD_TEMPE_P03			141 		//  3℃对应AD值
#define			C_AD_TEMPE_P04			148 		//  4℃对应AD值
#define			C_AD_TEMPE_P05			156 		//  5℃对应AD值
#define			C_AD_TEMPE_P06			163 		//  6℃对应AD值
#define			C_AD_TEMPE_P07			171 		//  7℃对应AD值
#define			C_AD_TEMPE_P08			179 		//  8℃对应AD值
#define			C_AD_TEMPE_P09			187 		//  9℃对应AD值
#define			C_AD_TEMPE_P10			196 		// 10℃对应AD值
#define			C_AD_TEMPE_P11			205 		// 11℃对应AD值
#define			C_AD_TEMPE_P12			215 		// 12℃对应AD值
#define			C_AD_TEMPE_P13			224 		// 13℃对应AD值
#define			C_AD_TEMPE_P14			235 	    // 14℃对应AD值
#define			C_AD_TEMPE_P15			245 	    // 15℃对应AD值
#define			C_AD_TEMPE_P16			256 	    // 16℃对应AD值
#define			C_AD_TEMPE_P17			267 	    // 17℃对应AD值
#define			C_AD_TEMPE_P18			279 	    // 18℃对应AD值
#define			C_AD_TEMPE_P19			291 	    // 19℃对应AD值
#define			C_AD_TEMPE_P20			304 	    // 20℃对应AD值	
#define			C_AD_TEMPE_P21			316 	    // 21℃对应AD值
#define			C_AD_TEMPE_P22			330 	    // 22℃对应AD值
#define			C_AD_TEMPE_P23			344 	    // 23℃对应AD值
#define			C_AD_TEMPE_P24			358 	    // 24℃对应AD值
#define			C_AD_TEMPE_P25			372 	    // 25℃对应AD值
#define			C_AD_TEMPE_P26			387 	    // 26℃对应AD值
#define			C_AD_TEMPE_P27			403 	    // 27℃对应AD值
#define			C_AD_TEMPE_P28			419 	    // 28℃对应AD值
#define			C_AD_TEMPE_P29			435 	    // 29℃对应AD值
#define			C_AD_TEMPE_P30			452 	    // 30℃对应AD值
#define			C_AD_TEMPE_P31			470 	    // 31℃对应AD值
#define			C_AD_TEMPE_P32			488 	    // 32℃对应AD值
#define			C_AD_TEMPE_P33			506 	    // 33℃对应AD值
#define			C_AD_TEMPE_P34			525 	    // 34℃对应AD值
#define			C_AD_TEMPE_P35			544 	    // 35℃对应AD值
#define			C_AD_TEMPE_P36			564 	    // 36℃对应AD值
#define			C_AD_TEMPE_P37			585 	    // 37℃对应AD值
#define			C_AD_TEMPE_P38			605 	    // 38℃对应AD值
#define			C_AD_TEMPE_P39			627 	    // 39℃对应AD值
#define			C_AD_TEMPE_P40			649 	    // 40℃对应AD值
#define			C_AD_TEMPE_P41			671 	    // 41℃对应AD值
#define			C_AD_TEMPE_P42			694 	    // 42℃对应AD值
#define			C_AD_TEMPE_P43			717 	    // 43℃对应AD值
#define			C_AD_TEMPE_P44			741 	    // 44℃对应AD值
#define			C_AD_TEMPE_P45			765 	    // 45℃对应AD值
#define			C_AD_TEMPE_P46			790 	    // 46℃对应AD值
#define			C_AD_TEMPE_P47			815 	    // 47℃对应AD值
#define			C_AD_TEMPE_P48			840 	    // 48℃对应AD值		---表中间AD值
#define			C_AD_TEMPE_P49			866 	    // 49℃对应AD值
#define			C_AD_TEMPE_P50			893 	    // 50℃对应AD值
#define			C_AD_TEMPE_P51			920 	    // 51℃对应AD值
#define			C_AD_TEMPE_P52			947 	    // 52℃对应AD值
#define			C_AD_TEMPE_P53			975 	    // 53℃对应AD值
#define			C_AD_TEMPE_P54			1003	    // 54℃对应AD值
#define			C_AD_TEMPE_P55			1031	    // 55℃对应AD值
#define			C_AD_TEMPE_P56			1060	    // 56℃对应AD值
#define			C_AD_TEMPE_P57			1090	    // 57℃对应AD值
#define			C_AD_TEMPE_P58			1119	    // 58℃对应AD值
#define			C_AD_TEMPE_P59			1149	    // 59℃对应AD值
#define			C_AD_TEMPE_P60			1179	    // 60℃对应AD值
#define			C_AD_TEMPE_P61      	1210 		// 61℃对应AD值
#define			C_AD_TEMPE_P62      	1241 		// 62℃对应AD值
#define			C_AD_TEMPE_P63      	1272 		// 63℃对应AD值
#define			C_AD_TEMPE_P64      	1303 		// 64℃对应AD值
#define			C_AD_TEMPE_P65      	1335 		// 65℃对应AD值
#define			C_AD_TEMPE_P66			1367		// 66℃对应AD值
#define			C_AD_TEMPE_P67      	1399 		// 67℃对应AD值
#define			C_AD_TEMPE_P68      	1431 		// 68℃对应AD值
#define			C_AD_TEMPE_P69      	1464 		// 69℃对应AD值
#define			C_AD_TEMPE_P70      	1496 		// 70℃对应AD值
#define			C_AD_TEMPE_P71      	1529 		// 71℃对应AD值
#define			C_AD_TEMPE_P72      	1562 		// 72℃对应AD值
#define			C_AD_TEMPE_P73      	1595 		// 73℃对应AD值
#define			C_AD_TEMPE_P74      	1628 		// 74℃对应AD值
#define			C_AD_TEMPE_P75      	1661 		// 75℃对应AD值
#define			C_AD_TEMPE_P76      	1694 		// 76℃对应AD值
#define			C_AD_TEMPE_P77      	1728 		// 77℃对应AD值
#define			C_AD_TEMPE_P78      	1761 		// 78℃对应AD值
#define			C_AD_TEMPE_P79      	1794 		// 79℃对应AD值
#define			C_AD_TEMPE_P80      	1827 		// 80℃对应AD值
#define			C_AD_TEMPE_P81      	1860 		// 81℃对应AD值
#define			C_AD_TEMPE_P82      	1893 		// 82℃对应AD值
#define			C_AD_TEMPE_P83      	1926 		// 83℃对应AD值
#define			C_AD_TEMPE_P84			1959		// 84℃对应AD值
#define			C_AD_TEMPE_P85      	1992 		// 85℃对应AD值
#define			C_AD_TEMPE_P86      	2024 		// 86℃对应AD值
#define			C_AD_TEMPE_P87      	2057 		// 87℃对应AD值
#define			C_AD_TEMPE_P88      	2089 		// 88℃对应AD值
#define			C_AD_TEMPE_P89      	2121 		// 89℃对应AD值
#define			C_AD_TEMPE_P90      	2154 		// 90℃对应AD值
#define			C_AD_TEMPE_P91      	2185 		// 91℃对应AD值
#define			C_AD_TEMPE_P92      	2217 		// 92℃对应AD值
#define			C_AD_TEMPE_P93      	2248 		// 93℃对应AD值
#define			C_AD_TEMPE_P94      	2279 		// 94℃对应AD值
#define			C_AD_TEMPE_P95      	2310 		// 95℃对应AD值
#define			C_AD_TEMPE_P96      	2341 		// 96℃对应AD值
#define			C_AD_TEMPE_P97      	2371 		// 97℃对应AD值
#define			C_AD_TEMPE_P98      	2401 		// 98℃对应AD值
#define			C_AD_TEMPE_P99      	2431 		// 99℃对应AD值
#define			C_AD_TEMPE_P100     	2461 		// 100℃对应AD值
#define			C_AD_TEMPE_P101     	2490 		// 101℃对应AD值
#define			C_AD_TEMPE_P102     	2518 		// 102℃对应AD值
#define			C_AD_TEMPE_P103     	2547 		// 103℃对应AD值
#define			C_AD_TEMPE_P104     	2575 		// 104℃对应AD值
#define			C_AD_TEMPE_P105     	2603 		// 105℃对应AD值
#define			C_AD_TEMPE_P106     	2631 		// 106℃对应AD值
#define			C_AD_TEMPE_P107     	2658 		// 107℃对应AD值
#define			C_AD_TEMPE_P108     	2685 		// 108℃对应AD值
#define			C_AD_TEMPE_P109     	2711 		// 109℃对应AD值
#define			C_AD_TEMPE_P110     	2737 		// 110℃对应AD值
#define			C_AD_TEMPE_P111     	2763 		// 111℃对应AD值
#define			C_AD_TEMPE_P112     	2788 		// 112℃对应AD值
#define			C_AD_TEMPE_P113     	2813 		// 113℃对应AD值
#define			C_AD_TEMPE_P114			2838		// 114℃对应AD值
#define			C_AD_TEMPE_P115     	2862 		// 115℃对应AD值
#define			C_AD_TEMPE_P116     	2886 		// 116℃对应AD值
#define			C_AD_TEMPE_P117     	2909 		// 117℃对应AD值
#define			C_AD_TEMPE_P118     	2932 		// 118℃对应AD值
#define			C_AD_TEMPE_P119     	2955 		// 119℃对应AD值
#define			C_AD_TEMPE_P120     	2978 		// 120℃对应AD值
#define			C_AD_TEMPE_P121     	3000 		// 121℃对应AD值
#define			C_AD_TEMPE_P122     	3021 		// 122℃对应AD值
#define			C_AD_TEMPE_P123     	3042 		// 123℃对应AD值
#define			C_AD_TEMPE_P124     	3062 		// 124℃对应AD值
#define			C_AD_TEMPE_P125     	3083 		// 125℃对应AD值
//----------------------------------------------------------------------------//
#endif
extern	U16	U16_ad_value_12bit_resultOK[ENUM_AD_ID_NUM];	//已防抖12bit AD值		

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
extern	U8	App_NTC_Check(U8 channel);	
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
extern	void	App_ADCLookupTemperatureTable(U8 channel);

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
extern	void	App_LookUpTemperature(void);

#endif
