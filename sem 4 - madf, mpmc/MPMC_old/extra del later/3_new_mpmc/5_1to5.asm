section .data
	num1 db '0'

section .text
	global _start
_start:
; subtracting 0 gives decimal?
	mov eax, '1'
	sub eax, '0' 
	inc eax
	inc eax
	inc eax
	inc eax
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
	
