#include<iostream>
#include<cstring>
using namespace std;
bool vis[14];
int ans[14];
int cnt;
int kinds;
bool judge()
{
    if(ans[10]/ans[11]!=ans[12]) return false;
    //if(ans[10]/ans[11]!=ans[12]||ans[10]%ans[11]!=0) return false;

    return true;
}
void DFS(int depth)
{
    if(depth>=9)
    {
        if(ans[1]+ans[2]!=ans[3]) return;
        if(ans[4]-ans[5]!=ans[6]) return;
        if(ans[7]*ans[8]!=ans[9]) return;
    }
    if(depth>=6)
    {
        if(ans[1]+ans[2]!=ans[3]) return;
        if(ans[4]-ans[5]!=ans[6]) return;
    }
    if(depth>=3)
    {
        if(ans[1]+ans[2]!=ans[3]) return;
    }
    if(depth>=12)
    {
        if(judge())
        {
            kinds++;
            for(int i=1;i<=12;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=13;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ans[cnt++]=i;
            DFS(depth+1);
            vis[i]=0;
            cnt--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cnt=1;
    kinds=0;
    memset(vis,0,sizeof(vis));
    DFS(0);
    cout<<kinds<<endl;
    system("pause");//ans=64 ?? 1376
}