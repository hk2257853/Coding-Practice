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
	sub byte[n],'0'

	mov eax,'0'
	mov [j],eax

	call input
	call selection_sort
	write_message prompt3,p3len
	call display

	mov eax,1
	mov ebx,0
	int 80h

input:
	write_message prompt2,p2len
	mov [i],dword 0
loop1:
	mov esi,[i]
	cmp esi,[n]
	jge after1

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
	mov [i],dword 0
loop2:
	mov esi,[i]
	cmp esi,[n]
	jge after2

	add esi,arr
	write_message esi,1
	write_message space,1

	inc dword[i]
	jmp loop2	
after2:
	write_message newline,1	
	ret


selection_sort:
	mov eax,0 		;al is counter for outer loop, initialise to 0
	mov bl,[n]
	sub bl,1		;bl is n-1
loop3:
	cmp al,bl		;repeat until al<n-1
	jge after3

	pushad
	call display
	popad
	
	mov ecx,0		;clear ecx register
	mov cl,al		;ecx is counter for inner loop, initialise to al+1
	add cl,1

	mov edi,arr
	add edi,eax		;edi points to arr[eax]
loop4:
	cmp cl,[n]		;repeat until cl<n
	jge after4

	mov esi,arr
	add esi,ecx		;esi points to arr[ecx]
	
	mov bh,[esi]
	mov dh,[edi]
	cmp bh,dh
	jge after5		;if bh<dh

	mov edi,arr		;edi points to arr[ecx]
	add edi,ecx
after5:
	inc cl
	jmp loop4
after4:
	;; swap arr[eax] and [edi]
	mov bh,[arr+eax]
	mov dh,[edi]
	mov [arr+eax],dh
	mov [edi],bh

	inc al
	inc byte[j]
	jmp loop3
after3:
	ret
