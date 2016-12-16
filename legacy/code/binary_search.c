#include<stdio.h> 
#include<stdlib.h> 


int binary(int *a,int first, int last,int element)
{

	int mid=0;

	while(first<=last)
	{
		mid = (first+last)/2;

		printf(" %d ",mid);
		printf(" -> %d ",a[mid]);

		if(a[mid]==element)
		{
			printf("\n");
			return mid;
		}
		else if(a[mid]>element)
		{
			last = mid-1;
		}
		else if(a[mid]<element)
		{
			first = mid+1;
		}


	}
}


int main()
{
	int a[10]	=	{2,4,5,7,9,12,16,21,35,39};

	int start=0;
	int last=9;
	int result;
	int i=0;

	printf("\n");


	for(i=0;i<10;i++)
	{
		printf(" %d ",a[i]);
	}

	printf("\n");

	result=binary(a,0,9,2);

	printf(" the element is at --> %d",result);


	printf("\n");

	return 0;
}