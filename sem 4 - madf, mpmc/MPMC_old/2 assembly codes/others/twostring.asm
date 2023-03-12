section .data
	word1 db 'word 1', 10 
	word2 db 'word 2', 10 
; hello is the variable
	word1len equ $-word1	
	word2len equ $-word2	
; hellolen is variable, eqn means equal to. it will store the len.

section .text
	global _start
_start:
	mov eax, 4
	mov ebx, 1

	mov ecx, word1
	mov edx, word1len
	int 80h

	mov ecx, word2
	mov edx, word2len
	int 80h

	mov eax, 1
	mov ebx, 0
	int 80h
	


