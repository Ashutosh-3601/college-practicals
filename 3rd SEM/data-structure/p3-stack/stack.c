#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef struct {
  int value;
} STACK;

STACK stack[MAX_STACK_SIZE];
int top = -1;

void stackOverflow(){
  printf("\n[STACK ERROR]\t: Overflow\n");
}

void stackUnderflow(){
  printf("\n[STACK ERROR]\t: Underflow\n");
}

void push(int * value){
  if(top >= MAX_STACK_SIZE-1){
    stackOverflow();
  }

  else stack[++top].value = *value;

}

int pop() {
  if(top == -1){
    stackUnderflow();
    return 0x123456;
  }
  else return stack[top--].value;
}

void displayStack() {
  if(top == -1) stackUnderflow();
  else {
    printf("Stack[Index]\t\tValue\n\n");
    for(int i = 0; i <= top; i++){
      printf("Stack[%d]\t\t\t%d\n", top-i, stack[top-i].value);
    }
  }
}

int palindrome(){
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
}

int main() {
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
        push(&value);
        break;
        }
      case 2: {
        int poppedValue = pop();
        if(poppedValue != 0x123456)
        printf("\nPopped the value %d from stack\n", poppedValue);
        break;
      }
      case 3: {
        displayStack();
        break;
      }
      case 4: {
        int isPalin = palindrome();
        if(isPalin) printf("YES, it\'s a palindrome\n");
        else printf("NO, it\'s not a palindrome\n");
        break;
      }
      case 5: exit(0);
      default: printf("\n//Wrong Choice//\n");break;
    }
  }
  return 0;
}
