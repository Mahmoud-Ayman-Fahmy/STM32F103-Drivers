/*******************************************/
/* Author     : Mahmoud Ayman              */
/* Date       : 28 AUG 2020                */
/* Version    : V01                        */
/* File Name  : AFIO_program               */
/*******************************************/

void AFIO_voidSetEXTIConfiguration(u8 copy_u8Line , u8 copy_u8PortMap)
{
	u8 Local_u8RegIndex = 0;
	if(copy_u8Line <= 3)
	{
		Local_u8RegIndex = 0;
	}
	else if(copy_u8Line <= 7)
	{
		Local_u8RegIndex = 1;
		copy_u8Line -= 4;
	}
	else if(copy_u8Line <= 11)
	{
		Local_u8RegIndex = 2;
		copy_u8Line -= 8;
	}
	else if(copy_u8Line <= 15)
	{
		Local_u8RegIndex = 3;
		copy_u8Line -= 12;
	}
	AFIO->EXTICR[Local_u8RegIndex] &~= ((0b1111) << (copy_u8Line * 4));
	AFIO->EXTICR[Local_u8RegIndex] |= ((copy_u8PortMap) << (copy_u8Line * 4));
} 