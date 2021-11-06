/*
 * 4BitMode_Code.c
 *
 * Created: 06/11/2021 16:34:37
 * Author : Default
 */ 

#include <avr/io.h>

/*Typical Header file inclusion and CPU frequency definition*/ 
#define F_CPU 8000000UL 
#include <avr/io.h> 
#include <util/delay.h> 
#include "LCD.h" /*Inclusion of our own defined header file*/

/*Useful pin and port definitions*/ 
#define LCD_Dir DDRD 
#define LCD_Port PORTD 
#define RS PD0 
#define EN PD1

/*LCD command write function*/ 
void LCD_Cmd(unsigned char cmd){ 
	/*Sending the first nibble of data (Higher 4 bits)*/ 
	LCD_Port = (LCD_Port & 0x0F) | (cmd & 0xF0);
	/* Sending upper nibble */ 
	LCD_Port &= ~ (1<<RS); /* RS=0, command reg. */ 
	LCD_Port |= (1<<EN); /* Enable pulse ON */ 
	_delay_us(1); 
	LCD_Port &= ~ (1<<EN); /* Enable pulse OFF */ 
	_delay_us(200); 
	/*Sending the second nibble of data (Lower 4 bits)*/ 
	LCD_Port = (LCD_Port & 0x0F) | (cmd << 4);
	/* Sending lower nibble */ 
	LCD_Port |= (1<<EN); /* Enable pulse ON */
	 _delay_us(1); 
	 LCD_Port &= ~ (1<<EN); /* Enable pulse OFF */ 
	 _delay_ms(2); 
	 }
	 
/*LCD data write function */ 
void LCD_Char (unsigned char char_data){ 
	/*Sending the first nibble of data (Higher 4 bits)*/ 
	LCD_Port = (LCD_Port & 0x0F) | (char_data & 0xF0);
	/* Sending upper nibble */ 
	LCD_Port |= (1<<RS); /* RS=1, data reg. */ 
	LCD_Port |= (1<<EN); /* Enable pulse ON */ 
	_delay_us(1); LCD_Port &= ~ (1<<EN); /* Enable pulse OFF */
	_delay_us(200); 
	/*Sending the second nibble of data (Lower 4 bits)*/ 
	LCD_Port = (LCD_Port & 0x0F) | (char_data << 4); 
	/* Sending lower nibble */ 
	LCD_Port |= (1<<EN); /* Enable pulse ON */ 
	_delay_us(1); 
	LCD_Port &= ~ (1<<EN); /* Enable pulse OFF */ 
	_delay_ms(2); 
	}


/*LCD Initialize function */ 
void LCD_Init (void){ 
	LCD_Dir = 0xFF; /* Make LCD command port direction as output pins*/ 
	_delay_ms(20); /* LCD Power ON delay always > 15ms */ 
	LCD_Cmd(0x02); /* Return display to its home position */ 
	LCD_Cmd(0x28); /* 2 line 4bit mode */ 
	LCD_Cmd(0x0C); /* Display ON Cursor OFF */ 
	LCD_Cmd(0x06); /* Auto Increment cursor */ 
	LCD_Cmd(0x01); /* Clear display */
}





