;Write an assembly language program to implement calculator using macros
section .data
msg1 db 'Enter first number:'
msg1len equ $-msg1
msg2 db 'Enter second number:'
msg2len equ $-msg2
msg3 db 'Sum = '
msg3len equ $-msg3
msg4 db 'Difference = '
msg4len equ $-msg4
msg5 db 'Product = '
msg5len equ $-msg5
msg6 db 'Division = '
msg6len equ $-msg6
msg7 db 'Remainder = '
msg7len equ $-msg7
newline db '	',10
newlinelen equ $-newline

section .bss
num1 resb 9
num2 resb 9
result resb 9
remainder resb 9

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

%macro ADDITION 3
    mov ax,[%1]
    sub ax,'0'
    mov bx,[%2]
    sub bx,'0'
    add ax,bx
    add ax,'0'
    mov [%3],ax
%endmacro

%macro SUBTRACTION 3
    mov ax,[%1]
    sub ax,'0'
    mov bx,[%2]
    sub bx,'0'
    sub ax,bx
    add ax,'0'
    mov [%3],ax
%endmacro

%macro MULTIPLY 3
    mov al,[%1]
	sub al,'0'
	mov bl,[%2]
	sub bl,'0'
	mul bl
	add ax,'0'
	mov [%3],ax
%endmacro

%macro DIVISION 4
    mov al,[%1]
	sub al,'0'
	mov bl,[%2]
	sub bl,'0'
	div bl
	add ah,'0'
	add al,'0'
	mov [%3],al
	mov [%4],ah
%endmacro

section .text
global _start


_start:
    write_message msg1,msg1len
    read_message num1,9
    write_message msg2,msg2len
    read_message num2,9

    ;ADDITION OF TWO NUMBERS
    ADDITION num1,num2,result
    write_message msg3,msg3len
    write_message result,9
    write_message newline,newlinelen

    ;SUBTRACTION OF TWO NUMBERS
    SUBTRACTION num1,num2,result
    write_message msg4,msg4len
    write_message result,9
    write_message newline,newlinelen

    ;MULTIPLICATION OF TWO NUMBERS
    MULTIPLY num1,num2,result
    write_message msg5,msg5len
    write_message result,9
    write_message newline,newlinelen

    ;DIVISION OF TWO NUMBERS
    DIVISION num1,num2,result,remainder
    write_message msg6,msg6len
    write_message result,9
    write_message newline,newlinelen
    write_message msg7,msg7len
    write_message remainder,9
    write_message newline,newlinelen
    
    mov eax,1
    mov ebx,0
    int 80h