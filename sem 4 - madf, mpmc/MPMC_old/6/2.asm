section .data
msg1 db 'Enter a number:',10
msg1len equ $-msg1
msg2 db 'Fibonacci upto n terms is:',10
msg2len equ $-msg2

section .bss
num resb 5
i resb 5
a resb 5
b resb 5
c resb 5
fibo resb 5

section .text
global _start
_start:
call outputmsg1
call inputnumber
call outputmsg2
call initializer
	mov al,[num]
	sub al,'0'
	mov bl,'0'
	sub bl,'0'
	cmp al,bl
	je zeroterm
	
	mov al,[num]
	sub al,'0'
	mov bl,'1'
	sub bl,'0'
	cmp al,bl
	je oneterm

	mov al,[num]
	sub al,'0'
	mov bl,'2'
	sub bl,'0'
	cmp al,bl
	je twoterms
	jmp morethantwoterms


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
	mov edx,msg2len
	int 80h
	ret

initializer:
	mov al,'2'
	mov [i],al
	mov al,'0'
	mov [a],al
	mov al,'1'
	mov [b],al
	ret

fibonacci:
	mov eax,[a]
	sub eax,'0'
	mov ebx,[b]
	sub ebx,'0'
	add eax,ebx
	add eax,'0'
	add ebx,'0'
	mov [a],ebx
	mov [b],eax
	
	call shownum
	
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
	je exit
	jmp fibonacci
	ret

shownum:
	mov eax,4
	mov ebx,1
	mov ecx,b
	mov edx,5
	int 80h
	ret


zeroterm:
	call exit

oneterm:
	mov eax,4 
	mov ebx,1
	mov ecx,a
	mov edx,5
	int 80h
	call exit

twoterms:
	mov eax,4 
	mov ebx,1
	mov ecx,a
	mov edx,5
	int 80h
	
	mov eax,4 
	mov ebx,1
	mov ecx,b
	mov edx,5
	int 80h
	call exit

morethantwoterms:
	mov eax,4 
	mov ebx,1
	mov ecx,a
	mov edx,5
	int 80h
	
	mov eax,4 
	mov ebx,1
	mov ecx,b
	mov edx,5
	int 80h
	call fibonacci
	


exit:
	mov eax,1
	mov ebx,0
	int 80h
	



	



