/**********************************************************/
/* Author    : Fawzy Elbayaa                              */
/* Date      : 7 aug 2023                                 */
/* Version   : V01                                        */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void MAFIO_voidSetEXTIConfiguration(U8 Copy_u8Line ,U8 Copy_u8PortMap)
{
	U8 Local_u8RegIndex=0;
	if(Copy_u8Line<=3) //register EXTICR[0]
	{
		Local_u8RegIndex = 0;
	}
	else if(Copy_u8Line<=7)   //register EXTICR[1]
	{
		Local_u8RegIndex=1;
		Copy_u8Line -=4;
	}
	else if(Copy_u8Line <=11)  //register EXTICR[2]
	{
		Local_u8RegIndex=2;
		Copy_u8Line -=8;
	}
	else if(Copy_u8Line<=15)   //register EXTICR[3]
	{
		Local_u8RegIndex=3;
		Copy_u8Line -=12;
	}
	AFIO ->EXTICR[Local_u8RegIndex] &= ~((0b1111)<< (Copy_u8Line*4));
	AFIO ->EXTICR[Local_u8RegIndex] |=  ((0b1111)<< (Copy_u8Line*4));
}
