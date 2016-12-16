#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next; 
};

struct node *ll;	//global head pointer

void insert(struct node **a,int datum)
{
	
	struct node *newnode;
	newnode =(struct node*)malloc(sizeof(struct node));
	newnode->data=datum;
	newnode->next=*a;
	*a=newnode; 
}

void populate(int n)
{
	struct node *a;
	int k;
	int i;	
	
	a =(struct node*)malloc(sizeof(struct node));
	a->next = NULL;
	a->data = rand()%10;
	for(i=0;i<n;i++)
	{
		k=rand()%10;
		insert(&a,k);
	}
ll=a;
}

void print_list_data()
{
struct node *a;
	a=ll;
	while(a->next!=NULL)
	{
		printf("%d\n",a->data);
		a=a->next;
		//printf("%d\n",ll->next);
	}
}

void print_list_link()
{
struct node *a;
	a=ll;
	printf("%x\n",a);
	while(a->next!=NULL)
	{
		printf("%x\n",a->next);
		a=a->next;
		
	}
}

void pop_head(	)
{
struct node *a;
int temp;	
	temp=ll->data;
	ll=ll->next;
}


int insert1(int position,int n,int datum)
{
	int index=position;
	struct node *a,*newnode;
	a=ll;
	int datum1=datum;
	int count=0;
	if(position<0||position>n)
	{
		printf("enter valid index\n");
		return 0;
	}
printf("valid index\n");
	if(index==1)
	{
		newnode = (struct node*)(malloc(sizeof(struct node)));
			newnode->next=ll;
			newnode->data=datum1;
			ll=newnode;	
			printf("element added\n");
			print_list_data();
			return 0;
	}

	while(a->next!=NULL)
	{
		count++;
		if(count==(index-1))
		{	
			newnode = (struct node*)(malloc(sizeof(struct node)));
			newnode->next=a->next;
			a->next=newnode;
			newnode->data=datum1;
		}
		a=a->next;
	}
printf("element added\n");
print_list_data(); 
return 0;
}

void detect_loop(struct node **a)
{
	struct node *b,*slow,*fast;
	int count;
	b=*a;
	slow=b;
	fast=b;


	while(slow && fast && fast->next)
	{
		count++;
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast)
		{
			printf("loop found\n");
			return;
		}
	}

	printf("no loop\n");
	printf("count = %d\n",count);

	/*
	printf("b -> %x\n",*b);
	printf("slow -> %x\n",slow);
	printf("slow -> %x\n",slow->next);
	printf("slow -> %x\n",slow->next->next);
	printf("fast -> %x\n",fast);*/
}

void populate_array_list(int num)
{
	struct node *a;
	
}
int main()
{	
	int n; // initial number of elements
	int pos;
	printf("entern number of elements in the linked list :");
	scanf("%d",&n);
	populate(n);
	printf("print before pop\n");
	//print_list_data();
	print_list_link();
	//printf("entern the position of the inserted element :");
	//scanf("%d",&pos);
	//insert1(pos,n,100);

	detect_loop(&ll);



//	pop_head();
	/*working functions*/
	//printf("print after pop\n");
	//print_list_data();
	//print_list_link(); 
	
return 0;
}
