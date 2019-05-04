#include<iostream>
using namespace std;
int quickpow(int a,unsigned long long b)
{
    unsigned long long  ans=1;
    int base=a;
    while(b)
    {
        if(b&1) ans=ans*base%100;
        base=base*base%100;
        b>>=1;
    }
    return ans%100;
}

int main()
{
    int t;
    while(cin>>t)
    {
        if(t==0) break;
        unsigned long long num[t+1];
        for(int i=1;i<=t;i++)
        {
            cin>>num[i];
        }
        for(int i=1;i<=t;i++)
        {
            cout<<"Case "<<i<<": "<<(quickpow(4,num[i]-1)+quickpow(2,num[i]-1))%100<<endl;
        }
        cout<<endl;
    }
}
