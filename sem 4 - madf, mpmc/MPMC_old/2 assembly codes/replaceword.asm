section .data
name db 'flat alc',10

section .text
global _start

_start:
	mov eax,4 
	mov ebx,1
	mov ecx,name
	mov edx,10 ;length of string including newline
	int 0x80 ;synonym for int 80h

	mov [name],dword 'tfcs'

	mov eax,4 
	mov ebx,1
	mov ecx,name
	mov edx,5
	int 80h
	
	mov eax,1
	mov ebx,0
	int 80h
