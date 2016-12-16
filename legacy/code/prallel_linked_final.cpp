#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h> 
#include <assert.h> 
#include <time.h>
#include <sys/time.h>

#define Initial_List_Size 10
#define NoOfThreads 16


using namespace std;

struct node { // std linked list node
    int data;
    struct node *next;
};

void appened_insert(struct node **current_node,int data)
{
	//*current_node is head
	struct node *new_node=NULL;
	static struct node *tail=NULL;

	if(*current_node==NULL)
	{
		printf("current node is the head of the linked list\n");
		new_node =  (struct node *)malloc(sizeof(struct node));
		assert(new_node!=NULL);

		new_node->data=data;
		new_node->next=NULL;
		*current_node=new_node;
		tail=new_node;
		return;
	}
	else
	{
		//	printf("not the first node in the list\n");
		new_node =  (struct node *)malloc(sizeof(struct node));
		new_node->data=data;
		new_node->next=NULL;
		assert(new_node!=NULL);

		tail->next=new_node;
		tail=new_node;

	}

}

void print_list_data(struct node **current_node)
{
struct node *a;
	a=*current_node;
	while(a->next!=NULL)
	{
		printf("%d\n",a->data);
		a=a->next;
	}
	printf("%d\n",a->data);
}

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;   
pthread_cond_t  cond = PTHREAD_COND_INITIALIZER;
pthread_t t[NoOfThreads]; 

struct thread_parameters
{
	struct node *root;
	int datum;	
};

void *thread_insert(void *tp)
{

	thread_parameters *tp1;
	tp1 = (thread_parameters*) tp;
//	cout<<tp1->root<<"\n";
//	cout<<tp1->datum<<"\n";
	int flag=0;
/*
	if(tp!=NULL)
	{
	free((thread_parameters*)tp);
	tp=NULL;
	}
*/
	struct node *temp_1,*temp_2;
	temp_1 = tp1->root;
	temp_2 = tp1->root;

//	cout<<"temp-->"<<temp_1<<"\n";

	struct node *new_node=NULL;
	new_node =  (struct node *)malloc(sizeof(struct node));
	new_node->data = tp1->datum;

	
	while(temp_1->next!=NULL && flag==0)
	{
		//cout<<"reached here\n";
		pthread_mutex_lock(&mutex);
		if(new_node->data<temp_1->data)
		{
			flag=1;
			temp_2->next = new_node;
			new_node->next = temp_1;
			pthread_mutex_unlock(&mutex);
			break;
		}
		pthread_mutex_unlock(&mutex);
		temp_2=temp_1;
		temp_1=temp_1->next;

	}
	
	pthread_mutex_lock(&mutex);
	if(flag==0)
	{
		temp_1->next=new_node;
		new_node->next = NULL;
	}
	pthread_mutex_unlock(&mutex);

}



int main()
{

	struct node *head=NULL;
	int temp_data=0;
	int i=0,j=0;
	int initial_number_of_elements = Initial_List_Size;
	int ret;
	struct timeval time; 
    gettimeofday(&time,NULL);
   // srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
	
	appened_insert(&head,(0));	//	head/root node's data is always 0;
	for(i=0;i<initial_number_of_elements-1;i++)
	{
		
		temp_data=(temp_data+(rand()%100));
		appened_insert(&head,(temp_data));
	}


	cout<<"Initial list : ";
	print_list_data(&head);


	cout<<"\n\n";

	for(i=0;i<NoOfThreads;i++)
	{
	//	srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
		thread_parameters *tp;
		tp = (thread_parameters*) malloc(sizeof(struct thread_parameters));
		tp->root = head;
		tp->datum = rand()%100;
		if(tp->datum==0)
		{
			tp->datum=10;
		}
		ret=pthread_create(&t[i], NULL,thread_insert,(void*)tp);
		if( ret ) {
            perror("Thread creation fail");
            exit(2);    
        }

	}

	for(j=0; j<NoOfThreads; j++)
	{
      pthread_join(t[j], NULL);
	}

	cout<<"Final list : ";
	print_list_data(&head);
	cout<<"\n\n";
	return 0;
}
