;
; LW10-2.asm
;
; Created: 09.01.2021 15:48:15
; Author : Petrushin
;

m:
	;call pp1
	;call pp2
	;call pp3
	;call pp4
	;call pp5
	call pp6
	jmp m

pp1: 
	ldi r16, 0x0f
	ldi r17 , 0x45
	ldi r18 , 0x67
	ldi r19 , 0x89
	ldi r20 , 0x18
	and r17, r16
	andi r17,0b00000010;
	or r18, r16
	tst r16 eor r19, r16
	eor r19, r19 mov r17, r20
	and r17, r16
	swap r16
	and r18, r16
	or r17, r18
	bst r16, 7
	bld r20, 2
	ret

pp2:
	ldi r16, 250
	ldi r17 , 200
	ldi r18 , 250
	ldi r19 , 200
	eor r1, r1
	eor r2, r2
	mov r0, r16
	add r0, r17
	adc r1 ,r2
	add r0, r18
	adc r1 ,r2
	add r0, r19
	adc r1 ,r2
	ror r1
	ror r0
	ror r1
	ror r0
	ret

;Разработайте программу нахождения среднего значения двух чисел.
pp3:
	ldi r16, 10
	ldi r17 , 20
	mov r0, r16
	add r0, r17
	ror r0
	ret

;Разработайте программу нахождения среднего значения 10 чисел, размещенных в памяти.
pp4:
	ldi r16, 10
	ldi r17, 20
	ldi r18, 20
	ldi r19 , 15
	ldi r20 , 15
	ldi r21 , 15
	ldi r22 , 15
	ldi r23 , 20
	ldi r24 , 20
	ldi r25 , 10
	ldi xh, 0x01
	ldi xl, 0x60
	st x+, r16
	st x+, r17
	st x+, r18
	st x+, r19
	st x+, r20
	st x+, r21
	st x+, r22
	st x+, r23
	st x+, r24
	st x+, r25

	ld r10, -x
	mov r0, r10

	ld r10, -x
	add r0, r10

	ld r10, -x
	add r0, r10
	
	ld r10, -x
	add r0, r10
	
	ld r10, -x
	add r0, r10
	
	ld r10, -x
	add r0, r10
	
	ld r10, -x
	add r0, r10
	
	ld r10, -x
	add r0, r10
	
	ld r10, -x
	add r0, r10
	
	ld r10, -x
	add r0, r10

	ldi r16, 10
	clr   r18      
    sub   r0,r16 
    inc   r18         
    brcc  PC-2      
    dec   r18 

	ret

;Разработайте программу умножения двух положительных чисел и двух чисел со знаком.
pp5:
	;ldi r16, 20
	;ldi r17, 15
	;mul r16, r17

	ldi r18, -2
	ldi r19, -15
	muls r18, r19
	ret

;Реализуйте вычисление следующей функции
pp6:
	ldi r16, 7
	ldi r17, 3
	ldi r18, 35
	ldi r19, 0
	ldi r20, 2
	ldi r21, 0x05
	ldi r22, 0xAA
	sts 0x0150, r17
	lds r5, 0x0150
	sts 0x0160, r17
	
	mov r10, r16
	add r10, r5
	mul r10, r20
	mov r10, r0

	mov r11, r18
	mul r11, r21
	mov r11, r0

	mov r12, r19
	and r12, r22

	add r10, r11
	add r10, r12

	lds r10, 0x0160
	ret


