#include<iostream>
using namespace std;
int big[25]={0};
int small[25]={0};
int main()
{
    small[1]=1;
    big[2]=1;
    small[2]=1;
    big[3]=1;
    small[3]=2;
    for(int i=4;i<=20;i++)
    {
        small[i]=small[i-1]+big[i-1];
        big[i]=small[i-1];
    }//斐波那契数列
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<small[n]+big[n]<<endl;
    }
}