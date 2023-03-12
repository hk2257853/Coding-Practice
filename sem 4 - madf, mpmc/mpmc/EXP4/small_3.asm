section .data
	msg1 db 'Enter the first number : '
	msg1len equ $-msg1
	msg2 db 'Enter the Second number: '
	msg2len equ $-msg2
	msg4 db 'Enter the third number: '
	msg4len equ $-msg4
	msg3 db 'The Smallest number is : '
	msg3len equ $-msg3
	newline db ' ',10
	newlinelen equ $-newline

section .bss
	num1 resb 5
	num2 resb 5
	num3 resb 5
	small resb 5

section .text
global _start

_start:
	;Input first number
	mov eax, 4
	mov ebx, 1
	mov ecx, msg1
	mov edx, msg1len
	int 80h

	mov eax, 3
	mov ebx, 2
	mov ecx, num1
	mov edx, 5
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, newline
	mov edx, newlinelen
	int 80h	
	
	;Input Second number
	mov eax, 4
	mov ebx, 1
	mov ecx, msg2
	mov edx, msg2len
	int 80h

	mov eax, 3
	mov ebx, 2
	mov ecx, num2
	mov edx, 5
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, newline
	mov edx, newlinelen
	int 80h	
	
	;Input third number
	mov eax, 4
	mov ebx, 1
	mov ecx, msg4
	mov edx, msg4len
	int 80h

	mov eax, 3
	mov ebx, 2
	mov ecx, num3
	mov edx, 5
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, newline
	mov edx, newlinelen
	int 80h		

	;Compare
	
	mov eax,[num1]
	cmp eax,[num2]
	jl L1
	mov eax,[num2]

	L1:
		cmp eax,[num3]
		jl L2
		mov eax,[num3]

	L2:
		mov [small],eax
	
		mov eax, 4
		mov ebx, 1
		mov ecx, msg3
		mov edx, msg3len
		int 80h

		mov eax, 4
		mov ebx, 1
		mov ecx, small
		mov edx, 5
		int 80h	
		
	mov eax,1
	mov ebx,0
	int 80h

