/******************************************/
/******************************************/
/*******   Author:   Amin Darwish  ********/
/*******   Layer        MCAL       ********/                 
/*******   Module:      TIMER0     ********/       
/*******   Version:     1.0        ********/                     
/******************************************/                               
/******************************************/
#include "STD_types.h"
#include "BIT_math.h"

#include "Err_types.h"
#include "TIMER_reg.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
#include "TIMER_interface.h"



void TIMER_voidInit(void)
{ 

/************************************************************************/
/*           	/*      TIMER 0    */                                                         
/************************************************************************/


 /* SET MODE  */
#ifdef TIMER0_ENABLE
     #if TIMER0_U8_WAVRFORM_MODE == TIMER0_U8_NORMAL
	        CLEAR_BIT(TCCR0,WGM00);
	        CLEAR_BIT(TCCR0,WGM01);
   
	 #elif TIMER0_U8_WAVRFORM_MODE == TIMER0_U8_PWM_PHASE_CORRECT
	        SET_BIT(TCCR0,WGM00);
	        CLEAR_BIT(TCCR0,WGM01);
   
	 #elif TIMER0_U8_WAVRFORM_MODE == TIMER0_U8_CTC 
	        CLEAR_BIT(TCCR0,WGM00);
	        SET_BIT(TCCR0,WGM01);
	 
	 #elif TIMER0_U8_WAVRFORM_MODE == TIMER0_U8_FAST_PWM 
	        SET_BIT(TCCR0,WGM00);
	        SET_BIT(TCCR0,WGM01);
     #endif

     #if TIMER0_U8_COMPARE_OUTPUT_MODE == TIMER0_U8_OC0_DISCONNECTED
               CLEAR_BIT(TCCR0, COM00);
     	       CLEAR_BIT(TCCR0, COM01);
      #elif TIMER0_U8_COMPARE_OUTPUT_MODE == TIMER0_U8_OC0_TOGGLE
	           #if	TIMER0_U8_WAVRFORM_MODE == TIMER0_U8_PWM_PHASE_CORRECT || TIMER0_U8_WAVRFORM_MODE == TIMER0_U8_FAST_PWM
	           #warning ("CHOOSED UNAVAILABLE OPTION IN TIMER OUTPUT MODE!!")
               #else 
			         SET_BIT(TCCR0, COM00);
			         CLEAR_BIT(TCCR0, COM01);

               #endif
	  #elif TIMER0_U8_COMPARE_OUTPUT_MODE == TIMER0_U8_OC0_CLEAR
	          	   CLEAR_BIT(TCCR0, COM00);
	          	   SET_BIT(TCCR0, COM01);
					 
	  #elif TIMER0_U8_COMPARE_OUTPUT_MODE == TIMER0_U8_OC0_SET			 
					 SET_BIT(TCCR0, COM00);
					 SET_BIT(TCCR0, COM01);
	  #endif				 
						 
 /*  Set Prescaler */
 
      #if TIMER0_U8_PRESCALER == TIMER0_U8_STOP
             /* No Clock Source  */
             CLEAR_BIT(TCCR0,CS00);
             CLEAR_BIT(TCCR0,CS01);
             CLEAR_BIT(TCCR0,CS02);
	  #elif TIMER0_U8_PRESCALER == TIMER0_U8_DIVIDED_BY_1	 
             /* No Prescaling  */
             SET_BIT(TCCR0,CS00);
             CLEAR_BIT(TCCR0,CS01);
             CLEAR_BIT(TCCR0,CS02);
	  #elif TIMER0_U8_PRESCALER == TIMER0_U8_DIVIDED_BY_8	 
             /* Division by 8  */
             CLEAR_BIT(TCCR0,CS00);
             SET_BIT(TCCR0,CS01);
             CLEAR_BIT(TCCR0,CS02);
	  #elif TIMER0_U8_PRESCALER == TIMER0_U8_DIVIDED_BY_64	 
              /* Division by 64 */
             SET_BIT(TCCR0,CS00);
             SET_BIT(TCCR0,CS01);
             CLEAR_BIT(TCCR0,CS02); 
	  #elif TIMER0_U8_PRESCALER == TIMER0_U8_DIVIDED_BY_256		 
	          /* Division by 256  */
             CLEAR_BIT(TCCR0,CS00);
             CLEAR_BIT(TCCR0,CS01);
             SET_BIT(TCCR0,CS02);
	  #elif TIMER0_U8_PRESCALER == TIMER0_U8_DIVIDED_BY_1024	 
             /* Division by 1024*/
             SET_BIT(TCCR0,CS00);
             CLEAR_BIT(TCCR0,CS01);
             SET_BIT(TCCR0,CS02);
	  #endif
	  /* Set Interrupt */
	  #if TIMER0_U8_INTERRUPT == TIMER0_U8_ENABLE_INTERRUPT
	         #if TIMER0_U8_WAVRFORM_MODE == TIMER0_U8_NORMAL
			      SET_BIT(TIMSK, TOIE0);
			 #elif TIMER0_U8_WAVRFORM_MODE ==  TIMER0_U8_CTC
			      SET_BIT(TIMSK, OCIE0);	  
			#endif
	  #endif
#endif	  		  
}
/************************************************************************/
/*           	/*      TIMER 1    */                                                           
/************************************************************************/


	/* SET MODE  */
