#include<stdio.h>
#include <time.h>

void towers(int, char, char, char);
int main() 
{ 
int num; 
printf("enter the number of disks : "); 
scanf("%d", &num); 
printf("the sequence of moves involved in the ower of honai are : \n");

  /* clock structure variables*/
clock_t start, end;
double cpu_time_used;
/* Start the clock */
start = clock();

towers(num, 'A','C','B'); 

/* Stop the clock after returning from function*/
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("Calculating took %f seconds to execute \n", cpu_time_used);
} 

void towers(int num, char frompeg, char topeg, char auxpeg) 
{ 
if(num == 1) 
{ 
printf("\n MOVE DISK 1 FROM PEG %c TO PEG %c", frompeg, topeg); 
return; 
} 
towers( num -1, frompeg, auxpeg ,topeg); 
printf("\n MOVE DISK %d FROM PEG %c TO PEG %c", num,frompeg, topeg);
towers( num -1, auxpeg ,topeg ,frompeg );
}
