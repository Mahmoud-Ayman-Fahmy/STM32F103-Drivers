/*******************************************/
/* Author     : Mahmoud Ayman              */
/* Date       : 29 AUG 2020                */
/* Version    : V01                        */
/* File Name  : STK_program                */
/*******************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_config.h"
#include "STK_private.h"

/* CallBack Pointer to Function Variables */
void (*STK_CallBack)(void);

u8 STK_IntervalMode;

void STK_voidInit(void)
{
	/* Adjust SysTick Clock */
	#if     SYSTICK_CLOCK == AHB
		CLR_BIT(STK->CTRL, 2);
	#elif   SYSTICK_CLOCK == AHB_PER_EIGHT
		SET_BIT(STK->CTRL, 2);
	#endif
	
	/* Disable SysTick interrupt */
	CLR_BIT(STK->CTRL, 1);
	
	/* Disable SysTick */ 
	CLR_BIT(STK->CTRL, 0);
}

void STK_voidSetBusyWait(u32 copy_u32Ticks)
{
	/* Load Ticks Number in LOAD register */
	STK->LOAD = copy_u32Ticks;
	/* Enable SysTick */
	SET_BIT(STK->CTRL, 0);
	
	while(GET_BIT(STK->CTRL,16)==0);
	/* Disable SysTick */ 
	CLR_BIT(STK->CTRL, 0);
	STK->LOAD = 0;
	STK->VAL  = 0; 
}

void STK_voidSetIntervalSignal(u32 copy_u32Ticks ,void (*copy_ptr)(void))
{
	/* Load Ticks Number in LOAD register */
	STK->LOAD = copy_u32Ticks;
	/* Enable SysTick */
	SET_BIT(STK->CTRL, 0);
	/* Save CallBack */
	STK_CallBack = copy_ptr;
	/* Set Interval Type */
	STK_IntervalMode = STK_SINGLE_INTERVAL;
	/* Enable Interrupt */ 
	SET_BIT(STK->CTRL, 1);
}

void STK_voidSetIntervalPeriodic(u32 copy_u32Ticks ,void (*copy_ptr)(void))
{
	/* Load Ticks Number in LOAD register */
	STK->LOAD = copy_u32Ticks;
	/* Enable SysTick */
	SET_BIT(STK->CTRL, 0);
	/* Save CallBack */
	STK_CallBack = copy_ptr;
	/* Set Interval Type */
	STK_IntervalMode = STK_PERIODIC_INTERVAL;
	/* Enable Interrupt */ 
	SET_BIT(STK->CTRL, 1);
}

void STK_voidStopTimer(void)
{
	/* Disable SysTick interrupt */
	CLR_BIT(STK->CTRL, 1);
	
	/* Disable SysTick */ 
	CLR_BIT(STK->CTRL, 0);
	STK->LOAD = 0;
	STK->VAL  = 0; 
}

u32 STK_u32GetElapsedTime(void)
{
	u32 Local_u32Time = 0;
	Local_u32Time = (STK->LOAD) - (STK->VAL);
	return Local_u32Time;
}

u32 STK_u32GetRemainingTime(void)
{
	u32 Local_u32Time = 0;
	Local_u32Time = (STK->VAL);
	return Local_u32Time;
}

void SysTick_Handler(void)
{
	u8 Local_u8Temp = 0;
	if(STK_IntervalMode == STK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK->CTRL, 1);
	
		/* Stop Timer */
		SET_BIT(STK->CTRL, 0);
		STK -> LOAD = 0;
		STK -> VAL  = 0;
	}
	STK_CallBack();
	
	/* Clear interrupt flag */
	Local_u8Temp = GET_BIT(STK->CTRL,16);
}