#ifdef TIMER1_ENABLE
	#if TIMER1_U8_WAVRFORM_MODE == TIMER1_U8_NORMAL
	         CLEAR_BIT(TCCR1A,WGM10);
	         CLEAR_BIT(TCCR1A,WGM11);
	         CLEAR_BIT(TCCR1B,WGM12);
	         CLEAR_BIT(TCCR1B,WGM13);
			 
	#elif TIMER1_U8_WAVRFORM_MODE == TIMER1_U8_PWM_PHASE_CORRECT_8_BIT 
	         SET_BIT(TCCR1A,WGM10);
	         CLEAR_BIT(TCCR1A,WGM11);
	         CLEAR_BIT(TCCR1B,WGM12);
	         CLEAR_BIT(TCCR1B,WGM13);
		
	#elif TIMER1_U8_WAVRFORM_MODE == TIMER1_U8_PWM_PHASE_CORRECT_9_BIT 
	         CLEAR_BIT(TCCR1A,WGM10);
	         SET_BIT(TCCR1A,WGM11);
			 CLEAR_BIT(TCCR1B,WGM12);
			 CLEAR_BIT(TCCR1B,WGM13);
	
	#elif TIMER1_U8_WAVRFORM_MODE == TIMER1_U8_PWM_PHASE_CORRECT_10_BIT
	         SET_BIT(TCCR1A,WGM10);
	         SET_BIT(TCCR1A,WGM11);
	         CLEAR_BIT(TCCR1A,WGM12);
	         CLEAR_BIT(TCCR1A,WGM13);
			
	#elif TIMER1_U8_WAVRFORM_MODE == TIMER1_U8_CTC_OCR1A
			 CLEAR_BIT(TCCR1A,WGM10);
			 CLEAR_BIT(TCCR1A,WGM11);
			 SET_BIT(TCCR1B,WGM12);
			 CLEAR_BIT(TCCR1B,WGM13);
			
	#elif TIMER1_U8_WAVRFORM_MODE == TIMER1_U8_FAST_PWM_8_BIT		
			 SET_BIT(TCCR1A,WGM10);
			 CLEAR_BIT(TCCR1A,WGM11);
			 SET_BIT(TCCR1B,WGM12);
			 CLEAR_BIT(TCCR1B,WGM13);

	#elif TIMER1_U8_WAVRFORM_MODE == TIMER1_U8_FAST_PWM_9_BIT
	         CLEAR_BIT(TCCR1A,WGM10);
	         SET_BIT(TCCR1A,WGM11);
	         SET_BIT(TCCR1B,WGM12);
	         CLEAR_BIT(TCCR1B,WGM13);
	
	#elif TIMER1_U8_WAVRFORM_MODE == TIMER1_U8_FAST_PWM_10_BIT
	         SET_BIT(TCCR1A,WGM10);
	         SET_BIT(TCCR1A,WGM11);
	         SET_BIT(TCCR1B,WGM12);
	         CLEAR_BIT(TCCR1B,WGM13);
			 
	#elif TIMER1_U8_WAVRFORM_MODE == 	TIMER1_U8_PWM_PHASE_FREQUENCY_CORRECT_ICR1
	         CLEAR_BIT(TCCR1A,WGM10);
	         CLEAR_BIT(TCCR1A,WGM11);
	         CLEAR_BIT(TCCR1B,WGM12);
	         SET_BIT(TCCR1B,WGM13);
		 
	#elif TIMER1_U8_WAVRFORM_MODE == TIMER1_U8_PWM_PHASE_FREQUENCY_CORRECT_OCR1A		 
			 SET_BIT(TCCR1A,WGM10);
			 CLEAR_BIT(TCCR1A,WGM11);
			 CLEAR_BIT(TCCR1B,WGM12);
			 SET_BIT(TCCR1B,WGM13);
			 
	#elif TIMER1_U8_WAVRFORM_MODE == TIMER1_U8_PWM_PHASE_CORRECT_ICR1 		 
			 CLEAR_BIT(TCCR1A,WGM10);
			 CLEAR_BIT(TCCR1A,WGM11);
			 CLEAR_BIT(TCCR1B,WGM12);
			 SET_BIT(TCCR1B,WGM13);
			 
	#elif TIMER1_U8_WAVRFORM_MODE == TIMER1_U8_PWM_PHASE_CORRECT_OCR1A
	          SET_BIT(TCCR1A,WGM10);
	          SET_BIT(TCCR1A,WGM11);
	          CLEAR_BIT(TCCR1B,WGM12);
	          SET_BIT(TCCR1B,WGM13);
			 
	#elif TIMER1_U8_WAVRFORM_MODE == TIMER1_U8_CTC_ICR1		 
			  CLEAR_BIT(TCCR1A,WGM10);
			  CLEAR_BIT(TCCR1A,WGM11);
			  SET_BIT(TCCR1B,WGM12);
			  SET_BIT(TCCR1B,WGM13);
			 		 
	#elif TIMER1_U8_WAVRFORM_MODE == TIMER1_U8_FAST_PWM_ICR1
	          CLEAR_BIT(TCCR1A,WGM10);
	          SET_BIT(TCCR1A,WGM11);
	          SET_BIT(TCCR1B,WGM12);
	          SET_BIT(TCCR1B,WGM13);
			  
	#elif TIMER1_U8_WAVRFORM_MODE == TIMER1_U8_FAST_PWM_OCR1A		  
			  SET_BIT(TCCR1A,WGM10);
			  SET_BIT(TCCR1A,WGM11);
			  SET_BIT(TCCR1B,WGM12);
			  SET_BIT(TCCR1B,WGM13);
			  		 			 		
	#endif

    #ifdef TIMER1_CHANNEL_A_ENABLE
	      #if TIMER1_U8_CHANNEL_A_COMPARE_OUTPUT_MODE == TIMER1_U8_OC1_DISCONNECTED
	              CLEAR_BIT(TCCR1A, COM1A0);
	              CLEAR_BIT(TCCR1A, COM1A1);
	      		
	      #elif TIMER1_U8_CHANNEL_A_COMPARE_OUTPUT_MODE == TIMER1_U8_OC1_TOGGLE
	              SET_BIT(TCCR1A, COM1A0);
	              CLEAR_BIT(TCCR1A, COM1A1);
	      
	      #elif TIMER1_U8_CHANNEL_A_COMPARE_OUTPUT_MODE == TIMER1_U8_OC1_CLEAR
	              CLEAR_BIT(TCCR1A, COM1A0);
	              SET_BIT(TCCR1A, COM1A1);
	      
	      #elif TIMER1_U8_CHANNEL_A_COMPARE_OUTPUT_MODE == TIMER1_U8_OC1_SET
	              SET_BIT(TCCR1A, COM1A0);
	              SET_BIT(TCCR1A, COM1A1);
	      
	      #endif
	#endif
    #ifdef TIMER1_CHANNEL_B_ENABLE
         #if TIMER1_U8_CHANNEL_B_COMPARE_OUTPUT_MODE == TIMER1_U8_OC1_DISCONNECTED
         CLEAR_BIT(TCCR1A, COM1B0);
         CLEAR_BIT(TCCR1A, COM1B1);
         
         #elif TIMER1_U8_CHANNEL_B_COMPARE_OUTPUT_MODE == TIMER1_U8_OC1_TOGGLE
         SET_BIT(TCCR1A, COM1B0);
         CLEAR_BIT(TCCR1A, COM1B1);
         
         #elif TIMER1_U8_CHANNEL_B_COMPARE_OUTPUT_MODE == TIMER1_U8_OC1_CLEAR
         CLEAR_BIT(TCCR1A, COM1B0);
         SET_BIT(TCCR1A, COM1B1);
         
         #elif TIMER1_U8_CHANNEL_B_COMPARE_OUTPUT_MODE == TIMER1_U8_OC1_SET
         SET_BIT(TCCR1A, COM1B0);
         SET_BIT(TCCR1A, COM1B1);
         
         #endif	
	#endif
	/*  Set Prescaler */
	
	#if TIMER1_U8_PRESCALER == TIMER1_U8_STOP
	          /* No Clock Source  */
	          CLEAR_BIT(TCCR1B,CS10);
	          CLEAR_BIT(TCCR1B,CS11);
	          CLEAR_BIT(TCCR1B,CS12);
	#elif TIMER1_U8_PRESCALER == TIMER1_U8_DIVIDED_BY_1
	          /* No Prescaling  */
	          SET_BIT(TCCR1B,CS10);
	          CLEAR_BIT(TCCR1B,CS11);
	          CLEAR_BIT(TCCR1B,CS12);
	#elif TIMER1_U8_PRESCALER == TIMER1_U8_DIVIDED_BY_8
	          /* Division by 8  */
	          CLEAR_BIT(TCCR1B,CS10);
	          SET_BIT(TCCR1B,CS11);
	          CLEAR_BIT(TCCR1B,CS12);
	#elif TIMER1_U8_PRESCALER == TIMER1_U8_DIVIDED_BY_64
	          /* Division by 64 */
	          SET_BIT(TCCR1B,CS10);
	          SET_BIT(TCCR1B,CS11);
	          CLEAR_BIT(TCCR1B,CS12);
	#elif TIMER1_U8_PRESCALER == TIMER1_U8_DIVIDED_BY_256
	          /* Division by 256  */
	          CLEAR_BIT(TCCR1B,CS10);
	          CLEAR_BIT(TCCR1B,CS11);
	          SET_BIT(TCCR1B,CS12);
	#elif TIMER1_U8_PRESCALER == TIMER1_U8_DIVIDED_BY_1024
	          /* Division by 1024*/
	          SET_BIT(TCCR1B,CS10);
	          CLEAR_BIT(TCCR1B,CS11);
	          SET_BIT(TCCR1B,CS12);
	#endif
	 
	#if TIMER1_U8_INPUT_CAPURE == TIMER1_U8_RISING_INPUT_CAPURE 
	          SET_BIT(TCCR1B, ICES1);
	#elif TIMER1_U8_INPUT_CAPURE == TIMER1_U8_FALING_INPUT_CAPURE		  
	          CLEAR_BIT(TCCR1B, ICES1);
	#endif   
