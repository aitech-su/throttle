#ifndef __LCM_H
#define __LCM_H		
#include "sys.h"	 
#include "stdlib.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK MiniSTM32F103开发板
//2.4寸/2.8寸/3.5寸/4.3寸/7寸 TFT液晶驱动	  
//支持驱动IC型号包括:ILI9341/ILI9325/RM68042/RM68021/ILI9320/ILI9328/LGDP4531/LGDP4535/
//                  SPFD5408/1505/B505/C505/NT35310/NT35510/SSD1963等		    
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2010/7/4
//版本：V3.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved	
//********************************************************************************
//V1.2修改说明
//支持了SPFD5408的驱动,另外把液晶ID直接打印成HEX格式.方便查看LCD驱动IC.
//V1.3
//加入了快速IO的支持
//修改了背光控制的极性（适用于V1.8及以后的开发板版本）
//对于1.8版本之前(不包括1.8)的液晶模块,请修改LCD_Init函数的LCD_LED=1;为LCD_LED=1;
//V1.4
//修改了LCD_ShowChar函数，使用画点功能画字符。
//加入了横竖屏显示的支持
//V1.5 20110730
//1,修改了B505液晶读颜色有误的bug.
//2,修改了快速IO及横竖屏的设置方式.
//V1.6 20111116
//1,加入对LGDP4535液晶的驱动支持
//V1.7 20120713
//1,增加LCD_RD_DATA函数
//2,增加对ILI9341的支持
//3,增加ILI9325的独立驱动代码
//4,增加LCD_Scan_Dir函数(慎重使用)	  
//6,另外修改了部分原来的函数,以适应9341的操作
//V1.8 20120905
//1,加入LCD重要参数设置结构体lcddev
//2,加入LCD_Display_Dir函数,支持在线横竖屏切换
//V1.9 20120911
//1,新增RM68042驱动（ID:6804），但是6804不支持横屏显示！！原因：改变扫描方式，
//导致6804坐标设置失效，试过很多方法都不行，暂时无解。
//V2.0 20120924
//在不硬件复位的情况下,ILI9341的ID读取会被误读成9300,修改LCD_Init,将无法识别
//的情况（读到ID为9300/非法ID）,强制指定驱动IC为ILI9341，执行9341的初始化。
//V2.1 20120930
//修正ILI9325读颜色的bug。
//V2.2 20121007
//修正LCD_Scan_Dir的bug。
//V2.3 20130120
//新增6804支持横屏显示
//V2.4 20131120
//1,新增NT35310（ID:5310）驱动器的支持
//2,新增LCD_Set_Window函数,用于设置窗口,对快速填充,比较有用,但是该函数在横屏时,不支持6804.
//V2.5 20140211
//1,新增NT35510（ID:5510）驱动器的支持
//V2.6 20140504
//1,新增ASCII 24*24字体的支持(更多字体用户可以自行添加)  
//2,修改部分函数参数,以支持MDK -O2优化
//3,针对9341/35310/35510,写时间设置为最快,尽可能的提高速度
//4,去掉了SSD1289的支持,因为1289实在是太慢了,读周期要1us...简直奇葩.不适合F4使用
//5,修正68042及C505等IC的读颜色函数的bug.
//V2.7 20140710
//1,修正LCD_Color_Fill函数的一个bug. 
//2,修正LCD_Scan_Dir函数的一个bug.
//V2.8 20140721
//1,解决MDK使用-O2优化时LCD_ReadPoint函数读点失效的问题.
//2,修正LCD_Scan_Dir横屏时设置的扫描方式显示不全的bug.
//V2.9 20141130
//1,新增对SSD1963 LCD的支持.
//2,新增LCD_SSD_BackLightSet函数
//3,取消ILI93XX的Rxx寄存器定义
//V3.0 20150423
//修改SSD1963 LCD屏的驱动参数.
//////////////////////////////////////////////////////////////////////////////////	 

////////////////////////////////////////////////////////////////////
//-----------------LCD端口定义---------------- 
#define	LCD_BL PCout(10) 				 //LCD背光    	PC10

#define	LCD_EN_SET	 GPIOC->BSRR=1<<9;    //使能			PC9
#define	LCD_RS_SET	 GPIOC->BSRR=1<<8;    //数据/命令 	PC8	   
#define	LCD_WR_SET	 GPIOC->BSRR=1<<7;    //写数据			PC7
#define	LCD_CS1_SET  GPIOC->BSRR=1<<6;    //片选端口  	PC6
#define	LCD_CS2_SET  GPIOB->BSRR=1<<8;    //片选端口  	PB8

							    
#define	LCD_EN_CLR	 GPIOC->BRR=1<<9;     //使能	  	PC9
#define	LCD_RS_CLR	 GPIOC->BRR=1<<8;     //数据/命令 	PC8	   
#define	LCD_WR_CLR	 GPIOC->BRR=1<<7;     //写数据			PC7
#define	LCD_CS1_CLR  GPIOC->BRR=1<<6;     //片选端口  	PC6 
#define	LCD_CS2_CLR  GPIOB->BRR=1<<8;     //片选端口  	PB8
 	
//PB0~15,作为数据线
  
#define DATAOUT(x) GPIOB->BSRR=((~x&0xff)<<16)|x;
//#define DATAOUT(x) GPIOB->ODR=((GPIOB->ODR)&0xFF00)+x;
//#define DATAOUT(x) GPIOB->ODR=x; //数据输出
#define DATAIN     GPIOB->IDR;   //数据输入		 
//////////////////////////////////////////////////////////////////////

#define ON			    	0x3F
#define OFF			    	0x3E
#define STAR_LINE0		0xC0      //起始點在最高0xC0處,次高在0xFF處
#define PAGE0			    0xB8      //0-7
#define Y_ADDRESS0		0x40      //0-63
#define CS1   		    0x01      //CS1=1
#define CS2     	  	0x02      //CS2=2
#define LCM_NORMAL  	0x00      //LCM_NORMAL
#define LCM_INVERT     0x01      //LCM_INVERT




void LCM_Init(void);  //初始化	
void clear_lcm(void);
void logo(u8 logo_offset);	

void LCD_WR_REG(u8 data,u8 csx);
void LCD_WR_DATAX(u8 data,u8 csx,u8 invertx);

void write_number(u8 PAGE,u8 Y_ADDRESS,u8 invertx,u8 number);	
void write_word_symbol(u8 PAGE,u8 Y_ADDRESS,u8 W,u8 invertx,u16 offset);
void write_word_e(u8 PAGE,u8 Y_ADDRESS,u8 W,u8 invertx,u16 offset);

void write_word_t(u8 PAGE,u8 Y_ADDRESS,u8 invertx,u8 offset);
void write_word_c(u8 PAGE,u8 Y_ADDRESS,u8 invertx,u8 offset);
void write_word_j(u8 PAGE,u8 Y_ADDRESS,u8 invertx,u8 offset);
void write_word_k(u8 PAGE,u8 Y_ADDRESS,u8 W,u8 invertx,u16 offset);


void write_word_up_down(u8 PAGE,u8 Y_ADDRESS,u8 W,u8 invertx,const unsigned char *p);
  		 
#endif
