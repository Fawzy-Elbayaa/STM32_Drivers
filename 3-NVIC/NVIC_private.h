/**********************************************************/
/* Author    : fawzy elbayaa                              */
/* Date      : 25 jul 2023                           */
/* Version   : V01                                        */
/**********************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/***********************REISTER DEFINITION******************/
#define  NVIC_BASE_ADDRESS       0xE000E100
#define  SCB_BASE_ADDRESS        0xE000ED00

#define      NVIC_ISER0        *((volatile U32 *)(NVIC_BASE_ADDRESS+0X000))/*SET INT FROM BIT 0 TO 31*/
#define      NVIC_ISER1        *((volatile U32 *)(NVIC_BASE_ADDRESS+0X004))/*SET INT FROM BIT 32 TO 59*/
#define      NVIC_ISER2        *((volatile U32 *)(NVIC_BASE_ADDRESS+0X008))

#define      NVIC_ICER0        *((volatile U32 *)(NVIC_BASE_ADDRESS+0X080))/*CLEAR INT FROM BIT 0 TO 31*/
#define      NVIC_ICER1        *((volatile U32 *)(NVIC_BASE_ADDRESS+0X084))/*CLERAR INT FROM BIT 32 TO 59*/
#define      NVIC_ICER2        *((volatile U32 *)(NVIC_BASE_ADDRESS+0X088))

#define      NVIC_ISPR0        *((volatile U32 *)(NVIC_BASE_ADDRESS+0X100))/*SET PENDING FLAG FROM BIT 0 TO 31*/
#define      NVIC_ISPR1        *((volatile U32 *)(NVIC_BASE_ADDRESS+0X104))/*SET PENDING FLAG FROM BIT 32 TO 59*/
#define      NVIC_ISPR2        *((volatile U32 *)(NVIC_BASE_ADDRESS+0X108))

#define      NVIC_ICPR0        *((volatile U32 *)(NVIC_BASE_ADDRESS+0X180)) /*CLEAR PENDING FLAG FROM BIT 0 TO 31*/
#define      NVIC_ICPR1        *((volatile U32 *)(NVIC_BASE_ADDRESS+0X184)) /*CLEAR PENDING FLAG FROM BIT 32 TO 59*/
#define      NVIC_ICPR2        *((volatile U32 *)(NVIC_BASE_ADDRESS+0X188))

#define      NVIC_IABR0        *((volatile U32 *)(NVIC_BASE_ADDRESS+0X200)) //FOR READ ACTIVE FLAG 
#define      NVIC_IABR1        *((volatile U32 *)(NVIC_BASE_ADDRESS+0X204))
#define      NVIC_IABR2        *((volatile U32 *)(NVIC_BASE_ADDRESS+0X208))

#define     NVIC_IPR		       ((volatile U8 *)NVIC_BASE_ADDRESS + 0x300)  /**without derefrence*/


#define      NVIC_STIR        *((volatile U32 *)(NVIC_BASE_ADDRESS+0XE00))

#define     SCB_AIRCR         *((volatile U32 *)(SCB_BASE_ADDRESS+0x0C))/*Application interrupt and reset control register*/


#endif
