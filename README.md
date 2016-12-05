# FASM-Bresenham-algorithm
Bresenham algorithm written in Flat Assembler as include file (.inc)

;interface:
;ds:x1 ds:y1 	- coordinates of line begin point
;ds:x2 ds:y2 	- coordinates of line edn point
;ds:e 			-helping variable, undeclared
;ds:kx			-helping variable, undeclared
;ds:ky			-helping variable, undeclared
;ds:ddy			-helping variable, undeclared
;ds:ddx			-helping variable, undeclared
;ds:kolor 	-drawing color

;example function execution:
;	mov [ds:x1],40+300
;	mov [ds:y1],345
;	mov [ds:x2],10+300
;	mov [ds:y2],10
;	call Bresenham

in .asm file type... include'bresenham.inc'
