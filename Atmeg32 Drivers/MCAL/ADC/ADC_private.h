/*
 * ADC_private.h
 *
 * Created: 9/22/2023 9:47:30 PM
 *  Author: amind
 */ 
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#define ADMUX				*((volatile u8*)0x27)		//ADC multiplexer selection register
/* ADMUX Bits   */
#define ADMUX_REFS1         7							//Reference selection bit1
#define ADMUX_REFS0         6							//Reference selection bit0
#define ADMUX_ADLAR         5							//ADC left adjust result

#define ADCSRA				*((volatile u8*)0x26)		//ADC control and status register A
/* ADSAR Bits   */
#define ADCSRA_ADEN			7							//ADC enable
#define ADCSRA_ADSC			6                           //Start conversion
#define ADCSRA_ADATE        5                           //Auto trigger enable
#define ADCSRA_ADIF			4                           //Interrupt flag
#define ADCSRA_ADIE			3                           //Interrupt enable
#define ADCSRA_ADPS2	    2                           //Prescaler bit2
#define ADCSRA_ADPS1	    1                           //Prescaler bit1
#define ADCSRA_ADPS0	    0                           //Prescaler bit0


/* Data Reg  */
#define ADCH				*((volatile u8*)0x25)		//ADC high register
#define ADCL				*((volatile u8*)0x24)		//ADC Low register
#define ADC_DATA_RE 		*((volatile u16*)0x24)		//ADC Low + High


#define SFIOR  *((volatile u8 *)0x50)
/* SFIOR Bits   */
#define ADTS2			7                          //Trigger Source bit2
#define ADTS1	     	6                          //Trigger Source bit1
#define ADTS0		    5                          //Trigger Source bit0





#endif /* ADC_PRIVATE_H_ */