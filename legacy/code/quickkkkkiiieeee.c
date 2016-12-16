#include <stdio.h>

void quickSort( int[], int, int);
int partition( int[], int, int);


void main() 
{
	// int a[] = { 7, 12, 1, -2, 0, 15, 4, 11, 9};


  int a[] = {21,3,2,15,1,8,6};
  

	int i;
	printf("\n\nUnsorted array is:  ");
	for(i = 0; i < 7; ++i)
		printf(" %d ", a[i]);

	quickSort( a, 0, 6);

	printf("\n\nSorted array is:  ");
	for(i = 0; i < 7; ++i)
		printf(" %d ", a[i]);

  printf("\n");

}



void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r ) 
   {
   	// divide and conquer
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
	
}



int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];

   printf(" pivot --> %d  ", pivot);
   i = l; j = r+1;
		
   while(1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;

   printf(" J value %d \n\n ", j);


   return j;
}