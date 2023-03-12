section .data
	hello db 'hello world', 10 
; hello is the variable
	hellolen equ $-hello	
; hellolen is variable, eqn means equal to. it will store the len.

section .text
	global _start
_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, hello
	mov edx, hellolen
	int 80h
	mov eax, 1
	mov ebx, 0
	int 80h
	
; uname -m
; sudo apt-get install build essentials
; sudo apt-get install nasm

; compiling:
; nasm -f elf  hello.asm
; ld -m elf_i386 -s -o hello hello.o
; ./hello


; elf executalbe & leakable format
