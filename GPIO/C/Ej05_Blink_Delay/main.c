/*
 * EJ05_Blink_Delay
 *
 * Created: 19/04/2017 12:11:47 a.m.
 * Author : MyEP	
   Realiza blink por Lectura, XOR y Escritura, y Delay
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
 

int main(void)
{
	DDRB=0b00100000; // PB5 es salida, el resto entradas
    while (1) 
    {
		PORTB=0b00100000;
		_delay_ms(100);
		PORTB=0b00000000;
		_delay_ms(1000);
    }
}
