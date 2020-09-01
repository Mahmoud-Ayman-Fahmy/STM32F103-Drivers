/*************************************/
/* Author     : Mahmoud Ayman        */
/* Date       : 19 AUG 2020          */
/* Version    : V01                  */
/* File Name  : GPIO_program         */
/*************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
void GPIO_voidSetPinDirection(u8 copy_u8PortID , u8 copy_u8PIN_ID , u8 copy_u8Direction , u8 copy_u8Mode , u8 copy_u8Speed)
{
	switch(copy_u8PortID)
	{
		/* GPIOA */
		case GPIOA :
			if(copy_u8PIN_ID <=7)
			{
				switch(copy_u8Direction)
				{
					case OUTPUT :
						if(copy_u8Speed != INPUT_SPEED)
						{
							switch(copy_u8Speed)
							{
								case OUT_SPEED_10MHZ      : SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4));
													        CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+1);
													        break;
								case OUT_SPEED_2MHZ       : CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4));
													        SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+1);
													        break;
							    case OUT_SPEED_50MHZ      : SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4));
													        SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+1);
													        break;
								//default                 : break;
							}                             
							switch(copy_u8Mode)           
							{                             
								case OUTPUT_PUSHPULL      : CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
													        break;
								case OUTPUT_OPEN_DRAIN    : SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
													        break;
								case AF_OUTPUT_PUSHPULL   : CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case AF_OUTPUT_OPEN_DRAIN : SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								//default                 : break;      
							}                                           
						}                                               
						break;
					case INPUT :                                        
						if(copy_u8Speed==INPUT_SPEED)                   
						{                                               
							/* SET Input Mode*/                         
							CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4));
							CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+1);
							switch(copy_u8Mode)                         
							{                                           
								case INPUT_ANALOG         : CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case INPUT_FLOATING       : SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case INPUT_PULLDOWN       : CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
															CLR_BIT(GPIOA_ODR , copy_u8PIN_ID );
													        break;
								case INPUT_PULLUP         : CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
															SET_BIT(GPIOA_ODR , copy_u8PIN_ID );
													        break;
								//default                 : break;
							}
						}
						break;
						
						
				}
			}
			else if(copy_u8PIN_ID < 16 && copy_u8PIN_ID > 7)
			{
				copy_u8PIN_ID -=8;
				switch(copy_u8Direction)
				{
					case OUTPUT :
						if(copy_u8Speed != INPUT_SPEED)
						{
							switch(copy_u8Speed)
							{
								case OUT_SPEED_10MHZ      : SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4));
													        CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+1);
													        break;
								case OUT_SPEED_2MHZ       : CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4));
													        SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+1);
													        break;
							    case OUT_SPEED_50MHZ       : SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4));
													        SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+1);
													        break;
								//default                 : break;
							}                             
							switch(copy_u8Mode)           
							{                             
								case OUTPUT_PUSHPULL      : CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
													        break;
								case OUTPUT_OPEN_DRAIN    : SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
													        break;
								case AF_OUTPUT_PUSHPULL   : CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case AF_OUTPUT_OPEN_DRAIN : SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								//default                 : break;      
							}                                           
						}                                               
						break;
					case INPUT :                                        
						if(copy_u8Speed==INPUT_SPEED)                   
						{                                               
							/* SET Input Mode*/                         
							CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4));
							CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+1);
							switch(copy_u8Mode)                         
							{                                           
								case INPUT_ANALOG         : CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case INPUT_FLOATING       : SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case INPUT_PULLDOWN       : CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
															CLR_BIT(GPIOA_ODR , copy_u8PIN_ID );
													        break;
								case INPUT_PULLUP         : CLR_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOA_CRL , (copy_u8PIN_ID * 4)+3);
															SET_BIT(GPIOA_ODR , copy_u8PIN_ID );
													        break;
								//default                 : break;
							}
						}	
				}

			}
			break;
		/* End of GPIOA */ 
		
		/* GPIOB */
		case GPIOB :
			if(copy_u8PIN_ID <=7)
			{
				switch(copy_u8Direction)
				{
					case OUTPUT :
						if(copy_u8Speed != INPUT_SPEED)
						{
							switch(copy_u8Speed)
							{
								case OUT_SPEED_10MHZ      : SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4));
													        CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+1);
													        break;
								case OUT_SPEED_2MHZ       : CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4));
													        SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+1);
													        break;
							    case OUT_SPEED_50MHZ       : SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4));
													        SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+1);
													        break;
								//default                 : break;
							}                             
							switch(copy_u8Mode)           
							{                             
								case OUTPUT_PUSHPULL      : CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
													        break;
								case OUTPUT_OPEN_DRAIN    : SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
													        break;
								case AF_OUTPUT_PUSHPULL   : CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case AF_OUTPUT_OPEN_DRAIN : SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								//default                 : break;      
							}                                           
						}                                               
						break;
					case INPUT :                                        
						if(copy_u8Speed==INPUT_SPEED)                   
						{                                               
							/* SET Input Mode*/                         
							CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4));
							CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+1);
							switch(copy_u8Mode)                         
							{                                           
								case INPUT_ANALOG         : CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case INPUT_FLOATING       : SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case INPUT_PULLDOWN       : CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
															CLR_BIT(GPIOB_ODR , copy_u8PIN_ID );
													        break;
								case INPUT_PULLUP         : CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
															SET_BIT(GPIOB_ODR , copy_u8PIN_ID );
													        break;
								//default                 : break;
							}
						}	
				}
			}
			else if(copy_u8PIN_ID < 16 && copy_u8PIN_ID > 7)
			{
				copy_u8PIN_ID -=8;
				switch(copy_u8Direction)
				{
					case OUTPUT :
						if(copy_u8Speed != INPUT_SPEED)
						{
							switch(copy_u8Speed)
							{
								case OUT_SPEED_10MHZ      : SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4));
													        CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+1);
													        break;
								case OUT_SPEED_2MHZ       : CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4));
													        SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+1);
													        break;
							    case OUT_SPEED_50MHZ       : SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4));
													        SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+1);
													        break;
								//default                 : break;
							}                             
							switch(copy_u8Mode)           
							{                             
								case OUTPUT_PUSHPULL      : CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
													        break;
								case OUTPUT_OPEN_DRAIN    : SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
													        break;
								case AF_OUTPUT_PUSHPULL   : CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case AF_OUTPUT_OPEN_DRAIN : SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								//default                 : break;      
							}                                           
						}                                               
						break;
					case INPUT :                                        
						if(copy_u8Speed==INPUT_SPEED)                   
						{                                               
							/* SET Input Mode*/                         
							CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4));
							CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+1);
							switch(copy_u8Mode)                         
							{                                           
								case INPUT_ANALOG         : CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case INPUT_FLOATING       : SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case INPUT_PULLDOWN       : CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
															CLR_BIT(GPIOB_ODR , copy_u8PIN_ID );
													        break;
								case INPUT_PULLUP         : CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
															SET_BIT(GPIOB_ODR , copy_u8PIN_ID );
													        break;
								//default                 : break;
							}
						}	
			}
		}
			break;
	
		/* End of GPIOB */
		
		/* GPIOC */
		case GPIOC :
			if(copy_u8PIN_ID <=7)
			{
				switch(copy_u8Direction)
				{
					case OUTPUT :
						if(copy_u8Speed != INPUT_SPEED)
						{
							switch(copy_u8Speed)
							{
								case OUT_SPEED_10MHZ      : SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4));
													        CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+1);
													        break;      
								case OUT_SPEED_2MHZ       : CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4));
													        SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+1);
													        break;      
							    case OUT_SPEED_50MHZ       : SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4));
													        SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+1);
													        break;      
								//default                 : break;      
							}                                           
							switch(copy_u8Mode)                         
							{                                           
								case OUTPUT_PUSHPULL      : CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case OUTPUT_OPEN_DRAIN    : SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case AF_OUTPUT_PUSHPULL   : CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case AF_OUTPUT_OPEN_DRAIN : SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								//default                 : break;      
							}                                           
						}                                               
						break;
					case INPUT :                                        
						if(copy_u8Speed==INPUT_SPEED)                   
						{                                               
							/* SET Input Mode*/                         
							CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4));
							CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+1);
							switch(copy_u8Mode)                         
							{                                           
								case INPUT_ANALOG         : CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case INPUT_FLOATING       : SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case INPUT_PULLDOWN       : CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+3);
															CLR_BIT(GPIOC_ODR , copy_u8PIN_ID );
													        break;      
								case INPUT_PULLUP         : SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+3);
															SET_BIT(GPIOC_ODR , copy_u8PIN_ID );
													        break;      
								//default                 : break;      
							}                                           
						}	                                            
				}                                                       
			}                                                           
			else if(copy_u8PIN_ID < 16 && copy_u8PIN_ID > 7)            
			{                                                           
				copy_u8PIN_ID -=8;                                      
				switch(copy_u8Direction)                                
				{                                                       
					case OUTPUT :                                       
						if(copy_u8Speed != INPUT_SPEED)                 
						{                                               
							switch(copy_u8Speed)                        
							{                                           
								case OUT_SPEED_10MHZ      : SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4));
													        CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+1);
													        break;      
								case OUT_SPEED_2MHZ       : CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4));
													        SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+1);
													        break;      
							    case OUT_SPEED_50MHZ       : SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4));
													        SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+1);
													        break;      
								//default                 : break;      
							}                                           
							switch(copy_u8Mode)                         
							{                                           
								case OUTPUT_PUSHPULL      : CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case OUTPUT_OPEN_DRAIN    : SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case AF_OUTPUT_PUSHPULL   : CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case AF_OUTPUT_OPEN_DRAIN : SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								//default                 : break;      
							}                                           
						}                                               
						break;
					case INPUT :                                        
						if(copy_u8Speed==INPUT_SPEED)                   
						{                                               
							/* SET Input Mode*/                         
							CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4));
							CLR_BIT(GPIOC_CRL , (copy_u8PIN_ID * 4)+1);
							switch(copy_u8Mode)                         
							{                                           
								case INPUT_ANALOG         : CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case INPUT_FLOATING       : SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
													        break;      
								case INPUT_PULLDOWN       : CLR_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
															CLR_BIT(GPIOB_ODR , copy_u8PIN_ID );
													        break;
								case INPUT_PULLUP         : SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+2);
													        SET_BIT(GPIOB_CRL , (copy_u8PIN_ID * 4)+3);
															SET_BIT(GPIOB_ODR , copy_u8PIN_ID );
													        break;
								//default                 : break;
							}
						}	
			}
		}
		/* End of PortC */
	}
}
	


