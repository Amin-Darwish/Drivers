/******************************************/
/******************************************/
/*******   Author:   Amin Darwish  ********/
/*******   Layer        MCAL       ********/                 
/*******   Module:      TIMER     ********/       
/*******   Version:     1.0        ********/                     
/******************************************/                               
/******************************************/

#include "STD_types.h"

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define TIMER_U8_TIMER_0    0
#define TIMER_U8_TIMER_1	1
#define TIMER_U8_TIMER_2	2

/*                  TIMER0                             */

#define TIMER0_U8_NORMAL             0
#define TIMER0_U8_PWM_PHASE_CORRECT  1
#define TIMER0_U8_CTC                2
#define TIMER0_U8_FAST_PWM           3

#define TIMER0_U8_OC0_DISCONNECTED   0
#define	TIMER0_U8_OC0_TOGGLE	     1
#define	TIMER0_U8_OC0_CLEAR			 2
#define TIMER0_U8_OC0_SET			 3

#define TIMER0_U8_STOP               0
#define	TIMER0_U8_DIVIDED_BY_1		 1
#define	TIMER0_U8_DIVIDED_BY_8		 2
#define	TIMER0_U8_DIVIDED_BY_64		 3
#define	TIMER0_U8_DIVIDED_BY_256     4
#define	TIMER0_U8_DIVIDED_BY_1024    5

#define TIMER0_U8_DISABLE_INTERRUPT  0 
#define	TIMER0_U8_ENABLE_INTERRUPT   1

/*                          TIMER1                                                  */
#define TIMER1_U8_NORMAL                                0
#define TIMER1_U8_PWM_PHASE_CORRECT_8_BIT  			    1
#define TIMER1_U8_PWM_PHASE_CORRECT_9_BIT 			    2
#define TIMER1_U8_PWM_PHASE_CORRECT_10_BIT			    3
#define TIMER1_U8_CTC_OCR1A							    4
#define TIMER1_U8_FAST_PWM_8_BIT					    5
#define TIMER1_U8_FAST_PWM_9_BIT                        6
#define TIMER1_U8_FAST_PWM_10_BIT					    7
#define TIMER1_U8_PWM_PHASE_FREQUENCY_CORRECT_ICR1	    8
#define TIMER1_U8_PWM_PHASE_FREQUENCY_CORRECT_OCR1A	    9
#define TIMER1_U8_PWM_PHASE_CORRECT_ICR1                10
#define TIMER1_U8_PWM_PHASE_CORRECT_OCR1A			    11
#define TIMER1_U8_CTC_ICR1							    12
#define TIMER1_U8_FAST_PWM_ICR1						    13
#define	TIMER1_U8_FAST_PWM_OCR1A                        14
													 

#define TIMER1_U8_OC1_DISCONNECTED    0
#define	TIMER1_U8_OC1_TOGGLE       	  1
#define	TIMER1_U8_OC1_CLEAR        	  2
#define	TIMER1_U8_OC1_SET          	  3

#define TIMER1_U8_STOP                0  
#define	TIMER1_U8_DIVIDED_BY_1		  1
#define	TIMER1_U8_DIVIDED_BY_8		  2
#define	TIMER1_U8_DIVIDED_BY_32		  3
#define	TIMER1_U8_DIVIDED_BY_64		  4
#define	TIMER1_U8_DIVIDED_BY_128      5
#define	TIMER1_U8_DIVIDED_BY_256	  6
#define	TIMER1_U8_DIVIDED_BY_1024	  7

#define TIMER1_U8_FALING_INPUT_CAPURE  0
#define	TIMER1_U8_RISING_INPUT_CAPURE  1


/*                  TIMER2                             */

#define TIMER2_U8_NORMAL             0
#define TIMER2_U8_PWM_PHASE_CORRECT  1
#define TIMER2_U8_CTC                2
#define TIMER2_U8_FAST_PWM           3

#define TIMER2_U8_OC2_DISCONNECTED   0
#define	TIMER2_U8_OC2_TOGGLE	     1
#define	TIMER2_U8_OC2_CLEAR			 2
#define TIMER2_U8_OC2_SET			 3

#define TIMER1_U8_STOP               0
#define	TIMER1_U8_DIVIDED_BY_1	     1
#define	TIMER1_U8_DIVIDED_BY_8	     2
#define	TIMER1_U8_DIVIDED_BY_32	     3
#define	TIMER1_U8_DIVIDED_BY_64      4
#define	TIMER1_U8_DIVIDED_BY_128     5
#define	TIMER1_U8_DIVIDED_BY_256     6 
#define TIMER1_U8_DIVIDED_BY_1024    7

