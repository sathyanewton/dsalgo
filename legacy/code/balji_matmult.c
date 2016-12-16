#include <stdio.h>

#include <stdlib.h>
int main() {
	unsigned int a[100][100],b[100][100],c[100][100],i,j,k,sum=0,n=4;


	for(i=0;i<n;i++)
		for(j=0;j<n;j++) {
			a[i][j]=3;
			b[i][j]=4;
			c[i][j]=0;
		}
			
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			sum=0;
			for(k=0;k<n;k++)
				sum=sum+a[i][k]*b[k][j];
			c[i][j]=sum;
		}
	}

	printf("\n");printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++) {
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}


for(i=0;i<n;i++)
		for(j=0;j<n;j++) {
			c[i][j]=0;
		}
			
	for(i=0;i<2;i++) {
		for(j=0;j<4;j++) {
			sum=0;
			for(k=0;k<n;k++)
				sum=sum+a[i][k]*b[k][j];
			c[i][j]=sum;
		}
	}


	printf("\n");printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++) {
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}




	for(i=2;i<4;i++) {
		for(j=0;j<4;j++) {
			sum=0;
			for(k=0;k<n;k++)
				sum=sum+a[i][k]*b[k][j];
			c[i][j]=sum;
		}
	}

	printf("\n");printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++) {
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}


	return 0;
}
