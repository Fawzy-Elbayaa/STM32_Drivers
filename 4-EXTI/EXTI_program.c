/**********************************************************/
/* Author    : Fawzy Elbayaa                              */
/* Date      : 7 aug 2023                                 */
/* Version   : V01                                        */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void MEXTI_voidInit()
{
	#if EXTI_MODE   == RISING
	SET_BIT(EXTI ->RTSR  , EXTI_LINE);
	
	#elif EXTI_MODE == FALLING
	SET_BIT(EXTI ->FTSR  , EXTI_LINE);
	#elif EXTI_MODE == ON_CHANGE
	SET_BIT(EXTI ->RTSR  , EXTI_LINE);
	SET_BIT(EXTI ->FTSR  , EXTI_LINE);
	#else 
        #error "Wrong Mode and Line Choice"

    #endif
void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI->IMR , Copy_u8Line);
}
void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI->IMR , Copy_u8Line);
}

void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI ->SWIER  , Copy_u8Line);
}
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case  RISING    :  SET_BIT(EXTI ->RTSR  , EXTI_LINE);   break;
		case  FALLING   :  SET_BIT(EXTI ->FTSR  , EXTI_LINE);   break;
		case  ON_CHANGE :  SET_BIT(EXTI ->RTSR  , EXTI_LINE);   
	                       SET_BIT(EXTI ->FTSR  , EXTI_LINE);  
                           break;
	}
}