#endif
	

/************************************************************************/
/*           	/*      TIMER 2    */                                                           
/************************************************************************/


/* SET MODE  */
#ifdef TIMER2_ENABLE
      #if TIMER2_U8_WAVRFORM_MODE == TIMER2_U8_NORMAL
              CLEAR_BIT(TCCR2,WGM20);
              CLEAR_BIT(TCCR2,WGM21);
      
      #elif TIMER2_U8_WAVRFORM_MODE == TIMER2_U8_PWM_PHASE_CORRECT
              SET_BIT(TCCR2,WGM20);
              CLEAR_BIT(TCCR2,WGM21);
      
      #elif TIMER2_U8_WAVRFORM_MODE == TIMER2_U8_CTC
              CLEAR_BIT(TCCR2,WGM20);
              SET_BIT(TCCR2,WGM21);
      
      #elif TIMER2_U8_WAVRFORM_MODE == TIMER2_U8_FAST_PWM
              SET_BIT(TCCR2,WGM20);
              SET_BIT(TCCR2,WGM21);
      #endif
      
      #if TIMER2_U8_COMPARE_OUTPUT_MODE == TIMER2_U8_OC2_DISCONNECTED
              CLEAR_BIT(TCCR2, COM20);
              CLEAR_BIT(TCCR2, COM21);
      #elif TIMER2_U8_COMPARE_OUTPUT_MODE == TIMER2_U8_OC2_TOGGLE
                #if	TIMER2_U8_WAVRFORM_MODE == TIMER2_U8_PWM_PHASE_CORRECT || TIMER2_U8_WAVRFORM_MODE == TIMER2_U8_FAST_PWM
                #warning ("CHOOSED UNAVAILABLE OPTION IN TIMER OUTPUT MODE!!")
               
			    #else
                      SET_BIT(TCCR2, COM20);
                      CLEAR_BIT(TCCR2, COM21);
      
                #endif
      #elif TIMER2_U8_COMPARE_OUTPUT_MODE == TIMER2_U8_OC2_CLEAR
             CLEAR_BIT(TCCR2, COM20);
             SET_BIT(TCCR2, COM21);
      
      #elif TIMER2_U8_COMPARE_OUTPUT_MODE == TIMER2_U8_OC2_SET
             SET_BIT(TCCR2, COM20);
             SET_BIT(TCCR2, COM21);
      #endif
      
      /*  Set Prescaler */
      
      #if TIMER2_U8_PRESCALER == TIMER2_U8_STOP
             /* No Clock Source  */
             CLEAR_BIT(TCCR2,CS20);
             CLEAR_BIT(TCCR2,CS21);
             CLEAR_BIT(TCCR2,CS22);
      #elif TIMER2_U8_PRESCALER == TIMER2_U8_DIVIDED_BY_1
             /* No Prescaling  */
             SET_BIT(TCCR2,CS20);
             CLEAR_BIT(TCCR2,CS21);
             CLEAR_BIT(TCCR2,CS22);
      #elif TIMER2_U8_PRESCALER == TIMER2_U8_DIVIDED_BY_8
             /* Division by 8  */
             CLEAR_BIT(TCCR2,CS20);
             SET_BIT(TCCR2,CS21);
             CLEAR_BIT(TCCR2,CS22);
	  #elif TIMER2_U8_PRESCALER == TIMER2_U8_DIVIDED_BY_32
             /* Division by 32 */
             SET_BIT(TCCR2,CS20);
             SET_BIT(TCCR2,CS21);
             CLEAR_BIT(TCCR2,CS22);
      #elif TIMER2_U8_PRESCALER == TIMER2_U8_DIVIDED_BY_64
             /* Division by 64  */
             CLEAR_BIT(TCCR2,CS20);
             CLEAR_BIT(TCCR2,CS21);
             SET_BIT(TCCR2,CS22);
      #elif TIMER2_U8_PRESCALER == TIMER2_U8_DIVIDED_BY_128
             /* Division by 128*/
             SET_BIT(TCCR2,CS20);
             CLEAR_BIT(TCCR2,CS21);
             SET_BIT(TCCR2,CS22);
	  #elif TIMER2_U8_PRESCALER == TIMER2_U8_DIVIDED_BY_256
			  /* Division by 256*/
			  CLEAR_BIT(TCCR2,CS20);
			  SET_BIT(TCCR2,CS21);
			  SET_BIT(TCCR2,CS22);
      #elif TIMER2_U8_PRESCALER == TIMER2_U8_DIVIDED_BY_1024
              /* Division by 1024*/
              SET_BIT(TCCR2,CS00);
              SET_BIT(TCCR2,CS21);
              SET_BIT(TCCR2,CS22);

      #endif
      /* Set Interrupt */
      #if TIMER2_U8_INTERRUPT == TIMER2_U8_ENABLE_INTERRUPT
           #if TIMER2_U8_WAVRFORM_MODE == TIMER2_U8_NORMAL
           SET_BIT(TIMSK,TOIE2);
           #elif TIMER2_U8_WAVRFORM_MODE ==  TIMER2_U8_CTC
           SET_BIT(TIMSK,OCIE2);
           #endif
      #endif
