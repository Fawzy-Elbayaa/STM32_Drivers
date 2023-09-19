/**********************************************************/
/* Author    : Fawzy Elbayaa                              */
/* Date      : 7 aug 2023                                 */
/* Version   : V01                                        */
/**********************************************************/

#ifndef  AFIO_PRIVATE_H
#define  AFIO_PRIVATE_H


typedef struct
{
	volatile U32 EVCR;
	volatile U32 MAPR;
	volatile U32 EXTICR[4];
	volatile U32 MAPR2;
}AFIO_t;

#define AFIO ((volatile AFIO_t *) 0x40010000 )




#endif

