section .data
input1 db 'Enter a number:',10
input2 db 'Enter 2nd number:    ',10
input3 db 'Enter 3rd number:    ',10
output1 db 'The sum is:',10


section .bss
sum resb 5
num1 resb 5
num2 resb 5
num3 resb 5

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

	mov eax,4 
	mov ebx,1
	mov ecx,input2
	mov edx,21
	int 80h

	mov eax,3
	mov ebx,2
	mov ecx,num2
	mov edx,5
	int 80h

	mov eax,4 
	mov ebx,1
	mov ecx,input2
	mov edx,21
	int 80h

	mov eax,3
	mov ebx,2
	mov ecx,num3
	mov edx,5
	int 80h

	mov eax,[num1] 
	sub eax,'0'
	mov ebx,[num2]
	sub ebx,'0'
	add eax,ebx
	mov ebx,[num3]
	sub ebx,'0'
	add eax,ebx
	add eax,'0'
	mov [sum],eax

	mov eax,4 
	mov ebx,1
	mov ecx,output1
	mov edx,11
	int 80h

	

	mov eax,4 
	mov ebx,1
	mov ecx,sum
	mov edx,5
	int 80h

	mov eax,1
	mov ebx,0
	int 80h

