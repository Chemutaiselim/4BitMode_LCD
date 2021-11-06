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

/*Our main program*/ 
int main(void) { 
	LCD_Init(); /* Initialize LCD */ 
	LCD_String("MSP II:EMT 3202"); 
	/* Write a string on 1st line of LCD*/ 
	LCD_Cmd(0xC0); /* Go to 2nd line*/ 
	LCD_String("Hello World"); /* Write string on 2nd line*/
}









