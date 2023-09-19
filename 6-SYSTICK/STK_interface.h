/**********************************************************/
/* Author    : Fawzy Elbayaa                              */
/* Date      : 7 aug 2023                                 */
/* Version   : V01                                        */
/**********************************************************/

#ifndef  STK_INTERFACE_H
#define  STK_INTERFACE_H

/* Apply Clock choice from configuration file
   Disable SysTick interrupt
   Disable Systick                          */
void MSTK_voidInit(void);
void MSTK_voidSetBusyWait( U32 Copy_u32Ticks );
void MSTK_voidSetIntervalSingle  ( U32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidSetIntervalPeriodic( U32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidStopInterval(void);
U32  MSTK_u32GetElapsedTime(void);
U32  MSTK_u32GetRemainingTime(void);


#endif
