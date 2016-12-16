#include<stdio.h> 
#include<stdlib.h> 


void swap (int *a,int *b)
{
    int temp;

    temp = *b;
    *b=*a;
    *a=temp;

}




int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);

    //int i = (l);
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            
            i++;
            swap (&arr[i], &arr[j]);


        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}
 
/* A[] --> Array to be sorted, 
  l  --> Starting index, 
  h  --> Ending index */
void quickSort(int A[], int l, int h)
{
    if (l < h)
    {        
        /* Partitioning index */
        int p = partition(A, l, h); 
        quickSort(A, l, p - 1);  
        quickSort(A, p + 1, h);
    }
}


int main()
{

    int a[7]={21,3,2,15,1,8,6};

     printf(" unsorted - > ");

    for(int i=0;i<7;i++)
    {
        printf(" %d - > ",a[i]);
    }


    quickSort(a,1,6);

     printf("\n");

    printf(" sorted - > ");

    for(int i=0;i<7;i++)
    {
        printf(" %d - > ",a[i]);
    }

    printf("\n");
    return 0;
}