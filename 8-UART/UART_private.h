/**********************************************************/
/* Author    : Fawzy Elbayaa                              */
/* Date      : 8 SEP 2023                                 */
/* Version   : V01                                        */
/**********************************************************/

#ifndef  UART_PRIVATE_H
#define  UART_PRIVATE_H

typedef Struct
{
	volatile U32 SR;
	volatile U32 DR;
	volatile U32 BRR;
	volatile U32 CR1;
	volatile U32 CR2;
	volatile U32 CR3;
	volatile U32 GTPR;
}MUART_Type;


#define MUSART1  ((Volatile MUART_Type *)0x40013800) 

#endif

