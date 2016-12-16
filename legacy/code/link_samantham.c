#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node
{
	int data;
	struct node *next; 
};

/*
		insert function==> input parameters(data,head)
							check if its the root node
									==>if yes==> allocate root, insert data, keep next pointer=NULL
														RETURN head.

								==>else ==> iterate through the list to find the node who's next value is NULL
												allocate new node, insert data, keep the new node's next to NULL.

*/



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
		printf("not the first node in the list\n");
		new_node =  (struct node *)malloc(sizeof(struct node));
		new_node->data=data;
		new_node->next=NULL;
		assert(new_node!=NULL);

		tail->next=new_node;
		tail=new_node;

	}

}


void position_insert(struct node **current_node,int data,int postion)
{
	int i=1;
	int flag=0;
	struct node *temp;
	struct node *new_node;
	temp=*current_node;

	new_node = (struct node *)malloc(sizeof(struct node));
	assert(new_node!=NULL);

	new_node->data=data;

	while(temp->next!=NULL)
	{
		i++;
		if(i==(postion))
		{
			printf("entered in postion : %d\n",i);
			flag=1;
			new_node->next=temp->next;
			temp->next=new_node;
		}

		temp=temp->next;
	}
	if(	postion<=(i+1) && flag==0)
	{
		flag=1;
		printf("Entered position is the position of the final node in the list \n");
		appened_insert(current_node,data);
	}
	if(postion>(i) && flag==0)
	{
		printf("invalid position\n");
	}
	//check for position greater than size of list or negative postions.
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


void print_list_link(struct node **current_node)
{
struct node *a;
	a=*current_node;
	printf("%u\n",a);
	while(a->next!=NULL)
	{
		printf("%u\n",a->next);
		a=a->next;
		
	}
}





int main()
{

	struct node *head=NULL;

	appened_insert(&head,(1));		//	1
	appened_insert(&head,(1));		//	2
		appened_insert(&head,(1));		//	3
	//	appened_insert(&head,(1));		//	4
	//	appened_insert(&head,(1));		//	5
	//	appened_insert(&head,(1));		//	6
	//	appened_insert(&head,(1));		//	7
	//	appened_insert(&head,(1));		//	8

	//	print_list_link(&head);
	print_list_data(&head);

	position_insert(&head,6,3);
	position_insert(&head,8,4);

	print_list_data(&head);

	//	position_insert(&head,6,10);

	//	print_list_data(&head);


	return 0;
}

