//http://codeforces.com/problemset/problem/1057/A
//TODO:1700
#include<iostream>
#include<vector>
using namespace std;
#define N 200010
vector<int> V[N];
int ans[N];
int n;
int step;
bool DFS(int start,int pre)
{
    if(start==n)
    {
        //到达终点
        return true;
    }
    for(int i=0;i<V[start].size();i++)
    {
        int next=V[start][i];
        if(next!=pre)
        {
            ans[step++]=next;
            if(DFS(next,start)) return true;//对于不同的搜索结果 分开执行
            else step--;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    int number;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) V[i].clear();
        for(int i=2;i<=n;i++)
        {
            cin>>number;
            V[number].push_back(i);
            V[i].push_back(number);//树形结构 双向
        }
        ans[0]=1;
        step=1;
        DFS(1,0);
        for(int i=0;i<step;i++)
        {
            cout<<ans[i];
            if(i!=step-1) cout<<" ";
        }
        cout<<endl;
    }
}
