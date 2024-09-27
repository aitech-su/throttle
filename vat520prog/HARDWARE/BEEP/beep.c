#include "beep.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK精英STM32F103开发板V1
//蜂鸣器驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2015/1/10
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

//初始化PB8为输出口.并使能这个口的时钟		    
//蜂鸣器初始化
void BEEP_Init(void)
{
	RCC->APB2ENR|=1<<4;    	//使能PORTC时钟	   	  
	GPIOC->CRH&=0XFF0FFFFF; 
	GPIOC->CRH|=0X00300000;	//PC.3 推挽输出    
	BEEP=0;					//关闭蜂鸣器输出
}

 void BEEP_on(void)
{		
		u8 t=255;
	while(1)
	{
		t--;
		BEEP=!BEEP;		  		//xor蜂鸣器
		
		delay_us(100);
		
		 if (t==0)
		 {
			BEEP=0;    //关闭蜂鸣器输出
		  break;		
		 }
	}
}
