#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==2||(n-2)%4==0) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}