#include <iostream>
using namespace std;

class node{
	public:	
		int data;
		node *next;
		node *prev;
		node();
};

node::node(){
	//cout<<"allocating memory for node\n";
	this->data=0;
	this->next=NULL;
	this->prev=NULL;	
}

class list{
	node *head;
	public:
		list();
        	void addnode(int);
        	void printlist();
};

list::list(){
cout<<"constructor\n";
this->head=NULL;
}

void list::addnode(int data){
	node* ptr;
	if(head == NULL){
		this->head=new node;
        //cout<<"head is"<<head<<endl;
		this->head->data=data;
		//cout<<"head data"<<head->data<<endl;
        	this->head->next = NULL;
        	this->head->prev=NULL;
	}
	else{
		ptr = this->head;
		//cout<<"else part head is"<<ptr<<endl;
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		node* temp=ptr;
		ptr->next = new node;
		ptr->next->data=data;
		//cout<<"ptrdata is "<<ptr->next->data<<endl;
		//cout<<"ptr->prevdata is "<<temp->data;
		ptr->next->next = NULL;
		ptr->next->prev=temp;
	}	
}

void list::printlist(){
	node* ptr=this->head;
	if(ptr==NULL)cout<<"list empty\n";
	else{
	 while(ptr){
		cout<<ptr->data<<"->";
		ptr = ptr->next;
		}
		if(ptr == NULL)
		{
			cout<<"NULL";
		}
	cout<<endl;
	}
}

int main(int argc, char *argv[]){
list *a=new list;
a->addnode(1);
a->printlist();
a->addnode(2);
a->addnode(3);
a->addnode(7);
a->addnode(31);
a->addnode(3132);
a->addnode(123);
a->printlist();
return 0;
}
