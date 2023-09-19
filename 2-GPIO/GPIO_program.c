/**********************************************************************************/
/*Author    :Fawzy Elbayaa                                                        */
/*Date      :12/07/2023                                                           */
/*Version   :VO1                                                                  */
/**********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

oid MGPIO_VoidSetPinDirection(U8 Copy_u8PORT , U8 Copy_u8PIN , U8 Copy_u8MODE)
{
	switch(Copy_u8PORT)
	{
		case PORTA :  
	              if(Copy_u8PIN<=7)                                                         /*the pin that your selected is low */
	              {                                                                       
	  	             GPIOA_CRL &= ~(0b1111<<(Copy_u8PIN*4));                               /*to reset 4 bit for every pin*/
	  	             GPIOA_CRL |=  (Copy_u8MODE<<(Copy_u8PIN*4));                          /*to set mode and config for  every pin*/
	              }                                                                       
	              else if((Copy_u8PIN > 7) &&  (Copy_u8PIN <=15))                            /*the pin that your selected is high*/
	              {                                                                          
		             Copy_u8PIN = Copy_u8PIN-8;                                              /*to correct choose your pins  */
		             GPIOA_CRH &= ~(0b1111<<(Copy_u8PIN*4));                                /*to reset 4 bit for every pin*/
		             GPIOA_CRH |=  (Copy_u8MODE<<(Copy_u8PIN*4));                           /*to set mode and config for  every pin*/
	              }                                                                       
                  break;                                                                  
       case PORTB :                                                                       
		          if(Copy_u8PIN<=7)                                                          /*the pin that your selected is low */
	              {                                                                       
		              GPIOB_CRL &= ~(0b1111<<(Copy_u8PIN*4));                               /*to reset 4 bit for every pin*/
		              GPIOB_CRL |=  (Copy_u8MODE<<(Copy_u8PIN*4));                          /*to set mode and config for  every pin*/
	              }                                                                       
	              else if((Copy_u8PIN > 7) &&  (Copy_u8PIN <=15))                            /*the pin that your selected is high*/
	              {                                                                       
		              Copy_u8PIN = Copy_u8PIN-8;                                             /*to correct choose your pins  */
		              GPIOB_CRH &= ~(0b1111<<(Copy_u8PIN*4));                               /*to reset 4 bit for every pin*/
		              GPIOB_CRH |=  (Copy_u8MODE<<(Copy_u8PIN*4));                          /*to set mode and config for  every pin*/
	              }                                                                       
	              break;                                                                  
		case PORTC :                                                                      
		          if(Copy_u8PIN<=7)                                                          /*the pin that your selected is low */
	              {                                                                       
		               GPIOC_CRL &= ~(0b1111<<(Copy_u8PIN*4));                              /*to reset 4 bit for every pin*/
    	               GPIOC_CRL |=  (Copy_u8MODE<<(Copy_u8PIN*4));                         /*to set mode and config for  every pin*/
                  }                                                                       
	              else if((Copy_u8PIN > 7) &&  (Copy_u8PIN <=15))                            /*the pin that your selected is high*/
	              {                                                                       
	 	               Copy_u8PIN = Copy_u8PIN-8;                                            /*to correct choose your pins  */
	 	               GPIOC_CRH &= ~(0b1111<<(Copy_u8PIN*4));                              /*to reset 4 bit for every pin*/
	 	               GPIOC_CRH |=  (Copy_u8MODE<<(Copy_u8PIN*4));                         /*to set mode and config for  every pin*/
	              }
		          break;
	    default : break;
	}             
} 
void MGPIO_VoidSetPinValue(U8 Copy_u8PORT , U8 Copy_u8PIN , U8 Copy_u8Value)              
{                                                                                         
	if(Copy_u8PIN <=15)                                                                   /*to check the pin from 1 to 16 only*/                            
	{                                                                                     
	        switch(Copy_u8PORT)                                                           
	        {                                                                             
	        	case PORTA :                                                              
	                      if(Copy_u8Value == GPIO_HIGH)                                     /*IS THE OUTPUT PIN IS HIGH??*/
	                      {                                                               
	          	             SET_BIT(GPIOA_ODR , Copy_u8PIN);                                /*SET THE PIN YOUR SELECTED IS HIGH*/
	                      }                                                               
	                      else if(Copy_u8Value == GPIO_LOW)                                   /*IS THE OUTPUT PIN IS LOW??*/
	                      {                                                               
	          	             CLR_BIT(GPIOA_ODR , Copy_u8PIN);                                /*SET THE PIN YOUR SELECTED IS LOW*/
	                      }                                                               
                          break;                                                          
               case PORTB :                                                               
	        	          if(Copy_u8Value == GPIO_HIGH)                                     /*IS THE OUTPUT PIN IS HIGH??*/
	                      {                                                               
	          	             SET_BIT(GPIOB_ODR , Copy_u8PIN);                                /*SET THE PIN YOUR SELECTED IS HIGH*/
	                      }                                                               
	                      else if(Copy_u8Value == GPIO_LOW)                                   /*IS THE OUTPUT PIN IS LOW??*/
	                      {                                                               
	          	             CLR_BIT(GPIOB_ODR , Copy_u8PIN);                                /*SET THE PIN YOUR SELECTED IS LOW*/
	                      }                                                               
                          break;                                                          
	        	case PORTC :                                                              
	        	          if(Copy_u8Value == GPIO_HIGH)                                      /*IS THE OUTPUT PIN IS HIGH??*/
	                      {                                                               
	          	             SET_BIT(GPIOC_ODR , Copy_u8PIN);                                /*SET THE PIN YOUR SELECTED IS HIGH*/
	                      }                                                               
	                      else if(Copy_u8Value == GPIO_LOW)                                  /*IS THE OUTPUT PIN IS LOW??*/
	                      {                                                               
	          	             CLR_BIT(GPIOC_ODR , Copy_u8PIN);                                /*SET THE PIN YOUR SELECTED IS LOW*/
	                      }
                          break;
	            default : break;
	        }
	}
	else
	{
		/*DO NOTHING*/
	}
}

U8 MGPIO_U8GetPinValue(U8 Copy_u8PORT , U8 Copy_u8PIN)
{
	U8 Local_U8Result=0;
	if(Copy_u8PIN <=15)                                                                   /*to check the pin from 1 to 16 only*/                            
	{                                                                                     
	        switch(Copy_u8PORT)                                                           
	        {                                                                             
	        	case PORTA :   Local_U8Result = GET_BIT(GPIOA_IDR , Copy_u8PIN);         /*TO GET THE BIT AND PUT IN THE VARIABLE */
				break; 
				
				case PORTB :   Local_U8Result = GET_BIT(GPIOB_IDR , Copy_u8PIN);         /*TO GET THE BIT AND PUT IN THE VARIABLE */
				break; 
				
				case PORTC :   Local_U8Result = GET_BIT(GPIOC_IDR , Copy_u8PIN);         /*TO GET THE BIT AND PUT IN THE VARIABLE */
				break; 
				          
	            default : break;
	        }
	}
	else
	{
		/*DO NOTHING*/
	}
	return Local_U8Result;
	
}
                
			      
			      
			      
			      