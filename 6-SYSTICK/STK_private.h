/**********************************************************/
/* Author    : Fawzy Elbayaa                              */
/* Date      : 7 aug 2023                                 */
/* Version   : V01                                        */
/**********************************************************/

#ifndef  STK_PRIVATE_H
#define  STK_PRIVATE_H


typedef struct
{
	volatile U32  CTRL;
	volatile U32  LOAD;
	volatile U32  VAL;
	volatile U32  CALIB;
}MSTK_t;

#define MSTK  ((volatile MSTK_t *)0xE000E010)

#define     MSTK_SRC_AHB           0
#define     MSTK_SRC_AHB_8         1

#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1


#endif

