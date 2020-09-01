/*******************************************/
/* Author     : Mahmoud Ayman              */
/* Date       : 25 AUG 2020                */
/* Version    : V01                        */
/* File Name  : NVIC_private               */
/*******************************************/

#ifndef  NVIC_PRIVATE_H
#define  NVIC_PRIVATE_H 

/* NVIC Registers */
#define NVIC_ISER0      *((u32*)0xE000E100) /* Enable  External Interrupt from 0 to  31 */
#define NVIC_ISER1      *((u32*)0xE000E104) /* Enable  External Interrupt from 32 to 63 */

#define NVIC_ICER0      *((u32*)0xE000E180) /* Disable External Interrupt from 0 to  31 */
#define NVIC_ICER1      *((u32*)0xE000E184) /* Disable External Interrupt from 32 to 63 */

#define NVIC_ISPR0      *((u32*)0xE000E200) /* Set   Pending Flag from 0  to  31 */
#define NVIC_ISPR1      *((u32*)0xE000E204) /* Set   Pending Flag from 32 to  63 */

#define NVIC_ICPR0      *((u32*)0xE000E280) /* Clear Pending Flag from 0  to  31 */
#define NVIC_ICPR1      *((u32*)0xE000E284) /* Clear Pending Flag from 32 to  63 */

#define NVIC_IABR0      *((u32*)0xE000E300) /* Get Active Flag from 0  to  31 */
#define NVIC_IABR1      *((u32*)0xE000E304) /* Get Active Flag from 32 to  63 */

#define NVIC_IPR         ((u8*)0xE000E400)


#define NVIC_GROUP_4_SUB_0   0x05FA0300
#define NVIV_GROUP_3_SUB_1   0x05FA0400
#define NVIV_GROUP_2_SUB_2   0x05FA0500
#define NVIV_GROUP_1_SUB_3   0x05FA0600
#define NVIV_GROUP_0_SUB_4   0x05FA0700





#endif