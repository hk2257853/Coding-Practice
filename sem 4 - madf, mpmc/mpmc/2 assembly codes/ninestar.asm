section .data
stars times 9 db '*'

section .text
global _start
_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, stars
	mov edx, 9
	int 80h

	mov eax, 1
	mov ebx, 0
	int 80h
