#include<iostream>
#include<cstring>
using namespace std;
#define size 25
int ans;
int n,k,w;
struct node
{
    int value;
    int weight;
};
node a[size];
bool vis[size];
int currentw;
int currentv;
void DFS(int dep,int pre)
{
    if(dep>=k)
    {
        if(currentv>ans) ans=currentv;
        return;
    }
    for(int i=pre+1;i<n;i++)
    {
        if(!vis[i]&&currentw+a[i].weight<=w)
        {
            vis[i]=1;
            currentw+=a[i].weight;
            currentv+=a[i].value;
            DFS(dep+1,i);
            vis[i]=0;
            currentw-=a[i].weight;
            currentv-=a[i].value;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        memset(vis,0,sizeof(vis));
        ans=0;
        currentw=0;
        currentv=0;
        for(int i=0;i<n;i++) cin>>a[i].value>>a[i].weight;
        cin>>w;
        DFS(0,-1); //注意起始搜索位！！！与pre+1对应的是-1
        cout<<ans<<endl;
    }
}