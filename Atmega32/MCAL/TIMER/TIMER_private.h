/******************************************/
/******************************************/
/*******   Author:   Amin Darwish  ********/
/*******   Layer        MCAL       ********/
/*******   Module:      TIMER     ********/
/*******   Version:     1.0        ********/
/******************************************/                               
/******************************************/


#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define NULL     0

#define TIMER0_OVF_CALLBACK_INDEX              0
#define TIMER1_OVF_CALLBACK_INDEX              1
#define TIMER2_OVF_CALLBACK_INDEX              2

#define TIMER0_CTC_CALLBACK_INDEX              3
#define TIMER1_CTCCHANNEL_A_CALLBACK_INDEX     4
#define TIMER1_CTCCHANNEL_B_CALLBACK_INDEX     5
#define TIMER2_CTC_CALLBACK_INDEX              6

#define TIMER1_INPUT_CAPURE_CALLBACK_INDEX     7

void (*TIMER_CallBack[8])(void) = {NULL};

/************************************************************************/
/*                             TIMER 0 REGISTER                                            */
/************************************************************************/


#define TCCR0      (* (volatile u8 *)(0x53))
#define TCNT0      (* (volatile u8 *)(0x52))
#define OCR0	   (* (volatile u8 *)(0x5C))
#define TIMSK	   (* (volatile u8 *)(0x59))
#define TIFR	   (* (volatile u8 *)(0x58))

/*          TCCR0 - Timer/Counter Control Register  */

#define FOC0    7     // Force Output Compare
#define WGM00   6     //  Waveform Generation Mode 
#define COM01   5     //  Compare Match Output Mode
#define COM00   4     //  Compare Match Output Mode
#define WGM01   3     //  Waveform Generation Mode 
#define CS02    2     // Clock Select
#define CS01    1     // Clock Select
#define CS00    0     // Clock Select

/*              TIMSK – Timer/Counter Interrupt Mask Register                         */
#define OCIE0   1     // Timer/Counter0 Output Compare Match Interrupt Enable
#define TOIE0   0     // Timer/Counter0 Overflow Interrupt Enable

/*              TIFR – Timer/Counter Interrupt Flag Register                       */
#define OCF0    1     //  Output Compare Flag 0
#define TOV0    0     //  Overflow Flag


void __vector_11(void) __attribute__((signal));
void __vector_10(void) __attribute__((signal));

/************************************************************************/
/*                             TIMER 1 REGISTER                                            */
/************************************************************************/



#define TCCR1A   (* (volatile u8 *)(0x4F))
#define TCCR1B   (* (volatile u8 *)(0x4E))
#define TCNT1	 (* (volatile u8 *)(0x4C))
#define OCR1A	 (* (volatile u8 *)(0x4A))
#define OCR1B	 (* (volatile u8 *)(0x48))
#define ICR1	 (* (volatile u8 *)(0x46))

/*            TCCR1A – Timer/Counter1 Control Register A        */
#define COM1A1  7
#define COM1A0	6
#define COM1B1	5
#define COM1B0	4
#define FOC1A	3
#define FOC1B	2
#define WGM11	1
#define WGM10	0

/*               TCCR1B – Timer/Counter1 Control Register B                         */

#define ICNC1   7
#define ICES1   6
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

/*              TIMSK – Timer/Counter Interrupt Mask Register                         */

#define TICIE1	5       // Timer/Counter1, Input Capture Interrupt Enable
#define OCIE1A	4       // Timer/Counter1, Output Compare A Match Interrupt Enable
#define OCIE1B	3       // Timer/Counter1, Output Compare B Match Interrupt Enable
#define TOIE1	2       // Timer/Counter1, Overflow Interrupt Enable

/*               TIFR – Timer/Counter Interrupt Flag Register                        */

#define ICF1	5       //  Timer/Counter1, Input Capture Flag
#define OCF1A	4       //  Timer/Counter1, Output Compare A Match Flag
#define OCF1B	3       //  Timer/Counter1, Output Compare B Match Flag
#define TOV1	2       //  Timer/Counter1, Overflow Flag


void __vector_6(void) __attribute__((signal));
void __vector_7(void) __attribute__((signal));
void __vector_8(void) __attribute__((signal));
void __vector_9(void) __attribute__((signal));

/************************************************************************/
/*                             TIMER 2 REGISTER                                            */
/************************************************************************/

#define TCCR2      (* (volatile u8 *)(0x45))
#define TCNT2      (* (volatile u8 *)(0x44))
#define OCR2	   (* (volatile u8 *)(0x43))

/*          TCCR2 - Timer/Counter Control Register  */

#define FOC2    7     // Force Output Compare
#define WGM20   6     //  Waveform Generation Mode
#define COM21   5     //  Compare Match Output Mode
#define COM20   4     //  Compare Match Output Mode
#define WGM21   3     //  Waveform Generation Mode
#define CS22    2     // Clock Select
#define CS21    1     // Clock Select
#define CS20    0     // Clock Select

/*              TIMSK – Timer/Counter Interrupt Mask Register                         */

#define OCIE2   7     // Timer/Counter2 Output Compare Match Interrupt Enable
#define TOIE2   6     // Timer/Counter2 Overflow Interrupt Enable

/*              TIFR – Timer/Counter Interrupt Flag Register                       */
#define OCF2    7     //  Output Compare Flag 0
#define TOV2    6     //  Overflow Flag


void __vector_4(void) __attribute__((signal));
void __vector_5(void) __attribute__((signal));




#endif