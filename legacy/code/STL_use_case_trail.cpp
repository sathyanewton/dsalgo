/* 
	This program's purpose is to do some trail and error on STL use-cases and try make them very familiar. 
	We shall also try to extend to do the same with pointers. 
	
	Basically this a code-stratchpad for this job search. 
*/


#include <time.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <stdlib.h>
#include <cstring>

using namespace std; 

struct cmp_str
{
    bool operator()(char const *a, char const *b)
    {
        return std::strcmp(a, b) < 0;
    }
};

// sample task 1 --> find the number of occurances of each alphabet or charecter in a string. 
// make many assumptions to reduce corner case of the problem. 


void ascii_hash(string s, int*a)
{
	char *c = NULL; 
	int i = 0; 

	int *ascii_hash_pointer;

	ascii_hash_pointer = a;

	c = (char*) &s[0]; 

	while(*c != '\0')
	{
		cout<<(int)*c<<"\n";
		ascii_hash_pointer[(int)(*c)] = ascii_hash_pointer[(int)(*c)] + 1;
		c++; 
	}

}

void print_map(map<char,int>*mymap_pointer)
{
	map<char,int>::iterator it;
	for(it = mymap_pointer->begin();it != mymap_pointer->end(); it++)
	{
		cout<<"value --> "<<it->first<<" --> "<<it->second<<"\n";
	}
}


void populate_map(string s, map<char,int>*mymap_pointer)
{
	char *c; 
	c = &s[0];
	int temp=0;

	//find function call

	map<char,int>::iterator it;
	

	while(*c != '\0')
	{
		it = mymap_pointer->find(*c);
		if(it==mymap_pointer->end())
		{
		mymap_pointer->insert ( std::pair<char,int>(*c,1) );
		}
		else
		{
			temp = (int)it->second;
			cout<<"temp --> "<<temp<<"\n";
			temp++;
			it->second = temp; 
			
		}
		c++;	
	}
}

int main()
{
		
	// Solution for sample task 1. 
	// traditional approach. using ascii hash. 

	string user_input;
	
	int i=0; 
	// cout<<" Goma give input string : "<<"\n";
	int ascii_hash_pointer[256] = {0};
	int *a; 
	int number_of_charecters_in_user_input=0;
	a = ascii_hash_pointer;

	// using map 
	map<char,int> mymap;
	map<char,int> *mymap_pointer;

	// mymap_pointer = &mymap;

	cout<< "Enter the user input --> ";
	cin>>user_input; 

	char *c = (char*) &user_input[0]; 

	while(*c != '\0')
	{
		cout<<*c<<"\n";
		c++;
		number_of_charecters_in_user_input++;
	}

	ascii_hash(user_input,a);

	mymap_pointer = &mymap;

	for(i=0;i<256;i++)
	{
		if(ascii_hash_pointer[i] >= 1)
		{
			cout<<" ascii_hash["<<i<<"] -- > "<<ascii_hash_pointer[i]<<"\n"; 
		}
	}

	populate_map(user_input,mymap_pointer);

	print_map(mymap_pointer);

	return 0;
} 
