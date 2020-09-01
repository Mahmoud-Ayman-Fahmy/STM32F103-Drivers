/*************************************/
/* Author     : Mahmoud Ayman        */
/* Date       : 17 AUG 2020          */
/* Version    : V01                  */
/* File Name  : RCC_config           */
/*************************************/

#ifndef  RCC_CONFIG_H
#define  RCC_CONFIG_H

/* OPtions:     RCC_HSE_CRYSTAL
				RCC_HSE_RC
				RCC_HSI
				RCC_PLL
*/
#define RCC_CLOCK_TYPE   RCC_HSE_CRYSTAL

/*  clock security system Enable and Disable		*/
/*	Options:    CSS_ENABLE
				CSS_DISABLE
*/

#define 	CLOCK_SECURITY_SYSTEM		CSS_DISABLE

/* Options:     RCC_PLL_IN_HSI_DIV_2 
				RCC_PLL_IN_HSE_DIV_2
				RCC_PLL_IN_HSE
*/

/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT    RCC_PLL_IN_HSE_DIV_2
#endif

/* Note: Select value only if you have PLL as input clock source */
/* OPtions: 2 to 16 */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL  4
#endif


#endif