<<<<<<< HEAD
;interfejs:
;ds:x1 ds:y1 	- punkt pocz¹tku linii
;ds:x2 ds:y2 	- punkt koñca linii
;ds:e 			-zmienna pomocnicza, nie deklarowana
;ds:kx			-zmienna pomocnicza, nie deklarowana
;ds:ky			-zmienna pomocnicza, nie deklarowana
;ds:ddy			-zmienna pomocnicza, nie deklarowana
;ds:ddx			-zmienna pomocnicza, nie deklarowana
;ds:kolor 		- kolor malowania linii
;przyk³adowe wywo³anie funkcji:
;	mov [ds:x1],40+300
;	mov [ds:y1],345
;	mov [ds:x2],10+300
;	mov [ds:y2],10
;	call Bresenham

bresenham:
push ax
push bx
push cx
push dx
;krok01
;if x1<=x2 then kx=1 else kx=-1

	mov ax,0xffff
	;dec ax	;ax=-1
	mov dx,[ds:x1]
	mov bx,[ds:x2]
	cmp dx,bx
	ja wiekszyX2 ;to nie poprawiaj, czyli omiñ
;	pisz 'g'
;key
	;inc ax
	;inc ax
	mov ax,1
wiekszyX2:
	;mov byte [ds:kx],al
	mov[ds:kx],ax 
;		pisz '9'
;krok02
;jak w pkt1 ale z ky
;		fobx 8,8,8,8
;		fobx 'k','0','2',':'
;		key
	mov ax,0xffff
	;dec ax	;ax=-1
	;mov ax,-1
	mov dx,[ds:y1]
	mov bx,[ds:y2]
	cmp dx,bx
	ja wiekszyY2 ;to nie poprawiaj, czyli omiñ
	;inc ax
	;inc ax
	mov ax,1
wiekszyY2:
	;mov byte [ds:ky],al
 	 mov [ds:ky],ax

;krok03
;modul odleg³oœci x 
;		fobx 8,8,8,8
;		fobx 'k','0','3',':'
;		key
	mov ax,[ds:x2]
	mov dx,[ds:x1]
	cmp ax,dx
	jae ax_wieksze
	xchg ax,dx
ax_wieksze:
	sub ax,dx
	;btr ax,15	;modu³
	mov [ds:ddx],ax

;krok04
;modu³ odleg³oœci y
;		fobx 8,8,8,8
;		fobx 'k','0','4',':'
;		key
	mov ax,[ds:y2]
	mov dx,[ds:y1]
	cmp ax,dx
	jae ax_wiekszey
	xchg ax,dx
ax_wiekszey:
	sub ax,dx
	;btr ax,15	;modu³
	mov [ds:ddy],ax
;krok05
;zapalamy pierwszy bit
;		fobx 8,8,8,8
;		fobx 'k','0','5',':'
;		key
	Zapal_pixelx1y1
;krok06	
;wybieramy wersje algorytmu do odpalenia

;		fobx 8,8,8,8
;		fobx 'k','0','6',':'
;		key
	mov dx,[ds:ddx]
	mov bx,[ds:ddy]
	cmp dx,bx
	jb k16
;krok07
;wartosc poczatkowa bledu to e=ddx/2
;		fobx 8,8,8,8
;		fobx 'k','0','7',':'
;		key
	push [ds:ddx]
	pop [ds:e]
	shr [ds:e],2
	;mov ax,[ds:ddx]
	;mov dx,2
	;div dx
	;mov byte [ds:e],al
;krok 08
;		fobx 8,8,8,8
;		fobx 'k','0','8',':'
;		key
	mov cx,[ds:ddx]
petla09_14:
	push cx
;krok09
;		fobx 8,8,8,8
;		fobx 'k','0','9',':'
;		key
	mov ax,[ds:x1]
	add ax,[ds:kx];ssssssssssssssssssss
	;	inc [ds:x1]
	mov [ds:x1],ax
;krok10
		;fobx 8,8,8,8
		;fobx 'k','1','0',':'
;		key
	mov ax,[ds:e]
	sub ax,[ds:ddy]
	mov [ds:e],ax
;krok11
		;fobx 8,8,8,8
		;fobx 'k','1','1',':'

	mov dx,[ds:e]
	xor bx,bx ; mov bx,00h
	cmp dx,bx
	;cmp [ds:e],0
	jge k14
;krok12
;		fobx 8,8,8,8
;		fobx 'k','1','2',':'

	mov ax,[ds:y1]
	add ax,[ds:ky];ssssssssssssssssssssssssssss
	mov [ds:y1],ax
	;inc [ds:y1]
