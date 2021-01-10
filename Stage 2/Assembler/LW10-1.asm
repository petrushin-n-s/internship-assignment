;
; LW10-1.asm
;
; Created: 09.01.2021 13:26:54
; Author : Petrushin
;

m:
	;call pp1
	;call pp2
	call pp3
	jmp m

pp1:
	ldi r16, 10
	ldi r17, 0x10
	ldi r18, 0x20
	ldi r19, 0x30
	mov r1, r16
	mov r2, r17
	mov r3, r18
	mov r4, r18
	ldi xh, 0x01
	ldi xl, 0x60
	st x+, r1
	st x+, r2
	st x+, r3
	st x+, r4
	ld r10, -x
	sts 0x0070, r16
	lds r5, 0x0060
	push r1
	push r2
	push r3
	push r4
	pop r14
	pop r13
	pop r12
	pop r11
	ret

;Запишите заданные числа в ячейки памяти с адресами 0х0160, 0х0161, 0х0162, 0х0163.
pp2:
	ldi r16, 7
	ldi r17, 3
	ldi r18, 35
	ldi r19, 0
	mov r1, r16
	mov r2, r17
	mov r3, r18
	mov r4, r19
	ldi xh, 0x01
	ldi xl, 0x60
	st x+, r1
	st x+, r2
	st x+, r3
	st x+, r4
	ret

;Разработайте подпрограмму pp3, которая сохраняет заданные числа в стеке и извлекает числа из стека в заданные регистры.
pp3:
	ldi r16, 7
	ldi r17, 3
	ldi r18, 35
	ldi r19, 0
	push r16
	push r17
	push r18
	push r19
	pop r14
	pop r13
	pop r12
	pop r11
	ret