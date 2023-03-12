;Write an assembly language program to implement the write system call to display two inputs using macros
section .data
msg1 db 'Enter a string:'
msg1len equ $-msg1
msg2 db 'The string is '
msg2len equ $-msg2
msg3 db 'Enter string 2:'
msg3len equ $-msg3
msg4 db 'string 2 is '
msg4len equ $-msg4
newline db '	',10
newlinelen equ $-newline

section .bss
stringa resb 20
string resb 20

%macro write_message 2
    mov eax,4
    mov ebx,1
    mov ecx,%1
    mov edx,%2
    int 80h
%endmacro

section .text
global _start

_start:
    write_message msg1,msg1len
    
    mov eax,3
    mov ebx,2
    mov ecx,string
    mov edx,20
    int 80h

    write_message msg2,msg2len
    write_message string,20

    write_message msg3,msg3len
    
    mov eax,3
    mov ebx,2
    mov ecx,stringa
    mov edx,9
    int 80h

    write_message msg4,msg4len
    write_message stringa,20

    mov eax,1
    mov ebx,0
    int 80h
