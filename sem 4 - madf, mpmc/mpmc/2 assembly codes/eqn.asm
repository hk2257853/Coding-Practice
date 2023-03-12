section .data
sys_exit equ 1
sys_write equ 4
stdin equ 0
stdout equ 1
msg1 db 'hello',10
msg2 db 'welcome',10
msg1len equ $-msg1
msg2len equ $-msg2

section .text
global _start
_start:
	mov eax,sys_write 
	mov ebx,stdout
	mov ecx,msg1
	mov edx,6
	int 80h

	mov eax,sys_write 
	mov ebx,stdout
	mov ecx,msg2
	mov edx,8
	int 80h
	
	mov eax,sys_exit
	mov ebx,0
	int 80h

