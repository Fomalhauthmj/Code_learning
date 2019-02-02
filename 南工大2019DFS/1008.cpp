#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int ans;
int half[9];
int x[30];
int y[30];
int rel[9][2];
bool judge()
{
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<":"<<rel[i][0]<<" "<<rel[i][1]<<endl;
        if(rel[i][0]!=rel[i][1]) return false;
    }
    return true;
}
void DFS(int k)//最大状态数 K8 2^28次
{
    if(rel[x[k]][0]>half[x[k]]) return;
    if(rel[x[k]][1]>half[x[k]]) return;
    if(rel[y[k]][0]>half[y[k]]) return;
    if(rel[y[k]][1]>half[y[k]]) return;
    if(k>m)
    {
        if(judge()) ans++;
        return;
    }
    rel[x[k]][0]++;
    rel[y[k]][0]++;
    DFS(k+1);
    rel[x[k]][0]--;
    rel[y[k]][0]--;

    rel[x[k]][1]++;
    rel[y[k]][1]++;
    DFS(k+1);
    rel[x[k]][1]--;
    rel[y[k]][1]--;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(half,0,sizeof(half));
        for(int i=1;i<=m;i++)
        {
            cin>>x[i]>>y[i];
            half[x[i]]++;
            half[y[i]]++;
        }
        bool flag=0;
        for(int i=1;i<=n;i++)
        {
            if(half[i]%2==1)
            {
                flag=1;break;
            }
            half[i]/=2;
        }
        if(flag) 
        {
            cout<<0<<endl;
            continue;
        }
        ans=0;
        memset(rel,0,sizeof(rel));
        DFS(1);
        cout<<ans<<endl;
    }
}