/**********************************************************/
/* Author    : Fawzy Elbayaa                              */
/* Date      : 8 SEP 2023                                 */
/* Version   : V01                                        */
/**********************************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "UART_interface.h"
#include  "UART_private.h"
#include  "UART_config.h"

void      MUSRAT1_voidInit(void)
{
	/*1 Start bit, 8 Data bits, n Stop bit */
	CLR_BIT(MUSART1 ->CR1 , 12 );
	
	/*  BAUDE RATE ==9600 */
	MUSART1 ->BRR = 0X341;
	
	/*  TX ENABLE */
	SET_BIT(MUSART1 ->CR1 , 3);
	
	/* RX ENABLE */
	SET_BIT(MUSART1 ->CR1 , 2);
	
	/*  USART ENABLE */
	SET_BIT(MUSART1 ->CR1 , 13);
	
	
}
void      MUSART1_voidTransmit(U8 Arr[])
{
	U8 i = 0 ;
	while(Arr[i] != '\0')
	{
		MUSART1 ->DR = Arr[i];
		//wait until transmit complete 
		while(((MUSART1 ->SR) &0X40 )==0);
		i++;
	}
}
U8        MUSART1_u8Receive(void)
{
	//wait until receive complete 
	while(((MUSART1 ->SR) &0X20 )==0);
	return (0xFF & MUSART1 ->DR);
}


