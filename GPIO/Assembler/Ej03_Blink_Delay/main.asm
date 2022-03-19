;
; Ej03_asm_Blink_delay
;
; Created: 17/12/2016 01:48:24 p.m.
; Author : MyEP
; Realiza blink por Lectura, XOR y Escritura
; Introduce delay

#define T1		200
#define	T2		250
#define T3		10

start:
    ldi		r16, 0b00100000
	out		DDRB, r16
loop:	
	IN		r17, PORTB		; Lee puerto B, guarda en r15							1
	EOR		r17, r16			; or exclusiva r15 y r16, guarda en r15				1
	OUT		PORTB, r17		; escribe r15 en puerto B (no modifica los demás bits	1
	CALL	delay			; 														4
    rjmp	loop			; salto relativo, 2 ciclos.								2

delay:	
	ldi		r17, T1		;														1
dly1:
	ldi		r18, T2		;														1 x							T1
dly2:	
	ldi		r19, T3		;														1 x		 T2 x T1
dly3:
	dec		r19			;														1 x T3 x T2 x T1
	brne	dly3		;														2 x T3 x T2 x T1 + 1 x T2 x T1
	dec		r18			;														1 x      T2 x T1 
	brne	dly2		;														2 x      T2 x T1 + 1 x      T1
	dec		r17			;														1 x							T1
	brne	dly1		;														2 x							T1 + 1
	ret					;														4
						; 5 x T1 + 5 x T2 x T1 + 3 x T3 x T2 x T1
						; 1000 + 250000 + 150000 x T3
