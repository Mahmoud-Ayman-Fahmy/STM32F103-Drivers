/*******************************************/
/* Author     : Mahmoud Ayman              */
/* Date       : 28 AUG 2020                */
/* Version    : V01                        */
/* File Name  : EXTI_interface             */
/*******************************************/

#ifndef  EXTI_INTERFACE_H
#define  EXTI_INTERFACE_H


#define   LINE0       0
#define   LINE1       1
#define   LINE2       2
#define   LINE3       3
#define   LINE4       4
#define   LINE5       5
#define   LINE6       6
#define   LINE7       7
#define   LINE8       8
#define   LINE9       9
#define   LINE10      10
#define   LINE11      11
#define   LINE12      12
#define   LINE13      13
#define   LINE14      14
#define   LINE15      15


#define   FALLING     0
#define   RISING      1
#define   ON_CHANGE   2

void EXTI_voidInit(u8 copy_u8Mode,u8 copy_u8Line);

void EXTI_voidEnableEXTI(u8 copy_u8Line);

void EXTI_voidDisableEXTI(u8 copy_u8Line);

void EXTI_voidSoftwareTrigger(u8 copy_u8Line);

#endif 