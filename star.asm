format MZ
entry seg_kod: poczatek
stack seg_stos: 256



macro key{
; wait for any key press:
mov ah, 0
int 16h
}
macro Zapal_pixelx1y1 {
	mov ah,0ch
	mov al,[ds:kolor]
	mov bh,00h
	mov cx,[ds:x1]
	mov dx,[ds:y1]
	int 10h
};koniec makra zapal_pixel



segment seg_stos use16
	   db 256 dup(?)
segment seg_dane use16
	x1 dw 100
	y1 dw 100
	x2 dw 60
	y2 dw 140
	e  dw 0000h
	kx dw 00h
	ky dw 00h
	ddx dw 00h
	ddy dw 00h
	kolor db 09h
	napis db '::',24h
	napis2 db 66,24H
buf: times 5 db 20h, '$'
	bseek db 0
	gseek	db 1
	rseek db 0
	maluj db 00h
	srodek dw 0000h
	zielony db 00000010b
	wierzcholki_x_y dw 10,10,233,10,203,345,40,345

;segment seg_kod use16

;****************************************************************


segment seg_kod use16
include 'bresenham.inc'
include 'fill.inc'

;****************************************************************
;****************************************************************

poczatek:
	mov ax,seg_stos
	mov ss,ax
	mov ax,seg_dane
	mov ds,ax

	mov ah,00h
	mov al,13h 

	int 10h
	mov ax,0A000h
	mov es,ax

;przerwanie wywo³uj¹ce napis
	mov ah,09h
	mov dx,napis
	int 21h


check_keyboard:
	mov ah,01h
	int 16h
	jnz nie_ma_co_czytac
		xor ah,ah
		int 16h

			mov [ds:napis2],al
			push ax
			mov ah,09h
			
			mov dx,napis2
			int 21h
			pop ax

	cmp ah,12h
	je koniec
	nie_ma_co_czytac:		

			jmp check_keyboard
koniec:
key
include 'cords1.inc'
include 'cords2.inc'


key
key



kk:
mov     ax,03h                  ; Set text mode 
        int     10h 
        mov     ax,04C00h 
        int     21h 
ret;koniec programu

