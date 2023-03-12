section .data
	sys.exit equ 1
	sys.write equ 4
	stdin equ 0
	sys.out equ 1
	sys.read equ 3
	sys.in equ 2

	msg1 db 'Enter length of the rectangle:'
	msg1len equ $-msg1
	msg2 db 'Enter breadth of the rectangle:'
	msg2len equ $-msg2
	msg3 db 'Area of rectangle = '
	msg3len equ $-msg3	
	msg4 db 'Perimeter of rectangle = '
	msg4len equ $-msg4
	msg5 db 'Enter base of the triangle:'
	msg5len equ $-msg5
	msg6 db 'Enter height of the triangle:'
	msg6len equ $-msg6
	msg7 db 'Area of triangle = '
	msg7len equ $-msg7
	msg8 db 'Perimeter of triangle = '
	msg8len equ $-msg8
    	msg9 db 'Enter the length of side 1:'
	msg9len equ $-msg9
	msg10 db 'Enter the length of side 2:'
	msg10len equ $-msg10
	msg11 db 'Enter the length of side 3:'
	msg11len equ $-msg11
	newl db '	',10
	newllength equ $-newl

section .bss
	len resb 9
	breadth resb 9
	base resb 9
	height resb 9
	area resb 9
	perimeter resb 9	
    	s1 resb 9	
    	s2 resb 9	
    	s3 resb 9	

section .text
global _start

_start:
	;area n perimeter of rectangle
	mov eax,sys.write ;showing string input len
	mov ebx,sys.out
	mov ecx,msg1
	mov edx,msg1len
	int 80h
	
	mov eax,sys.read ;input len
	mov ebx,sys.in
	mov ecx,len
	mov edx,9
	int 80h
	
	mov eax,sys.write ;showing string input breadth
	mov ebx,sys.out
	mov ecx,msg2
	mov edx,msg2len
	int 80h
	
	mov eax,sys.read ;input breadth
	mov ebx,sys.in
	mov ecx,breadth
	mov edx,9
	int 80h
	
    	mov eax,sys.write ;show a new line
	mov ebx,sys.out
	mov ecx,newl
	mov edx,newllength
	int 80h

	;area of rectangle
	mov eax,sys.write ;show string area of rec
	mov ebx,sys.out
	mov ecx,msg3
	mov edx,msg3len
	int 80h

	mov al,[len] ;calculating area
	sub al,'0'
	mov bl,[breadth]
	sub bl,'0'
	mul bl
	add ax,'0'
	mov [area],ax

	mov eax,sys.write ;display area
	mov ebx,sys.out
	mov ecx,area
	mov edx,9
	int 80h

	mov eax,sys.write ;show newline
	mov ebx,sys.out
	mov ecx,newl
	mov edx,newllength
	int 80h
	
	; PERIMETER
	mov eax,sys.write ;show perimeter of rec
	mov ebx,sys.out
	mov ecx,msg4
	mov edx,msg4len
	int 80h

	mov al,[len] ;calculate perimeter of rec
	sub al,'0'
	mov bl,[breadth]
	sub bl,'0'
	add al,bl
	mov bl,'2' ;2lb
    	sub bl,'0'
	mul bl
	add ax,'0'
	mov [perimeter],ax	

	mov eax,sys.write ;show perimeter
	mov ebx,sys.out
	mov ecx,perimeter
	mov edx,9
	int 80h

	mov eax,sys.write ;show newline
	mov ebx,sys.out
	mov ecx,newl
	mov edx,newllength
	int 80h
	
    	mov eax,sys.write ;show another newline to go to triangle section
	mov ebx,sys.out
	mov ecx,newl
	mov edx,newllength
	int 80h

	;ar and peri of tri
	mov eax,sys.write ;show input base
	mov ebx,sys.out
	mov ecx,msg5
	mov edx,msg5len
	int 80h
	
	mov eax,sys.read ;input base 
	mov ebx,sys.in
	mov ecx,base
	mov edx,9
	int 80h
	
	mov eax,sys.write ;show input height
	mov ebx,sys.out
	mov ecx,msg6
	mov edx,msg6len
	int 80h
	
	mov eax,sys.read ;input height
	mov ebx,sys.in
	mov ecx,height
	mov edx,9
	int 80h
	
    	mov eax,sys.write ;show newline
	mov ebx,sys.out
	mov ecx,newl
	mov edx,newllength
	int 80h

	
	mov eax,sys.write ;show area of triangle is
	mov ebx,sys.out
	mov ecx,msg7
	mov edx,msg7len
	int 80h
	
	mov al,[base]		;calculate area of triangle,int form		
	sub al,'0'
	mov bl,[height]
	sub bl,'0'
	mul bl
    	add ax,'0'
    	mov [area],ax
    	mov al,[area]

   	mov bl,'2'
	sub al,'0'
	sub bl,'0'
	div bl
	add ax,'0'
	mov [area],ax		

	mov eax,sys.write ;output area
	mov ebx,sys.out
	mov ecx,area
	mov edx,9
	int 80h

	mov eax,sys.write ;show a newline
	mov ebx,sys.out
	mov ecx,newl
	mov edx,newllength
	int 80h
	
   	 mov eax,sys.write ;show another newline
	mov ebx,sys.out
	mov ecx,newl
	mov edx,newllength
	int 80h

	;PERIMETER
    	mov eax,sys.write ;input length of side1
	mov ebx,sys.out
	mov ecx,msg9
	mov edx,msg9len
	int 80h
	
	mov eax,sys.read
	mov ebx,sys.in
	mov ecx,s1
	mov edx,9
	int 80h

    	mov eax,sys.write
	mov ebx,sys.out
	mov ecx,msg10
	mov edx,msg10len
	int 80h
	
	mov eax,sys.read ;input length of side2
	mov ebx,sys.in
	mov ecx,s2
	mov edx,9
	int 80h

 	mov eax,sys.write
	mov ebx,sys.out
	mov ecx,msg11
	mov edx,msg11len
	int 80h
	
	mov eax,sys.read  ;input length of side3
	mov ebx,sys.in
	mov ecx,s3
	mov edx,9
	int 80h

    	mov eax,sys.write
	mov ebx,sys.out
	mov ecx,newl
	mov edx,newllength
	int 80h

	mov eax,sys.write
	mov ebx,sys.out
	mov ecx,msg8
	mov edx,msg8len
	int 80h

	mov al,[s1] ;calculate perimeter s1+s2+s3
	sub al,'0'
	mov bl,[s2]
	sub bl,'0'
	add al,bl
    	mov bl,[s3]
    	sub bl,'0'
    	add al,bl
	add ax,'0'
	mov [perimeter],ax	

	mov eax,sys.write ;output perimeter
	mov ebx,sys.out
	mov ecx,perimeter
	mov edx,9
	int 80h

	mov eax,sys.write
	mov ebx,sys.out
	mov ecx,newl
	mov edx,newllength
	int 80h

	mov eax,sys.exit
	mov ebx,stdin
	int 80h