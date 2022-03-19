;
; Ej01_asm_Blink_LXE
;
; Created: 17/12/2016 01:48:24 p.m.
; Author : MyEP
; Realiza blink por set/reset de bit

start:
    ldi r16,0b00100000
	out DDRB, r16
loop:	
	SBI	PORTB,5			; PB5=1	2 ciclos
	CBI PORTB,5			; PB5=0	2 ciclos
    rjmp loop			; salto relativo, 2 ciclos. 
	;Total lazo: 6 ciclos. Total período onda: 6 ciclos, 2,66MHZ a 16MHz de clock
