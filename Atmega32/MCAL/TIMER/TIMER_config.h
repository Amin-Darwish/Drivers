/******************************************/
/******************************************/
/*******   Author:   Amin Darwish  ********/
/*******                           ********/
/*******   Module:  TIMER CONFIG    ********/
/*******   Version:     1.0        ********/
/******************************************/
/******************************************/

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


/*
          TIMER0 CONFIGURATION
          
          UNCOMMMENT TO ENABLE TIMER 0
          COMMMENT TO DISABLE TIMER 0
  
*/

 #define TIMER0_ENABLE
 

/*
              Waveform Generation Mode  (WGM)
			  
	OPTIONS:-
	
	          1- TIMER0_U8_NORMAL
			  2- TIMER0_U8_PWM_PHASE_CORRECT  
			  3- TIMER0_U8_CTC 
              4- TIMER0_U8_FAST_PWM
*/
			  
#define TIMER0_U8_WAVRFORM_MODE  TIMER0_U8_CTC

/*
            COMPARE MATCH OUPUT MODE OC0 (PORTB 3)
			 
OPTIONS (non_PWM MODE):-
	                 1-TIMER0_U8_OC0_DISCONNECTED
					 2-TIMER0_U8_OC0_TOGGLE
					 3-TIMER0_U8_OC0_CLEAR
					 4-TIMER0_U8_OC0_SET
              
OPTIONS (FAST_PWM MODE):-
                     1-TIMER0_U8_OC0_DISCONNECTED
                     2-TIMER0_U8_OC0_CLEAR       (Clear OC0 on compare, Set OC0 on Top )
                     3-TIMER0_U8_OC0_SET         (Set OC0 on compare, Clear OC0 on Top )


OPTIONS (PHASE_CORRECT_PWM MODE):-

                     1-TIMER0_U8_OC0_DISCONNECTED                                          
                     2-TIMER0_U8_OC0_CLEAR       (Clear OC0 on compare, Set OC0 on Top ) 
                     3-TIMER0_U8_OC0_SET         (Set OC0 on compare, Clear OC0 on Top ) 
*/


#define TIMER0_U8_COMPARE_OUTPUT_MODE    TIMER0_U8_OC0_DISCONNECTED

/*
                           PRESCALER

OPTIONS:-
          1-TIMER0_U8_STOP                 NO CLOCK SOURCE
		  2-TIMER0_U8_DIVIDED_BY_1
		  3-TIMER0_U8_DIVIDED_BY_8
		  4-TIMER0_U8_DIVIDED_BY_64
		  5-TIMER0_U8_DIVIDED_BY_256
		  6-TIMER0_U8_DIVIDED_BY_1024
*/

#define TIMER0_U8_PRESCALER          TIMER0_U8_DIVIDED_BY_256

/*
                    INTERRUPT
OPTIONS:-   
               1-TIMER0_U8_DISABLE_INTERRUPT
			   2-TIMER0_U8_ENABLE_INTERRUPT
*/

#define TIMER0_U8_INTERRUPT          TIMER0_U8_ENABLE_INTERRUPT 


/************************************************************************/
/*                  TIMER1 CONFIGURATION                                                        */
/************************************************************************/
                          
/*
          
          
          UNCOMMMENT TO ENABLE  TIMER 1
          COMMMENT   TO DISABLE TIMER 1
		  UNCOMMMENT TO ENABLE  TIMER 1  CHANNEL A
		  COMMMENT   TO DISABLE TIMER 1  CHANNEL A 
		  UNCOMMMENT TO ENABLE  TIMER 1  CHANNEL B
		  COMMMENT   TO DISABLE TIMER 1  CHANNEL B
		   
*/

// #define TIMER1_ENABLE
// #define TIMER1_CHANNEL_A_ENABLE 
 //#define TIMER1_CHANNEL_B_ENABLE

/*
              Waveform Generation Mode  (WGM)
			  
	OPTIONS:-
	
	          1- TIMER1_U8_NORMAL
			  2- TIMER1_U8_PWM_PHASE_CORRECT_8_BIT  
			  3- TIMER1_U8_PWM_PHASE_CORRECT_9_BIT 
              4- TIMER1_U8_PWM_PHASE_CORRECT_10_BIT
			  5- TIMER1_U8_CTC_OCR1A
			  6- TIMER1_U8_FAST_PWM_8_BIT
			  7- TIMER1_U8_FAST_PWM_9_BIT
			  8- TIMER1_U8_FAST_PWM_10_BIT
			  9- TIMER1_U8_PWM_PHASE_FREQUENCY_CORRECT_ICR1
			  10-TIMER1_U8_PWM_PHASE_FREQUENCY_CORRECT_OCR1A
			  11-TIMER1_U8_PWM_PHASE_CORRECT_ICR1
			  12-TIMER1_U8_PWM_PHASE_CORRECT_OCR1A
			  13-TIMER1_U8_CTC_ICR1 
			  14-TIMER1_U8_FAST_PWM_ICR1
			  15-TIMER1_U8_FAST_PWM_OCR1A
			  
*/
			  
#define TIMER1_U8_WAVRFORM_MODE    TIMER1_U8_NORMAL


