;srodkowy kwadrat
mov[ds:kolor],00000001b
mov [ds:x1],100
mov [ds:y1],100
mov [ds:x2],130
mov [ds:y2],100
call bresenham
mov [ds:x1],130
mov [ds:y1],100
mov [ds:x2],130
mov [ds:y2],130
call bresenham
mov [ds:x1],130
mov [ds:y1],130
mov [ds:x2],100
mov [ds:y2],130
call bresenham
mov [ds:x1],100
mov [ds:y1],130
mov [ds:x2],100
mov [ds:y2],100
call bresenham
;key
;north
mov[ds:kolor],00000010b
mov [ds:x1],100
mov [ds:y1],100-1
mov [ds:x2],130
mov [ds:y2],100-1
call bresenham
mov [ds:x1],130
mov [ds:y1],100-1
mov [ds:x2],115
mov [ds:y2],55-1
call bresenham
mov [ds:x1],115
mov [ds:y1],55-1
mov [ds:x2],100
mov [ds:y2],100-1
call bresenham
;key
;east
mov[ds:kolor],00000011b
mov [ds:x1],130+1
mov [ds:y1],100
mov [ds:x2],175+1
mov [ds:y2],115
call bresenham
;key
mov [ds:x1],175+1
mov [ds:y1],115
mov [ds:x2],130+1
mov [ds:y2],130
call bresenham
;key
mov [ds:x1],130+1
mov [ds:y1],130
mov [ds:x2],130+1
mov [ds:y2],100
call bresenham
;key
;south
mov[ds:kolor],00000100b
mov [ds:x1],100
mov [ds:y1],130+1
mov [ds:x2],130
mov [ds:y2],130+1
call bresenham
mov [ds:x1],130
mov [ds:y1],130+1
mov [ds:x2],115
mov [ds:y2],175+1
call bresenham
mov [ds:x1],115
mov [ds:y1],175+1
mov [ds:x2],100
mov [ds:y2],130+1
call bresenham
;key
;west
mov[ds:kolor],00000101b
mov [ds:x1],100-1
mov [ds:y1],100
mov [ds:x2],100-1
mov [ds:y2],130
call bresenham
mov [ds:x1],100-1
mov [ds:y1],130
mov [ds:x2],55-1
mov [ds:y2],115
call bresenham
mov [ds:x1],55-1
mov [ds:y1],115
mov [ds:x2],100-1
mov [ds:y2],100
call bresenham
key

mov bx,0000000100001001b
call fill					;kwadracik
mov bx,0000001000001010b
call fill					;north
mov bx,0000001100001011b
call fill					;east
mov bx,0000010000001100b
call fill					;south
mov bx,0000010100001101b
call fill					;west

