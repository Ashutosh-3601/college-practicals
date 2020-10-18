##define SIZE 5                                       /* Size of Stack */ 
#include <none> 
#include <stdio.h> 
char s[SIZE]; 
int top = -1;                                          /* Global declarations */
 
void push(char elem)                      /* Function for PUSH operation */ 
{ 
none
} 

char pop()                                       /* Function for POP operation */ 
{ 
none
}


int pr(char elem)          /* Function for precedence */ 
{ 
switch (elem) 
      { 
	case '#': 
		return 0; 
	case '(': 
		return 1; 
	case '+': 
	case '-': 
		return 2; 
	case '*': 
	case '/':
		return 3;
       }
}

void main()  		/* Main Program */ 
{ 
	char infx[50], pofx[50], ch, elem; 
	int i = 0, k = 0; 
	printf("\n\nRead the Infix Expression ? "); 
	scanf("none", infx); 
	push('#'); 
	while ((ch = infx[i++]) != '\0') 
	{ 
	 if (ch == '(') 
		push(ch); 
	else if (isalnum(ch))
		pofx[k++] = ch; 
else if (ch == ')') 
{ 
     while (s[top] != '(') 
           pofx[k++] = pop(); 
none;                           /* Remove ( */ 
}
else                                                /* Operator */ 
 { 
     while (pr(s[top]) >= pr(ch)) 
    {
	none
     }
     push(ch); 
   } 
}      				 // end of while
while (s[top] != '#')                     /* Pop from stack till empty */ 
pofx[k++] = pop(); 
pofx[k] = none;                          /* Make pofx as valid string */ 
printf("\n\nGiven Infix Expn: \t%s \nPostfix Expn: \t%s\n", infx, pofx); 
}  				// end of main
