#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
bool prime[40]={0};
bool used[20];
int num[20];
int n;
int casenum=1;
void DFS(int step)
{
    if(step==n&&prime[num[n]+num[1]]) 
    {
        for(int i=1;i<n;i++)
        {
            cout<<num[i]<<" ";
        }
        cout<<num[n]<<endl;
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[num[step]+i]&&used[i]==0&&num[step]!=i)
        {
            num[step+1]=i;
            used[i]=1;
            DFS(step+1);
            used[i]=0;
        }
    }
}
int main()
{
    for(int i=2;i<=39;i++)
    {
        int flag=0;
        for(int j=2;j<=sqrt(i);j++)
        {
             if(i%j==0) 
            {
                flag=1;
                break;
            }
        }
        if(flag==1) prime[i]=0;
        else prime[i]=1;
    }
    while(cin>>n)
    {
        memset(used,0,sizeof(used));
        memset(num,0,sizeof(num));
        cout<<"Case "<<casenum++<<":"<<endl;
        num[1]=1;
        DFS(1);
        cout<<endl;
    }
}