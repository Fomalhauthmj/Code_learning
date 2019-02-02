#include<iostream>
#include<cstring>
using namespace std;
#define max 1000010
int res[max]={0};
int main()
{
    res[1]=1;
    res[2]=2;
    for(int i=3;i<max;i++)
    {
        res[i]=(res[i-2]+res[i/2])%1000000000;
    }
    int n;
    while(cin>>n)
    {
        cout<<res[n]<<endl;
    }
}   