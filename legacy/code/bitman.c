#include<stdio.h> 
#include<stdlib.h> 

typedef unsigned int uint; 

void print_bin(unsigned int n)
{
	int i=32;
	while (i) {
	    if (n & 0x80000000)
	         printf("1");
	    else
	        printf("0");	

	    n <<= 1;
	    i--;
	}
	printf("\n");
}

uint generate_mask(int i, int j) // this function generates a mask. 
{							// uses of mask is to always do bitwise AND with the number
	unsigned int max = ~0;	
	unsigned int mask;
	if(i>j)
	{
		printf("invalid entries");
		return;

	}
	unsigned int left = (max-((1<<j)-1));
	unsigned int right = ((1<<i)-1);
	mask = left|right;
	return mask;
}

int count_number1(uint n)
{
	int count=0,temp;
	uint i;
	uint n1 = n;
	while(n1>0)
	{
		temp = (n>>i)&1;
		if(temp==1)
		{
			count++;
		}
		n1=n1>>1;
		i++;
	}
	return count;
}

int count_number2(uint n)
{
	int count;
	while(n>0)
	{
		n = n&(n-1);
		count++;
	}
	return count;
}

uint toggle_allbits(uint n)
{
	uint temp;
	int i;
	while(i<32)
	{	
		temp = (n>>i)&1;
		
		if(temp == 0)
		{
			n=(n | (1<<i));
		}
		else if(temp == 1)
		{
			n =(n & ~(1<<i));
		}
		i++;
	}
return n;
}


void check_for_power_of_2(uint n)
{
	int temp;
	temp = n & (n-1);
	if(temp == 0)
	{
		printf("power of two\n");
	}
	else
	{
		printf("dai jinglee\n");
	}
}

void convert_decimal_into_binary(float a)
{
	int i=31;
	while(i>=0)
	{
		a=(a*2);
		if(a>1)
		{
			printf("1");
			a=a-1;
		}
		else if(a<1)
		{
			printf("0");
		}
		
		i--;
	}
	printf("\n");
}

void print_decimal(float n)
{
	int t = (int) n ;
	int n1,t2,i=31;
	float t3;
	n1=t;
	//printf("%d",t);
	while(i>=0)
	{
		t2=((t>>i)&1);
		printf("%d",t2);
		i--;
	}
printf(".");
t3=n-t;
//printf("%f",t3);
convert_decimal_into_binary(t3);
}

void reverse(int n)
{
	int n1=n;
	int i;
	int c=0;
	int t;
	while(n1>0)
	{
		t=((n>>i)&1);
		printf("%d",t);
		c++;
		i++;
		n1=n1>>1;
	}
	c=32-c;
	for(i=c;i>0;i--)
	{
		printf("0");
	}
	printf("\n");
}



int main()
{
	unsigned int n,count;
	uint mask;
	printf("enter integer : ");
	scanf("%d",&n); 
	print_bin(n);
	reverse(n);
/*
	mask = generate_mask(3,8);
	print_bin(mask);
*/
/*
	count = count_number2(n);
	printf("%d\n",count);
*/
	//n = toggle_allbits(n);
	//print_bin(n);

	//check_for_power_of_2(n);
	//convert_decimal_into_binary(0.88);

//print_decimal(8.88);

	return 0;
}