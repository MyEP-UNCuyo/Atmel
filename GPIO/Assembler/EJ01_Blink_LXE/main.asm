;
; Ej01_asm_Blink_LXE
;
; Created: 17/12/2016 01:48:24 p.m.
; Author : MyEP
; Realiza blink por Lectura, XOR y Escritura

start:
    ldi r16,0b00100000	; La CPU AVR (de los ATmega) tiene 32 registros de propósito general 
						; y de trabajo, de r0 a r31. Se utilizan para operar, direccionar etc.
	out DDRB, r16		; DDRB es el Data Direction Register para PORTB, define el sentido de cada pin
loop:	
	IN  r15, PORTB		; Lee puerto B, guarda en r15
	EOR r15,r16			; or exclusiva r15 y r16, guarda en r15
	OUT PORTB, r15		; escribe r15 en puerto B (no modifica los demás bits)
    rjmp loop			; salto relativo, 2 ciclos. 
	;Total lazo: 5 ciclos. Total período onda: 10 ciclos, 1,6MHZ a 16MHz de clock
