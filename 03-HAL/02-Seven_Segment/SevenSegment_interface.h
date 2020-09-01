/*******************************************/
/* Author     : Mahmoud Ayman              */
/* Date       : 20 AUG 2020                */
/* Version    : V01.0                      */
/* File Name  : SevenSegment_interface     */
/*******************************************/

#ifndef  SEVEN_SEGMENT_INTERFACE_H
#define  SEVEN_SEGMENT_INTERFACE_H

/* PORT Number */
#define GPIOA   0
#define GPIOB   1
/* if use send GPIOA you must connect from PIN0 to PIN6
			   GPIOB you must connect PIN0,PIN1,PIN5,PIN6
									  PIN7,PIN8,PIN9
									  
*/ 
void SevenSegment_voidDisplay(u8 copy_u8Port ,u8 copy_u8value);

#endif