#define TIMER2_U8_DISABLE_INTERRUPT  0
#define	TIMER2_U8_ENABLE_INTERRUPT   1


/************************************************************************/
/*           Timer Function                                            */
/************************************************************************/

typedef enum
{
	Timer_Normal_Mode,
	Timer_CTC_Mode
	
}Timer_Modes;

typedef enum
{
	Timer_Interrupt_Enable,
	Timer_Interrupt_Disable
	
}Timer_Interrupt;

typedef enum
{
	NO_CLK_SRC,
	NO_PRESCALER,
	PRESCALER_CLK_8,
	PRESCALER_CLK_64,
	PRESCALER_CLK_256,
	PRESCALER_CLK_1024,
	
}Timer_PRESCALER;

typedef struct
{
	u8 Timer;
	Timer_Modes      Timer_Mode;
	Timer_PRESCALER  Timer_Prescaler;
	Timer_Interrupt  Timer_OVF_INT;
	Timer_Interrupt  Timer_CTC_INT;
	
}Timer_Configuration;


void TIMER_voidInit(void);

/*                     TIMER0                                      */
void TIMER0_voidSetOVFRegister(u8 Copy_u8Value);
void TIMER0_voidSetCTCRegister(u8 Copy_u8Value);

void TIMER0_voidEnableOVFINT(void);
void TIMER0_voidDisableOVFINT(void);
void TIMER0_voidClearOVFFlag(void);

void TIMER0_voidEnableCTCINT(void);
void TIMER0_voidDisableCTCINT(void);
void TIMER0_voidClearCTCFlag(void);

void TIMER0_voidSetOVFCallBack(void(*Copy_pvCallBack)(void));
void TIMER0_voidSetCTCCallBack(void(*Copy_pvCallBack)(void));

void TIMER0_voidForceOutputCompare(void);

/*                     TIMER1                                      */

void TIMER1_voidSetOVFRegister(u16 Copy_u16Value);
void TIMER1_voidChannel_A_SetCTCRegister(u16 Copy_u16Value);
void TIMER1_voidChannel_B_SetCTCRegister(u16 Copy_u16Value);
u16  TIMER1_u16InputCaptureValue(void);

void TIMER1_voidEnableOVFINT(void);
void TIMER1_voidDisableOVFINT(void);
void TIMER1_voidClearOVFFlag(void);

void TIMER1_voidChannel_A_EnableCTCINT(void);
void TIMER1_voidChannel_A_DisableCTCINT(void);
void TIMER1_voidChannel_A_ClearCTCFlag(void);

void TIMER1_voidChannel_B_EnableCTCINT(void);
void TIMER1_voidChannel_B_DisableCTCINT(void);
void TIMER1_voidChannel_B_ClearCTCFlag(void);

void TIMER1_voidEnableInputCaptureINT(void);
void TIMER1_voidDisableInputCaptureINT(void);
void TIMER1_voidClearInputCaptureFlag(void);

void TIMER1_voidSetOVFCallBack(void(*Copy_pvCallBack)(void));
void TIMER1_voidChannel_A_SetCTCCallBack(void(*Copy_pvCallBack)(void));
void TIMER1_voidChannel_B_SetCTCCallBack(void(*Copy_pvCallBack)(void));
void TIMER1_voidSetInputCaptureCallBack(void(*Copy_pvCallBack)(void));

void TIMER1_voidChannel_A_ForceOutputCompare(void);
void TIMER1_voidChannel_B_ForceOutputCompare(void);

/*                     TIMER2                                      */

void TIMER2_voidSetOVFRegister(u8 Copy_u8Value);
void TIMER2_voidSetCTCRegister(u8 Copy_u8Value);

void TIMER2_voidEnableOVFINT(void);
void TIMER2_voidDisableOVFINT(void);
void TIMER2_voidClearOVFFlag(void);

void TIMER2_voidEnableCTCINT(void);
void TIMER2_voidDisableCTCINT(void);
void TIMER2_voidClearCTCFlag(void);

void TIMER2_voidSetOVFCallBack(void(*Copy_pvCallBack)(void));
void TIMER2_voidSetCTCCallBack(void(*Copy_pvCallBack)(void));

void TIMER2_voidForceOutputCompare(void);




#endif