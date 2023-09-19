/************************************************************************************/
/*Author       :Fawzy Elbayaa                                                       */
/*Version      :V01                                                                 */
/*Date         :10 JUL  2023                                                        */
/************************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/************* BUSES*************/

#define RCC_AHB       0
#define RCC_APB1      1
#define RCC_APB2      2


/*
 *@brief  initialize the clock source
 *@param  none
 *@retval none
*/
void RCC_VoidInitSysClock(void);

/*
 *@brief  ENABLE THE CLOCK
 *@param  copy_u8Bus: options 1- RCC_AHB
                              2- RCC_APB1
							  3- RCC_APB2
 *@param  Copy_u8perID : PIN IN REG FROM 0 TO 31
 *@retval NOT RETURN ANY VALUE
*/
void RCC_VoidEnableClock(U8 Copy_u8Bus   , U8 Copy_u8perID);

/*
 *@brief  DISABLE THE CLOCK
 *@param  copy_u8Bus: options 1- RCC_AHB
                              2- RCC_APB1
							  3- RCC_APB2
 *@param  Copy_u8perID : PIN IN REG FROM 0 TO 31
 *@retval NOT RETURN ANY VALUE
*/
void RCC_VoidDisableClock(U8 Copy_u8Bus   , U8 Copy_u8perID);




#endif


