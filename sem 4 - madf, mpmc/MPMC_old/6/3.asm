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
msg6 db 'Quotient = '
msg6len equ $-msg6
msg7 db 'Remainder = '
msg7len equ $-msg7
newline db '	',10
newlinelen equ $-newline

section .bss
num1 resb 5
num2 resb 5
result resb 5
remainder resb 5
quo resb 5
rem resb 5

section .text
global _start
_start:
call outputmsg1
call inputnumber1
call outputmsg2
call inputnumber2
call addition
call subtraction
call multiplication
call division
mov eax,1
mov ebx,0
int 80h

outputmsg1:
	mov eax,4 
	mov ebx,1
	mov ecx,msg1
	mov edx,msg1len
	int 80h
	ret

inputnumber1:
	mov eax,3
	mov ebx,2
	mov ecx,num1
	mov edx,5
	int 80h
	ret

outputmsg2:
	mov eax,4 
	mov ebx,1
	mov ecx,msg2
	mov edx,msg2len
	int 80h
	ret

inputnumber2:
	mov eax,3
	mov ebx,2
	mov ecx,num2
	mov edx,5
	int 80h
	ret

addition:
	mov eax,[num1]
    	sub eax,'0'
    	mov ebx,[num2]
    	sub ebx,'0'
	add eax,ebx
	add eax,'0'
	mov [result],eax
	mov eax,4
    	mov ebx,1
    	mov ecx,msg3
    	mov edx,msg3len
    	int 80h
	call printresult
	ret

subtraction:
	mov eax,[num1]
	sub eax,'0'
	mov ebx,[num2]
	sub ebx,'0'
	sub eax,ebx
	add eax,'0'
	mov [result],eax
	mov eax,4
    	mov ebx,1
    	mov ecx,msg4
    	mov edx,msg4len
    	int 80h
	call printresult
	ret

multiplication:
	mov eax,[num1]
	sub eax,'0'
	mov ebx,[num2]
	sub ebx,'0'
	mul ebx
	add eax,'0'
	mov [result],eax
	mov eax,4
    	mov ebx,1
    	mov ecx,msg5
    	mov edx,msg5len
    	int 80h
	call printresult
	ret

division:
	mov al,[num1] 
	sub al,'0'
	mov bl,[num2]
	sub bl,'0'
	div bl
	add al,'0'
	add ah,'0'
	mov [quo],al
	mov [rem],ah
	call printdivisionresult
	ret
	

printresult:
	mov eax,4
    	mov ebx,1
    	mov ecx,result
    	mov edx,5
    	int 80h
	
	mov eax,4
    	mov ebx,1
    	mov ecx,newline
    	mov edx,newlinelen
    	int 80h	
	ret

printdivisionresult:
	mov eax,4
    	mov ebx,1
    	mov ecx,msg6
    	mov edx,msg6len
    	int 80h

	mov eax,4
    	mov ebx,1
    	mov ecx,quo
    	mov edx,5
    	int 80h

	mov eax,4
    	mov ebx,1
    	mov ecx,newline
    	mov edx,newlinelen
    	int 80h

	mov eax,4
    	mov ebx,1
    	mov ecx,msg7
    	mov edx,msg7len
    	int 80h

	mov eax,4
    	mov ebx,1
    	mov ecx,rem
    	mov edx,5
    	int 80h
	
	mov eax,4
    	mov ebx,1
    	mov ecx,newline
    	mov edx,newlinelen
    	int 80h	
	ret
	

exit:
	mov eax,1
	mov ebx,0
	int 80h



