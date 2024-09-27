#include "lcm.h"
#include "stdlib.h"
#include "font_12864.h" 
#include "usart.h"
#include "delay.h"	
#include "adcall.h"

//////////////////////////////////////////////////////////////////////////////////	 
//    LCM_Init  I/O SET
//////////////////////////////////////////////////////////////////////////////////	 
 void LCM_Init(void)
 {
//////////////////////////////////////////////////////////////
//  PORTCʱ�� 
///////////////////////////////////////////////////////////
 		RCC->APB2ENR|=1<<4;    //ʹ��PORTCʱ��	   

		GPIOC->CRL&=0X00FFFFFF; 
  	GPIOC->CRL|=0X33000000; //PC7,6 ������� W/R=PC7,CS1=PC6
	 	GPIOC->ODR|=0<<7;       //W/R=PC7 ���LOW
	  GPIOC->ODR|=0<<6;       //CS1=PC6 ���LOW

	   	 
	  GPIOC->CRH&=0XFFFFF000; 
  	GPIOC->CRH|=0X00000333; //PC10,9,8 ������� LCD����PC10=EN=PC9  R/S=PC8 
    GPIOC->ODR|=1<<10;      //PC10 LCD��������� Ҳ�Ɍ��� LCD_BL=1;
	  GPIOC->ODR|=0<<9;       //EN=PC9���LOW
	  GPIOC->ODR|=0<<8;       //R/S=PC8 ���LOW
	 
//////////////////////////////////////////////////////////////////		
// 	PORTBʱ��	 	 
/////////////////////////////////////////////////////////
	  RCC->APB2ENR|=1<<3;    //ʹ��PORTBʱ��	
	 
	 	RCC->APB2ENR|=1<<0;    //��������ʱ�� MCU��λ�ᣬPA13/14/15 & PB3/4Ĭ�J���Þ�JTAG���ܡ��Еr�҂����˳������MCU I/O�ڵ��YԴ�������@Щ���O�Þ���ͨI/O��ԭ�ľWַ��https://read01.com/oLNPzL.html
	  JTAG_Set(SWD_ENABLE);  //����SWD  ��Q PB3/4 �Y���e�`
	 
	 
		GPIOB->CRL=0X33333333;   //PB0-7  �������
	   
	  GPIOB->CRH&=0XFFFFFFF0;
	  GPIOB->CRH|=0X00000003;  //PB8 ������� CS2=PB8
	  GPIOB->ODR|=0<<8;        //PB8 CS2=PB8���LOW�C
		
		LCD_WR_REG(ON,CS1);           //CS1=1  off=0x3e  on=0x3f
		LCD_WR_REG(ON,CS2);	          //CS2=2  off=0x3e  on=0x3f
		LCD_WR_REG(STAR_LINE0,CS1);  	//cs1=1  STAR_LINE0	��ʼ�c�����0xC0̎,�θ���0xFF̎ 
		LCD_WR_REG(STAR_LINE0,CS2);	  //cs2=2  STAR_LINE0	��ʼ�c�����0xC0̎,�θ���0xFF̎
 
 }
 
 //�� ���LCM
  void clear_lcm(void)		    //clr ���� 128*64
{			
      u8 i,j;	
	    for(j=0;j<8;j++)
	   {			 
			LCD_WR_REG(PAGE0+j,CS1);
			LCD_WR_REG(PAGE0+j,CS2); 
			LCD_WR_REG(Y_ADDRESS0,CS1); 
			LCD_WR_REG(Y_ADDRESS0,CS2);
			 
		  for(i=0;i<64;i++)	
	      {				
	      	LCD_WR_DATAX(0x00,CS1,LCM_NORMAL);
					LCD_WR_DATAX(0x00,CS2,LCM_NORMAL);
       	}       	
	  	}
}	

