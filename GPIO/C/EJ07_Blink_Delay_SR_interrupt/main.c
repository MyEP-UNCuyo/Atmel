/* EJ07_Blink_Delay_PCI_interrupt
 * Created: 19/04/2017 12:11:47 a.m.
 * Author : MyEp
   Realiza blink en PB5 por Lectura, XOR y Escritura, Delay, 
   y Activación/Desactivación por "Interrupción por Cambio en Pin(PCI)" 
   en 2 pines (S=PB3, R=PB4) 
   */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>	
#include <avr/interrupt.h>

#define ACT PINB&1<<(PORTB3)		// La lectura de PORTB es PINB. PINB&1<<(PORTB3) equivale a PORTB.3==1
#define DES PINB&1<<(PORTB4)		//
enum estado{activado,desactivado};
enum estado osc_estado;

int main(void)
{
    DDRB=1<<PORTB5;					// PORTB5 está definido en iom328p.h como 5. Es simplemente 1<<5
	
	PCICR|=1<<PCIE0;				  //PCIE0 habilita PCINT 0..7 (PORTB), PCIE1 PCINT 8..14 (PORTC) etc
	PCMSK0 = (1<<PORTB3)|(1<<PORTB4); //Dentro de PORTB se habilita interrupción por cambio en PCINT3 o PCINT4
	osc_estado=activado;			  
	sei();							  // Activación global de interrupciones
	
    while (1)					// Con respecto al EJ06, el polling de ACT y DES se efectúa en la
    {							// rutina de interrupción (para individualizar bit), no en el programa principal
		switch(osc_estado)
			{
			case desactivado:
				break;
			case activado:
				PORTB|=1<<PORTB5;		// Equivale a PORTB=PINB|00100000
				_delay_ms(800);
				PORTB&=~(1<<PORTB5);	// Equivale a PORTB=PINB&11011111
				_delay_ms(200);				
				break;
			default: break;
			}
    }
}

ISR (PCINT0_vect) // Rutina de Servicio de Interrupción
{
	if(DES) osc_estado=desactivado;	// Es necesario individualizar bit porque ambos van al mismo vector,
	if(ACT) osc_estado=activado;	// y si es flanco subida (es decir, si actual vale 1)
}