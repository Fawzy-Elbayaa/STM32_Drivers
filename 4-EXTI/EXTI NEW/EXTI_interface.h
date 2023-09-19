/*****************************************/
/* Author  :  fawzy Elbayaa                */
/* Version :  V01                        */
/* Date    :  12 August 2023             */
/*****************************************/
#ifndef EXTI0_INTERFACE_H
#define EXTI0_INTERFACE_H

void MEXTI_voidInit(void);
void MEXTI_voidSetSignalLatch(U8 Copy_u8EXTILine , U8 Copy_u8EXTISenseMode);
void MEXTI_voidEnableEXTI(U8 Copy_u8EXTILine);
void MEXTI_voidDisableEXTI(U8 Copy_u8EXTILine);
void MEXTI_voidSoftwareTrigger(U8 Copy_u8EXTILine);

void MEXTI_voidSetCallBack(void (*ptr) (void));

#define		 FALLING_EDGE		1

#define		 RISING_EDGE		3

#define		 ON_CHANGE			5

#define		 EXTI_LINE0			0

#define		 EXTI_LINE1			1

#define		 EXTI_LINE2			2

#endif
