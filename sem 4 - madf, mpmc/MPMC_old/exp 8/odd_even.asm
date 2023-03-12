section .data
	prompt db "Enter size of array",10
	plen equ $-prompt
	prompt2 db "Enter elements",10
	p2len equ $-prompt2
	dialogue db "The elements are "
	dlen equ $-dialogue
	space db ' '	
	ores db "Odd : "
	orl equ $-ores
	eres db "Even : "
	erl equ $-eres
	newline db 10
	
section .bss
	arr resb 10
	ocount resb 1
	ecount resb 1
	dis_buffer resb 3
	ip_buffer resb 4
	size resb 4	

%macro SYS_WRITE 2
	mov eax,4
	mov ebx,1
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro

%macro SYS_READ 2
	mov eax,3
	mov ebx,2
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro

	
section .text
global _start

_start:
	SYS_WRITE prompt,plen
	SYS_READ size,2
	SYS_WRITE prompt2,p2len
	
	sub [size],dword '0'
	and [size],dword 000fh
	mov eax,arr
	mov edx,[size]
	call input
	
	mov esi,arr
	mov edx,[size]
	call oecount

	SYS_WRITE eres,erl
	mov bl,[ecount]
	call print_bl

	SYS_WRITE newline,1
	
	SYS_WRITE ores,orl
	mov bl,[ocount]
	call print_bl
	
	mov eax,1
	mov ebx,0
	int 80h
;; ------------------- end of main ------------------

input:	
	;; eax should contain address of array
	;; edx should contain size of array
	;; scans bytes
	mov ecx,0
repeat_input:	
	cmp ecx,edx
	jge after_input

	mov ebx,eax
	add ebx,ecx
	mov esi,ebx
	pushad
	call scan_esi
	popad
	inc ecx
	jmp repeat_input
after_input:	
	ret
	
;; ---------------------------------------------------
	
oecount:
;; esi should contain address of array
;; edx should contain size of array
;; stores values in ocount and ecount variables
	mov [ocount],byte 0
	mov [ecount],byte 0
	mov ecx,0
repeat_oecount:	
	cmp ecx,edx
	jge after_oecount
	
	mov al,[esi+ecx]
	cbw
	mov bl,2
	div bl			;al=al/2 , ah=al%2
	cmp ah,0
	je even			;if (ah%2)==0
odd:
	inc byte[ocount]
	jmp after_oe
even:
	inc byte[ecount]
after_oe:
	inc ecx
	jmp repeat_oecount
after_oecount:
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
	
;; --------------------------------------------------
scan_esi:
	;; esi should contain address of value to be scanned	
	mov eax,3
	mov ebx,2
	mov ecx,ip_buffer
	mov edx,4
	int 80h

	mov al,0
	mov ecx,0
scan_esi_loop:	
	cmp ecx,dword 3
	jge after_scan_esi

	cmp byte [ip_buffer+ecx],10
	je after_scan_esi

	mov bl,10
	mul bl			;al=al*10
	mov bl,[ip_buffer+ecx]
	sub bl,'0'		;bl= digit
	add al,bl		;al=al+bl
	
	inc ecx
	jmp scan_esi_loop
after_scan_esi:	
	mov [esi],al
	
	ret
	
