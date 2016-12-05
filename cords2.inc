;srodkowy kwadrat
mov[ds:kolor],00000001b
mov [ds:x1],110
mov [ds:y1],90
mov [ds:x2],120
mov [ds:y2],100
call bresenham
mov [ds:x1],120
mov [ds:y1],100
mov [ds:x2],110
mov [ds:y2],110
call bresenham
mov [ds:x1],110
mov [ds:y1],110
mov [ds:x2],100
mov [ds:y2],100
call bresenham
mov [ds:x1],100
mov [ds:y1],100
mov [ds:x2],110
mov [ds:y2],90
call bresenham
;key
mov bx,0000000100001001b
call fill					;kwadracik


;north-left
mov[ds:kolor],00000010b
mov [ds:x1],95
mov [ds:y1],85
mov [ds:x2],110
mov [ds:y2],90
call bresenham
mov [ds:x1],110
mov [ds:y1],90
mov [ds:x2],100
mov [ds:y2],100
call bresenham
mov [ds:x1],100
mov [ds:y1],100
mov [ds:x2],95
mov [ds:y2],85
call bresenham
mov bx,0000001000001010b
call fill					;north


;key
;east-north
mov[ds:kolor],00000011b
mov [ds:x1],110
mov [ds:y1],90
mov [ds:x2],125
mov [ds:y2],85
call bresenham
;key
mov [ds:x1],125
mov [ds:y1],85
mov [ds:x2],120
mov [ds:y2],100
call bresenham
;key
mov [ds:x1],120
mov [ds:y1],100
mov [ds:x2],110
mov [ds:y2],90
call bresenham
;key
mov bx,0000001100001011b
call fill					;east



;south-east
mov[ds:kolor],00000100b
mov [ds:x1],120
mov [ds:y1],100
mov [ds:x2],125
mov [ds:y2],115
call bresenham
mov [ds:x1],125
mov [ds:y1],115
mov [ds:x2],110
mov [ds:y2],110
call bresenham
mov [ds:x1],110
mov [ds:y1],110
mov [ds:x2],120
mov [ds:y2],100
call bresenham
;key
mov bx,0000010000001100b
call fill					;south


;west-south
mov[ds:kolor],00000101b
mov [ds:x1],110
mov [ds:y1],110
mov [ds:x2],95
mov [ds:y2],115
call bresenham
mov [ds:x1],95
mov [ds:y1],115
mov [ds:x2],100
mov [ds:y2],100
call bresenham
mov [ds:x1],100
mov [ds:y1],100
mov [ds:x2],110
mov [ds:y2],110
call bresenham
mov bx,0000010100001101b
call fill					;west


key

;mov bx,0000000100001001b
;call fill					;kwadracik
;mov bx,0000001000001010b
;call fill					;north
;mov bx,0000001100001011b
;call fill					;east
;mov bx,0000010000001100b
;call fill					;south
;mov bx,0000010100001101b
;call fill					;west