#endif

/*          TIMER0                      */

void TIMER0_voidSetOVFRegister(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value;
}
void TIMER0_voidSetCTCRegister(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}

void TIMER0_voidEnableOVFINT(void)
{
	SET_BIT(TIMSK, TOIE0);
}
void TIMER0_voidDisableOVFINT(void)
{
	CLEAR_BIT(TIMSK, TOIE0);
}
void TIMER0_voidClearOVFFlag(void)
{
	SET_BIT(TIFR, TOV0);
}

void TIMER0_voidEnableCTCINT(void)
{
	SET_BIT(TIMSK, OCIE0);
}
void TIMER0_voidDisableCTCINT(void)
{
	CLEAR_BIT(TIMSK, OCIE0);
}
void TIMER0_voidClearCTCFlag(void)
{
	SET_BIT(TIFR, OCF0);
}

void TIMER0_voidSetOVFCallBack(void(*Copy_pvCallBack)(void))
{
	if (Copy_pvCallBack != NULL)
	{
		TIMER_CallBack[TIMER0_OVF_CALLBACK_INDEX] = Copy_pvCallBack;
	}
}
void TIMER0_voidSetCTCCallBack(void(*Copy_pvCallBack)(void))
{
	if (Copy_pvCallBack != NULL)
	{
		TIMER_CallBack[TIMER0_CTC_CALLBACK_INDEX] = Copy_pvCallBack;
	}
}

