section .data
input1 db 'Enter a number:',10
output1 db 'Num is odd',10
output2 db 'Num is even',10

section .bss
sum resb 5
num1 resb 5
num2 resb 5
rem resb 5


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

	mov al,[num1] ;calculating the quo
	sub al,'0'
	mov bl,'2'
	sub bl,'0'
	div bl
	add al,'0'
	add ah,'0'
	mov [rem],ah

	mov al,[rem] 
	sub al,'0'
	mov bl,'1'
	sub bl,'0'
	cmp al,bl
	jl evencondition 
	jmp oddcondition 

	mov eax,1
	mov ebx,0
	int 80h

evencondition:
	mov eax,4 
	mov ebx,1
	mov ecx,output2
	mov edx,11
	int 80h

	mov eax,1
	mov ebx,0
	int 80h

oddcondition:

	mov eax,4 
	mov ebx,1
	mov ecx,output1
	mov edx,10
	int 80h

	mov eax,1
	mov ebx,0
	int 80h
	
