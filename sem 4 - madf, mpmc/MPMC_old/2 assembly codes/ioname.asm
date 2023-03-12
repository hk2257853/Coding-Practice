section .data
	text1 db 'Enter name:', 10 
	textlen equ $-text1	

section .bss
	inputext resb 5
; my name has 5 alphabets

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
	mov ecx, inputext
	mov edx, 5
	int 80h

; display
	mov eax, 4
	mov ebx, 1
	mov ecx, inputext
	mov edx, 5
	int 80h

	mov eax, 1
	mov ebx, 0
	int 80h
	
