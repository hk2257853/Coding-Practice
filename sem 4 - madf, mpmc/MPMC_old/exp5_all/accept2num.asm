;Write an assembly language program to implement the read system call using macros to accept two inputs and display it
section .data
msg1 db 'Enter a number:'
msg1len equ $-msg1
msg2 db 'The number entered is:'
msg2len equ $-msg2
msg3 db 'Enter 2nd number:'
msg3len equ $-msg3
msg4 db 'The 2nd number: '
msg4len equ $-msg4
newline db '	',10
newlinelen equ $-newline

section .bss
num resb 9
numb resb 9

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
    read_message num,9
    write_message msg3,msg3len
    read_message numb,20
    
    write_message msg2,msg2len
    write_message num,9
    write_message msg4,msg4len
    write_message numb,20

    mov eax,1
    mov ebx,0
    int 80h
