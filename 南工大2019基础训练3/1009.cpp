#include<iostream>
#include<cstring>
#include<time.h>
using namespace std;
int a[19];
bool vis[20];
//从图形不难看出每个数字位于三条直线上
//则为满足题意 每天直线和为(1+...+19)*3/15=38 以此为剪枝条件
void DFS(int depth)
{
    if(depth>=3)
    {
        if((a[0]+a[1]+a[2])!=38) return;
    }
    if(depth>=7)
    {
        if((a[3]+a[4]+a[5]+a[6])!=38) return;
    }
    if(depth>=8)
    {
        if((a[0]+a[3]+a[7])!=38) return;
    }
    if(depth>=12)
    {
        if((a[2]+a[6]+a[11])!=38) return;
        if((a[7]+a[8]+a[9]+a[10]+a[11])!=38) return;
    }
    if(depth>=13)
    {
        if((a[1]+a[4]+a[8]+a[12])!=38) return;
    }
    if(depth>=16)
    {
        if((a[12]+a[13]+a[14]+a[15])!=38) return;
        if((a[1]+a[5]+a[10]+a[15])!=38) return;
    }
    if(depth>=17)
    {
        if((a[7]+a[12]+a[16])!=38) return;
        if((a[2]+a[5]+a[9]+a[13]+a[16])!=38) return;
    }
    if(depth>=18)
    {
        if((a[6]+a[10]+a[14]+a[17])!=38) return;
        if((a[3]+a[8]+a[13]+a[17])!=38) return;
    }
    if(depth>=19)
    {
        if((a[16]+a[17]+a[18])!=38) return;
        if((a[0]+a[4]+a[9]+a[14]+a[18])!=38) return;
        if((a[18]+a[15]+a[11])!=38) return;
        for(int i=7;i<=11;i++) cout<<a[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=1;i<=19;i++)
    {
        if(!vis[i])//数字i未被使用过
        {
            vis[i]=1;//标记为已使用
            a[depth]=i;//当前深度假设值
            DFS(depth+1);//深度优先搜索
            vis[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int start=clock();
    memset(vis,0,sizeof(vis));
    a[0]=15;
    a[1]=13;
    vis[15]=vis[13]=1;
    DFS(2);
    int end=clock();
    cout<<"time:"<<end-start<<"ms"<<endl;
    //9 6 5 2 16
    system("pause");
}