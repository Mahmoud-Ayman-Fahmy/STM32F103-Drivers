/*************************************/
/* Author     : Mahmoud Ayman        */
/* Date       : 17 AUG 2020          */
/* Version    : V01                  */
/* File Name  : RCC_interface        */
/*************************************/

#ifndef  RCC_INTERFACE_H
#define  RCC_INTERFACE_H

#define RCC_AHB   0 
#define RCC_APB1  1 
#define RCC_APB2  2

/*
	Function Name : voidInitSysClock
	Argumrnt      : void
	Description   : adjust system clock 
*/

	void RCC_voidInitSysClock(void);
/*
	Function Name : voidEnableClock
	Argumrnt      : Bus Number (AHB , APB1 and APB2) and Peripheral Number (in the register)  
	Description   : Set the clock bit in the specific bus sent by user
*/

   void RCC_voidEnableClock(u8 copy_u8BusId, u8 copy_peripheralId);
/*
	Function Name : voidDisableClock
	Argumrnt      : Bus Number (AHB , APB1 and APB2) and Peripheral Number (in the register)  
	Description   : Clear the clock bit in the specific bus sent by user
*/   
   void RCC_voidDisableClock(u8 copy_u8BusId, u8 copy_peripheralId);
   
   
#endif