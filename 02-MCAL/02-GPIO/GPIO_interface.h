/*************************************/
/* Author     : Mahmoud Ayman        */
/* Date       : 19 AUG 2020          */
/* Version    : V01                  */
/* File Name  : GPIO_interface       */
/*************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define OUTPUT                    1
#define INPUT                     0
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
/******************/             
/* High and low define */        
#define HIGH                      1
#define LOW                       0
/******************/             
/* Output Mode */                
#define OUTPUT_PUSHPULL           1
#define OUTPUT_OPEN_DRAIN         3
#define AF_OUTPUT_PUSHPULL        5
#define AF_OUTPUT_OPEN_DRAIN      7
/******************/
/* INPUT MODE */ 
#define INPUT_ANALOG              13
#define INPUT_FLOATING            14
#define INPUT_PULLDOWN            15
#define INPUT_PULLUP              16
/******************/
/* SPEED */
#define INPUT_SPEED               1
#define OUT_SPEED_10MHZ           3
#define OUT_SPEED_2MHZ            7
#define OUT_SPEED_50MHZ           5
/******************/

void GPIO_voidSetPinDirection(u8 copy_u8PortID , u8 copy_u8PIN_ID , u8 copy_u8Direction , u8 copy_u8Mode , u8 copy_u8Speed);

void GPIO_voidSetPinValue(u8 copy_u8PortID , u8 copy_u8PIN_ID , u8 copy_u8Value);

u8 GPIO_u8GetPinValue(u8 copy_u8PortID , u8 copy_u8PIN_ID );

void GPIO_voidWriteport(u8 copy_u8PortID , u8 copy_u8val);

#endif