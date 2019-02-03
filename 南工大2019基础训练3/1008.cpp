#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
bool vis[13];
int ans[13];
int cnt=0;
bool judge()
{
    queue<int> a; 
    for(int i=0;i<13;i++)
    {
        a.push(ans[i]);
    }
    int cur=0;
    int now;
    while(a.size()>=2)
    {
        now=a.front();
        a.push(now);
        a.pop();
        now=a.front();
        if(now!=cur++) return false;
        a.pop();
    }
    now=a.front();
    if(now!=12) return false;
    return true;
}
int temp=0;
void DFS(int d)
{
    if(d>=2&&ans[1]!=0) return;
    if(d>=4&&ans[3]!=1) return;
    if(d>=6&&ans[5]!=2) return;
    if(d>=8&&ans[7]!=3) return;
    if(d>=10&&ans[9]!=4) return;
    if(d>=12&&ans[11]!=5) return;
    if(d>=13)
    {
        //cout<<temp++<<endl;
        if(judge())
        {
            for(int i=0;i<13;i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int i=0;i<13;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ans[cnt++]=i;
            DFS(d+1);
            cnt--;
            vis[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    DFS(0);
    system("pause");//6 0 11 1 7 2 10 3 8 4 12 5 9
    //"7,A,Q,2,8,3,J,4,9,5,K,6,10"
}