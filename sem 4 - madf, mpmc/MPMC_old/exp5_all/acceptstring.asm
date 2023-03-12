;Write an assembly language program to implement the read system call using macros to accept a number and display it
section .data
msg1 db 'Enter a string:'
msg1len equ $-msg1
msg2 db 'The entered string is '
msg2len equ $-msg2
newline db '	',10
newlinelen equ $-newline

section .bss
string resb 20

%macro write_message 2
    mov eax,4
    mov ebx,1
    mov ecx,%1
    mov edx,%2
    int 80h
%endmacro

%macro read_message 2
    mov eax,3
    mov ebx,2
    mov ecx,%1
    mov edx,%2
    int 80h
%endmacro

section .text
global _start

_start:
    write_message msg1,msg1len
    read_message string,20
    write_message msg2,msg2len
    write_message string,20


    mov eax,1
    mov ebx,0
    int 80h