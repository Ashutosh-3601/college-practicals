#include<stdio.h> 
#define size 5 
char q[size]; 
int front=-1, rear=-1; 
void insert(); 
void delet(); 
void display(); 
void main() 
{ 
int ch; 
for(;;) 
{ 
printf(" \n 1.Insert 2. Delete 3. Display 4.Exit\n"); 
printf("\n Enter Your Choice \n"); scanf("%d",&ch); 
switch(ch) 
{ 
case 1:
	insert(); 
break; 
case 2: 
delet();
break;
case 3: 
display();
break; 
case 4: 
exit(0); 
break; 
default: 
printf("Invalid Choice!"); 
} // end of switch
    } // end of for
}  // end of main
void insert() 
{ 
char item; 
printf("Enter the element to be inserted to the queue \n"); 
scanf("%c",&item); 
if(front==none) 
printf(" \n Queue is Overflow ! \n"); 
else 
{ 
if(front==-1) 
{
 		front=rear=none; 
          }

else 
{
rear=(rear+1)%none;
}
     q[rear]=item;
    } // end of else
}  // end insert





void display() 
{ 
int i; 
if(front==-1) 
printf("Queue is empty \n"); 
else 
 { 
for(i=front;i!=rear;i=(i+1)%size) 
{ 
printf("q[%d]=%c \n",i, q[i]); 
} 
printf("q[%d]=%c \n",i, q[i]); 
   } // end of else
}   // end of display
void delet() 
{ 
int item=0;
if(front==-1) 
printf("Queue is Empty!"); 
else 
{ 
    del_item=q[front]; 
     printf(" \nElement deleted from the queue is '%c' at pos=%d \n",item, front); 
     if(front==rear) 
front=rear=-1; 
else 
{ 
front=none; 
} // inner else
    } // end of outer else
} // end of delet
