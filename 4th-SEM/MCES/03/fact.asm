	AREA fact,CODE,READONLY
ENTRY
	MOV R0,#0X0005		        ; move the value Number=05 to R0 register
	MOV R3,R0			; move the same N value to R3
FACT SUBS R3,R3,#1		        ; subtract N-1
	MUL R0,R3,R0		        ; multiply R3 and R0
	CMP R3,#1			; compare R3 is 1 or not
	BNE FACT			; if R3 is not 1 then branch to the label FACT else execute the next instruction
	LDR R5,=RES			; load the address of RES variable to R5 register
	STR R0,[R5]			; store the result in RES memory location
	SWI &11				; logical end of program
	AREA DATA1,DATA,READWRITE
RES DCW 0				; RES is declared as half word with initial value 0
	END				; end of program
