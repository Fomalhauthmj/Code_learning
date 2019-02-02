#include<iostream>
using namespace std;
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        if(n<k) cout<<1<<endl;
        else if(n%k==0) cout<<0<<endl;
        else if(n>k) cout<<1<<endl;
    }
}