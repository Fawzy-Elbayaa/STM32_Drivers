/**********************************************************/
/* Author    : Fawzy Elbayaa                              */
/* Date      : 7 aug 2023                                 */
/* Version   : V01                                        */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/* Define Callback Global Variable */
static void(*MSTK_CallBack)(void);

/* Define Variable for interval mode */
static U8 MSTK_u8ModeOfInterval;

void MSTK_voidInit(void)
{
	#if     MSTK_CLK_SRC == MSTK_SRC_AHB
	SET_BIT(MSTK -> CTRL  , 2) /*SET CLOCK SOURCE AHB*/
    
    #elif  	MSTK_CLK_SRC == MSTK_SRC_AHB_8
	CLR_BIT(MSTK -> CTRL  , 2); /*SET CLOCK SOURCE AHB/8 */

	#else
	 #error "wrong choose MSTK_CLK_SRC "
	#endif

	CLR_BIT(MSTK -> CTRL, 1); //DIsABLE INT OF SYSTICK
	CLR_BIT(MSTK -> CTRL , 0); //DIsABLE THE STSTICK OF SYSTICK
}
void MSTK_voidSetBusyWait( U32 Copy_u32Ticks )
{
	/* Load ticks to load register */
	MSTK ->LOAD = Copy_u32Ticks;  
	
	/*START TIMER*/
	SET_BIT(MSTK ->CTRL , 0);

    /* Wait untill flag is raised */	
	while(GET_BIT(MSTK ->CTRL , 16) == 0);
	
	/*STOP TE TIMER*/
	CLR_BIT(MSTK ->CTRL , 0);
	MSTK ->LOAD = 0;
	MSTK ->VAL  = 0; 
}

void MSTK_voidSetIntervalSingle  ( U32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	MSTK ->LOAD = Copy_u32Ticks;  
	
	/* Start Timer */
	SET_BIT(MSTK ->CTRL , 0);
	
	/*load local variable of fun to glocal variable */
	MSTK_CallBack = Copy_ptr;  
	
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(MSTK ->CTRL, 1);

	
}
void MSTK_voidSetIntervalPeriodic( U32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	MSTK ->LOAD = Copy_u32Ticks;  
	
	/* Start Timer */
	SET_BIT(MSTK ->CTRL , 0);
	
	/*load local variable of fun to glocal variable */
	MSTK_CallBack = Copy_ptr;  
	
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(MSTK->CTRL, 1);
	
}
void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(MSTK->CTRL, 1);
	
	/* Stop Timer */
	SET_BIT(MSTK->CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
}
U32  MSTK_u32GetElapsedTime(void)
{
	U32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = (MSTK -> LOAD)  - (MSTK -> VAL);
	return Local_u32ElapsedTime ;
}
U32  MSTK_u32GetRemainingTime(void)
{
	U32 Local_u32RemainTime;
	
	Local_u32RemainTime = MSTK -> VAL ;
	
	return Local_u32RemainTime;
}

void SysTick_Handler(void)
{
	U8 Local_u8Temporary;
	
	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(MSTK ->CTRL, 1);
	
		/* Stop Timer */
		SET_BIT(MSTK ->CTRL, 0);
		MSTK -> LOAD = 0;
		MSTK -> VAL  = 0;
	}
	
	/* Callback notification */
	MSTK_CallBack();
	
	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(MSTK->CTRL,16);
}


