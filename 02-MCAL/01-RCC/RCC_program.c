/*************************************/
/* Author     : Mahmoud Ayman        */
/* Date       : 17 AUG 2020          */
/* Version    : V01                  */
/* File Name  : RCC_program          */
/*************************************/

/* Libraries include */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Owned deriver files */
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	#if    RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL 
		RCC_CR   = 0x00010000;  /* Enable HSE with no bypass */  
		RCC_CFGR = 0x00000001; 
	#elif  RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000;  /* Enable HSE with  bypass */
		RCC_CFGR = 0x00000001;
	#elif  RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081   /* Enable HSI (HSION BIT) and triming defualt 16 */
		RCC_CFGR = 0x00000000;
	#elif  RCC_CLOCK_TYPE == RCC_PLL
		SET_BIT(RCC_CFGR , 1);
		CLR_BIT(RCC_CFGR , 0);
		#if   RCC_PLL_MUL_VAL == 2
			CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL_VAL == 3
			SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL_VAL == 4
			CLR_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL_VAL == 5
			SET_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL_VAL == 6
			CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL_VAL == 7
			SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL_VAL == 8
			CLR_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL_VAL == 9
			SET_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL_VAL == 10
			CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL_VAL == 11
			SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL_VAL == 12
			CLR_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL_VAL == 13
			SET_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL_VAL == 14
			CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL_VAL == 15
			SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MUL_VAL == 16
			CLR_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#endif
		
		#if   RCC_PLL_InPUT == RCC_PLL_IN_HSI_DIV_2
			CLR_BIT(RCC_CFGR,16);
		#elif RCC_PLL_InPUT == RCC_PLL_IN_HSE_DIV_2
			SET_BIT(RCC_CFGR,16);
			SET_BIT(RCC_CFGR,17);
		#elif RCC_PLL_InPUT == RCC_PLL_IN_HSE
			SET_BIT(RCC_CFGR,16);
			CLR_BIT(RCC_CFGR,17);
		#endif
		SET_BIT(RCC_CR,24);
		while(!GET_BIT(RCC_CR,25));
	#else
		#error("You chosed wrong Clock type")
	#endif
	#if       CLOCK_SECURITY_SYSTEM == CSS_DISABLE
		CLR_BIT(RCC_CR, 19);
	#elif     CLOCK_SECURITY_SYSTEM == CSS_ENABLE
		SET_BIT(RCC_CR, 19);
	#endif
}


void RCC_voidEnableClock(u8 copy_u8BusId, u8 copy_peripheralId)
{
	if(copy_peripheralId <= 31)
	{
		switch(copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  , copy_peripheralId);  break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR , copy_peripheralId);  break;
		    case RCC_APB2 : SET_BIT(RCC_APB2ENR , copy_peripheralId);  break;
	  	   // default   : /* Return Error */                    break;
		}
	}
	else
    {
		/* Return Error */
	}
}
void RCC_voidDisableClock(u8 copy_u8BusId, u8 copy_peripheralId)
{
	if(copy_peripheralId <= 31)
	{
		switch(copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  , copy_peripheralId);  break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR , copy_peripheralId);  break;
		    case RCC_APB2 : CLR_BIT(RCC_APB2ENR , copy_peripheralId);  break;
	  	   // default   : /* Return Error */                    break;
		}
	}
	else
    {
		/* Return Error */
	}
}
