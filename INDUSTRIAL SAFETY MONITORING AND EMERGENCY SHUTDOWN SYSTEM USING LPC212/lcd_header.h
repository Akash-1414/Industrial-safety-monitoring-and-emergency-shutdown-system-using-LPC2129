#include<lpc21xx.h>


#define LCD 0xff<<23
#define RS 1<<21
#define E	1<<22

void LCD_INIT(void);
void LCD_COMD(unsigned char);
void LCD_DATA(unsigned char);
void LCD_STR(unsigned char *);
void LCD_SCROLL(unsigned char *);

void LCD_INIT(void)
{
	IODIR1|=LCD|RS|E;
	LCD_COMD(0x01);
	LCD_COMD(0x02);
	LCD_COMD(0x0c);
	LCD_COMD(0x38);
}

void LCD_COMD(unsigned char cmd)
{
	IOCLR1=LCD;
	IOSET1=(cmd<<23);
	IOCLR1=RS;
	IOSET1=E;
	delay_ms(2);
	IOCLR1=E;
}

void LCD_DATA(unsigned char d)
{

	IOCLR1=LCD;
	IOSET1=(d<<23);
	IOSET1=RS;
	IOSET1=E;
	delay_ms(2);
	IOCLR1=E;
}
void LCD_STR(unsigned char *s)
{	
	while(*s)
	{
		LCD_DATA(*s++);
	}
	
}

void LCD_SCROLL(unsigned char *s)
{
	char i,j,len=0;
	while(s[len]!='\0')
	len++;

	for(i=0;i<len;i++)
	{
		LCD_COMD(0x80);
		for(j=0;j<16;j++)
		{
			if((i+j)<len)
			{
				LCD_DATA(s[i+j]);
			}
			else
				LCD_DATA(' ');
			
		}
			delay_ms(300); 


	}
}
