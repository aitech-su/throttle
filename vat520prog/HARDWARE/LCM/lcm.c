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
//  PORTC时钟 
///////////////////////////////////////////////////////////
 		RCC->APB2ENR|=1<<4;    //使能PORTC时钟	   

		GPIOC->CRL&=0X00FFFFFF; 
  	GPIOC->CRL|=0X33000000; //PC7,6 推挽输出 W/R=PC7,CS1=PC6
	 	GPIOC->ODR|=0<<7;       //W/R=PC7 输出LOW
	  GPIOC->ODR|=0<<6;       //CS1=PC6 输出LOW

	   	 
	  GPIOC->CRH&=0XFFFFF000; 
  	GPIOC->CRH|=0X00000333; //PC10,9,8 推挽输出 LCD背光PC10=EN=PC9  R/S=PC8 
    GPIOC->ODR|=1<<10;      //PC10 LCD背光输出高 也可寫成 LCD_BL=1;
	  GPIOC->ODR|=0<<9;       //EN=PC9输出LOW
	  GPIOC->ODR|=0<<8;       //R/S=PC8 输出LOW
	 
//////////////////////////////////////////////////////////////////		
// 	PORTB时钟	 	 
/////////////////////////////////////////////////////////
	  RCC->APB2ENR|=1<<3;    //使能PORTB时钟	
	 
	 	RCC->APB2ENR|=1<<0;    //开启辅助时钟 MCU復位後，PA13/14/15 & PB3/4默認配置為JTAG功能。有時我們為了充分利用MCU I/O口的資源，會把這些埠設置為普通I/O口原文網址：https://read01.com/oLNPzL.html
	  JTAG_Set(SWD_ENABLE);  //开启SWD  解決 PB3/4 資料錯誤
	 
	 
		GPIOB->CRL=0X33333333;   //PB0-7  上拉输出
	   
	  GPIOB->CRH&=0XFFFFFFF0;
	  GPIOB->CRH|=0X00000003;  //PB8 推挽输出 CS2=PB8
	  GPIOB->ODR|=0<<8;        //PB8 CS2=PB8输出LOW
		
		LCD_WR_REG(ON,CS1);           //CS1=1  off=0x3e  on=0x3f
		LCD_WR_REG(ON,CS2);	          //CS2=2  off=0x3e  on=0x3f
		LCD_WR_REG(STAR_LINE0,CS1);  	//cs1=1  STAR_LINE0	起始點在最高0xC0處,次高在0xFF處 
		LCD_WR_REG(STAR_LINE0,CS2);	  //cs2=2  STAR_LINE0	起始點在最高0xC0處,次高在0xFF處
 
 }
 
 //寫 清除LCM
  void clear_lcm(void)		    //clr 畫面 128*64
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

