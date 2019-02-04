/*
22阶完美正方形一共有8种。下面的组合是另一种：
2 5 9 11 16 17 19 21 22 24 26 30 31 33 35 36 41 46 47 50 52 61
如果告诉你该方案紧贴着上边沿的是从左到右依次为：47 46 61
你能计算出紧贴着下边沿的是哪几个正方形吗？
*/
#include<iostream>
#include<cstring>
using namespace std;
//边长为47+46+61=154  TODO:点阵对每个点深搜
int map[154][154];
int ans[19];
int square[19]={2 ,5, 9, 11 ,16, 17, 19 ,21 ,22 ,24, 26, 30, 31 ,33 ,35 ,36, 41 ,50, 52};
bool vis[19];
void init()
{
    for(int i=0;i<47;i++)
    {
        for(int j=0;j<47;j++)
            map[i][j]=1;
    }
    for(int i=47;i<93;i++)
    {
        for(int j=0;j<46;j++)
            map[i][j]=1;
    }
    for(int i=93;i<154;i++)
    {
        for(int j=0;j<61;j++)
            map[i][j]=1;
    }
}
void fill(int r,int c,int s)
{
    for(int i=r;i<r+square[s];i++)
    {
        for(int j=c;j<c+square[s];j++)
        {
            map[i][j]=1;
        }
    }
}
void clear(int r,int c,int s)
{
    for(int i=r;i<r+square[s];i++)
    {
        for(int j=c;j<c+square[s];j++)
        {
            map[i][j]=0;
        }
    }
}
bool no_repeat_legal(int r,int c,int s)
{
    if(r+square[s]>154||c+square[s]>154) return false;
    for(int i=r;i<r+square[s];i++)
    {
        for(int j=c;j<c+square[s];j++)
        {
            if(map[i][j]) return false;
        }
    }
    return true;
}
bool judge()
{
    for(int i=0;i<154;i++)
    {
        for(int j=0;j<154;j++)
        {
            if(!map[i][j]) return false;
        }
    }
    return true;
}
int cnt=0;
bool DFS(int depth)
{
    if(depth>=19)
    {
        for(int i=0;i<cnt;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return true;
    }
    for(int i=0;i<154;i++)
    {
        for(int j=0;j<154;j++)
        {
            if(!map[i][j])
            {
                for(int k=0;k<19;k++)
                {
                    if(!vis[k]&&no_repeat_legal(i,j,k))
                    {
                        bool flag=false;
                        if(j+square[k]==154)//一列填充好 记录最后一块
                        {
                            ans[cnt++]=square[k];
                            flag=true;
                        }
                        fill(i,j,k);
                        vis[k]=1;
                        if(DFS(depth+1)) return true;
                        if(flag) cnt--;//回溯
                        vis[k]=0;
                        clear(i,j,k);
                    }
                }
                return false;//这里的return false 返回语句是必须的 否则跑不出结果
                //实际意义为找遍所有的正方形也填不满这一列 这个搜索分支显然无效 直接剪去
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(map,0,sizeof(map));
    memset(vis,0,sizeof(vis));
    init();
    DFS(0);
    system("pause");
    //50 33 30 41
}