#include<iostream>
#include<cstring>
using namespace std;
int ans[10];
bool vis[10];
int kinds;
int cnt;
bool judge()
{
    if(ans[4]>=min(ans[0],ans[1])) return false;
    if(ans[5]>=min(ans[1],ans[2])) return false;
    if(ans[6]>=min(ans[2],ans[3])) return false;
    if(ans[7]>=min(ans[4],ans[5])) return false;
    if(ans[8]>=min(ans[5],ans[6])) return false;
    if(ans[9]>=min(ans[7],ans[8])) return false;
    return true;
}
void print()
{
    cout<<ans[9]<<endl;
    cout<<ans[7]<<" "<<ans[8]<<endl;
    cout<<ans[4]<<" "<<ans[5]<<" "<<ans[6]<<endl;
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
}
void DFS(int depth)
{
    if(depth>=10)
    {
        if(judge()) 
        {
            kinds++;
            print();
        }
        return;
    }
    for(int i=0;i<10;i++)
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
    cnt=0;
    kinds=0;
    DFS(0);
    cout<<kinds<<endl;
    system("pause");//ans=768
}