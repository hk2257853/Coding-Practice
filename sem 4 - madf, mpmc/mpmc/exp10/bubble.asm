section .data
	prompt db "Enter number of elements: "
	plen equ $-prompt
	prompt2 db "Enter the elements in the array:",10
	p2len equ $-prompt2
	prompt3 db "The sorted array is:",10
	p3len equ $-prompt3
	prompt4 db "Pass "
	p4len equ $-prompt4
	prompt5 db " => "
	p5len equ $-prompt5
	newline db 10
	space db ' '
	
section .bss
	n resb 4
	arr resb 10
	i resb 4
	j resb 9
	trash resb 1

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
	mov eax,3
	mov ebx,2
	mov ecx,trash
	mov edx,1
	int 80h
%endmacro
	
section .text
	global _start

_start:
	write_message prompt,plen
	read_message n,1
	
	call input
	write_message newline,1
	mov eax,'0'
	mov [j],eax
	call bubble_sort
	write_message prompt3,p3len
	call display

	mov eax,1
	mov ebx,0
	int 80h

input:
	write_message prompt2,p2len
	mov [i],dword '0'
loop1:
	mov esi,[i]
	cmp esi,[n]
	jge after1

	sub esi,'0'
	add esi,arr
	read_message esi,1

	inc dword[i]
	jmp loop1	
after1:
	ret


display:
	write_message prompt4,p4len
	write_message j,9
	write_message prompt5,p5len
	mov [i],dword '0'
loop2:
	mov esi,[i]
	cmp esi,[n]
	jge after2

	sub esi,'0'
	add esi,arr
	write_message esi,1
	write_message space,1

	inc dword[i]
	jmp loop2	
after2:
	write_message newline,1	
	ret


bubble_sort:
	mov al,0 		;al is counter for outer loop, initialise to 0
	mov bl,[n]
	sub bl,'0'
	sub bl,1		;bl is n-1
loop3:
	cmp al,bl		;repeat until al<n-1
	jge after3

	pushad
	call display
	popad
	
	mov ecx,0		;ecx is counter for inner loop, initialise to 0
	mov dl,bl
	sub dl,al		;dl is n-1-al
loop4:
	cmp cl,dl		;repeat until cl<n-1-al
	jge after4

	mov esi,arr
	add esi,ecx		;esi points to arr[ecx]

	mov ah,[esi]
	mov bh,[esi+1]
	cmp ah,bh
	jle after5		;if ah>bh

	mov [esi+1],ah		;swap esi and esi+1
	mov [esi],bh

after5:	
	inc cl
	jmp loop4
after4:
	inc al
	inc byte[j]
	jmp loop3
after3:
	ret
