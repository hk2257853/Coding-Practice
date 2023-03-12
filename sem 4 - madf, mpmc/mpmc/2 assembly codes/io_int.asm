section .data
	text1 db 'Enter number:', 10 
	textlen equ $-text1	

section .bss
	num resb 5
; int is 4 bit + 1 for sign

section .text
	global _start
_start:
;print text1 
	mov eax, 4
	mov ebx, 1
	mov ecx, text1
	mov edx, textlen
	int 80h

;input
	mov eax, 3
	mov ebx, 2
	mov ecx, num
	mov edx, 5
	int 80h

; display
	mov eax, 4
	mov ebx, 1
	mov ecx, num
	mov edx, 5
	int 80h

	mov eax, 1
	mov ebx, 0
	int 80h
	
