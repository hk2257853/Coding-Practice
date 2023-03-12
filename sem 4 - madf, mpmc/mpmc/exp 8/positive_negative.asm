	section .data
	pres db "Positive : "
	prl equ $-pres
	nres db "Negative : "
	nrl equ $-nres
	arr db 10,-2,-54,55,23,-61,72,-15,122,-17
	newline db 10
	
	section .bss
	pcount resb 1
	ncount resb 1
	dis_buffer resb 3

%macro SYS_WRITE 2
	mov eax,4
	mov ebx,1
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro
	
	section .text
	global _start

_start:
	mov eax,arr
	mov edx,10
	call pncount

	SYS_WRITE pres,prl
	mov bl,[pcount]
	call print_bl

	SYS_WRITE newline,1
	
	SYS_WRITE nres,nrl
	mov bl,[ncount]
	call print_bl
	
	mov eax,1
	mov ebx,0
	int 80h
	;; ------------------- end of main ------------------

pncount:
	;; eax should contain address of array
	;; edx should contain size of array
	;; stores values in pcount and ncount variables
	mov [pcount],byte 0
	mov [ncount],byte 0
	mov ecx,0
repeat_pncount:	
	cmp ecx,edx
	jge after_pncount

	mov bl,[eax+ecx]

	cmp bl,0
	jl negative
	jg positive
	jmp after_np
negative:
	inc byte[ncount]
	jmp after_np
positive:
	inc byte[pcount]
after_np:
	inc ecx
	jmp repeat_pncount
after_pncount:
	ret

	
	;; ---------------------------------------------------------
print_bl:
	;; bl should contain value to be printed
	mov ecx,3
	mov esi,2
	mov al,bl
print_bl_loop:
	mov ah,0
	mov dl,10
	div dl
	add ah,'0'
	mov [dis_buffer+esi],ah
	dec esi
	loop print_bl_loop

	mov eax,4
	mov ebx,1
	mov ecx,dis_buffer
	mov edx,3
	int 80h
	
	ret
