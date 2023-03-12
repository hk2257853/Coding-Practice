%macro read_number 1
	   mov eax, 3
	   mov ebx, 2
	   mov ecx, %1
	   mov edx, 5
	   int 80h
%endmacro

%macro write_string 2
	   mov eax, 4
	   mov ebx, 1
	   mov ecx, %1
	   mov edx, %2
	   int 80h
%endmacro

%macro write_number 1
	   mov eax, 4
	   mov ebx, 1
	   mov ecx, %1
	   mov edx, 5
	   int 80h
%endmacro

section .data
	msg1 db 'Enter a Number: ',9
	len1 equ $-msg1
	msg2 db 'The Number Is: ',9
	len2 equ $-msg2

section .bss
	num resb 5

section .text
	global _start

_start:
		
	write_string msg1, len1	
	read_number num
	write_string msg2, len2
	write_number num

	mov eax, 1
	mov ebx, 0
	int 80h
