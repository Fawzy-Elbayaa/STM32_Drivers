/*****************************************/
/* Author  :  Ahmed Assaf                */
/* Version :  V01                        */
/* Date    : 29 August 2020              */
/*****************************************/
#ifndef EXTI0_PRIVATE_H
#define EXTI0_PRIVATE_H


typedef	struct
{
	volatile	U32		IMR;
	volatile	U32		EMR;
	volatile	U32		RTSR;
	volatile	U32		FTSR;
	volatile	U32		SWIER;
	volatile	U32		PR;
	
}EXTI_Type;

#define	EXTI		(( EXTI_Type * )0X40010400)



#endif
