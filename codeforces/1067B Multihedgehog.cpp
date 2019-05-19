//http://codeforces.com/problemset/problem/1067/B
//!:❌  Wrong answer on test 42
//http://codeforces.com/contest/1067/status/B
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define N 100010
int n;
long long k;
vector<int> V[N];
int degree[N];
int leaf[N];
int dis[N];
bool vis[N];
queue<int> Q;
bool BFS()
{
    while(!Q.empty()) Q.pop();
    for(int i=1;i<=n;i++)
    {
        if(degree[i]==1)
        {
            Q.push(i);
        }
    }//将所有degree=1的点加入
    int del_num=0;
    while(!Q.empty())
    {
        int now=Q.front();Q.pop();vis[now]=1;//添加访问
        //cout<<"now:"<<now<<endl;
        del_num++;
        if(leaf[now]<3&&dis[now]!=0) return false;
        for(auto ele:V[now])
        {
            if(!vis[ele])
            {
                if(dis[ele]==0)
                {
                    dis[ele]=dis[now]+1;
                }
                else
                {
                    if(dis[ele]!=dis[now]+1) return false;
                }
                leaf[ele]++;
                degree[ele]--;  //!:子结点now-> 父结点degree-1
                if(degree[ele]==1) Q.push(ele);
            }
        }
    }
    if(del_num!=n) return false;
    if(*max_element(dis+1,dis+1+n)==k) return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(false);
    int a,b;
    while(cin>>n>>k)
    {
        for(int i=1;i<=n;i++) V[i].clear();
        memset(degree,0,sizeof(degree));
        memset(leaf,0,sizeof(leaf));
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        for(int i=1;i<=n-1;i++)
        {
            cin>>a>>b;
            V[a].push_back(b);
            V[b].push_back(a);//树的结构
            degree[a]++;
            degree[b]++;
        }
        if(n<4||k>10)//1阶至少4个 10阶9w个
        {
            cout<<"No"<<endl;
            continue;
        }
        if(BFS()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}