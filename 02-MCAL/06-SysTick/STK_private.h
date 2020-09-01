/*******************************************/
/* Author     : Mahmoud Ayman              */
/* Date       : 29 AUG 2020                */
/* Version    : V01                        */
/* File Name  : STK_private                */
/*******************************************/

#ifndef  STK_PRIVATE_H
#define  STK_PRIVATE_H

typedef struct
{
	volatile u32 CTRL
	volatile u32 LOAD
	volatile u32 VAL
	volatile u32 CALIB
}STK_t;

#define STK ((volatile STK_t*)0xE000E010)

#define STK_SINGLE_INTERVAL     0
#define STK_PERIODIC_INTERVAL   1

#endif