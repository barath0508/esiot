ORG 0000H

; Addition
MOV A, #25H
MOV R0, #12H
ADD A, R0
MOV R1, A

; Subtraction
MOV A, #25H
CLR C
SUBB A, R0
MOV R2, A

; Multiplication
MOV A, #06H
MOV B, #03H
MUL AB
MOV R3, A

; Division
MOV A, #10H
MOV B, #04H
DIV AB
MOV R4, A
MOV R5, B

; AND
MOV A, #0F0H
ANL A, #0AAH
MOV R6, A

; OR
MOV A, #0F0H
ORL A, #0AAH
MOV R7, A

; XOR
MOV A, #0F0H
XRL A, #0AAH
MOV 30H, A

; Increment and Decrement
MOV A, #09H
INC A
DEC A
MOV 31H, A

HERE:
SJMP HERE

END