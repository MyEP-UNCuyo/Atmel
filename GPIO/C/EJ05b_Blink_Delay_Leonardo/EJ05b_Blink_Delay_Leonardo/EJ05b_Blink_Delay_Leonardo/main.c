/*
 * Ej05_Blink_Delay_Leonardo.c
 *
 * Created: 06/05/2017 07:44:06 p.m.
 * Author : MyEP	
   Realiza blink por Lectura, XOR y Escritura, y Delay. Plataforma LEONARDO
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC=1<<DDC7; // PC7 es salida, el resto entradas
    while (1) 
    {
		PORTC^=1<<PORTC7;
		_delay_ms(100);
    }
}
