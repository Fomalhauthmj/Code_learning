#include<iostream>
using namespace std;
int main()
{
    int n,a,b;
    while(cin>>n)
    {
        if(n==1) cout<<"Hello World"<<endl;
        else
        {
            cin>>a>>b;
            cout<<a+b<<endl;
        }
    }
}