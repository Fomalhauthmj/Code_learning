#include<iostream>
using namespace std;
int res[25]={0};
int main()
{
    res[0]=1;
    res[1]=3;
    for(int i=2;i<=20;i++)
    {
        res[i]=2*res[i-1]+res[i-2];
    }
    int c;
    cin>>c;
    while(c--)
    {
        int n;
        cin>>n;
        cout<<res[n]<<endl;
    }
}