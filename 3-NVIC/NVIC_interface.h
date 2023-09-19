/**********************************************************/
/* Author    : Fawzy Elbayaa                              */
/* Date      : 25 jul 2023                                */
/* Version   : V01                                        */
/**********************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidEnableInterrupt  (U8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (U8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag   (U8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (U8 Copy_u8IntNumber);
U8 MNVIC_u8GetActiveFlag        (U8 Copy_u8IntNumber);
void MNVIC_voidSetPriority(S8 Copy_s8IntID,U8 Copy_u8GroupPriority,U8 Copy_u8SubPriority , U32 Copy_u32Group);


#define GROUP3                   0X05FA0300  /*4 BIT FOR GROUP AND 0 BIT FOR SUB*/
#define GROUP4                   0X05FA0400  /*3 BIT FOR GROUP AND 1 BIT FOR SUB*/
#define GROUP5                   0X05FA0500  /*2 BIT FOR GROUP AND 2 BIT FOR SUB*/
#define GROUP6                   0X05FA0600  /*1 BIT FOR GROUP AND 3 BIT FOR SUB*/
#define GROUP7                   0X05FA0700  /*0 BIT FOR GROUP AND 4 BIT FOR SUB*/
#endif
