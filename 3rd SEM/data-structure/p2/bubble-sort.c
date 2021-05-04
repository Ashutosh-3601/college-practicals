#include <stdio.h>
#define SIZE 10
void bubbleSort( int * const array, const int size ); /* prototype */
int choice; /* for storing ascending & descending */

/// Prints the output
void display(int const * array){
  if(choice == 1)
  printf( "\nData items in ascending order\n" );
  else printf( "\nData items in descending order\n" );
 
/* loop through array a */
for ( int i = 0; i < SIZE; i++ )
 {
printf( "%4d", array[ i ] );
} /* end for */
}

int main( void )
{
/* initialize array a */
int a[ SIZE ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
int i; /* counter */

printf("Select way of sorting\n1.Ascending\n2.Descending\nDefault descending.\n");
scanf("%d", &choice);

printf( "Data items in original order\n" );
/* loop through array a */
 for ( i = 0; i < SIZE; i++ ) {
 printf( "%4d", a[ i ] );
} /* end for */

bubbleSort(a, SIZE ); /* sort the array */
display(a);

printf( "\n" );
return 0; /* indicates successful termination */
 } /* end main */
 
/* sort an array of integers using bubble sort algorithm */
void bubbleSort( int * const array, const int size )
{
void swap( int *element1Ptr, int *element2Ptr ); /* prototype */
int pass; /* pass counter */
int j; /* comparison counter */
 
 /* loop to control passes */
for ( pass = 0; pass < size - 1; pass++ ) {
 
/* loop to control comparisons during each pass */
 for ( j = 0; j < size-1; j++ ) {
 
 /* swap adjacent elements if they are out of order */
 
 if(choice == 1) {
 if ( array[ j ] > array[ j + 1 ] ) {
 swap( &array[ j ], &array[ j + 1 ] );
  }
  }
  else {
  if ( array[ j ] < array[ j + 1 ] ) {
 swap( &array[ j ], &array[ j + 1 ] );
  }  
  } /* end if */
 } /* end inner for */
} /* end outer for */
} /* end function bubbleSort */
 
 
 
/* swap values at memory locations to which element1Ptr and
element2Ptr point */
void swap( int* n1, int* n2 )
{
  int temp;
  temp = *n1;
  *n1 = *n2;
  *n2 = temp;
// none
} /* end function swap */
