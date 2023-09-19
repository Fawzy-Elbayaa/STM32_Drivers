/************************************************************************************/
/*Author       :Fawzy Elbayaa                                                       */
/*Version      :V01                                                                 */
/*Date         :10 JUL  2023                                                        */
/************************************************************************************/





#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_VoidInitSysClock(void)
{
	#if    RCC_CLOCK_TYPE==RCC_HSE_CRYSTAL
    //RCC_CR  &=  ~(0xFFFFFFFF);
	RCC_CR   =   0X00010000;    /*ENABLE HSE WITH no by pass*/
	RCC_CFGR =   0X00000001;    /* HSE selected as system clock*/
	
	#elif  RCC_CLOCK_TYPE==RCC_HSE_RC
	RCC_CR   =   0X00050000;    /*enable HSE with by pass*/
	RCC_CFGR =   0X00000001;    /* HSE selected as system clock*/
	
	#elif  RCC_CLOCK_TYPE==RCC_HSI
	
	RCC_CR   =   0x00000081;   /* ENABLE HSI + trimming =0*/
	RCC_CFGR =   0X00000000;    /*HSI selected as system clock*/

	#elif  RCC_CLOCK_TYPE==RCC_PLL
	/********************************************V01*************************************************/
	RCC_RC   = 0X01000000;      /* PLL ON*/
	RCC_CFGR = 0X00000002;      /* PLL selected as system clock*/
	    #if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		CLR_BIT(CFGR , 16);    /**TO CHHOSE HSI/2 PLL entry clock source*/
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
		SET_BIT(CFGR , 17);    /*HSE clock divided by 2*/
	
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		CLR_BIT(CFGR , 17);     /* HSE clock not divided*/
		SET_BIT(CFGR , 16);     /*: HSE oscillator clock selected as PLL input clock*/
		
		
		#endif
	/**********************************************V01***************************************************/
	#else
	  #error ("you choosed wrong clock type ");
		
	
	#endif
}


void RCC_VoidEnableClock(U8 Copy_u8Bus   , U8 Copy_u8perID)
{
	if(Copy_u8perID<=31)
	{
		switch(Copy_u8Bus)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  , Copy_u8perID);      break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR , Copy_u8perID);      break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR , Copy_u8perID);      break;
		}
	}
	else
	{
		/*return error*/
	}
}


void RCC_VoidDisableClock(U8 Copy_u8Bus   , U8 Copy_u8perID)
{
	if(Copy_u8perID<=31)
	{
		switch(Copy_u8Bus)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  , Copy_u8perID);      break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR , Copy_u8perID);      break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR , Copy_u8perID);      break;
		}
	}
	else
	{
		/*return error*/
	}
}