;krok13
;		fobx 8,8,8,8
;		fobx 'k','1','3',':'
;		key
	mov ax,[ds:e]
	add ax,[ds:ddx]
	mov [ds:e],ax
;krok14
;		fobx 8,8,8,8
;		fobx 'k','1','4',':'
;		key
 k14:
;	Zapal_pixelx1y1
		mov ah,0ch
		mov al,[ds:kolor]
		mov bh,00h
		mov cx,[ds:x1]
		mov dx,[ds:y1]
		int 10h


	;;;;;;loop near petla09_14
pop cx
dec cx
jnz petla09_14



;krok15
		;fobx 8,8,8,8
		;fobx 'k','1','5',':'
;		key
	jmp koniec_makra

;********
;krok16
k16:
		;fobx 8,8,8,8
		;fobx 'k','1','6',':'
;		key
	push [ds:ddy]
	pop [ds:e]
	shr [ds:e],2

	;shr [ds:ddy],2
	;mov ax,[ds:ddy]
	;mov dx,2
	;div dx
	
	;mov [ds:e],ax
;krok 17
	mov cx,[ds:ddy]
petla17_23:
push cx
;krok18-9
;key
	mov ax,[ds:y1]
	add ax,[ds:ky]
	mov [ds:y1],ax
;krok19-10
;key
	mov ax,[ds:e]
	sub ax,[ds:ddx]
	mov [ds:e],ax
;krok20-11
;key
	mov dx,[ds:e]
	xor bx,bx ;mov bx,00h
	cmp dx,bx
	;cmp [ds:e],0
	jge k23
;krok21-12
;key
	mov ax,[ds:x1]
	add ax,[ds:kx]
	mov [ds:x1],ax
;krok22-13
;key
	mov ax,[ds:e]
	add ax,[ds:ddy]
	mov [ds:e],ax
;krok23
;key
 k23:
	;Zapal_pixelx1y1
		mov ah,0ch
		mov al,[ds:kolor]
		mov bh,00h
		mov cx,[ds:x1]
		mov dx,[ds:y1]
		int 10h

	pop cx
	dec cx
	jnz petla17_23
;krok24
	;jmp koniec_makra
koniec_makra:
	pop dx
	pop cx
	pop bx
	pop ax

ret
=======
;interfejs:
;ds:x1 ds:y1 	- punkt pocz¹tku linii
;ds:x2 ds:y2 	- punkt koñca linii
;ds:e 			-zmienna pomocnicza, nie deklarowana
;ds:kx			-zmienna pomocnicza, nie deklarowana
;ds:ky			-zmienna pomocnicza, nie deklarowana
;ds:ddy			-zmienna pomocnicza, nie deklarowana
;ds:ddx			-zmienna pomocnicza, nie deklarowana
;ds:kolor 		- kolor malowania linii
;przyk³adowe wywo³anie funkcji:
;	mov [ds:x1],40+300
;	mov [ds:y1],345
;	mov [ds:x2],10+300
;	mov [ds:y2],10
;	call Bresenham

bresenham:
push ax
push bx
push cx
push dx
;krok01
;if x1<=x2 then kx=1 else kx=-1

	mov ax,0xffff
	;dec ax	;ax=-1
	mov dx,[ds:x1]
	mov bx,[ds:x2]
	cmp dx,bx
	ja wiekszyX2 ;to nie poprawiaj, czyli omiñ
;	pisz 'g'
;key
	;inc ax
	;inc ax
	mov ax,1
wiekszyX2:
	;mov byte [ds:kx],al
	mov[ds:kx],ax 
;		pisz '9'
;krok02
;jak w pkt1 ale z ky
;		fobx 8,8,8,8
;		fobx 'k','0','2',':'
;		key
	mov ax,0xffff
	;dec ax	;ax=-1
	;mov ax,-1
	mov dx,[ds:y1]
	mov bx,[ds:y2]
	cmp dx,bx
	ja wiekszyY2 ;to nie poprawiaj, czyli omiñ
	;inc ax
	;inc ax
	mov ax,1
wiekszyY2:
	;mov byte [ds:ky],al
 	 mov [ds:ky],ax

;krok03
;modul odleg³oœci x 
;		fobx 8,8,8,8
;		fobx 'k','0','3',':'
;		key
	mov ax,[ds:x2]
	mov dx,[ds:x1]
	cmp ax,dx
	jae ax_wieksze
	xchg ax,dx
ax_wieksze:
	sub ax,dx
	;btr ax,15	;modu³
	mov [ds:ddx],ax

