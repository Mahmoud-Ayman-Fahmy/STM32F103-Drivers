/*******************************************/
/* Author     : Mahmoud Ayman              */
/* Date       : 28 AUG 2020                */
/* Version    : V01                        */
/* File Name  : EXTI_private               */
/*******************************************/

#ifndef  EXTI_PRIVATE_H
#define  EXTI_PRIVATE_H

/* EXTI Registers in struct */
typedef struct {
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
	
}EXIT_t;

#define EXTI_REG ((volatile EXIT_t*)0x40010400)



#endif 