/**********************************************************/
/* Author    : Fawzy Elbayaa                              */
/* Date      : 7 aug 2023                                 */
/* Version   : V01                                        */
/**********************************************************/

#ifndef  EXTI_INTERFACE_H
#define  EXTI_INTERFACE_H

void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(U8 Copy_u8Line);
void MEXTI_voidDisableEXTI(U8 Copy_u8Line);
void MEXTI_voidSwTrigger(U8 Copy_u8Line);
void MEXTI_voidSetSignalLatch(U8 Copy_u8Line , U8 Copy_u8Mode);



#endif
