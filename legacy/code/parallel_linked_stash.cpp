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
	//check for position greater than size of list or negative postions.
}

struct thread_parameters
{
	
};

void *thread_insert(void *tp)
{



}