//寫 LOGO 顯示
  void logo(u8 logo_offset)		   //*p=logo_table{0}的地址 128*64=8192bit  8192/8=1024 byte u16=65536
{	
	      u8 i,j;   
        p=logo_bmp+logo_offset*1024;      //:一張logo=1024 ....  128*64=8192/8bit=1024
	     
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



//寫0-9數字  

void write_number(u8 PAGE,u8 Y_ADDRESS,u8 invertx,u8 number)	   //寫數字:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,number是 0-9
{	 			
					u8 W=8;																								 //字的寬度都是8
	        p=n_0+number*16; 																		   //數字 0 的起始位置
					write_word_up_down(PAGE,Y_ADDRESS,W,invertx,p);        //PAGE=0-7,Y_ADDRESS=0-127,字的寬度都是8,上下兩行占用16個0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=n_0的地址+number 0-9						
}

//寫符號

void write_word_symbol(u8 PAGE,u8 Y_ADDRESS,u8 W,u8 invertx,u16 offset)	  //寫字:PAGE=0-7,Y_ADDRESS=0-127,W=字的寬度,invertx LCM_NORMAL=0,LCM_INVERT=1,number是 0-9
{			  	       
	        p=s_0+offset*2; 
					write_word_up_down(PAGE,Y_ADDRESS,W,invertx,p);         //PAGE=0-7,Y_ADDRESS=0-127,字的寬度都是8,上下兩行占用16個0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=k_0+offset*(W*2)
}

//寫英文字

void write_word_e(u8 PAGE,u8 Y_ADDRESS,u8 W,u8 invertx,u16 offset)	  //寫字:PAGE=0-7,Y_ADDRESS=0-127,W=字的寬度,invertx LCM_NORMAL=0,LCM_INVERT=1,number是 0-9
	
{	
	        p=e_0+offset*2; 
					write_word_up_down(PAGE,Y_ADDRESS,W,invertx,p);         //PAGE=0-7,Y_ADDRESS=0-127,字的寬度都是8,上下兩行占用16個0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=k_0+offset*(W*2)
}



//寫繁體字

void write_word_t(u8 PAGE,u8 Y_ADDRESS,u8 invertx,u8 offset)	  //寫字:PAGE=0-7,Y_ADDRESS=0-127,W=字的寬度,invertx LCM_NORMAL=0,LCM_INVERT=1,number是 0-9
{			  	       
	        u8 W=16;																									//字的寬度都是16
					p=t_0+offset*32; 
					write_word_up_down(PAGE,Y_ADDRESS,W,invertx,p);          //PAGE=0-7,Y_ADDRESS=0-127,字的寬度都是8,上下兩行占用16個0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=t_0+offset*32
}

//寫簡體字

void write_word_c(u8 PAGE,u8 Y_ADDRESS,u8 invertx,u8 offset)	  //寫字:PAGE=0-7,Y_ADDRESS=0-127,W=字的寬度,invertx LCM_NORMAL=0,LCM_INVERT=1,number是 0-9
{			  	       
	        u8 W=16;																									//字的寬度都是16
					p=c_0+offset*32; 
					write_word_up_down(PAGE,Y_ADDRESS,W,invertx,p);          //PAGE=0-7,Y_ADDRESS=0-127,字的寬度都是8,上下兩行占用16個0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=t_0+offset*32
}

//寫日文字

void write_word_j(u8 PAGE,u8 Y_ADDRESS,u8 invertx,u8 offset)	  //寫字:PAGE=0-7,Y_ADDRESS=0-127,W=字的寬度,invertx LCM_NORMAL=0,LCM_INVERT=1,number是 0-9
{			  	
					u8 W=16;																									//字的寬度都是16
	        p=j_0+offset*32; 
					write_word_up_down(PAGE,Y_ADDRESS,W,invertx,p);         //PAGE=0-7,Y_ADDRESS=0-127,字的寬度都是8,上下兩行占用16個0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=j_0+offset*(W*2)
}

//寫韓文字

void write_word_k(u8 PAGE,u8 Y_ADDRESS,u8 W,u8 invertx,u16 offset)	  //寫字:PAGE=0-7,Y_ADDRESS=0-127,W=字的寬度,invertx LCM_NORMAL=0,LCM_INVERT=1,number是 0-9
{			  	       
	        p=k_0+offset*2; 
					write_word_up_down(PAGE,Y_ADDRESS,W,invertx,p);         //PAGE=0-7,Y_ADDRESS=0-127,字的寬度都是8,上下兩行占用16個0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=k_0+offset*(W*2)
}



//寫字或數字的上下半部

void write_word_up_down(u8 PAGE,u8 Y_ADDRESS,u8 W,u8 invertx,const unsigned char *p)	  //寫字或數字的上下半部 PAGE=0-7,Y_ADDRESS=0-127,字的寬度是W,上下兩行占用16個0xff,invertx LCM_NORMAL=0,LCM_INVERT=1 p=n_0的地址
{	
			    u8 i,csx;	 
					if (Y_ADDRESS<64)
              {csx=CS1;}
					else{csx=CS2;
					     Y_ADDRESS-=64;
					    }
								     		      	      		  										
				 LCD_WR_REG(PAGE+PAGE0,csx);               //字的上半部
			   LCD_WR_REG(Y_ADDRESS+Y_ADDRESS0,csx); 	   
			 
	    for(i=0;i<W;i++)
	      {			 
      	 LCD_WR_DATAX(*(p+i),csx,invertx);           //	LCD_WR_DATAX(p[i],csx,invert); *p=p{i}      	
	    	}
				
			 	 LCD_WR_REG(PAGE+PAGE0+1,csx);             //字的下半部  
			   LCD_WR_REG(Y_ADDRESS+Y_ADDRESS0,csx); 	   
			 
	    for(i=0;i<W;i++)
	      {			 
      	 LCD_WR_DATAX(*(p+W+i),csx,invertx);      	      	
	    	}		 
}
//写寄存器函数 寫命令
//data:寫命令的值
                                               		
 void LCD_WR_REG(u8 data,u8 csx)        //data:寫命令的值 csx=cs1 OR cs2 
{ 
	LCD_EN_CLR; 		//除能		  PC9   加此行解決雄鐸cs1,cs2同時亮的問題  
	LCD_WR_CLR;     //写数据			PC7
	LCD_RS_CLR;     //数据/命令 	PC8	
	
		if  (csx==CS1)
        {LCD_CS1_SET;}
    else{LCD_CS2_SET;}	
		
	DATAOUT(data); 	
	LCD_EN_SET; 		//使能	  	PC9 
	delay_us(5);	
	LCD_EN_CLR; 		//除能		  PC9
 	LCD_CS1_CLR;  	//片选端口  	PC6 
	LCD_CS2_CLR;    //片选端口  	PB8	
} 

////////////////////////////////////////////////
//写数据函数 寫字型
//
//data:寫字型的值
 void LCD_WR_DATAX(u8 data,u8 csx,u8 invertx)  //data:寫字型的值 csx=cs1 OR cs2  invertx LCM_NORMAL=0,LCM_INVERT=1
{
	LCD_EN_CLR; 		//除能	  	PC9    加此行解決雄鐸cs1,cs2同時亮的問題
	LCD_WR_CLR;     //写数据			PC7	
	LCD_RS_SET;     //数据/命令 	PC8	
	
  	if  (csx==CS1)
        {LCD_CS1_SET;}
		else{LCD_CS2_SET;}	

		if  (invertx==LCM_NORMAL)
        {DATAOUT(data);}
		else{data=~data;
		     DATAOUT(data);}	
		
	LCD_EN_SET; 		//使能	  	PC9
	delay_us(5);
	LCD_EN_CLR; 		//除能		  PC9
 	LCD_CS1_CLR; 		//片选端口  	PC6 
	LCD_CS2_CLR;    //片选端口  	PB8	
} 
 



