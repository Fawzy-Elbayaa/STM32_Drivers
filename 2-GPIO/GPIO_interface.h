/**********************************************************************************/
/*Author         :Fawzy Elbayaa                                                        */
/*Date           :12/07/2023                                                           */
/*Version        :VO1                                                                  */
/*Description    :GPIO_INTERFACE                                                 */
/**********************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "STD_TYPES.h"

/******************************************THE PORTS TO APIS******************************/
#define PORTA                 0
#define PORTB                 1
#define PORTC                 2

/******************************************THE PINS TO APIS******************************/
#define PIN0                  0
#define PIN1                  0
#define PIN2                  0
#define PIN3                  0
#define PIN4                  0
#define PIN5                  0
#define PIN6                  0
#define PIN7                  0
#define PIN8                  0
#define PIN9                  0
#define PIN10                 0
#define PIN11                 0
#define PIN12                 0
#define PIN13                 0
#define PIN14                 0
#define PIN15                 0


/***********************************************THE OUTPUT OF PIN***********************/
#define GPIO_HIGH             1       /*THE PIN IS HIGH*/
#define GPIO_LOW              0       /*THE PIN IS LOW */


/******************************************THE MODE AND CONFIGGRATION TO APIS**********************************************/
/************************OUTPUT MODE  10 MHHZ*************************/
#define OUTPUT_SPEED_10MHZ_PP                    0b0001    /*OUTPUT 10 MHZ WITH PUSH PULL*/
#define OUTPUT_SPEED_10MHZ_OD                    0b0101    /*OUTPUT 10 MHZ WITH OPEN DRAIN*/
#define OUTPUT_SPEED_10MHZ_AFPP                  0b1001    /*OUTPUT 10 MHZ WITH ALTERNATIVE FUN PUSH PULL*/
#define OUTPUT_SPEED_10MHZ_AFOD                  0b1101    /*OUTPUT 10 MHZ WITH ALTERNATIVE FUN OPEN DRAIN*/

/************************OUTPUT MODE 2 MHHZ*********************/

#define OUTPUT_SPEED_2MHZ_PP                    0b0010    /*OUTPUT 2 MHZ WITH PUSH PULL*/
#define OUTPUT_SPEED_2MHZ_OD                    0b0110    /*OUTPUT 2 MHZ WITH OPEN DRAIN*/
#define OUTPUT_SPEED_2MHZ_AFPP                  0b1010    /*OUTPUT 2 MHZ WITH ALTERNATIVE FUN PUSH PULL*/
#define OUTPUT_SPEED_2MHZ_AFOD                  0b1110    /*OUTPUT 2 MHZ WITH ALTERNATIVE FUN OPEN DRAIN*/

/************************OUTPUT MODE 50 MHHZ*********************/

#define OUTPUT_SPEED_50MHZ_PP                   0b0011    /*OUTPUT 50 MHZ WITH PUSH PULL*/
#define OUTPUT_SPEED_50MHZ_PP                   0b0011    /*OUTPUT 50 MHZ WITH OPEN DRAIN*/
#define OUTPUT_SPEED_50MHZ_PP                   0b0011    /*OUTPUT 50 MHZ WITH ALTERNATIVE FUN PUSH PULL*/
#define OUTPUT_SPEED_50MHZ_PP                   0b0011    /*OUTPUT 50 MHZ WITH ALTERNATIVE FUN OPEN DRAIN*/

/******************************INPUT  MODE**************************/

#define INPUT_ANANLOG                           0b0000    /*INPUT WITH ANALGE*/
#define INPUT_FLOATING                          0b0100    /*INPUT WITH FLAOTINGG*/
#define INPUT_PULL_UP_DOWN                      0b1000    /*INPUT WITH PULL UP AND PULL DOWN*/

/**************************************************************************************************************************************/
/*****************************************************THE FUN TO APIS******************************************************************/
/*
 *@brief  set direction for  your seletion pin
 *@param  Copy_u8PORT :  set port to select
  @param  Copy_u8PIN  :  set pin to select in port
  @param  Copy_u8MODE :  set mode in your pin 
 *@retval             : none
*/
void MGPIO_VoidSetPinDirection(U8 Copy_u8PORT , U8 Copy_u8PIN , U8 Copy_u8MODE);

/*
 *@brief  set Value  for  your seletion pin
 *@param  Copy_u8PORT :  set port to select
  @param  Copy_u8PIN  :  set pin to select in port
  @param  Copy_u8MODE :  set mode in your pin 
 *@retval             : none
*/
void MGPIO_VoidSetPinValue(U8 Copy_u8PORT , U8 Copy_u8PIN , U8 Copy_u8Value);


/*
 *@brief  get reading in the pin (high or low)
 *@param  Copy_u8PORT :  set port to select
  @param  Copy_u8PIN  :  set pin to select in port
   
 *@retval             : get the pin (high or low)
*/
U8 MGPIO_U8GetPinValue(U8 Copy_u8PORT , U8 Copy_u8PIN);


#endif