/*
            COMPARE MATCH OUPUT MODE OC1A,OC1B (PORTD 4,5)
			 
OPTIONS (non_PWM MODE):-
	                 1-TIMER1_U8_OC1_DISCONNECTED      (Normal port operation, OC1A/OC1B disconnected)
					 2-TIMER1_U8_OC1_TOGGLE            (Toggle OC1A/OC1B on compare match )   
					 3-TIMER1_U8_OC1_CLEAR             (Clear OC1A/OC1B on compare match )
					 4-TIMER1_U8_OC1_SET               (Set OC1A/OC1B on compare match )
              
OPTIONS (FAST_PWM MODE):-
                     1-TIMER1_U8_OC1_DISCONNECTED      (Normal port operation, OC1A/OC1B disconnected)
                     2-TIMER1_U8_OC1_TOGGLE            ( WGM13:0 = 15: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation). For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected)
                     3-TIMER1_U8_OC1_CLEAR              (Clear OC1A/OC1B on compare, Set OC1A/OC1B on Bottom )
				     4-TIMER1_U8_OC1_SET                (Set OC1A/OC1B on compare, Clear OC1A/OC1B on Bottom )
				                                       


OPTIONS (Phase Correct and Phase and Frequency Correct PWM):-

                     1-TIMER1_U8_OC1_DISCONNECTED      (Normal port operation, OC1A/OC1B disconnected)                                      
                     2-TIMER1_U8_OC1_TOGGLE            ((WGM13:0 = 9 or 14: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation). For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected)
                     3-TIMER1_U8_OC1_CLEAR             (Clear OC0 on compare, Set OC0 on Top ) 
					 4-TIMER1_U8_OC1_SET               (Set OC0 on compare, Clear OC0 on Top ) 
					 
*/ 


#define TIMER1_U8_CHANNEL_A_COMPARE_OUTPUT_MODE        TIMER1_U8_OC1_DISCONNECTED
#define TIMER1_U8_CHANNEL_B_COMPARE_OUTPUT_MODE        TIMER1_U8_OC1_DISCONNECTED

/*
                           PRESCALER

OPTIONS:-
          1-TIMER1_U8_STOP                 NO CLOCK SOURSE
		  2-TIMER1_U8_DIVIDED_BY_1
		  3-TIMER1_U8_DIVIDED_BY_8
		  4-TIMER1_U8_DIVIDED_BY_32
		  5-TIMER1_U8_DIVIDED_BY_64
		  6-TIMER1_U8_DIVIDED_BY_128
		  7-TIMER1_U8_DIVIDED_BY_256
		  8-TIMER1_U8_DIVIDED_BY_1024
*/

#define TIMER1_U8_PRESCALER TIMER1_U8_DIVIDED_BY_1

/*
                    INPUT CAPURE EDGE SELECT
OPTIONS:-   
               1-TIMER1_U8_FALING_INPUT_CAPURE
			   2-TIMER1_U8_RISING_INPUT_CAPURE
			   
*/

#define TIMER1_U8_INPUT_CAPURE   TIMER1_U8_RISING_INPUT_CAPURE 

/************************************************************************/
/*                                                                      */
/************************************************************************/



/*
          TIMER2 CONFIGURATION
          
          UNCOMMMENT TO ENABLE TIMER 2
          COMMMENT TO DISABLE TIMER 2
  
*/

// #define TIMER2_ENABLE
 

/*
              Waveform Generation Mode  (WGM)
			  
	OPTIONS:-
	
	          1- TIMER2_U8_NORMAL
			  2- TIMER2_U8_PWM_PHASE_CORRECT  
			  3- TIMER2_U8_CTC 
              4- TIMER2_U8_FAST_PWM
*/
			  
#define TIMER2_U8_WAVRFORM_MODE TIMER2_U8_NORMAL

/*
            COMPARE MATCH OUPUT MODE OC2 (PORTD 7)
			 
OPTIONS (non_PWM MODE):-
	                 1-TIMER2_U8_OC2_DISCONNECTED
					 2-TIMER2_U8_OC2_TOGGLE
					 3-TIMER2_U8_OC2_CLEAR
					 4-TIMER2_U8_OC2_SET
              
OPTIONS (FAST_PWM MODE):-
                     1-TIMER2_U8_OC2_DISCONNECTED
                     2-TIMER2_U8_OC2_CLEAR       (Clear OC2 on compare, Set OC2 on Top )
                     3-TIMER2_U8_OC2_SET         (Set OC2 on compare, Clear OC2 on Top )


OPTIONS (PHASE_CORRECT_PWM MODE):-

                     1-TIMER2_U8_OC2_DISCONNECTED                                          
                     2-TIMER2_U8_OC2_CLEAR       (Clear OC2 on compare, Set OC2 on Top ) 
                     3-TIMER2_U8_OC2_SET         (Set OC2 on compare, Clear OC2 on Top ) 
*/


#define TIMER2_U8_COMPARE_OUTPUT_MODE TIMER2_U8_OC2_DISCONNECTED

/*
                           PRESCALER

OPTIONS:-
          1-TIMER2_U8_STOP                 NO CLOCK SOURSE
		  2-TIMER2_U8_DIVIDED_BY_1
		  3-TIMER2_U8_DIVIDED_BY_8
		  4-TIMER2_U8_DIVIDED_BY_64
		  5-TIMER2_U8_DIVIDED_BY_256
		  6-TIMER2_U8_DIVIDED_BY_1024
*/

#define TIMER2_U8_PRESCALER TIMER2_U8_DIVIDED_BY_1

/*
                    INTERUPPT
OPTIONS:-   
               1-TIMER2_U8_ENABLE_INTERRUPT
			   2-TIMER2_U8_DISABLE_INTERRUPT
*/

#define TIMER2_U8_INTERRUPT   TIMER2_U8_DISABLE_INTERRUPT 



#endif