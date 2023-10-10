/*
 * CFile1.c
 *
 * Created: 9/9/2023 8:32:42 PM
 *  Author: amind
 */ 
#include "EXTI_interface.h"


void EXTI_voidEnable(u8 Copy_u8SenseMode, u8 Copy_u8Line) {
   
    SET_BIT(SREG,GIE_BIT);  //General Interrupt Enable 
	switch (Copy_u8Line) 
	{

	case EXTI_LINE0:
		SET_BIT(GICR, GICR_INT0_BIT);
		   switch (Copy_u8SenseMode)
		     {
		        case EXTI_LOW_LEVEL:
		        	CLEAR_BIT(MCUCR, MCUCR_ISC00_BIT);
		        	CLEAR_BIT(MCUCR, MCUCR_ISC01_BIT);
		        	break;
		        case EXTI_ON_CHANGE:
		        	SET_BIT(MCUCR, MCUCR_ISC00_BIT);
		        	CLEAR_BIT(MCUCR, MCUCR_ISC01_BIT);
		        	break;
		        case EXTI_FALLING_EDGE:
		        	CLEAR_BIT(MCUCR, MCUCR_ISC00_BIT);
		        	SET_BIT(MCUCR, MCUCR_ISC01_BIT);
		        	break;
		        case EXTI_RISING_EDGE:
		        	SET_BIT(MCUCR, MCUCR_ISC00_BIT);
		        	SET_BIT(MCUCR, MCUCR_ISC01_BIT);
		        	break;
		       }
		break;

	case EXTI_LINE1:
		SET_BIT(GICR, GICR_INT1_BIT);
		switch (Copy_u8SenseMode) {
		case EXTI_LOW_LEVEL:
			CLEAR_BIT(MCUCR, MCUCR_ISC10_BIT);
			CLEAR_BIT(MCUCR, MCUCR_ISC11_BIT);
			break;
		case EXTI_ON_CHANGE:
			SET_BIT(MCUCR, MCUCR_ISC10_BIT);
			CLEAR_BIT(MCUCR, MCUCR_ISC11_BIT);
			break;
		case EXTI_FALLING_EDGE:
			CLEAR_BIT(MCUCR, MCUCR_ISC10_BIT);
			SET_BIT(MCUCR, MCUCR_ISC11_BIT);
			break;
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCR, MCUCR_ISC10_BIT);
			SET_BIT(MCUCR, MCUCR_ISC11_BIT);
			break;
		}
		break;

	case EXTI_LINE2:
		SET_BIT(GICR, GICR_INT2_BIT);
		switch (Copy_u8SenseMode) {
		case EXTI_FALLING_EDGE:
			CLEAR_BIT(MCUCSR, MCUCSR_ISC2_BIT);
			break;
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCSR, MCUCSR_ISC2_BIT);
			break;
		}
		break;
	}
}

void EXTI_voidDisable(u8 Copy_u8Line) {
	switch (Copy_u8Line) {
		case EXTI_LINE0:
		CLEAR_BIT(GICR, GICR_INT0_BIT);
		break;
		case EXTI_LINE1:
		CLEAR_BIT(GICR, GICR_INT1_BIT);
		break;
		case EXTI_LINE2:
		CLEAR_BIT(GICR, GICR_INT2_BIT);
		break;
	}
}


void EXTI_voidClearFlag(u8 Copy_u8Line) {
	switch (Copy_u8Line) {
		case EXTI_LINE0:
		SET_BIT(GIFR, GIFR_INTF0_BIT);
		break;
		case EXTI_LINE1:
		SET_BIT(GIFR, GIFR_INTF1_BIT);
		break;
		case EXTI_LINE2:
		SET_BIT(GICR, GICR_INT2_BIT);
		break;
	}
}

