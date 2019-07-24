#include<iostream>
using namespace std;
int res[31]={0};
int main()
{
    res[1]=1;
    res[0]=1;
    for(int i=2;i<=30;i++)
    {
        res[i]=res[i-1]+2*res[i-2];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<res[n]<<endl;
    }
}