//�� LOGO �@ʾ
  void logo(u8 logo_offset)		   //*p=logo_table{0}�ĵ�ַ 128*64=8192bit  8192/8=1024 byte u16=65536
{	
	      u8 i,j;   
        p=logo_bmp+logo_offset*1024;      //:һ��logo=1024 ....  128*64=8192/8bit=1024
	     
	    for(j=0;j<8;j++)
	   {			 
			LCD_WR_REG(PAGE0+j,CS1);
			LCD_WR_REG(Y_ADDRESS0,CS1); 
			LCD_WR_REG(PAGE0+j,CS2);	
      LCD_WR_REG(Y_ADDRESS0,CS2);	
			 
		  	for(i=0;i<64;i++,p++)	
	      {				
	      	LCD_WR_DATAX(*p,CS1,LCM_NORMAL); 
       	} 
				

				for(i=0;i<64;i++,p++)			
	      {					
	      	LCD_WR_DATAX(*p,CS2,LCM_NORMAL);			
       	}
				
	  	}
}



//��0-9����  

void write_number(u8 PAGE,u8 Y_ADDRESS,u8 invertx,u8 number)	   //������:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,number�� 0-9
{	 			
					u8 W=8;																								 //�ֵČ��ȶ���8
	        p=n_0+number*16; 																		   //���� 0 ����ʼλ��
					write_word_up_down(PAGE,Y_ADDRESS,W,invertx,p);        //PAGE=0-7,Y_ADDRESS=0-127,�ֵČ��ȶ���8,������ռ��16��0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=n_0�ĵ�ַ+number 0-9						
}

//����̖

void write_word_symbol(u8 PAGE,u8 Y_ADDRESS,u8 W,u8 invertx,u16 offset)	  //����:PAGE=0-7,Y_ADDRESS=0-127,W=�ֵČ���,invertx LCM_NORMAL=0,LCM_INVERT=1,number�� 0-9
{			  	       
	        p=s_0+offset*2; 
					write_word_up_down(PAGE,Y_ADDRESS,W,invertx,p);         //PAGE=0-7,Y_ADDRESS=0-127,�ֵČ��ȶ���8,������ռ��16��0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=k_0+offset*(W*2)
}

//��Ӣ����

void write_word_e(u8 PAGE,u8 Y_ADDRESS,u8 W,u8 invertx,u16 offset)	  //����:PAGE=0-7,Y_ADDRESS=0-127,W=�ֵČ���,invertx LCM_NORMAL=0,LCM_INVERT=1,number�� 0-9
	
{	
	        p=e_0+offset*2; 
					write_word_up_down(PAGE,Y_ADDRESS,W,invertx,p);         //PAGE=0-7,Y_ADDRESS=0-127,�ֵČ��ȶ���8,������ռ��16��0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=k_0+offset*(W*2)
}



//�����w��

void write_word_t(u8 PAGE,u8 Y_ADDRESS,u8 invertx,u8 offset)	  //����:PAGE=0-7,Y_ADDRESS=0-127,W=�ֵČ���,invertx LCM_NORMAL=0,LCM_INVERT=1,number�� 0-9
{			  	       
	        u8 W=16;																									//�ֵČ��ȶ���16
					p=t_0+offset*32; 
					write_word_up_down(PAGE,Y_ADDRESS,W,invertx,p);          //PAGE=0-7,Y_ADDRESS=0-127,�ֵČ��ȶ���8,������ռ��16��0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=t_0+offset*32
}

//�����w��

void write_word_c(u8 PAGE,u8 Y_ADDRESS,u8 invertx,u8 offset)	  //����:PAGE=0-7,Y_ADDRESS=0-127,W=�ֵČ���,invertx LCM_NORMAL=0,LCM_INVERT=1,number�� 0-9
{			  	       
	        u8 W=16;																									//�ֵČ��ȶ���16
					p=c_0+offset*32; 
					write_word_up_down(PAGE,Y_ADDRESS,W,invertx,p);          //PAGE=0-7,Y_ADDRESS=0-127,�ֵČ��ȶ���8,������ռ��16��0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=t_0+offset*32
}

//��������

void write_word_j(u8 PAGE,u8 Y_ADDRESS,u8 invertx,u8 offset)	  //����:PAGE=0-7,Y_ADDRESS=0-127,W=�ֵČ���,invertx LCM_NORMAL=0,LCM_INVERT=1,number�� 0-9
{			  	
					u8 W=16;																									//�ֵČ��ȶ���16
	        p=j_0+offset*32; 
					write_word_up_down(PAGE,Y_ADDRESS,W,invertx,p);         //PAGE=0-7,Y_ADDRESS=0-127,�ֵČ��ȶ���8,������ռ��16��0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=j_0+offset*(W*2)
}

