/*
 * File Created: Thursday, 18th July 2019 8:30:09 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Thursday, 18th July 2019 8:30:58 pm
 * Copyright (c) 2019 北落师门
 */
#include<iostream>
#include<queue>
#include<bitset>
using namespace std;
const int N=3E4+50;
int n,m;
int nxt[N],head[N],ver[N],deg[N],tot=0;
int ret[N],cnt=0;
bitset<N> f[N];
void Add(int u,int v)
{
    ver[++tot]=v;
    nxt[tot]=head[u];
    head[u]=tot;
    deg[v]++;
}
queue<int> q;
void TopoSort()
{
    for(int i=1;i<=n;i++)
        if(!deg[i]) q.push(i);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        ret[++cnt]=now;
        for(int i=head[now];i;i=nxt[i])
        {
            int to=ver[i];
            if(--deg[to]==0) q.push(to);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        Add(u,v);
    }
    TopoSort();
    for(int i=cnt;i>=1;i--)
    {
        u=ret[i];
        for(int j=head[u];j;j=nxt[j])
        {
            v=ver[j];
            f[u]|=f[v];
        }
        f[u].set(u);
    }
    for(int i=1;i<=n;i++) cout<<f[i].count()<<endl;
    system("pause");
    return 0;
}