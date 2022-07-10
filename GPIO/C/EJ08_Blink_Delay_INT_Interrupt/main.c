/* EJ08_Blink_Delay_INT_Interrupt
 * Created: 19/04/2017 12:11:47 a.m.
 * Author : MyEP
   Realiza blink en PB5 por Lectura/Modificaci�n/Escritura 
   y Activaci�n/Desactivaci�n por "Interrupciones Externas INT0 e INT1"
   en 2 pines (S=PB3, R=PB4)
   Para completar comprensi�n leer manual de refe	rencia de los ATmega,
   y buscar los registros aqu� utilizados (EIMSK, EICRA)
 */

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>	
#include <avr/interrupt.h>

enum estado{activado,desactivado};
	
enum estado osc_estado;


int main(void)
{
    DDRB=1<<PORTB5;
	EIMSK=(1<<INT1)|(1<<INT0);	// INT0 set, INT1 reset
	EICRA=(1<<ISC00)|(1<<ISC01)|(1<<ISC10)|(1<<ISC11);	// ISC1x es 11 -> Flanco de subida
	
	sei();					// Activaci�n global de interrupciones
			
    while (1) 
    {		
		switch(osc_estado)
			{
			case desactivado:
				break;
			case activado:
				PORTB|=1<<PORTB5;
				_delay_ms(800);
				PORTB&=~(1<<PORTB5);
				_delay_ms(200);				
				break;
			default: break;
			}
    }
}

ISR (INT0_vect) // Rutina de Servicio de Interrupci�n de INT0
{
	osc_estado=activado;
}

ISR (INT1_vect) // Rutina de Servicio de Interrupci�n
{
	osc_estado=desactivado;
}
