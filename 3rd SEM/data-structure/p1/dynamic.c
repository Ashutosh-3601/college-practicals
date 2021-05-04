/* file - dynamic.c
 * @author - Ashutosh-3601

 ////////// NOTES TO ME ///////////
 * Pointer is created at main() and passed to each function by value. 
 * Memory freed at case 5.
 * 
 ///////// END //////////////
*/

#include<stdio.h> 
#include<stdlib.h> 
#define MAX 10 
int n,pos=0,i; 

//Creates dynamic allocation @param-pointer

void create_an_array(int *ptr) 
{ 
printf("Enter the size of the array: \n"); 
scanf("%d",&n); 
if(n > MAX) { 
  printf("Exceeded!\n");
  exit(0);
}
printf("Enter %d elements \n",n); 
for(i=0;i<n;i++) 
{
scanf("%d", ptr+i);
} 
printf("\n Dynamically Alloted. \n"); 
} 

//Display the array elements with suitable headings @param - pointer

void display(int *ptr) 
{ 
if(!n) printf("Oops! You forgot to create an array\nPress 1 to continue with array creation.\n");
else
{
printf("Position\t Value\n"); 
for(i=0;i<n;i++) 
{ 
printf("\nMemory[%d] \t %d\n", i, *(ptr+i)); 
} 
}
} 

// Insert an element at agiven position @param-pointer
void insert(int *ptr) 
{
  if(!n) printf("Oops! You forgot to create an array\nPress 1 to continue with array creation.\n");
else
{
int element, pos; 
printf(" Enter the Position and Element where the element to be inserted \n"); 
scanf("%d%d", &pos, &element); 
if( pos < 0 || pos > n-1) 
{ 
printf("Insertion is out of the boundary or filled\n"); 
}
else 
{
for(i=n;i>pos;i--) 
*(ptr + i) = *(ptr + (i-1)); 
*(ptr + pos) = element; 
n=n+1;
printf("Element is inserted!\n");
}
}
}

// deletion at a given position @param-pointer

void deletion(int *ptr) 
{
  if(!n) printf("Oops! You forgot to create an array\nPress 1 to continue with array creation.\n");
else
{
int pos,val; 
printf("Enter the position where element need to be deleted :"); 
scanf("%d", &pos); 
if( pos < 0 || pos > MAX-1) 
{ 
printf("Insertion is out of the boundary or filled\n"); 
} 
else 
{ 
val=*(ptr+pos); 
for(i=pos;i<n-1;i++)  
*(ptr+i) = *(ptr+i+1);
n=n-1; 
printf("Element %d is deleted from postion:%d \n",val, pos);
} 
}
} 




/// Main program

int main() 
{ 
int choice, *pointer = (int*)malloc(MAX*sizeof(int));

printf("1.Create an Array\n2.Display\n3.Insert at position\n4.Delete at given position\n5.Exit\n");
do
{ 
printf("Enter Your Choice:\n"); 
scanf("%d", &choice); 
switch(choice) 
{ 
case 1: create_an_array(pointer);break; 
case 2: display(pointer);break; 
case 3: insert(pointer); break; 
case 4: deletion(pointer); break; 
case 5: free(pointer);exit(0); 
default: printf("\n\n\n\tEnter proper Choice...."); 
} 
} while(1);
return 0;
}
