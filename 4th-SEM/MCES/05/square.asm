	AREA square,CODE,READONLY
ENTRY
	LDR R0,=TABLE     ; starting address of TABLE is loaded to R0 register
	MOV R1,#3         ; square of the number required
	MOV R1,R1,LSL #2  ; perform left shift by two bits to get the location address
	ADD R0,R0,R1      ; add the shift value to starting address of TABLE present in R0
	LDR R3,[R0]       ; get the square value present in the address pointed by R0 register
STOP B STOP	          ; R3 - contains result
TABLE DCD 0X0             ; lookup table having square of 10 number in hexadecimal format
	DCD 0X1
	DCD 0X4
	DCD 0X9
	DCD 0X10
	DCD 0X19
	DCD 0X24
	DCD 0X31
	DCD 0X40
	DCD 0X51
	DCD 0X64
	END
