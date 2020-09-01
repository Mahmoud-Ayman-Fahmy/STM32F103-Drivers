/*******************************************/
/* Author     : Mahmoud Ayman              */
/* Date       : 25 AUG 2020                */
/* Version    : V01                        */
/* File Name  : NVIC_program               */
/*******************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"  

void NVIC_voidInit(void)
{
	#define SCB_AIRCR  *((u32*)0xE000ED0C)
	SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION ;
}

void NVIC_voidSetPriority(u8 copy_u8PeripheralId ,u8 copy_u8GroupPriority , u8 copy_u8SUBPriority )
{ 
	if(copy_u8PeripheralId < 60)
	{
		#if   NVIC_GROUP_SUB_DISTRIBUTION == NVIC_GROUP_4_SUB_0
			u8 local_u8priorty = copy_u8GroupPriority;
			NVIC_IPR[copy_u8PeripheralId] = (local_u8priorty<<4);
		#elif NVIC_GROUP_SUB_DISTRIBUTION == NVIV_GROUP_3_SUB_1
			u8 local_u8priorty = copy_u8SUBPriority | (copy_u8GroupPriority<<1);
			NVIC_IPR[copy_u8PeripheralId] = (local_u8priorty<<4);
		#elif NVIC_GROUP_SUB_DISTRIBUTION == NVIV_GROUP_2_SUB_2
			u8 local_u8priorty = copy_u8SUBPriority | (copy_u8GroupPriority<<2);
			NVIC_IPR[copy_u8PeripheralId] = (local_u8priorty<<4);
		#elif NVIC_GROUP_SUB_DISTRIBUTION == NVIV_GROUP_1_SUB_3
			u8 local_u8priorty = copy_u8SUBPriority | (copy_u8GroupPriority<<3);
			NVIC_IPR[copy_u8PeripheralId] = (local_u8priorty<<4);
		#elif NVIC_GROUP_SUB_DISTRIBUTION == NVIV_GROUP_0_SUB_4
			u8 local_u8priorty = copy_u8SUBPriority | (copy_u8GroupPriority<<4);
			NVIC_IPR[copy_u8PeripheralId] = (local_u8priorty<<4);
		#endif
	}	 
}

void NVIC_voidEnableInterrupt (u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <=31)
	{
		NVIC_ISER0 = (1 << copy_u8IntNumber);
		//SET_BIT(NVIC_ISER0,copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << copy_u8IntNumber);
		//SET_BIT(NVIC_ISER1,copy_u8IntNumber);
	}
	else
	{
		/* Return Error */  	
	}
}

void NVIC_voidDisableInterrupt (u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <=31)
	{
		NVIC_ICER0 = (1 << copy_u8IntNumber);
		//SET_BIT(NVIC_ISER0,copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;
		NVIC_ICER1 = (1 << copy_u8IntNumber);
		//SET_BIT(NVIC_ISER1,copy_u8IntNumber);
	}
	else
	{
		/* Return Error */  	
	}
}

void NVIC_voidSetPendingFlag (u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <=31)
	{
		NVIC_ISPR0 = (1 << copy_u8IntNumber);
		//SET_BIT(NVIC_ISER0,copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1 << copy_u8IntNumber);
		//SET_BIT(NVIC_ISER1,copy_u8IntNumber);
	}
	else
	{
		/* Return Error */  	
	}
}

void NVIC_voidClearPendingFlag (u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <=31)
	{
		NVIC_ICPR0 = (1 << copy_u8IntNumber);
		//SET_BIT(NVIC_ISER0,copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << copy_u8IntNumber);
		//SET_BIT(NVIC_ISER1,copy_u8IntNumber);
	}
	else
	{
		/* Return Error */  	
	}
}

u8 NVIC_u8GetActiveFlag (u8 copy_u8IntNumber)
{
	u8 local_u8Result=0;
	if(copy_u8IntNumber <=31)
	{
		
		local_u8Result = GET_BIT(NVIC_IABR0,copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;
		local_u8Result = GET_BIT(NVIC_IABR1,copy_u8IntNumber);
	}
	else
	{
		/* Return Error */  	
	}
	return local_u8Result;
}