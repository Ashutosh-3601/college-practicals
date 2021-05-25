	AREA sum,CODE,READONLY
ENTRY
	MOV R1,#10		; initialising 10 as counter valuevin register as we need to add 1st 10 integers
	MOV R2,#0		; initial value
REP ADD R2,R1,R2	        ; add initial value 0 with 10
	SUBS R1,R1,#1	        ; substract the count by 1 and check R1 is zero or not
	BNE REP			; if not 0 then go back and add next number 
	LDR R5,=RES		; load the address of RES variable to R5 register
	STR R2,[R5]		; store the result of adding 10 integers present in R2 to RES variable
	SWI &11			; logically end the program

	AREA DATA1,DATA,READWRITE  ; data area to declare RES variable
RES DCD 0			; RES is variable of type one WORD(32 bit)
	END		    	; physical END of the program
