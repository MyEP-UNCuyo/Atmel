/*
 * EJ06_Blink_Delay_SR
 *
 * Created: 19/04/2017 12:11:47 a.m.
 * Author : MyEP
   Realiza blink en PB5 por Lectura, XOR y Escritura, Delay,
   y Activación/Desactivación por polling de 2 pines (S=PB3, R=PB4)
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#define mi_B5 0b00100000 // o (1<<5)
#define mi_B4 0b00010000 // o (1<<4)
#define mi_B3 0b00001000 // o (1<<3)

#define ACT (PINB&mi_B3)	// La lectura de PORTB es PINB. (PINB&mi_B3)==mi_B3 equivale a PORTB3==1
#define DES (PINB&mi_B4)	// Idem para PORTB4==1

typedef enum {desactivado, activado}estado;	// se define el tipo enumerado "estado" (equivale a #define desactivado 0 y #define acivado 1)
estado osc_estado;				// osc_estado es la variable tipo "estado", toma los 2 valores enumerados
volatile char temp;
int main(void)
{ 
    DDRB=mi_B5;						// PORTB5 es salida, las demás son entradas
	osc_estado=activado;			// 
    while (1) 
    {		
		switch(osc_estado)						// Según sea osc_estado es lo que hace
			{
			case desactivado:
				if(ACT) osc_estado=activado;	// desde un estado evalúa si pasa al otro
				break;
			case activado:
				if(DES) osc_estado=desactivado; // desde un estado evalúa si pasa al otro
				PORTB^=mi_B5;					// realiza tarea
				PORTB|=(1<<3);
				temp=PINB;
				PORTB^=1<<2;
				temp=PINB;
				_delay_ms(100);	
				temp++;				
				break;
			default:
				break;
			}
    }
}

