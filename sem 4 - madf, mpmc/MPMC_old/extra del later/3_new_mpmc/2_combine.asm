section .data
	text1 db 'Enter 1st number:', 10 
	textlen equ $-text1	
	text2 db 'Enter 2nd number:', 10 
	textlen2 equ $-text2	
	text3 db 'Addition:', 10 
	textlen3 equ $-text3
	text4 db 'Subraction:', 10 
	textlen4 equ $-text4
	text5 db 'Multiplication:', 10 
	textlen5 equ $-text5
	text6 db 'Division:', 10 
	textlen6 equ $-text6
	text7 db 'Quotient:', 10 
	textlen7 equ $-text7
	text8 db 'Remainder:', 10 
	textlen8 equ $-text8

section .bss
	num1 resb 5
	num2 resb 5
	ad resb 5
	su resb 5
	mu resb 5
	qu resb 5
	re resb 5 
; int is 4 bit + 1 for sign

section .text
	global _start
_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, text1
	mov edx, textlen
	int 80h

;input
	mov eax, 3
	mov ebx, 2
	mov ecx, num1
	mov edx, 5
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, text2
	mov edx, textlen2
	int 80h

;input
	mov eax, 3
	mov ebx, 2
	mov ecx, num2
	mov edx, 5
	int 80h

;addition
	mov eax, 4
	mov ebx, 1
	mov ecx, text3
	mov edx, textlen3
	int 80h

	mov eax, [num1]
	sub eax, '0' 
	mov ebx, [num2]
	sub ebx, '0'
	add eax, ebx
	add eax, '0'
	mov [ad], eax
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, ad
	mov edx, 5
	int 80h

;subraction
	mov eax, 4
	mov ebx, 1
	mov ecx, text4
	mov edx, textlen4
	int 80h

	mov eax, [num1]
	sub eax, '0' 
	mov ebx, [num2]
	sub ebx, '0'
	sub eax, ebx
	add eax, '0'
	mov [su], eax
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, su
	mov edx, 5
	int 80h

;multiplication
	mov eax, 4
	mov ebx, 1
	mov ecx, text5
	mov edx, textlen5
	int 80h

	mov eax, [num1]
	sub eax, '0' 
	mov ebx, [num2]
	sub ebx, '0'
	mul ebx
	add eax, '0'
	mov [mu], eax
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, mu
	mov edx, 5
	int 80h

;division
	mov al,[num1] 
	sub al,'0' 
	mov bl,[num2]
	sub bl,'0'
	div bl
	add al,'0'
	add ah,'0'
	mov [qu],al
	mov [re],ah

	mov eax,4 
	mov ebx,1
	mov ecx,text7
	mov edx,textlen7
	int 80h

	mov eax,4 
	mov ebx,1
	mov ecx,qu
	mov edx,5
	int 80h

	mov eax,4 
	mov ebx,1
	mov ecx,text8
	mov edx,textlen8
	int 80h

	mov eax,4 
	mov ebx,1
	mov ecx,re
	mov edx,5
	int 80h


	mov eax, 1
	mov ebx, 0
	int 80h


	
