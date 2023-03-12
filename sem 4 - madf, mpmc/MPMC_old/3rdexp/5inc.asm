section .data
msg1 db 'Enter a number:',10
newl db '     ',10

section .bss
num1 resb 5

section .text
global _start
_start:

	mov eax,4 
	mov ebx,1
	mov ecx,msg1
	mov edx,15
	int 80h
	
	mov eax,3 
	mov ebx,2
	mov ecx,num1
	mov edx,5
	int 80h

	mov eax,[num1]
	sub eax,'0'
	inc eax
	add eax,'0'
	mov [num1],eax
	
	mov eax,4 
	mov ebx,1
	mov ecx,num1
	mov edx,5
	int 80h

	mov eax,[num1]
	sub eax,'0'
	inc eax
	add eax,'0'
	mov [num1],eax
	
	mov eax,4 
	mov ebx,1
	mov ecx,num1
	mov edx,5
	int 80h

	mov eax,[num1]
	sub eax,'0'
	inc eax
	add eax,'0'
	mov [num1],eax
	
	mov eax,4 
	mov ebx,1
	mov ecx,num1
	mov edx,5
	int 80h

	mov eax,[num1]
	sub eax,'0'
	inc eax
	add eax,'0'
	mov [num1],eax
	
	mov eax,4 
	mov ebx,1
	mov ecx,num1
	mov edx,5
	int 80h
	
	mov eax,1
	mov ebx,0
	int 80h

