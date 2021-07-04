	AREA array,CODE,READONLY    ; AREA is an assembler directive directs assembler to create CODE area with the name array and its READONLY
ENTRY                               ; ENTRY is an assembler directive directs assembler beginning of Program
	LDR R0,=ARRAY               ; LDR instructions loads the 32 bit address into R0 register
	MOV R1,#10                  ; MOV instruction moves the immediate value 10 into R1 register(Counter)
	MOV R2,#0                   ; MOV instruction moves to immediate value 0(initial value of SUM) to R2 register where we store the Sum of an array of 16 bit number
REP LDRH R3,[R0]                    ; LDRH instruction loads the 1st 16-bit value of an ARRAY pointed by R0 to R3
	ADD R2,R2,R3                ; ADD instruction adds 1st element of an array with an initial value 0 in R2 and stores the result in R2
  ADD R0,R0,#2                      ; ADD instruction adds R0 the value 2 to increment to address so as to point next element of an ARRAY as the value is 16 bit
  SUBS R1,R1,#1                     ; SUBS decrement the counter value stored in R1 by 1 and updates the CPSR
	BNE REP                     ; BNE checks the bit value 'Z' in CPSR register to verify the R1 is zero or non-zero after subtracting, if it is non-zero then branch to REP label
	LDR R5,=SUM                 ; LDR loads the address of SUM variable into register R5
	STR R2,[R5]                 ; STR stores the content of R2(SUM) to SUM variable address pointed by R5
	SWI &11                     ; logical end of the program
ARRAY DCW 0X0001                    ; ARRAY variable of type 16 bit(DCW) declared with 10 values
	DCW 0X0001
	DCW 0X0002
	DCW 0X0003
	DCW 0X0004
	DCW 0X0005
	DCW 0X0006
	DCW 0X0007
	DCW 0X0008
	DCW 0Xffff
	AREA DATA1,DATA,READWRITE   ; AREA is an assembler directive directs assembler to create CODE area with the name DATA1 and its both READWRITE
SUM DCD 0                           ; SUM variable declared of type 32 bit (DCD) with initial value 0
	END
