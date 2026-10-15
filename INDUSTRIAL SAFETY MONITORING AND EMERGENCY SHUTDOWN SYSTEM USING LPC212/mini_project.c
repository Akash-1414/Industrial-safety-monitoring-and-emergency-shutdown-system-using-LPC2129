#include<lpc21xx.h>
#include"delay.h"
#include"lcd_header.h"
#include"uart.h"

#define LED 1<<12
#define M1 1<<9
#define M2 1<<10
#define IR 15

char flag=0;

unsigned char str[]="TITLE : INDUSTRIAL SAFETY MONITORING AND EMERGENCY SHUTDOWN SYSTEM USING LPC2129";

void EXINT0_ISR(void) __irq
{
  EXTINT=0x01;
  flag=2;
  VICVectAddr=0;
   
}


int main()
{
	UART_INIT();
	LCD_INIT();
	IODIR0|=LED|M1|M2;
	IOSET0=LED;
	
	
	PINSEL1|=0x01;
	VICIntSelect=0;
	VICVectCntl0=(0x20)|14;
	VICVectAddr0=(unsigned long)EXINT0_ISR;
	EXTMODE=0x01;
	EXTPOLAR=0x00;
	VICIntEnable=1<<14;
	UART_STR("TITLE : INDUSTRIAL SAFETY MONITORING AND EMERGENCY SHUTDOWN SYSTEM USING LPC2129\r\n"); 
	
	LCD_SCROLL(str);

	while(1)
	{
	  IOSET0=LED;
	 
	  if(flag==2) //ISR FUNCTION WRITTEN HERE TO MAKE ISR WITH LESS CODING
	  {
	  
           LCD_COMD(0x80);

           LCD_STR("MOTOR STOPPED");	
           UART_STR("MOTOR STOPPED\r\n");
  
           IOSET0=M1|M2;
           IOCLR0=LED;
           delay_sec(5);
           flag=0;
	  }
	  
	  if(flag==0)
	  {
	  	 UART_STR("MOTOR RUNNING\r\n");
		 LCD_COMD(0x80);
		 LCD_STR("MOTOR RUNNING");
		 flag=1;
	  }
	  
	   
	  IOSET0=M1;
	  IOCLR0=M2;
	  
	  if(((IOPIN0>>IR)&1)==0)
	  {
	  	if(flag)
		{
			UART_STR("MOTOR STOPPED\r\n");
			LCD_COMD(0x80);
			LCD_STR("MOTOR STOPPED");
			IOCLR0=LED;
			IOSET0|=M1|M2;
			flag=0;
			while(((IOPIN0>>IR)&1)==0);
		}
	
	  }
	 		


	}  
}
