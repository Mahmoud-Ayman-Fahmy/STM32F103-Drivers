/*************************************/
/* Author     : Mahmoud Ayman        */
/* Date       : 20 AUG 2020          */
/* Version    : V01                  */
/* File Name  : LED_program          */
/*************************************/

/* Libraries layer include */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Lower layer includes */
#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"
void LED_voidON(u8 copy_u8Port , u8 copy_u8Pin)
{
	switch(copy_u8Port)
	{
		case GPIOA : RCC_voidEnableClock(RCC_APB2,2);
					 break;
		case GPIOB : RCC_voidEnableClock(RCC_APB2,3);
					 break;
		case GPIOC : RCC_voidEnableClock(RCC_APB2,4);
					 break;
	}
	GPIO_voidSetPinDirection(copy_u8Port, copy_u8Pin, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
	GPIO_voidSetPinValue(copy_u8Port , copy_u8Pin, HIGH);
}

void LED_voidOFF(u8 copy_u8Port , u8 copy_u8Pin)
{
	switch(copy_u8Port)
	{
		case GPIOA : RCC_voidEnableClock(RCC_APB2,2);
					 break;
		case GPIOB : RCC_voidEnableClock(RCC_APB2,3);
					 break;
		case GPIOC : RCC_voidEnableClock(RCC_APB2,4);
					 break;
	}
	GPIO_voidSetPinDirection(copy_u8Port, copy_u8Pin, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
	GPIO_voidSetPinValue(copy_u8Port,copy_u8Pin,LOW);
}

void LED_voidTOGGLE(u8 copy_u8Port , u8 copy_u8Pin)
{
	u8 local_u8value = 0;
	//GPIO_voidSetPinDirction(copy_u8Port, copy_u8Pin, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);

	local_u8value = GPIO_u8GetPinValue( copy_u8Port , copy_u8Pin);
	if(local_u8value == HIGH)
	{
		GPIO_voidSetPinValue(copy_u8Port, copy_u8Pin, LOW);
	}
	else if(local_u8value == LOW)
	{
		GPIO_voidSetPinValue(copy_u8Port, copy_u8Pin, HIGH);
	}
}
