/*
* EJ04_Blink_LXE
*
* Created: 19/04/2017 12:11:47 a.m.
* Author : MyEP
Realiza blink por Lectura, XOR y Escritura
*/
#include <avr/io.h>
#define mi_B5 0b00100000; // o (1<<5). 
int main(void)
{
DDRB=mi_B5; // PB5 es salida, el resto entradas
while (1)
	{
	PORTB^=mi_B5;
	}
}

