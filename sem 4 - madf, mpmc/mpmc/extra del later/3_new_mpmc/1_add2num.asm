section .data
	text1 db 'Enter 1st number:', 10 
	textlen equ $-text1	
	text2 db 'Enter 2nd number:', 10 
	textlen2 equ $-text2	

section .bss
	num1 resb 5
	num2 resb 5
; int is 4 bit + 1 for sign

section .text
	global _start
_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, text1
	mov edx, textlen
	int 80h

;input
	mov eax, 3
	mov ebx, 2
	mov ecx, num1
	mov edx, 5
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, text2
	mov edx, textlen2
	int 80h

;input
	mov eax, 3
	mov ebx, 2
	mov ecx, num2
	mov edx, 5
	int 80h

; subtracting 0 gives decimal?
	mov eax, [num1]
	sub eax, '0' 
	mov ebx, [num2]
	sub ebx, '0'
	add eax, ebx
	add eax, '0'
	mov [num1], eax
	int 80h

; display sum
	mov eax, 4
	mov ebx, 1
	mov ecx, num1
	mov edx, 5
	int 80h


	mov eax, 1
	mov ebx, 0
	int 80h
	
