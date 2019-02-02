#include<iostream>
using namespace std;
#define max 501
int res[max]={0};
int main()
{
    res[1]=1;
    for(int i=2;i<=500;i++)
    {
        res[i]=res[i-1]+i*(1+i)/2;
        if((i-1)%2==0)
        {
            int temp=(i-1)/2;
            res[i]+=temp*(temp+1);
        }
        else
        {
            int temp=(i+1)/2;
            res[i]+=temp*temp;
        }
    }
    int n;
    while(cin>>n)
    {
        cout<<res[n]<<endl;
    }
}