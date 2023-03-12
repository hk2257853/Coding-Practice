section .data
input1 db 'Enter a number:',10
output1 db 'Num is lesser than 5',10
output2 db 'Num is greater than 5',10
output3 db 'Num is equal to 5',10

section .bss
sum resb 5
num1 resb 5
num2 resb 5


section .text
global _start
_start:
	mov eax,4 
	mov ebx,1
	mov ecx,input1
	mov edx,15
	int 80h
	
	mov eax,3
	mov ebx,2
	mov ecx,num1
	mov edx,5
	int 80h

	mov al,[num1] 
	sub al,'0'
	mov bl,'5'
	sub bl,'0'
	cmp al,bl
	je equalcondition ; If I put down it doesn't work
	jl lesscondition 
	jmp greatercondition ; jg is for greater... jmp is for jump

	
	mov eax,1
	mov ebx,0
	int 80h

lesscondition:
	mov eax,4 
	mov ebx,1
	mov ecx,output1
	mov edx,20
	int 80h

	mov eax,1
	mov ebx,0
	int 80h

greatercondition:

	mov eax,4 
	mov ebx,1
	mov ecx,output2
	mov edx,21
	int 80h

	mov eax,1
	mov ebx,0
	int 80h
	
equalcondition:

	mov eax,4 
	mov ebx,1
	mov ecx,output3
	mov edx,21
	int 80h

	mov eax,1
	mov ebx,0
	int 80h