void GPIO_voidSetPinValue(u8 copy_u8PortID , u8 copy_u8PIN_ID , u8 copy_u8Value)
{
	if(copy_u8PIN_ID < 16)
	{
		switch(copy_u8PortID)
		{
			case GPIOA :
				switch(copy_u8Value)
				{
					case HIGH :  SET_BIT(GPIOA_ODR , copy_u8PIN_ID);
								 break;
					case LOW  :	 CLR_BIT(GPIOA_ODR , copy_u8PIN_ID);
								 break;
					//default  : break;
				}
				break;
			case GPIOB :
				switch(copy_u8Value)
				{
					case HIGH :  SET_BIT(GPIOB_ODR , copy_u8PIN_ID);
								 break;
					case LOW  :	 CLR_BIT(GPIOB_ODR , copy_u8PIN_ID);
								 break;
					//default  : break;
				}
				break;
			case GPIOC :
				switch(copy_u8Value)
				{
					case HIGH :  SET_BIT(GPIOC_ODR , copy_u8PIN_ID);
								 break;
					case LOW  :	 CLR_BIT(GPIOC_ODR , copy_u8PIN_ID);
								 break;
					//default  : break;
				}
				break;
		}
	}
}

void GPIO_voidWriteport(u8 copy_u8PortID , u8 copy_u8val)
{
	switch(copy_u8PortID)
		{
			case GPIOA : GPIOA_ODR = copy_u8val; 
						 break;
			case GPIOB : GPIOB_ODR = copy_u8val;
						 break;
			case GPIOC : GPIOC_ODR = copy_u8val;
						 break;
			// default : break;
		}
}

u8 GPIO_u8GetPinValue(u8 copy_u8PortID , u8 copy_u8PIN_ID )
{
	u8 localu8ReturnValue=0;
	if(copy_u8PIN_ID < 16)
	{
		switch(copy_u8PortID)
		{
			case GPIOA : localu8ReturnValue = GET_BIT(GPIOA_IDR , copy_u8PIN_ID);
						 break;
			case GPIOB : localu8ReturnValue = GET_BIT(GPIOB_IDR , copy_u8PIN_ID);
						 break;
			case GPIOC : localu8ReturnValue = GET_BIT(GPIOC_IDR , copy_u8PIN_ID);
						 break;
			// default : break;
		}
	}
	return localu8ReturnValue;
}
