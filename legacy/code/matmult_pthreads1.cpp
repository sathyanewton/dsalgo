/*	Dr.R's parallel computing work		*/

#include <iostream> 
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define N 32
#define B 4

using namespace std;

int matA[N][N],matB[N][N],matC[N][N],mat_bench[N][N],mat_seq_blocking[N][N],mat_parallel_blocking[N][N];
int thread_id=0,thread_id1=0;
int cpuvar=0;
int jj1=0,kk1=0;


pthread_t t[N];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;    // critical operations 
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;    // critical operations 



void fill_matrices()
{
//	cout<<"inside fill matrices\n";
//	cout<<"N value --> "<<N<<"\n";
	int i=0,j=0;
	struct timeval time; 
	gettimeofday(&time,NULL);
	srand ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{				
				matA[i][j]=(rand()%10);
				matB[i][j]=(rand()%10);
				//cout<<i<<"-->"<<j<<"\n";
		}
	}
	
}

void print_matrices()
{
	int i=0,j=0;
	cout<<"printing matrix A : \n";
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
				cout<<matA[i][j]<<" ";
		}
		cout<<"\n";
	}

	cout<<"\n\n\n\n";

	cout<<"printing matrix B : \n";
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
				cout<<matB[i][j]<<" ";
		}
		cout<<"\n";
	}
}

/*	Benchmark O(N^2), 2 for loops i and j traditional apporach*/


void benchmark()
{
	int i=0,j=0,k=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			for(k=0;k<N;k++)
			{

			mat_bench[i][j]=mat_bench[i][j]+(matA[i][k]*matB[k][j]);

			}

		}
	}


}


/*	first apprpach, spawn N threads, each thread multiplies one row and N columns */

void *N_thread(void *tp)
{
	int tid = 0;
	cpu_set_t cpuset1, cpuset2 ;
	CPU_ZERO(&cpuset1);
	CPU_ZERO(&cpuset2);

	pthread_mutex_lock(&mutex);
	tid = thread_id++;
//	cout<<tid<<"\n";
	CPU_SET((cpuvar)%N, &cpuset1);
	cpuvar++;
	pthread_mutex_unlock(&mutex);

	int i=0,j=0;
	register int temp_sum=0;


	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			temp_sum = temp_sum + matA[tid][j] * matB[j][i];
		}
		matC[tid][i]=temp_sum;
		temp_sum=0;
	}


}




void sequential_blocking()
{
	int jj=0,kk=0,i=0,k=0,j=0;
	int temp_sum=0;

	for(jj=0;jj<N;jj=jj+B)
	{
		for(kk=0;kk<N;kk=kk+B)
		{
			for(i=0;i<N;i++)
			{
				for(j=jj;j<min(jj+B,N);j++)
				{
					temp_sum=0;
					for(k=kk;k<min(kk+B,N);k++)
					{
						temp_sum=temp_sum + matA[i][k]*matB[k][j];
					}
					mat_seq_blocking[i][j]=mat_seq_blocking[i][j] + temp_sum;
				}
			}
		}
	}


}
int global_i=0;
void *N_thread_blocked(void *tp)
{
	int tid = 0;
	int i=0,k=0,j=0;
	int temp_sum=0;
	int jj=0,kk=0;

	cpu_set_t cpuset1, cpuset2 ;
	CPU_ZERO(&cpuset1);
	CPU_ZERO(&cpuset2);

	pthread_mutex_lock(&mutex);
	tid = thread_id1++;
	cout<<"inside thread function  of --> "<<tid<<"\n";
	CPU_SET((cpuvar)%N, &cpuset1);
	cpuvar++;

	/*
	if(tid==0)
	{
		jj=0;
		kk=0;
	}
	else
	{
		jj1=(jj1+((tid)*B));
		jj=jj1;
		kk1=(kk1+((tid)*B));
		kk=kk1;
	}
	
	jj1=(jj1+((tid)*B));
		jj=jj1;
		cout<<"jj value --> "<<jj<<"\n";
		kk1=(kk1+((tid)*B));
		kk=kk1;
		cout<<"kk value --> "<<kk<<"\n";

	*/
		jj1=((tid)*B);
		jj=jj1;
		cout<<"jj value --> "<<jj<<"\n";
		kk1=((tid)*B);
		kk=kk1;
		cout<<"kk value --> "<<kk<<"\n";
		global_i=(tid*B);
		i=global_i;
		cout<<"i value --> "<<kk<<"\n";
	pthread_mutex_unlock(&mutex);

		
	for(i=0;i<N;i++)
	{
		for(j=jj;j<min(jj+B,N);j++)
		{
			temp_sum=0;
				for(k=kk;k<min(kk+B,N);k++)
				{
					temp_sum=temp_sum + matA[i][k]*matB[k][j];
				}
				pthread_mutex_lock(&mutex1);
				mat_parallel_blocking[i][j]=mat_parallel_blocking[i][j] + temp_sum;
				pthread_mutex_unlock(&mutex1);
		}
	}
}


int main()
{

int i,j;

fill_matrices();

cout<<"returned from fill matrices\n\n";

print_matrices();

cout<<"returned from print matrices\n\n";

for(i=0;i<N;i++)
{
   pthread_create(&t[i], NULL,N_thread,(void*)&i);
}


for(j=0; j<N; j++)
{
      pthread_join(t[j], NULL);
}

cout<<"printing matrix parallel output : \n";
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
				cout<<matC[i][j]<<" ";
		}
		cout<<"\n";
	}


benchmark();

cout<<"returned from benchmark\n\n";

cout<<"printing matrix serial output : \n";
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
				cout<<mat_bench[i][j]<<" ";
		}
		cout<<"\n";
	}

	sequential_blocking();
cout<<"returned from sequential_blocking\n\n";

cout<<"printing matrix sequential_blocking result : \n";

for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
				cout<<mat_seq_blocking[i][j]<<" ";
		}
		cout<<"\n";
	}

for(i=0;i<N/B;i++)
{
   pthread_create(&t[i], NULL,N_thread_blocked,(void*)&i);
}


for(j=0; j<N/B; j++)
{
      pthread_join(t[j], NULL);
}

cout<<"returned from parallel_blocking\n\n";

cout<<"printing matrix parallel_blocking result : \n";

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
				cout<<mat_parallel_blocking[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}
