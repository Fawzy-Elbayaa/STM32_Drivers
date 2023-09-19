/**********************************************************/
/* Author    : Fawzy Elbayaa                              */
/* Date      : 25 jul 2023                                */
/* Version   : V01                                        */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidEnableInterrupt  (U8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber<=31)  /*CHECK THE NUMBER LESS THAN 31 TO WRITE FIRST REG*/
	{
		NVIC_ISER0 = (1<<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber<=59)   /*THE NUMBER OF PERIPHERAL ARE CONNECTING WITH NVIC IS 59 ONLY */
	{
		Copy_u8IntNumber = Copy_u8IntNumber-32;  /*TO WRITE ON REG FROM BIT 0*/
		NVIC_ISER1 = (1<<Copy_u8IntNumber);
	}
	else
	{
		/*DO NOTHING*/
	}
	
}
void MNVIC_voidDisableInterrupt (U8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber<=31)  /*CHECK THE NUMBER LESS THAN 31 TO WRITE FIRST REG*/
	{
		NVIC_ICER0 = (1<<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber<=59)   /*THE NUMBER OF PERIPHERAL ARE CONNECTING WITH NVIC IS 59 ONLY */
	{
		Copy_u8IntNumber = Copy_u8IntNumber-32;  /*TO WRITE ON REG FROM BIT 0*/
		NVIC_ICER1 = (1<<Copy_u8IntNumber);
	}
	else
	{
		/*DO NOTHING*/
	}
	
}
void MNVIC_voidSetPendingFlag   (U8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber<=31)  /*CHECK THE NUMBER LESS THAN 31 TO WRITE FIRST REG*/
	{
		NVIC_ISPR0 = (1<<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber<=59)   /*THE NUMBER OF PERIPHERAL ARE CONNECTING WITH NVIC IS 59 ONLY */
	{
		Copy_u8IntNumber = Copy_u8IntNumber-32;  /*TO WRITE ON REG FROM BIT 0*/
		NVIC_ISPR1 = (1<<Copy_u8IntNumber);
	}
	else
	{
		/*DO NOTHING*/
	}
	
}
void MNVIC_voidClearPendingFlag (U8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber<=31)  /*CHECK THE NUMBER LESS THAN 31 TO WRITE FIRST REG*/
	{
		NVIC_ICPR0 = (1<<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber<=59)   /*THE NUMBER OF PERIPHERAL ARE CONNECTING WITH NVIC IS 59 ONLY */
	{
		Copy_u8IntNumber = Copy_u8IntNumber-32;  /*TO WRITE ON REG FROM BIT 0*/
		NVIC_ICPR1 = (1<<Copy_u8IntNumber);
	}
	else
	{
		/*DO NOTHING*/
	}
	
	
}
U8 MNVIC_u8GetActiveFlag (U8 Copy_u8IntNumber)
{
	U8 Local_u8Result;
	if(Copy_u8IntNumber<=31)  /*CHECK THE NUMBER LESS THAN 31 TO WRITE FIRST REG*/
	{
		Local_u8Result = GET_BIT(NVIC_IABR0 , Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber<=59)   /*THE NUMBER OF PERIPHERAL ARE CONNECTING WITH NVIC IS 59 ONLY */
	{
		Copy_u8IntNumber = Copy_u8IntNumber-32;  /*TO WRITE ON REG FROM BIT 0*/
		Local_u8Result = GET_BIT(NVIC_IABR1 , Copy_u8IntNumber);
	}
	else
	{
		/*DO NOTHING*/
	}
	return Local_u8Result;
	
}
void MNVIC_voidSetPriority(S8 Copy_s8IntID,U8 Copy_u8GroupPriority,U8 Copy_u8SubPriority , U32 Copy_u32Group)
{                              /*0x05FA0400 3 Group & 1 sub priority*/
	U8 Local_u8Priority = (Copy_u8SubPriority|(Copy_u8GroupPriority<<((Copy_u32Group - GROUP3)/256)));
	                                                     /*0x05FA0400 - 0X05FA0300*/
														 /*THEN res = (100 or 256 decimal) / 256 **the res = 1*/
														 /*then suppose GROUP PRIRITY = 3  (0x0011 <<1) = 0110 */
														 /*SUPPOSE SUB 2 (0110 | 0010) = 0110*/
														 /*THEN WRITE THE REG IPR <<4 IT RES*/
	                
					
	/*CORE PERIPHERAL*/
	if(Copy_s8IntID<0)
	{

	}
	/*EXTERNAL PERIPHERAL*/
	else if(Copy_s8IntID >=0)
	{
		NVIC_IPR[Copy_s8IntID]= Local_u8Priority<<4;
	}
	SCB_AIRCR =  Copy_u32Group;
}
