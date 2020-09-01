/*******************************************/
/* Author     : Mahmoud Ayman              */
/* Date       : 29 AUG 2020                */
/* Version    : V01                        */
/* File Name  : STK_intrface               */
/*******************************************/

#ifndef  STK_INTERFACE_H
#define  STK_INTERFACE_H

/* Apply Clock choice from configuration file
   Disable SysTick interrupt
   Disable SysTick
*/
void STK_voidInit(void);

/*
	Load Value to Reigster 
	Enable SysTick
	Wait until finish counting
*/
void STK_voidSetBusyWait(u32 copy_u32Ticks);
/*
	Load Value to Reigster 
	Enable SysTick
	return back until interrupt happen for one time
*/
void STK_voidSetIntervalSignal(u32 copy_u32Ticks ,void (*copy_ptr)(void));
/*
	Load Value to Reigster 
	Enable SysTick
	return back until interrupt happen periodicly
*/
void STK_voidSetIntervalPeriodic(u32 copy_u32Ticks ,void (*copy_ptr)(void));
/*
	Disable SysTick
	Assign 0 to LOAD and VAL Reigsters
*/
void STK_voidStopTimer(void);
/*
	Return the Time counted by SysTick (differnce between LOAD and VAL Reigsters)
*/
u32 STK_u32GetElapsedTime(void);
/*
	Return the Time Remaining to interrupt happen (VAL Reigsters)
*/
u32 STK_u32GetRemainingTime(void);

#define STK_AHB              0
#define STK_AHB_PER_EIGHT    1

#endif