/*******************************************/
/* Author     : Mahmoud Ayman              */
/* Date       : 20 AUG 2020                */
/* Version    : V01.0                      */
/* File Name  : Switch_program             */
/*******************************************/

/* Libraries layer files include */  
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer files include */
#include "RCC_interface.h"
#include "GPIO_interface.h"

/* Driver files include */
#include "Switch_interface.h"
#include "Switch_private.h" 
#include "Switch_config.h"

void Switch_voidInit(u8 copy_u8PortId , u8 copy_u8PIN)
{
	switch(copy_u8PortId)
	{
		case GPIOA : RCC_voidEnableClock(RCC_APB2,2);
					 break;
		case GPIOB : RCC_voidEnableClock(RCC_APB2,3);
					 break;
		case GPIOC : RCC_voidEnableClock(RCC_APB2,4);
					 break;
	}
	#if    CONNECTION_TYPE == NORMAL_CONNECT
		GPIO_voidSetPinDirection(copy_u8PortId, copy_u8PIN, INPUT, INPUT_FLOATING, INPUT_SPEED);
	#elif  CONNECTION_TYPE == PULL_UP_CONNECT
		GPIO_voidSetPinDirection(copy_u8PortId, copy_u8PIN, INPUT, INPUT_PULLUP, INPUT_SPEED);
	#elif  CONNECTION_TYPE == PULL_DOWN_CONNECT
		GPIO_voidSetPinDirection(copy_u8PortId, copy_u8PIN, INPUT, INPUT_PULLDOWN, INPUT_SPEED);
	#endif
}

u8 Switch_u8GetPin(u8 copy_u8PortId , u8 copy_u8PIN)
{
	u8 local_u8value=0;
	local_u8value = GPIO_u8GetPinValue(copy_u8PortId, copy_u8PIN);
	return local_u8value;
}