#include <iostream>
#include <vector>
using namespace std;
 
int main(){

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    v.pop_back();

    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++)
        cout<<*it<<endl;

    for(auto element:v){
        cout<<element<<endl;
    }
    
    vector<int> v2(3,50); //specifing size,elements

    //sorting vector
    

    return 0;
}