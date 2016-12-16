/* https://www.hackerrank.com/contests/programming-interview-questions/challenges/m-th-to-last-element */ 



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits> 
//#include <erorr> 
using namespace std;

struct node
{
   long long data; 
   struct node* next; 
   struct node* prev; 
}; 

struct node* insert(struct node* head, long long input_data, struct node** tail,long long* count)
{
    if(input_data > ULONG_MAX || input_data < 0)
    {
        cout<<strerror(EINVAL); 
        return (struct node*)NULL; 
    }
    if(head == NULL)
    {
        // first node of the list getting memory allocated. 
        //cout<<"head pointer memory allocation\n"; 
        head = (struct node*)malloc(sizeof(struct node));
        if(head == NULL)
        {
            cout<<strerror(errno); 
            return (struct node*)NULL; 
        }
        *count = *count + 1; 
        head->data = input_data; 
        head->next = NULL;
        head->prev = NULL; 
        *tail = head; 
    }
    else
    {
        //cout<<"else part not head \n";
        struct node* runner = head; 
        while(runner->next != NULL)
        {
            runner = runner->next;     
        }
        //allocation memory for other nodes 
        runner->next = (struct node*)malloc(sizeof(struct node)); 
        if(runner->next == NULL)
        {
            cout<<strerror(errno); 
            return (struct node*)NULL; 
        }
        *count = *count + 1; 
        runner->next->data = input_data; 
        runner->next->next = NULL;
        runner->next->prev = runner; 
        *tail = runner->next; 
    }
    return head; 
}

void print_list_forward(struct node* head)
{
    if(head == NULL)
    {
        cout<<strerror(EINVAL); 
    }
    else
    {
        struct node* runner = head; 
        while(runner != NULL)
        {
            cout<<runner->data<<" --> "; 
            runner = runner->next; 
        }
        if(runner == NULL)
        {
            cout<<"NULL";     
        }
    }
}

void print_list_reverse(struct node* tail)
{
    if(tail == NULL)
    {
        cout<<strerror(EINVAL); 
    }
    else
    {
        struct node* runner = tail; 
        while(runner != NULL)
        {
            cout<<runner->data<<" --> "; 
            runner = runner->prev; 
        }
        if(runner == NULL)
        {
            cout<<"NULL";     
        }
    }
}

long long find_element(struct node* tail,long long querry_index,long long count_input)
{
    long long result = 0; 
    long long count = 1; 
    //cout<<"Querry index "<<querry_index<<endl; 
    //cout<<"Count input "<<count_input<<endl;
    if(tail == NULL || querry_index < 1 || querry_index > (ULONG_MAX-1) || count_input < 0 || count_input > (ULONG_MAX - 1))
    {
        cout<<strerror(EINVAL); 
        return -1; 
    }
    if(querry_index > count_input)
    {
        return -2;     
    }
    
    //cout<<"In here "<<endl; 
    if(querry_index == 1)
    {
        result = tail->data;  
        //cout<<"Result --> "<<result; 
    }
    else 
    {
        struct node* runner = tail; 
        while(runner->prev != NULL)
        {
             if(count == querry_index)
             {
                result = runner->data;
               //cout<<"Result --> "<<result;
                break; 
             }
            runner = runner->prev;  
            count = count + 1;
           // cout<<"Count -- "<<count<<endl; 
        } 
    }
    return result; 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    /*Head and tail pointers declaration*/
     
    struct node* head = NULL; 
    struct node* tail = NULL;
    long long result = 0; 
    long long querry_index = 0; 
    long long count = 0; 
    
    cin>>querry_index; 
    if(querry_index < 1 || querry_index > (ULONG_MAX-1))
    {
        cout<<strerror(EINVAL); 
        exit(-1);
    }
    //cout<<querry_index<<endl; 
    long long input_element = 0; 
    //string s_input_element; 
    while(cin>>input_element && count < 1024)
    {
         //input_element = stoll(s_input_element); 
         if(input_element < 0 || input_element > ULONG_MAX)
         {
            cout<<strerror(EINVAL); 
            exit(-1);
         }      
         //cout<<input_element<<" ";  
         // insert element save head and tail pointer 
         head = insert(head,input_element,&tail,&count);
         if(head == NULL)
         {
            cout<<"Error in function insert\n"; 
            exit(-1);
         }
    }   
    
    //cout<<"Element count --> "<<count<<endl;
    //cout<<"tail element --> "<<tail->data<<endl; 
    //cout<<"\n\n";
    //print_list_forward(head); 
    //cout<<"\n\n";
    //print_list_reverse(tail); 
    //cout<<"\n\n";
    
    result = find_element(tail,querry_index,count);
    if(result == -1)
    {
        cout<<"Error in function find_element\n";
        exit(-1);
    }
    if(result == -2)
    {
        cout<<"NIL"; 
    }
    else
    {
        cout<<result; 
    }
    return 0;
}