//���n����

void write_word_k(u8 PAGE,u8 Y_ADDRESS,u8 W,u8 invertx,u16 offset)	  //����:PAGE=0-7,Y_ADDRESS=0-127,W=�ֵČ���,invertx LCM_NORMAL=0,LCM_INVERT=1,number�� 0-9
{			  	       
	        p=k_0+offset*2; 
					write_word_up_down(PAGE,Y_ADDRESS,W,invertx,p);         //PAGE=0-7,Y_ADDRESS=0-127,�ֵČ��ȶ���8,������ռ��16��0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=k_0+offset*(W*2)
}



//���ֻ��ֵ����°벿

void write_word_up_down(u8 PAGE,u8 Y_ADDRESS,u8 W,u8 invertx,const unsigned char *p)	  //���ֻ��ֵ����°벿 PAGE=0-7,Y_ADDRESS=0-127,�ֵČ�����W,������ռ��16��0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=n_0�ĵ�ַ
{	
			    u8 i,csx;	 
					if (Y_ADDRESS<64)
              {csx=CS1;}
					else{csx=CS2;
					     Y_ADDRESS-=64;
					    }
								     		      	      		  										
				 LCD_WR_REG(PAGE+PAGE0,csx);               //�ֵ��ϰ벿
			   LCD_WR_REG(Y_ADDRESS+Y_ADDRESS0,csx); 	   
			 
	    for(i=0;i<W;i++)
	      {			 
      	 LCD_WR_DATAX(*(p+i),csx,invertx);           //	LCD_WR_DATAX(p[i],csx,invert); *p=p{i}      	
	    	}
				
			 	 LCD_WR_REG(PAGE+PAGE0+1,csx);             //�ֵ��°벿  
			   LCD_WR_REG(Y_ADDRESS+Y_ADDRESS0,csx); 	   
			 
	    for(i=0;i<W;i++)
	      {			 
      	 LCD_WR_DATAX(*(p+W+i),csx,invertx);      	      	
	    	}		 
}
//д�Ĵ������� ������
//data:�������ֵ
                                               		
 void LCD_WR_REG(u8 data,u8 csx)        //data:�������ֵ csx=cs1 OR cs2 
{ 
	LCD_EN_CLR; 		//����		  PC9   �Ӵ��н�Q���Ics1,cs2ͬ�r���Ć��}  
	LCD_WR_CLR;     //д����			PC7
	LCD_RS_CLR;     //����/���� 	PC8	
	
		if  (csx==CS1)
        {LCD_CS1_SET;}
    else{LCD_CS2_SET;}	
		
	DATAOUT(data); 	
	LCD_EN_SET; 		//ʹ��	  	PC9 
	delay_us(5);	
	LCD_EN_CLR; 		//����		  PC9
 	LCD_CS1_CLR;  	//Ƭѡ�˿�  	PC6 
	LCD_CS2_CLR;    //Ƭѡ�˿�  	PB8	
} 

////////////////////////////////////////////////
//д���ݺ��� ������
//
//data:�����͵�ֵ
 void LCD_WR_DATAX(u8 data,u8 csx,u8 invertx)  //data:�����͵�ֵ csx=cs1 OR cs2  invertx LCM_NORMAL=0,LCM_INVERT=1
{
	LCD_EN_CLR; 		//����	  	PC9    �Ӵ��н�Q���Ics1,cs2ͬ�r���Ć��}
	LCD_WR_CLR;     //д����			PC7	
	LCD_RS_SET;     //����/���� 	PC8	
	
  	if  (csx==CS1)
        {LCD_CS1_SET;}
		else{LCD_CS2_SET;}	

		if  (invertx==LCM_NORMAL)
        {DATAOUT(data);}
		else{data=~data;
		     DATAOUT(data);}	
		
	LCD_EN_SET; 		//ʹ��	  	PC9
	delay_us(5);
	LCD_EN_CLR; 		//����		  PC9
 	LCD_CS1_CLR; 		//Ƭѡ�˿�  	PC6 
	LCD_CS2_CLR;    //Ƭѡ�˿�  	PB8	
} 
 



