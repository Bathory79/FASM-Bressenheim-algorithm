# FASM-Bresenham-algorithm <br />
Bresenham algorithm written in Flat Assembler as include file (.inc) <br />
<br />
;interface:<br />
;ds:x1 ds:y1 	- coordinates of line begin point<br />
;ds:x2 ds:y2 	- coordinates of line edn point<br />
;ds:e 			-helping variable, undeclared<br />
;ds:kx			-helping variable, undeclared<br />
;ds:ky			-helping variable, undeclared<br />
;ds:ddy			-helping variable, undeclared<br />
;ds:ddx			-helping variable, undeclared<br />
;ds:kolor 	-drawing color<br />
<br />
;example function execution:<br />
;	mov [ds:x1],40+300<br />
;	mov [ds:y1],345<br />
;	mov [ds:x2],10+300<br />
;	mov [ds:y2],10<br />
;	call Bresenham<br />
<br />
in .asm file type... include'bresenham.inc'<br />
<br />