void TIMER0_voidForceOutputCompare(void)
{
	SET_BIT(TCCR0, FOC0);
}

void __vector_11(void)
{
	TIMER_CallBack[TIMER0_OVF_CALLBACK_INDEX]();
	TIMER0_voidClearOVFFlag();
}
void __vector_10(void)
{
	TIMER_CallBack[TIMER0_CTC_CALLBACK_INDEX]();
	TIMER0_voidClearCTCFlag();
}


/*                     TIMER1                                      */

void TIMER1_voidSetOVFRegister(u16 Copy_u16Value)
{
	TCNT1 = Copy_u16Value;
}
void TIMER1_voidChannelASetCTCRegister(u16 Copy_u16Value)
{
	OCR1A = Copy_u16Value;
}
void TIMER1_voidChannelBSetCTCRegister(u16 Copy_u16Value)
{
	OCR1B = Copy_u16Value;
}
u16  TIMER1_u16InputCaptureValue(void)
{
	return ICR1;
}

void TIMER1_voidEnableOVFINT(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void TIMER1_voidDisableOVFINT(void)
{
	CLEAR_BIT(TIMSK,TOIE1);
}
void TIMER1_voidClearOVFFlag(void)
{
	SET_BIT(TIFR, TOV1);
}

void TIMER1_voidChannel_A_EnableCTCINT(void)
{
	SET_BIT(TIMSK,OCR1A);
}
void TIMER1_voidChannel_A_DisableCTCINT(void)
{
	CLEAR_BIT(TIMSK,OCR1A);
}
void TIMER1_voidChannel_A_ClearCTCFlag(void)
{
	SET_BIT(TIFR, OCF1A);
}


void TIMER1_voidChannel_B_EnableCTCINT(void){
	SET_BIT(TIMSK,OCIE1B);
}

void TIMER1_voidChannel_B_DisableCTCINT(void){
	CLEAR_BIT(TIMSK,OCIE1B);
}

void TIMER1_voidChannel_B_ClearCTCFlag(void){
	SET_BIT(TIFR,OCF1B);
}

void TIMER1_voidEnableInputCaptureINT(void){
	SET_BIT(TIMSK,TICIE1);
}

void TIMER1_voidDisableInputCaptureINT(void){
	CLEAR_BIT(TIMSK,TICIE1);
}

void TIMER1_voidClearInputCaptureFlag(void){
	SET_BIT(TIFR,ICF1);
}

void TIMER1_voidSetOVFCallBack(void (*Copy_pvCallBack) (void))
{
	TIMER_CallBack[TIMER1_OVF_CALLBACK_INDEX] = Copy_pvCallBack;
}

void TIMER1_voidChannel_A_SetCTCCallBack(void (*Copy_pvCallBack) (void))
{
	TIMER_CallBack[TIMER1_CTCCHANNEL_A_CALLBACK_INDEX] = Copy_pvCallBack;
}


void TIMER1_voidChannel_B_SetCTCCallBack(void (*Copy_pvCallBack) (void)
){
	TIMER_CallBack[TIMER1_CTCCHANNEL_B_CALLBACK_INDEX] = Copy_pvCallBack;
}

void TIMER1_voidSetInputCaptureCallBack(void (*Copy_pvCallBack) (void))
{
	TIMER_CallBack[TIMER1_INPUT_CAPURE_CALLBACK_INDEX] = Copy_pvCallBack;
}

void TIMER1_voidChannel_A_ForceOutputCompare(void)
{
	SET_BIT(TCCR1A,FOC1A);
}

void TIMER1_voidChannel_B_ForceOutputCompare(void)
{
	SET_BIT(TCCR1A,FOC1B);
}


void __vector_6(void)
{
	TIMER_CallBack[TIMER1_INPUT_CAPURE_CALLBACK_INDEX]();
	TIMER1_voidClearInputCaptureFlag();
}

void __vector_7(void)
{
	TIMER_CallBack[TIMER1_CTCCHANNEL_A_CALLBACK_INDEX]();
	TIMER1_voidChannel_A_ClearCTCFlag();
}

void __vector_8(void)
{
	TIMER_CallBack[TIMER1_CTCCHANNEL_A_CALLBACK_INDEX]();
	TIMER1_voidChannel_B_ClearCTCFlag();
}

void __vector_9(void)
{
	TIMER_CallBack[TIMER1_OVF_CALLBACK_INDEX]();
	TIMER1_voidClearOVFFlag();
}



/*										TIMER2											*/



void TIMER2_voidSetOVFRegister(u8 Copy_u8Value)
{
	TCNT2 = Copy_u8Value;
}

void TIMER2_voidSetCTCRegister(u8 Copy_u8Value)
{
	OCR2 = Copy_u8Value;
}

void TIMER2_voidEnableOVFINT(void)
{
	SET_BIT(TIMSK , TOIE2);

}

void TIMER2_voidDisableOVFINT(void)
{
	CLEAR_BIT(TIMSK , TOIE2);
}

void TIMER2_voidClearOVFFlag(void)
{
	SET_BIT(TIFR , TOV2);

}


void TIMER2_voidEnableCTCINT(void)
{
	SET_BIT(TIMSK , OCIE2);
}


void TIMER2_voidDisableCTCINT(void)
{
	CLEAR_BIT(TIMSK , OCIE2);
}


void TIMER2_voidClearCTCFlag(void)
{
	SET_BIT(TIFR , OCF2);
}

void TIMER2_voidSetCTCCallBack(void (*Copy_pvCallBack) (void))
{
	if(Copy_pvCallBack != NULL)
		TIMER_CallBack[TIMER2_CTC_CALLBACK_INDEX] = Copy_pvCallBack;
	

}


void TIMER2_voidSetOVFCallBack(void (*Copy_pvCallBack) (void))
{
	if(Copy_pvCallBack != NULL)
		TIMER_CallBack[TIMER2_OVF_CALLBACK_INDEX] = Copy_pvCallBack;
	
}

void TIMER2_voidForceOutputCompare(void)
{
	SET_BIT(TCCR2,FOC2);
}

void __vector_5(void)
{
	TIMER_CallBack[TIMER2_OVF_CALLBACK_INDEX]();
	TIMER2_voidClearOVFFlag();
}


void __vector_4(void)
{
	TIMER_CallBack[TIMER2_CTC_CALLBACK_INDEX]();
	TIMER2_voidClearCTCFlag();
}
