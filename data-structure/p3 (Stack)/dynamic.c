#include <stdio.h>
#include <stdlib.h>

int STACK_SIZE = 5, top = -1;

void stackOverflow(){
  printf("\n[STACK ERROR]\t: Overflow\n");
}

void stackUnderflow(){
  printf("\n[STACK ERROR]\t: Underflow\n");
}

void push(int * stackArray, int * value){
  if(top >= STACK_SIZE-1){
    stackArray = realloc(stackArray, sizeof(2*STACK_SIZE));
    STACK_SIZE *= 2;
  }
  else if(stackArray == NULL) stackOverflow();
  else *(stackArray + (++top)) = *value;

}

int pop(int * stackArray) {
  if(top == -1){
    stackUnderflow();
    return 0x123456;
  }
  else return *(stackArray + (top--));
}

void displayStack(int * stackArray) {
  if(top == -1) stackUnderflow();
  else {
    printf("Stack[Index]\t\tValue\n\n");
    for(int i = 0; i <= top; i++){
      printf("Stack[%d]\t\t\t%d\n", top-i, *(stackArray + (top-i)));
    }
  }
}

/*int palindrome(){
  if(top == -1) {
    stackUnderflow();
    return 0;
  }
  else {  
    int kk;
    STACK palin[MAX_STACK_SIZE];
    for(int i=0; i <= top; i++){
      palin[i].value = stack[top-i].value;
    }
    for(int i = 0; i <= top; i++){
      if(palin[i].value != stack[i].value)
      return 0;
    }
    return 1;
  }
}*/

int main() {
  int *stack = malloc(STACK_SIZE*sizeof(int));
  int choice;
  printf("\n\n1.\tInsert in stack\n2.\tDelete from stack\n3.\tDisplay stack\n4.\tCheck Palindrome\n5.\tExit\n\n");
  while(1){
    printf("\nEnter your choice\n");
    scanf("%d", &choice);
    switch(choice){
      case 1: {
        int value;
        printf("Enter the value to be inserted\n");
        scanf("%d", &value);
        push(stack, &value);
        break;
        }
      case 2: {
        int poppedValue = pop(stack);
        if(poppedValue != 0x123456)
        printf("\nPopped the value %d from stack\n", poppedValue);
        break;
      }
      case 3: {
        displayStack(stack);
        break;
      }
      /*case 4: {
        int isPalin = palindrome();
        if(isPalin) printf("YES, it\'s a palindrome\n");
        else printf("NO, it\'s not a palindrome\n");
        break;
      }*/
      case 5: free(stack); exit(0);
      default: printf("\n//Wrong Choice//\n");break;
    }
  }
  return 0;
}
