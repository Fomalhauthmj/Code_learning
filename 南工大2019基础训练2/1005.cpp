#include<iostream>
#include<cstring>
using namespace std;
bool vis[10];
int ans[10];
int cnt;
void DFS(int depth)
{
    if(depth>=10)
    {
        int temp1=0;
        for(int i=0;i<4;i++)
        {
            temp1=temp1*10+ans[i];
        }
        int temp2=0;
        for(int i=4;i<8;i++)
        {
            temp2=temp2*10+ans[i];
        }
        int temp3=0;
        for(int i=8;i<10;i++)
        {
            temp3=temp3*10+ans[i];
        }
        if((temp1-temp2)*temp3==900)
        {
            for(int i=0;i<10;i++) cout<<ans[i]<<" ";
            cout<<endl;
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
    DFS(0);
    system("pause");//6048
}