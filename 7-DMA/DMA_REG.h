/**********************************************************************************/
/*Author    :Fawzy Elbayaa                                                        */
/*Date      :27/08/2023                                                           */
/*Version   :VO1                                                                  */
/**********************************************************************************/
/*Preprocessor File Guard*/
#ifndef DMA_REG_H_
#define DMA_REG_H_

typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;
}DMA_Channel;

typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel Channel[7];
}DMA_t;

#define DMA	((volatile DMA_t*)0x40020000)

#endif