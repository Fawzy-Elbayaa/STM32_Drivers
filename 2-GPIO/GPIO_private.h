/**********************************************************************************/
/*Author    :Fawzy Elbayaa                                                        */
/*Date      :12/07/2023                                                           */
/*Version   :VO1                                                                  */
/**********************************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


#include "STD_TYPES.h"

/***************************THE BASE ADRESSES**********************************************/
#define GPIOA_BASE_ADD             0x40010800    /*THE BASE ADDRESS OF GPIOA*/
#define GPIOB_BASE_ADD             0x40010C00    /*THE BASE ADDRESS OF GPIOB*/
#define GPIOC_BASE_ADD             0x40011000    /*THE BASE ADDRESS OF GPIOC*/


/***************************THE REGISTER ADDRESSES OF PORTA**********************************************/
#define GPIOA_CRL                       *((U32 *)(GPIOA_BASE_ADD + 0x00))
#define GPIOA_CRH                       *((U32 *)(GPIOA_BASE_ADD + 0x04))
#define GPIOA_IDR                       *((U32 *)(GPIOA_BASE_ADD + 0x08))
#define GPIOA_ODR                       *((U32 *)(GPIOA_BASE_ADD + 0x0C))
#define GPIOA_BSRR                      *((U32 *)(GPIOA_BASE_ADD + 0x10))
#define GPIOA_BRR                       *((U32 *)(GPIOA_BASE_ADD + 0x14))
#define GPIOA_LCKR                      *((U32 *)(GPIOA_BASE_ADD + 0x18))

/***************************THE REGISTER ADDRESSES OF PORTB**********************************************/
#define GPIOB_CRL                       *((U32 *)(GPIOB_BASE_ADD + 0x00))
#define GPIOB_CRH                       *((U32 *)(GPIOB_BASE_ADD + 0x04))
#define GPIOB_IDR                       *((U32 *)(GPIOB_BASE_ADD + 0x08))
#define GPIOB_ODR                       *((U32 *)(GPIOB_BASE_ADD + 0x0C))
#define GPIOB_BSRR                      *((U32 *)(GPIOB_BASE_ADD + 0x10))
#define GPIOB_BRR                       *((U32 *)(GPIOB_BASE_ADD + 0x14))
#define GPIOB_LCKR                      *((U32 *)(GPIOB_BASE_ADD + 0x18))


/***************************THE REGISTER ADDRESSES OF PORTC**********************************************/
#define GPIOC_CRL                       *((U32 *)(GPIOC_BASE_ADD + 0x00))
#define GPIOC_CRH                       *((U32 *)(GPIOC_BASE_ADD + 0x04))
#define GPIOC_IDR                       *((U32 *)(GPIOC_BASE_ADD + 0x08))
#define GPIOC_ODR                       *((U32 *)(GPIOC_BASE_ADD + 0x0C))
#define GPIOC_BSRR                      *((U32 *)(GPIOC_BASE_ADD + 0x10))
#define GPIOC_BRR                       *((U32 *)(GPIOC_BASE_ADD + 0x14))
#define GPIOC_LCKR                      *((U32 *)(GPIOC_BASE_ADD + 0x18))


#endif
