#include<stdio.h> 
#include<stdlib.h> 

struct node{
	int key;
	struct node *left;
	struct node *right;
};


/*
void insert_root()
{
	struct node *lbt,*lbt1;
	int randkey;
	int i;
	lbt=(struct node *)malloc(sizeof(struct node));
	randkey=rand()%10;
	lbt->key=randkey;
	lbt->left=lbt->right=0;
btree_head=lbt;
}
*/

void insert(struct node **a,int key)
{
	//printf("inside insert\n");
	struct node *lbt;			//local btree
	lbt = *a;
	if( lbt == NULL)
	{
		//printf("inside if lbt==0 \n");
		lbt=(struct node *)malloc(sizeof(struct node));
		lbt->key=key;
		lbt->left=lbt->right=0;
		*a=lbt;
	}
	else
	{
		if(key<(lbt->key))
		{
			//printf("inside if lbt->key\n");
			insert(&(lbt->left),key);
		}
		else if(key>(lbt->key))
		{
			//printf("inside if lbt->key\n");
			insert(&(lbt->right),key);
		}
	}
}


struct node *search(struct node **a,int key)
{
	struct node *lbt,*lbt1;
	lbt=*a;
	if(lbt==0)
	{
		printf("enter valid pointer or element not found\n");
		return 0;
	}
	else
	{
		if(key==lbt->key)
		{
			printf("element found : %d \n",lbt->key);
			return lbt;
		}
		else if(key<(lbt->key))
		{
		
			return search(&(lbt->left),key);
		}
		else if(key>(lbt->key))
		{

			return search(&(lbt->right),key);
		}

	}

	return lbt1;
}


void print_tree(struct node **a)
{
	struct node *lbt;
	lbt = *a;
	printf("key : %d -> left : %d -> right : %d\n",lbt->key,lbt->left->key,lbt->right->key);
}

void in_order(struct node **a)
{
	struct node *head;

	 head = *a;	

	if(head == NULL)
	{
		return;
	}	
		in_order(&(head->left));
		printf("--> %d  ",head->key);
		in_order(&(head->right));
}


void decision(struct node **a)
{
	struct node *head;
	head = *a;
	if(head->left==NULL && head->right==NULL)
	{
		printf("case 1 \n");
	}
	else if((head->left!=NULL && head->right==NULL) | (head->left==NULL && head->right!=NULL))
	{
		printf("case 2 \n");
	}
	else if((head->left!=NULL && head->right!=NULL))
	{
		printf("case 3 \n");
	}
}

void deletion(struct node **a, int element)
{
	struct node *head;

	head = *a;

	if(head == NULL)
	{
		return;
	}

	//printf(" %d \n ",head->key);

	deletion(&(head->left),element);
	if(head->key == element )
	{
		printf("element found\n");
		if(head->left==NULL && head->right==NULL)
		{
			printf("case 1 \n");
			free(head);
		}
		else if((head->left!=NULL && head->right==NULL) | (head->left==NULL && head->right!=NULL))
		{
			printf("case 2 \n");
		}
		else if((head->left!=NULL && head->right!=NULL))
		{
			printf("case 3 \n");
		}
		
	}	
	deletion(&(head->right),element);
}




int main()
{
	int n1,n2,randkey,i;
	struct node *dumas;

	struct node *btree_head=NULL;		// btree head 

	insert(&btree_head,55);

	printf("1) %x\n",&btree_head);
	insert(&btree_head,42);
	insert(&btree_head,60);
	insert(&btree_head,25);
	insert(&btree_head,50);
	insert(&btree_head,57);
	insert(&btree_head,68);


	printf("2) %x\n",&btree_head);
	in_order(&btree_head);

	printf("\n3) %x\n",&btree_head);

	deletion(&btree_head,57);

	printf("\n4) %x\n",&btree_head);

	in_order(&btree_head);
	return 0;
}


