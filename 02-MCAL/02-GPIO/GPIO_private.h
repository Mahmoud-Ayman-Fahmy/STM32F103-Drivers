/*************************************/
/* Author     : Mahmoud Ayman        */
/* Date       : 19 AUG 2020          */
/* Version    : V01                  */
/* File Name  : GPIO_private         */
/*************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H



/* Port A Registers */
#define    GPIOA_CRL   *((u32 *)0x40010800)
#define    GPIOA_CRH   *((u32 *)0x40010804)
#define    GPIOA_IDR   *((u32 *)0x40010808)
#define    GPIOA_ODR   *((u32 *)0x4001080C)
#define    GPIOA_BSRR  *((u32 *)0x40010810)
#define    GPIOA_BRR   *((u32 *)0x40010814)
#define    GPIOA_LCKR  *((u32 *)0x40010818)
/***********************/

/* Port B Registers */
#define    GPIOB_CRL   *((u32 *)0x40010C00)
#define    GPIOB_CRH   *((u32 *)0x40010C04)
#define    GPIOB_IDR   *((u32 *)0x40010C08)
#define    GPIOB_ODR   *((u32 *)0x40010C0C)
#define    GPIOB_BSRR  *((u32 *)0x40010C10)
#define    GPIOB_BRR   *((u32 *)0x40010C14)
#define    GPIOB_LCKR  *((u32 *)0x40010C18)
/***********************/

/* Port C Registers */
#define    GPIOC_CRL   *((u32 *)0x40011000)
#define    GPIOC_CRH   *((u32 *)0x40011004)
#define    GPIOC_IDR   *((u32 *)0x40011008)
#define    GPIOC_ODR   *((u32 *)0x4001100C)
#define    GPIOC_BSRR  *((u32 *)0x40011010)
#define    GPIOC_BRR   *((u32 *)0x40011014)
#define    GPIOC_LCKR  *((u32 *)0x40011018)
/***********************/
#endif