;Write an assembly language program to implement the write system call to display a number using macros
section .data
msg db 'The number is '
msglen equ $-msg
num db '9'
numlen equ $-num
newline db '	',10
newlinelen equ $-newline

section .bss
len resb 9

section .text
global _start

%macro write_message 2
    mov eax,4
    mov ebx,1
    mov ecx,%1
    mov edx,%2
    int 80h
%endmacro

_start:
    write_message msg,msglen
    write_message num,numlen
    write_message newline,newlinelen
    mov eax,1
    mov ebx,0
    int 80h
