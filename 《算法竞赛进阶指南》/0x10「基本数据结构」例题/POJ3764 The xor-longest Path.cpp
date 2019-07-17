/*
 * File Created: Wednesday, 17th July 2019 10:45:06 am
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Wednesday, 17th July 2019 7:02:25 pm
 * Copyright (c) 2019 北落师门
 */
#include <iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
const int N = 1E5 + 50;
int n, head[N], nxt[N*2], weight[N*2], ver[N*2], tot = 0;
int trie[32 * N][2], cnt = 1;
bool vis[N];
int a[N];
void Add(int u, int v, int w)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
    weight[tot] = w;
}
void DFS(int start)
{
    for (int i = head[start]; i; i = nxt[i])
    {
        if (!vis[ver[i]])
        {
            a[ver[i]] = a[start] ^ weight[i];
            vis[ver[i]] = 1;
            DFS(ver[i]);
        }
    }
}
void Insert(int number)
{
    int p = 1;
    for (int i = 31; i >= 0; i--)
    {
        int now = (number >> i) & 1;
        if (!trie[p][now])
            trie[p][now] = ++cnt;
        p = trie[p][now];
    }
}
int Find(int number)
{
    int p = 1;
    int ret = 0;
    for (int i = 31; i >= 0; i--)
    {
        int now = (number >> i) & 1;
        if (!trie[p][now ^ 1])
            p = trie[p][now], ret <<= 1;
        else
            p = trie[p][now ^ 1], ret = (ret << 1) + 1;
    }
    return ret;
}
int main()
{
    while (cin >> n)
    {
        tot=0,cnt=1;
        memset(head,0,sizeof(head));
        memset(nxt,0,sizeof(nxt));
        memset(trie,0,sizeof(trie));
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        int u, v, w;
        for (int i = 0; i < n - 1; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            Add(u, v, w);
            Add(v, u, w);
        }
        vis[0]=1;
        DFS(0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            //cout<<a[i]<<endl;
            Insert(a[i]);
            ans = max(ans, Find(a[i]));
        }
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}