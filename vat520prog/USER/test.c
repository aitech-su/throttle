#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h" 
#include "beep.h" 	
#include "lcm.h"
#include "font_table.h"
#include "adc.h"
#include "adcall.h"
#include "timer.h"
#include "math.h"
#include "key.h"
//
//
 
 
int main(void)
    { 
 // u8 number=2;

	u16 adcx=0;
	u8	dir=1;
//	u16	led0pwmval=0;
	float pwmval;
		

	float temp=0;
		
	u8 t;

		
  Stm32_Clock_Init(9); 	//ϵͳʱ������
			
//***********************************************			
/* �_��HSI ���Ȳ�����r�R */
  //RCC->CR |= (uint32_t)0x00000001; 

/*�x��HSI��PLL�ĕr�RԴHSI���2���l�oPLL*/
  //RCC->CFGR |= (uint32_t)RCC_CFGR_PLLSRC_HSI_Div2; 

         
/*PLLCLK=8/2*13=52MHz   �O�ñ��l�õ��r�RԴPLL���l��*/
 // RCC->CFGR |= (uint32_t)RCC_CFGR_PLLMULL11;

/* PLL�����lݔ��  */
  //RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
 
/* ʹ�� PLL�r�R */
  //RCC->CR |= RCC_CR_PLLON;

/* �ȴ�PLL�r�R�;w*/
  //while((RCC->CR & RCC_CR_PLLRDY) == 0)
  // {
  //      }


/* �x��PLL��ϵ�y�r�R�ĕr�RԴ */
 // RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
 // RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    

/* �ȵ�PLL�ɞ�ϵ�y�r�R�ĕr�RԴ*/
  // while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08)
  //{

  //          }	
//*********************************************


			
	delay_init(72);	    	//��ʱ��ʼ��
	LED_Init();		  	  	//��ʼ����LED���ӵ�Ӳ���ӿ�
  //BEEP_Init();         	//��ʼ���������˿�	
	//BEEP_on();
	LCM_Init();
	Adc_Init();		  		//ADC��ʼ��	

	logo(ecpal);              //0=��һ�� 1=��2�� 2=��3��   logo(jtc4614); 
  delay_ms(1000); 
  clear_lcm(); 
	
	TIM1_PWM_Init(3599,0);//����Ƶ��PWMƵ��=72000/(3599+1)=20Khz  PWMƵ��=72000/(899+1)=80Khz 
	
	KEY_Init();          	//��ʼ���밴�����ӵ�Ӳ���ӿ�
	

	

	
	
	
	//write_number(0,0,LCM_INVERT,number);     //������:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,number�� 0-9
	//write_number(0,8,LCM_INVERT,4);
	
	write_number(0,64,LCM_INVERT,6);
	write_number(0,72,LCM_NORMAL,8);
	
	write_word_t(2,0,LCM_NORMAL,dian);      //�����w��:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,dian=� 
	write_word_t(2,16,LCM_NORMAL,liu);

	write_word_c(2,32,LCM_NORMAL,c_1);      //�����w��:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,dian=� 
	write_word_c(2,48,LCM_NORMAL,c_2);      //�����w��:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,dian=� 
		
	write_word_j(2,64,LCM_NORMAL,j_1);      //�����w��:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,dian=� 
	write_word_j(2,80,LCM_NORMAL,j_2);      //�����w��:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,dian=� 
		
	write_word_k(4,0,64,LCM_NORMAL,k_1);      //�����w��:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,dian=� 
	write_word_k(4,64,14,LCM_NORMAL,k_2);      //�����w��:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,dian=� 
	write_word_k(6,0,46,LCM_INVERT,k_3);      //�����w��:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,dian=� 
	write_word_k(6,64,46,LCM_NORMAL,k_4);      //�����w��:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,dian=� 	

 //write_word_e(0,16,W_a,LCM_INVERT,e_a);
	//write_word_e(0,23,W_b,LCM_NORMAL,e_b);
	

 write_word_e(0,80,W_A,LCM_INVERT,e_A);
	write_word_e(0,80+W_A,W_B,LCM_NORMAL,e_B);
	write_word_e(0,80+W_A+W_B,W_C,LCM_NORMAL,e_C);
	write_word_e(0,80+W_A+W_B+W_C,W_d,LCM_NORMAL,e_d);
	
	
	

				adcx=Get_Adc_Average(ADC_CH11,10);
		  	temp=(float)adcx*(3.265/2.56);														//temp=(float)adcx*(3.3/4096/16)*1000=3.3/2.56  /16�����15k�c1k���։�
				
				
			while(dir)
			{
		    	if (temp>1350) PWM_ON=1, GLED=1 ,dir=0;
		   	else   PWM_ON=0, GLED=!GLED,delay_ms(400);
							
			}
				for(t=0;t<2;t++)	
	     {
				LED0_PWM_VAL=2500;		
 		    delay_ms(400);
				
				LED0_PWM_VAL=1200;		
 		    delay_ms(400);
		
				LED0_PWM_VAL=800;		
 		    delay_ms(400);			
		
				LED0_PWM_VAL=600;		
 		    delay_ms(400);
				
				LED0_PWM_VAL=800;		
 		    delay_ms(400);
				
				LED0_PWM_VAL=1200;		
 		    delay_ms(400);
						
				LED0_PWM_VAL=2500;		
 		    delay_ms(400);
				
				
				LED0_PWM_VAL=6000;
				
				RLED=!RLED;
			}
			

  

		while(1)
		{	
			

			Adc11_display(2,0,LCM_NORMAL);
			Adc10_display(0,0,LCM_INVERT);
			Adc12_display(4,0,LCM_NORMAL);
			Adc13_display(6,0,LCM_NORMAL);
			
			

			
			
		 t=KEY_Scan(0);		//�õ���ֵ
	  	switch(t)
	  	{				 
			case KEY0_PRES:
				//LED0=!LED0;
				break;
			case KEY1_PRES:
				RLED=!RLED;
				break;
			case WKUP_PRES:				
			//	LED0=!LED0;
				//LED1=!LED1;
				break;
			default:
			delay_ms(1);	
 	 	} 
			
			
 

			adcx=Get_Adc_Average(ADC_CH10,10);
			temp=(float)adcx*(3.265/2.56);														//temp=(float)adcx*(3.3/4096/16)*1000=3.3/2.56  /16�����15k�c1k���։�
		

			pwmval=temp/100;		

		
			LED0_PWM_VAL=pow(pwmval,2)+600;		 



			
		
		
					//adcx=Get_Adc_Average(ADC_CH11,10);
			//temp=(float)adcx*(3.265/2.56);														//temp=(float)adcx*(3.3/4096/16)*1000=3.3/2.56  /16�����15k�c1k���։�

			
			//if (temp>1000) PWM_ON=1, GLED=1;
		  //else   PWM_ON=0, GLED=!GLED;
	
		
		
 		//delay_ms(1);	 
		//if(dir)led0pwmval++;
		//else led0pwmval--;	 
 		//if(led0pwmval>1200)dir=0;
		//if(led0pwmval==0)dir=1;	   					 
		//LED0_PWM_VAL=led0pwmval;	
		
		
		
				//LED0_PWM_VAL=800;		
 		//delay_ms(500);
				//LED0_PWM_VAL=0;		
 		//delay_ms(500);			
		
		
				//LED0_PWM_VAL=324;		
 		//delay_ms(500);
		
				//LED0_PWM_VAL=0;		
 		//delay_ms(500);			
		
				//LED0_PWM_VAL=450;		
 	//	delay_ms(500);
				//LED0_PWM_VAL=0;		
 		//delay_ms(500);		
			
			
		}										    
}		
		 
