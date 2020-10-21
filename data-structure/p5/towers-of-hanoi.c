#include<stdio.h> 
void towers(int, char, char, char); void main() 
{ 
int num; 
printf("enter the number of disks : "); 
scanf("%d", &num); 
printf("the sequence of moves involved in the ower of honai are : \n");
towers(num, 'A','C','B'); 
getch(); 
} 

void towers(int num, char frompeg, char topeg, char auxpeg) 
{ 
if(num == 1) 
{ 
printf("\n MOVE DISK 1 FROM PEG %c TO PEG %c", frompeg, topeg); 
return; 
} 
towers( num -1, frompeg, none ,topeg); 
printf("\n MOVE DISK %d FROM PEG %c TO PEG %c", num,frompeg, topeg);
towers( num -1, none ,none ,frompeg );
}
