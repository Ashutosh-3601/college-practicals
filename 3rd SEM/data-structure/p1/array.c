#include<stdio.h> 
#include<stdlib.h> 
#define MAX 10 
int n,pos=0,i; 

void create_an_array(int a[]) 
{ 
printf("Enter the size of the array: \n"); 
scanf("%d",&n); 
printf("Enter %d elements \n",n); 
for(i=0;i<n;i++) 
{ 
scanf("%d",&a[i]); 
} 
printf("\n Array Created \n"); 
} 

//Display the array elements with suitable headings 

void display(int a[]) 
{ 
if(!n) printf("Oops! You forgot to create an array\nPress 1 to continue with array creation.\n");
else
{
printf("Position\t Value\n"); 
for(i=0;i<n;i++) 
{ 
printf("\narray[%d] \t %d\n", i,a[i]); 
} 
}
} 

// Insert an element at agiven position//// 
void insert(int a[]) 
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
for(i=n-1;i>=pos;i--) 
a[i+1]=a[i]; 
a[pos]=element; 
n=n+1; 
printf("Element is inserted!\n");
}
}
}

// deletion at a given position//// 

void deletion(int a[]) 
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
val=a[pos]; 
for(i=pos;i<n ;i++) 
{ 
a[i]=a[i+1]; 
} 
n=n-1; 
printf("Element %d is deleted from postion:%d \n",val, pos); 
} 
}
} 




/// Main program

int main() 
{ 
int choice;
int array[MAX];
printf("1.Create an Array\n2.Display\n3.Insert at position\n4.Delete at given position\n5.Exit\n");
do
{ 
printf("Enter Your Choice:\n"); 
scanf("%d",&choice); 
switch(choice) 
{ 
case 1: create_an_array(array);break; 
case 2: display(array);break; 
case 3: insert(array); break; 
case 4: deletion(array); break; 
case 5:exit(0); 
default: printf("\n\n\n\tEnter proper Choice...."); 
} 
} while(1);
return 0;
}