;krok04
;modu³ odleg³oœci y
;		fobx 8,8,8,8
;		fobx 'k','0','4',':'
;		key
	mov ax,[ds:y2]
	mov dx,[ds:y1]
	cmp ax,dx
	jae ax_wiekszey
	xchg ax,dx
ax_wiekszey:
	sub ax,dx
	;btr ax,15	;modu³
	mov [ds:ddy],ax
;krok05
;zapalamy pierwszy bit
;		fobx 8,8,8,8
;		fobx 'k','0','5',':'
;		key
	Zapal_pixelx1y1
;krok06	
;wybieramy wersje algorytmu do odpalenia

;		fobx 8,8,8,8
;		fobx 'k','0','6',':'
;		key
	mov dx,[ds:ddx]
	mov bx,[ds:ddy]
	cmp dx,bx
	jb k16
;krok07
;wartosc poczatkowa bledu to e=ddx/2
;		fobx 8,8,8,8
;		fobx 'k','0','7',':'
;		key
	push [ds:ddx]
	pop [ds:e]
	shr [ds:e],2
	;mov ax,[ds:ddx]
	;mov dx,2
	;div dx
	;mov byte [ds:e],al
;krok 08
;		fobx 8,8,8,8
;		fobx 'k','0','8',':'
;		key
	mov cx,[ds:ddx]
petla09_14:
	push cx
;krok09
;		fobx 8,8,8,8
;		fobx 'k','0','9',':'
;		key
	mov ax,[ds:x1]
	add ax,[ds:kx];ssssssssssssssssssss
	;	inc [ds:x1]
	mov [ds:x1],ax
;krok10
		;fobx 8,8,8,8
		;fobx 'k','1','0',':'
;		key
	mov ax,[ds:e]
	sub ax,[ds:ddy]
	mov [ds:e],ax
;krok11
		;fobx 8,8,8,8
		;fobx 'k','1','1',':'

	mov dx,[ds:e]
	xor bx,bx ; mov bx,00h
	cmp dx,bx
	;cmp [ds:e],0
	jge k14
;krok12
;		fobx 8,8,8,8
;		fobx 'k','1','2',':'

	mov ax,[ds:y1]
	add ax,[ds:ky];ssssssssssssssssssssssssssss
	mov [ds:y1],ax
	;inc [ds:y1]
;krok13
;		fobx 8,8,8,8
;		fobx 'k','1','3',':'
;		key
	mov ax,[ds:e]
	add ax,[ds:ddx]
	mov [ds:e],ax
;krok14
;		fobx 8,8,8,8
;		fobx 'k','1','4',':'
;		key
 k14:
;	Zapal_pixelx1y1
		mov ah,0ch
		mov al,[ds:kolor]
		mov bh,00h
		mov cx,[ds:x1]
		mov dx,[ds:y1]
		int 10h


	;;;;;;loop near petla09_14
pop cx
dec cx
jnz petla09_14



;krok15
		;fobx 8,8,8,8
		;fobx 'k','1','5',':'
;		key
	jmp koniec_makra

;********
;krok16
k16:
		;fobx 8,8,8,8
		;fobx 'k','1','6',':'
;		key
	push [ds:ddy]
	pop [ds:e]
	shr [ds:e],2

	;shr [ds:ddy],2
	;mov ax,[ds:ddy]
	;mov dx,2
	;div dx
	
	;mov [ds:e],ax
;krok 17
	mov cx,[ds:ddy]
petla17_23:
push cx
;krok18-9
;key
	mov ax,[ds:y1]
	add ax,[ds:ky]
	mov [ds:y1],ax
;krok19-10
;key
	mov ax,[ds:e]
	sub ax,[ds:ddx]
	mov [ds:e],ax
;krok20-11
;key
	mov dx,[ds:e]
	xor bx,bx ;mov bx,00h
	cmp dx,bx
	;cmp [ds:e],0
	jge k23
;krok21-12
;key
	mov ax,[ds:x1]
	add ax,[ds:kx]
	mov [ds:x1],ax
;krok22-13
;key
	mov ax,[ds:e]
	add ax,[ds:ddy]
	mov [ds:e],ax
;krok23
;key
 k23:
	;Zapal_pixelx1y1
		mov ah,0ch
		mov al,[ds:kolor]
		mov bh,00h
		mov cx,[ds:x1]
		mov dx,[ds:y1]
		int 10h

	pop cx
	dec cx
	jnz petla17_23
;krok24
	;jmp koniec_makra
koniec_makra:
	pop dx
	pop cx
	pop bx
	pop ax

ret
>>>>>>> origin/master
