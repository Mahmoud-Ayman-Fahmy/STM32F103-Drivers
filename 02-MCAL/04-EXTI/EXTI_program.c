/*******************************************/
/* Author     : Mahmoud Ayman              */
/* Date       : 28 AUG 2020                */
/* Version    : V01                        */
/* File Name  : EXTI_program               */
/*******************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void EXTI_voidInit(u8 copy_u8Mode,u8 copy_u8Line)
{
	if(copy_u8Mode == RISING)
	{
		EXTI_REG->RTSR = (1 << copy_u8Line);
		//SET_BIT(EXTI_REG->RTSR,copy_u8Line);
	}
	else if(copy_u8Mode == FALLING)
	{
		EXTI_REG->FTSR = (1 << copy_u8Line);
		//SET_BIT(EXTI_REG->FTSR,copy_u8Line);
	}
	else if(copy_u8Mode == ON_CHANGE)
	{
		EXTI_REG->RTSR = (1 << copy_u8Line);
		//SET_BIT(EXTI_REG->RTSR,copy_u8Line);
		EXTI_REG->FTSR = (1 << copy_u8Line);
		//SET_BIT(EXTI_REG->FTSR,copy_u8Line);
	}
	else 
	{
		/* Return Error */
	}
	/* Disable Interrupt */
	CLR_BIT(EXTI_REG->IMR,copy_u8Line);
}

void EXTI_voidEnableEXTI(u8 copy_u8Line)
{
	SET_BIT(EXTI_REG->IMR,copy_u8Line);
}

void EXTI_voidDisableEXTI(u8 copy_u8Line)
{
	CLR_BIT(EXTI_REG->IMR,copy_u8Line);
}

void EXTI_voidSoftwareTrigger(u8 copy_u8Line)
{
	SET_BIT(EXTI_REG->SWIER,copy_u8Line);
}