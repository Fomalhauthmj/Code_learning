#include<iostream>
#include<cstring>
using namespace std;
int n;
bool is_prime[40];
bool vis[25];
int ans[25];
int cnt;
void DFS(int pre)
{
    if(cnt>n&&is_prime[1+pre]==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(i!=n)    cout<<ans[i]<<" ";
            else cout<<ans[i]<<endl;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&is_prime[i+pre]==1)
        {
            vis[i]=1;
            ans[cnt++]=i;
            DFS(i);
            vis[i]=0;
            cnt--;
        }
    }
}
int main()
{
    int casenum=1;
    memset(is_prime,0,sizeof(is_prime));
    int flag;
    for(int i=2;i<40;i++)
    {
        flag=0;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(!flag) is_prime[i]=1;
    }
    while(cin>>n)
    {
        memset(vis,0,sizeof(vis));
        vis[1]=1;
        ans[1]=1;
        cnt=2;
        cout<<"Case "<<casenum++<<":"<<endl;
        DFS(1);
        //print
        cout<<endl;
    }
}