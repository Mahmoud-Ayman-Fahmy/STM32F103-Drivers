/*******************************************/
/* Author     : Mahmoud Ayman              */
/* Date       : 20 AUG 2020                */
/* Version    : V01.0                      */
/* File Name  : Switch_interface           */
/*******************************************/

#ifndef  SWITCH_INTERFACE_H
#define  SWITCH_INTERFACE_H

/* Ports Name */
#define GPIOA                     0
#define GPIOB                     1
#define GPIOC                     2
/******************/
/* Pins Name */
#define PIN0                      0
#define PIN1                      1
#define PIN2                      2
#define PIN3                      3
#define PIN4                      4
#define PIN5                      5
#define PIN6                      6
#define PIN7                      7
#define PIN8                      8
#define PIN9                      9
#define PIN10                     10
#define PIN11                     11
#define PIN12                     12
#define PIN13                     13
#define PIN14                     14
#define PIN15                     15 


void Switch_voidInit(u8 copy_u8PortId , u8 copy_u8PIN);

u8 Switch_u8GetPin(u8 copy_u8PortId , u8 copy_u8PIN);
#endif