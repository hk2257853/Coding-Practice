section .data
msg1 db 'Enter a number:',10
msg1len equ $-msg1
msg2 db 'Factorial is:',10
msg2len equ $-msg2

section .bss
num resb 5
prod resb 5
i resb 5
fact resb 5

section .text
global _start
_start:
call outputmsg1
call inputnumber
call outputmsg2
call initializer
call factorialcalc
call outputnum
mov eax,1
mov ebx,0
int 80h


outputmsg1:
	mov eax,4 
	mov ebx,1
	mov ecx,msg1
	mov edx,15
	int 80h
	ret


inputnumber:
	mov eax,3
	mov ebx,2
	mov ecx,num
	mov edx,5
	int 80h
	ret

outputmsg2:
	mov eax,4 
	mov ebx,1
	mov ecx,msg2
	mov edx,13
	int 80h
	ret	

initializer:
	mov al,'1'
	mov [i],al
	mov al,'1'
	mov [fact],al
	ret
	

factorialcalc:
	mov al,[fact]
	sub al,'0'
	mov bl,[i]
	sub bl,'0'
	mul bl
	add ax,'0'
	mov [fact],ax
	mov al,[i]
	sub al,'0'
	inc al
	add al,'0'
	mov [i],al

	mov al,[i]
	sub al,'0'
	mov bl,[num]
	sub bl,'0'
	cmp al,bl
	jle factorialcalc
	ret

outputnum:
	mov eax,4
	mov ebx,1
	mov ecx,fact
	mov edx,5
	int 80h
	ret
