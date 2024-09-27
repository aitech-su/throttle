
#include "adc.h"
#include "lcm.h"
#include "adcall.h"


//m^n函数
//返回值:m^n次方.
u32 LCD_Pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}	




void Adc10_display(u8 PAGE,u8 Y_ADDRESS,u8 invertx)

{ 
  u8 t,number;
	u16 adcx;
	float temp;

		adcx=Get_Adc_Average(ADC_CH10,10);
		temp=(float)adcx*(3.265/2.56);														//temp=(float)adcx*(3.3/4096/16)*1000=3.3/2.56  /16是因為15k與1k電阻分壓
		adcx=temp;
		//adcx=1234;
	
			
		for(t=0;t<4;t++)	
	{
		number=(adcx/LCD_Pow(10,4-t-1))%10;
		write_number(PAGE,Y_ADDRESS,invertx,number);     //寫數字:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,number是 0-9
		Y_ADDRESS+=8;
		
		//temp=(float)adcx*(3.3/4096);
		//adcx=temp;

		//write_number(PAGE,Y_ADDRESS,invertx,number);     //寫數字:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,number是 0-9
		
		
		
		//temp-=adcx;
		//temp*=1000;
		//LCD_ShowxNum(172,150,temp,3,16,0X80);
		

	}
}

void Adc11_display(u8 PAGE,u8 Y_ADDRESS,u8 invertx)

{ 
  u8 t,number;
	u16 adcx;
	float temp;
	
		adcx=Get_Adc_Average(ADC_CH11,10);
		temp=(float)adcx*(3.265/2.56);														//temp=(float)adcx*(3.3/4096/16)*1000=3.3/2.56  /16是因為15k與1k電阻分壓
		adcx=temp;

		for(t=0;t<4;t++)	
	{
		number=(adcx/LCD_Pow(10,4-t-1))%10;
		
		write_number(PAGE,Y_ADDRESS,invertx,number);     //寫數字:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,number是 0-9
		
		Y_ADDRESS+=8;
		
		
		
		//adcx=Get_Adc_Average(ADC_CH11,10);
		//temp=(float)adcx*(3.3/2.56);
		//adcx=temp;
		//number=(adcx/LCD_Pow(10,4-t-1))%10;
		//吹write_number(4,Y_ADDRESS,invertx,number);     //寫數字:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,number是 0-9
		
		
		//temp-=adcx;
		//temp*=1000;
		//LCD_ShowxNum(172,150,temp,3,16,0X80);
		

	}
}

void Adc12_display(u8 PAGE,u8 Y_ADDRESS,u8 invertx)

{ 
  u8 t,number;
	u16 adcx;
	float temp;
	
		adcx=Get_Adc_Average(ADC_CH12,10);
		temp=(float)adcx*(3.265/2.56);														//temp=(float)adcx*(3.3/4096/16)*1000=3.3/2.56  /16是因為15k與1k電阻分壓
		adcx=temp;
  	//adcx=1234;
	
 
		for(t=0;t<4;t++)	
	{
		number=(adcx/LCD_Pow(10,4-t-1))%10;
		write_number(PAGE,Y_ADDRESS,invertx,number);     //寫數字:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,number是 0-9
		Y_ADDRESS+=8;
		
		//temp=(float)adcx*(3.3/4096);
		//adcx=temp;

		//write_number(PAGE,Y_ADDRESS,invertx,number);     //寫數字:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,number是 0-9
		
		
		
		//temp-=adcx;
		//temp*=1000;
		//LCD_ShowxNum(172,150,temp,3,16,0X80);
		

	}
}

void Adc13_display(u8 PAGE,u8 Y_ADDRESS,u8 invertx)

{ 
  u8 t,number;
	u16 adcx;
	float temp;
	
		adcx=Get_Adc_Average(ADC_CH13,10);
		temp=(float)adcx*(3.265/2.56);														//temp=(float)adcx*(3.3/4096/16)*1000=3.3/2.56  /16是因為15k與1k電阻分壓
		adcx=temp;
  	//adcx=1234;
	
 
		for(t=0;t<4;t++)	
	{
		number=(adcx/LCD_Pow(10,4-t-1))%10;
		write_number(PAGE,Y_ADDRESS,invertx,number);     //寫數字:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,number是 0-9
		Y_ADDRESS+=8;
		
		//temp=(float)adcx*(3.3/4096);
		//adcx=temp;

		//write_number(PAGE,Y_ADDRESS,invertx,number);     //寫數字:PAGE=0-7,Y_ADDRESS=0-127,invertx LCM_NORMAL=0,LCM_INVERT=1,number是 0-9
		
		
		
		//temp-=adcx;
		//temp*=1000;
		//LCD_ShowxNum(172,150,temp,3,16,0X80);
		

	}
}

