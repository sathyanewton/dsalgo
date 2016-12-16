#include <stdio.h> 

int print_function(char *s)
{
	int i=0;
	printf("inside print function\n");
	while(s[i]!='\0')
	{
		printf("%c",s[i]);
		i++;
	}
	printf("\n");
	return 0;
}

int yet_another_function(int *(print_function)(char*))
{
	char c[7];

	c[0]='s';
	c[1]='a';
	c[2]='t';
	c[3]='h';
	c[4]='y';
	c[5]='a';
	//c[6]='s';


	print_function(c);
	return 0;
}

int main()
{

	yet_another_function(print_function);



	return 0;
}

