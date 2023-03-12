section .data
input1 db 'Enter a number:',10
input2 db 'Enter another number:',10
outputsum db 'The sum is:',10
outputdiff db ' The difference is:',10
outputmul db ' The product is:',10
outputquo db 'The quotient is:',10
outputrem db 'The remainder is:',10
newl db '	',10
newllength equ $-newl


section .bss
sum resb 5
diff resb 5
prod resb 5
quo resb 5
rem resb 5
num1 resb 5
num2 resb 5


section .text
global _start
_start:
	mov eax,4 ;input first num
	mov ebx,1
	mov ecx,input1
	mov edx,15
	int 80h

	mov eax,3 ; input first num
	mov ebx,2
	mov ecx,num1
	mov edx,5
	int 80h

	mov eax,4 ;input second num
	mov ebx,1 
	mov ecx,input2
	mov edx,21
	int 80h

	mov eax,3 ;input second num
	mov ebx,2
	mov ecx,num2
	mov edx,5
	int 80h

	mov eax,[num1] ;calculating the sum
	sub eax,'0'
	mov ebx,[num2]
	sub ebx,'0'
	add eax,ebx
	add eax,'0'
	mov [sum],eax

	mov eax,[num1] ;calculating the difference 
	sub eax,'0'
	mov ebx,[num2]
	sub ebx,'0'
	sub eax,ebx
	add eax,'0'
	mov [diff],eax

	mov eax,[num1] ;calculating the product 
	sub eax,'0'
	mov ebx,[num2]
	sub ebx,'0'
	mul ebx
	add eax,'0'
	mov [prod],eax

	

	mov eax,4 ;output the sum
	mov ebx,1
	mov ecx,outputsum
	mov edx,11
	int 80h

	mov eax,4 ;output the sum
	mov ebx,1
	mov ecx,sum
	mov edx,5
	int 80h

	mov eax,4 ;output newline
	mov ebx,1
	mov ecx,newl
	mov edx,newllength
	int 80h

	mov eax,4 ;output the diff
	mov ebx,1
	mov ecx,outputdiff
	mov edx,19
	int 80h

	mov eax,4 ;output the diff
	mov ebx,1
	mov ecx,diff
	mov edx,5
	int 80h

	mov eax,4 ;output newline
	mov ebx,1
	mov ecx,newl
	mov edx,newllength
	int 80h
	
	mov eax,4 ;output the prod
	mov ebx,1
	mov ecx,outputmul
	mov edx,16
	int 80h	
	

	mov eax,4 ;output the prod
	mov ebx,1
	mov ecx,prod
	mov edx,5
	int 80h

	mov eax,4 ;output newline
	mov ebx,1
	mov ecx,newl
	mov edx,newllength
	int 80h

	mov al,[num1] ;calculating the quo
	sub al,'0' ;working
	mov bl,[num2]
	sub bl,'0'
	div bl
	add al,'0'
	add ah,'0'
	mov [quo],al
	mov [rem],ah

	mov eax,4 ;output the quotient
	mov ebx,1
	mov ecx,outputquo
	mov edx,16
	int 80h

	mov eax,4 ;output the quotient
	mov ebx,1
	mov ecx,quo
	mov edx,5
	int 80h

	mov eax,4 ;output newline
	mov ebx,1
	mov ecx,newl
	mov edx,newllength
	int 80h


	mov eax,4 ;output the rem
	mov ebx,1
	mov ecx,outputrem
	mov edx,17
	int 80h
	
	mov eax,4 ;output the rem
	mov ebx,1
	mov ecx,rem
	mov edx,5
	int 80h

	mov eax,1
	mov ebx,0
	int 80h


