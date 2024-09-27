#ifndef __LCM_H
#define __LCM_H		
#include "sys.h"	 
#include "stdlib.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK MiniSTM32F103������
//2.4��/2.8��/3.5��/4.3��/7�� TFTҺ������	  
//֧������IC�ͺŰ���:ILI9341/ILI9325/RM68042/RM68021/ILI9320/ILI9328/LGDP4531/LGDP4535/
//                  SPFD5408/1505/B505/C505/NT35310/NT35510/SSD1963��		    
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2010/7/4
//�汾��V3.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved	
//********************************************************************************
//V1.2�޸�˵��
//֧����SPFD5408������,�����Һ��IDֱ�Ӵ�ӡ��HEX��ʽ.����鿴LCD����IC.
//V1.3
//�����˿���IO��֧��
//�޸��˱�����Ƶļ��ԣ�������V1.8���Ժ�Ŀ�����汾��
//����1.8�汾֮ǰ(������1.8)��Һ��ģ��,���޸�LCD_Init������LCD_LED=1;ΪLCD_LED=1;
//V1.4
//�޸���LCD_ShowChar������ʹ�û��㹦�ܻ��ַ���
//�����˺�������ʾ��֧��
//V1.5 20110730
//1,�޸���B505Һ������ɫ�����bug.
//2,�޸��˿���IO�������������÷�ʽ.
//V1.6 20111116
//1,�����LGDP4535Һ��������֧��
//V1.7 20120713
//1,����LCD_RD_DATA����
//2,���Ӷ�ILI9341��֧��
//3,����ILI9325�Ķ�����������
//4,����LCD_Scan_Dir����(����ʹ��)	  
//6,�����޸��˲���ԭ���ĺ���,����Ӧ9341�Ĳ���
//V1.8 20120905
//1,����LCD��Ҫ�������ýṹ��lcddev
//2,����LCD_Display_Dir����,֧�����ߺ������л�
//V1.9 20120911
//1,����RM68042������ID:6804��������6804��֧�ֺ�����ʾ����ԭ�򣺸ı�ɨ�跽ʽ��
//����6804��������ʧЧ���Թ��ܶ෽�������У���ʱ�޽⡣
//V2.0 20120924
//�ڲ�Ӳ����λ�������,ILI9341��ID��ȡ�ᱻ�����9300,�޸�LCD_Init,���޷�ʶ��
//�����������IDΪ9300/�Ƿ�ID��,ǿ��ָ������ICΪILI9341��ִ��9341�ĳ�ʼ����
//V2.1 20120930
//����ILI9325����ɫ��bug��
//V2.2 20121007
//����LCD_Scan_Dir��bug��
//V2.3 20130120
//����6804֧�ֺ�����ʾ
//V2.4 20131120
//1,����NT35310��ID:5310����������֧��
//2,����LCD_Set_Window����,�������ô���,�Կ������,�Ƚ�����,���Ǹú����ں���ʱ,��֧��6804.
//V2.5 20140211
//1,����NT35510��ID:5510����������֧��
//V2.6 20140504
//1,����ASCII 24*24�����֧��(���������û������������)  
//2,�޸Ĳ��ֺ�������,��֧��MDK -O2�Ż�
//3,���9341/35310/35510,дʱ������Ϊ���,�����ܵ�����ٶ�
//4,ȥ����SSD1289��֧��,��Ϊ1289ʵ����̫����,������Ҫ1us...��ֱ����.���ʺ�F4ʹ��
//5,����68042��C505��IC�Ķ���ɫ������bug.
//V2.7 20140710
//1,����LCD_Color_Fill������һ��bug. 
//2,����LCD_Scan_Dir������һ��bug.
//V2.8 20140721
//1,���MDKʹ��-O2�Ż�ʱLCD_ReadPoint��������ʧЧ������.
//2,����LCD_Scan_Dir����ʱ���õ�ɨ�跽ʽ��ʾ��ȫ��bug.
//V2.9 20141130
//1,������SSD1963 LCD��֧��.
//2,����LCD_SSD_BackLightSet����
//3,ȡ��ILI93XX��Rxx�Ĵ�������
//V3.0 20150423
//�޸�SSD1963 LCD������������.
//////////////////////////////////////////////////////////////////////////////////	 

////////////////////////////////////////////////////////////////////
//-----------------LCD�˿ڶ���---------------- 
#define	LCD_BL PCout(10) 				 //LCD����    	PC10

#define	LCD_EN_SET	 GPIOC->BSRR=1<<9;    //ʹ��			PC9
#define	LCD_RS_SET	 GPIOC->BSRR=1<<8;    //����/���� 	PC8	   
#define	LCD_WR_SET	 GPIOC->BSRR=1<<7;    //д����			PC7
#define	LCD_CS1_SET  GPIOC->BSRR=1<<6;    //Ƭѡ�˿�  	PC6
#define	LCD_CS2_SET  GPIOB->BSRR=1<<8;    //Ƭѡ�˿�  	PB8

							    
#define	LCD_EN_CLR	 GPIOC->BRR=1<<9;     //ʹ��	  	PC9
#define	LCD_RS_CLR	 GPIOC->BRR=1<<8;     //����/���� 	PC8	   
#define	LCD_WR_CLR	 GPIOC->BRR=1<<7;     //д����			PC7
#define	LCD_CS1_CLR  GPIOC->BRR=1<<6;     //Ƭѡ�˿�  	PC6 
#define	LCD_CS2_CLR  GPIOB->BRR=1<<8;     //Ƭѡ�˿�  	PB8
 	
//PB0~15,��Ϊ������
  
#define DATAOUT(x) GPIOB->BSRR=((~x&0xff)<<16)|x;
//#define DATAOUT(x) GPIOB->ODR=((GPIOB->ODR)&0xFF00)+x;
//#define DATAOUT(x) GPIOB->ODR=x; //�������
#define DATAIN     GPIOB->IDR;   //��������		 
//////////////////////////////////////////////////////////////////////

#define ON			    	0x3F
#define OFF			    	0x3E
#define STAR_LINE0		0xC0      //��ʼ�c�����0xC0̎,�θ���0xFF̎
#define PAGE0			    0xB8      //0-7
#define Y_ADDRESS0		0x40      //0-63
#define CS1   		    0x01      //CS1=1
#define CS2     	  	0x02      //CS2=2
#define LCM_NORMAL  	0x00      //LCM_NORMAL
#define LCM_INVERT     0x01      //LCM_INVERT




void LCM_Init(void);  //��ʼ��	
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
