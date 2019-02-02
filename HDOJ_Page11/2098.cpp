#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    bool judge[10001]={0};
    int pos=0;
    int prime[1500]={0};
    for(int i=2;i<=10000;i++)
    {
        if(judge[i]==0) prime[pos++]=i;
        for(int j=0;j<pos;j++)
        {
            if(i*prime[j]>10000) break;
            judge[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        else
        {
            int sum=0;
            for(int i=0;i<pos;i++)
            {
                for(int j=i+1;j<pos;j++)
                {
                    if(prime[i]+prime[j]==n) sum++;
                }
            }
            cout<<sum<<endl;
        }
    }
}
