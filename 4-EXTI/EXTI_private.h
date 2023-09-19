/**********************************************************/
/* Author    : Fawzy Elbayaa                              */
/* Date      : 7 aug 2023                                 */
/* Version   : V01                                        */
/**********************************************************/

#ifndef  EXTI_PRIVATE_H
#define  EXTI_PRIVATE_H


typedef struct
{
	volatile U32 IMR;
	volatile U32 EMR;
	volatile U32 RTSR;
	volatile U32 FTSR;
	volatile U32 SWIER;
	volatile U32 PR;
}EXTI_t;

#define EXTI ((volatile EXTI_t *) 0x40010400 )

#define			LINE0				0
#define			LINE1				1
#define			LINE2				2
#define			LINE3				3
#define			LINE4				4


#define			RISING				0
#define			FALLING				1
#define			ON_CHANGE			2


#endif

