%macro write_string 2
	   mov eax, 4
	   mov ebx, 1
	   mov ecx, %1
	   mov edx, %2
	   int 80h
%endmacro

section .data
	msg1 db 'Hello, Programmers !!',10
	len1 equ $-msg1
	msg2 db 'Welcome to the World of ',10
	len2 equ $-msg2
	msg3 db 'Linux Assembly Programming',10
	len3 equ $-msg3

section .text
	global _start

_start:
	write_string msg1, len1
	write_string msg2, len2
	write_string msg3, len3

	mov eax, 1
	mov ebx, 0
	int 80h


	
