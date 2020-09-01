/*******************************************/
/* Author     : Mahmoud Ayman              */
/* Date       : 20 AUG 2020                */
/* Version    : V01.0                      */
/* File Name  : SevenSegment_program       */
/*******************************************/

/* Libraries layer files include */  
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer files include */
#include "RCC_interface.h"
#include "GPIO_interface.h"

/* Driver files include */
#include "SevenSegment_interface.h"
#include "SevenSegment_private.h" 
#include "SevenSegment_config.h"

void SevenSegment_voidDisplay(u8 copy_u8Port ,u8 copy_u8value)
{
	u8 local_u8displayarray[10]={0x7E,0x30,0x6D,0x79,0x33,0x5B,0x5F,0x70,0x7F,0x7B};
	switch(copy_u8Port)
	{
		case GPIOA : RCC_voidEnableClock(RCC_APB2,2);
					 GPIO_voidSetPinDirection(copy_u8Port, PIN0, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
					 GPIO_voidSetPinDirection(copy_u8Port, PIN1, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
					 GPIO_voidSetPinDirection(copy_u8Port, PIN2, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
					 GPIO_voidSetPinDirection(copy_u8Port, PIN3, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
					 GPIO_voidSetPinDirection(copy_u8Port, PIN4, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
					 GPIO_voidSetPinDirection(copy_u8Port, PIN5, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
					 GPIO_voidSetPinDirection(copy_u8Port, PIN6, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
					 break;
		case GPIOB : RCC_voidEnableClock(RCC_APB2,3);
				     GPIO_voidSetPinDirection(copy_u8Port, PIN0, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
					 GPIO_voidSetPinDirection(copy_u8Port, PIN1, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
					 GPIO_voidSetPinDirection(copy_u8Port, PIN5, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
					 GPIO_voidSetPinDirection(copy_u8Port, PIN6, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
					 GPIO_voidSetPinDirection(copy_u8Port, PIN7, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
					 GPIO_voidSetPinDirection(copy_u8Port, PIN8, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
					 GPIO_voidSetPinDirection(copy_u8Port, PIN9, OUTPUT, OUTPUT_PUSHPULL, OUT_SPEED_2MHZ);
					 break;
	}
	#if    SEVEN_SEGMENT_TYPE == COMMON_CATHOD
		GPIO_voidWriteport(copy_u8Port,local_u8displayarray[copy_u8value]);
	#elif  SEVEN_SEGMENT_TYPE == COMMON_ANODE
		GPIO_voidWriteport(copy_u8Port,~local_u8displayarray[copy_u8value]);
	#endif
}
