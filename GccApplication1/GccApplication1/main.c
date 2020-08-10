/*
 * GccApplication1.c
 *
 * Created: 7/10/2020 9:12:16 AM
 * Author : Osama Magdy
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "lcd.h"
#include <avr/eeprom.h>

	

int main(void)
{
	DDRA = 0x00;
	signed char y = 0 ;
	char str[3];
	PORTA = 0x01;
	InitLCD(LS_BLINK);
	LCDClear();
    /* Replace with your application code */
    char x ;
	while (1) 
    {
		
		x = eeprom_read_byte(0);
		
		if (x==100)
		{
			x=0;
		}
		
		if (y==100)
		{
			y=0;
		}
		
		LCDWriteStringXY(0,0,"EEPROM : ");
		
		//LCDWriteInt(x,2);
		itoa(x,str , 10);    ///// Using the last 10 is the radix of the number you want to print (decimal is 10 , binary is 2 and so on ) as it's mainly about how you read the bytes
		LCDWriteString(str);
		
		LCDWriteStringXY(0,1,"RAM : ");
		//LCDWriteInt(y,2);
		itoa(y,str , 10);		///// Using the last 10 is the radix of the number you want to print (decimal is 10 , binary is 2 and so on ) as it's mainly about how you read the bytes
		LCDWriteString(str);
		
		
		
		while(PINA == 0x00);
		
		while(PINA == 0x01);
		x=x+1;
		eeprom_write_byte(0,x);
		y=y+1;
    }
}


