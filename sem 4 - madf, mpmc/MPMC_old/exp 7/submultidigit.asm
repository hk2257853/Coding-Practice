section .data
msg1 db 'The difference is:',10
msg1len equ $-msg1
msg2 db 'Enter a number:',10
msg2len equ $-msg2
msg3 db 'Enter another number:',10
msg3len equ $-msg3

section .bss
num1 resb 5
num2 resb 5
sum resb 5

section .text

global _start
	_start:
	mov eax,4
	mov ebx,1
	mov ecx,msg2
	mov edx,msg2len
	int 80h

	mov eax,3
	mov ebx,2
	mov ecx,num1
	mov edx,5
	int 80h

	mov eax,4
	mov ebx,1
	mov ecx,msg3
	mov edx,msg3len
	int 80h

	mov eax,3
	mov ebx,2
	mov ecx,num2
	mov edx,5
	int 80h

	mov esi,3
	mov ecx,4
	clc

	sub_loop:
	mov al,[num1+esi]
	sbb al,[num2+esi]
	aaa ;ascii adjust after addition
	pushf
	or al,30h
	popf

	mov [sum+esi],al
	dec esi
	loop sub_loop

	mov eax,4
	mov ebx,1
	mov ecx,msg1
	mov edx,msg1len
	int 80h
	
	mov eax,4
	mov ebx,1
	mov ecx,sum
	mov edx,5
	int 80h

	mov eax,1
	mov ebx,0
	int 80h

