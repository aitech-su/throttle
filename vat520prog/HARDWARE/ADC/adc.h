#ifndef __ADC_H
#define __ADC_H	
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK MiniSTM32������
//ADC ����	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2014/3/9
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 

							  	 	    
#define ADC_CH0  0  	//ͨ��0
#define ADC_CH2  2  	//ͨ��2

#define ADC_CH10  10  	//ͨ��10
#define ADC_CH11  11  	//ͨ��11	
#define ADC_CH12  12  	//ͨ��12
#define ADC_CH13  13  	//ͨ��13	


void Adc_Init(void); 				//ADCͨ����ʼ��
u16  Get_Adc(u8 ch); 				//���ĳ��ͨ��ֵ 
u16 Get_Adc_Average(u8 ch,u8 times);//�õ�ĳ��ͨ��10�β�����ƽ��ֵ 	  
#endif 















