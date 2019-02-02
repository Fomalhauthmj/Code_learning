#include<iostream>
#include<cstring>
using namespace std;
bool vis[13];
int ans[12];
int cnt=3;
bool legal()
{
    int temp1=ans[1]+ans[11]+ans[3]+ans[4];
    int temp2=ans[1]+ans[5]+ans[8]+ans[2];
    int temp3=ans[4]+ans[6]+ans[9]+ans[2];
    int temp4=ans[7]+ans[8]+ans[9]+ans[10];
    int temp5=ans[0]+ans[5]+ans[11]+ans[7];
    int temp6=ans[0]+ans[3]+ans[6]+ans[10];
    if(temp1!=temp2||temp1!=temp3||temp1!=temp4||temp1!=temp5||temp1!=temp6) return false;
    if(temp2!=temp3||temp2!=temp4||temp2!=temp5||temp2!=temp6) return false;
    if(temp3!=temp4||temp3!=temp5||temp3!=temp6) return false;
    if(temp4!=temp5||temp4!=temp6) return false;
    if(temp5!=temp6) return false;
    return true;
}
void DFS(int step)
{
    if(step>=12)
    {
        if(legal())
        {
            for(int i=0;i<12;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=12;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ans[cnt++]=i;
            DFS(step+1);
            cnt--;
            vis[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(vis,0,sizeof(vis));
    vis[1]=vis[3]=vis[8]=1;
    ans[0]=1;
    ans[1]=8;
    ans[2]=3;//11->2
    DFS(3);//ans10
    system("pause");
}