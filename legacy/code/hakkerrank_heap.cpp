#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

using namespace std;

void print_input_vector(vector<int>* input_vector)
{
    int i = 0; 
    for(i=0;i<(*input_vector).size();i++)
    {
        cout<<(*input_vector)[i]<<" "; 
    }
    cout<<"\n";
}


int main(){
    int n;
    cin >> n;
    vector<int> a;
    float result; 
    for(int a_i = 0;a_i < n;a_i++)
    {
       int input_value; 
       cin >> input_value;
       a.push_back(input_value); 
       sort(a.begin(),a.end());
       //int index  = a.size()%2;
       //cout<<"Index -- "<<index<<"a.size() -- "<<a.size()<<endl; 
       if(a.size()%2 != 0)
       {
           result = (float)a[a.size()/2]; 
           //cout<<a[a_i]<<" -- "<<a_i<<" -- "<<result<<"\n"; 
           cout<<fixed << setprecision(1)<<(float)result<<endl; 
       }
       else
       {
           result = ((float)(a[a.size()/2] + a[((a.size()/2) - 1)])/2); 
           //cout<<a[a_i]<<" -- "<<a_i<<" -- "<<result<<"\n"; 
           cout<<fixed << setprecision(1)<<(float)result<<endl; 
       }
    }
    //print_input_vector(&a);
    return 0;
}
