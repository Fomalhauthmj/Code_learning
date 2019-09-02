//记录了两种根据SPFA判定负环的做法 BFS/DFS 注意重新建图
#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N = 305;
const int M = 505;
int head[N], ver[M], edge[M], nxt[M], tot, n, m;
bool vis[N];
ll d[N];
struct edge
{
    int u,v,w;
}e[2*M];
void add(int x, int y, int z)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z;
    //cout<<"add:"<<tot<<endl;
}
bool SPFA(int x)
{
    //cout<<"x:"<<x<<endl;
    vis[x] = true;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        //cout<<x<<"->"<<y<<endl;
        if (d[y] > d[x] + edge[i])
        {
            d[y] = d[x] + edge[i];
            if (vis[y])
            {
                vis[x] = false;
                return true;
            }
            if (SPFA(y))
            {
                vis[x] = false;
                return true;
            }
        }
    }
    return vis[x] = false;
}
bool Judge(int s, int t, int mid)
{
    memset(d, 0, sizeof(d));
    memset(vis,0,sizeof(vis));
    //add(s, t, mid);
    memset(head,0,sizeof(head));
    tot=0;
    for(int i=0;i<m;i++) add(e[i].u,e[i].v,e[i].w);
    add(s,t,mid);
    for (int i = 0; i < n; ++i)
    {
        if (SPFA(i))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        //init
        scanf("%d%d", &n, &m);
        for (int i = 0, x, y, w; i < m; i++)
            scanf("%d%d%d", &x, &y, &w),e[i]={x,y,w};
        for (int i = 0, s, t; i < 6; i++)
        {
            scanf("%d%d", &s, &t);
            int left = -1e9;
            int right = 1e9;
            int mid;
            while (left < right)
            {
                mid = (left + right)>>1;
                //cout << "cur:" << mid << endl;
                if (Judge(s, t, mid))
                {
                    right = mid;
                }
                else
                    left = mid+1;
            }
            printf("%d\n", left);
            e[m++]={s,t,left};
        }
    }
    //system("pause");
    return 0;
}

#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N = 305;
const int M = 505;
int head[N], ver[M], edge[M], nxt[M], tot, n, m,cnt[N];
bool vis[N];
ll d[N];
struct edge
{
    int u,v,w;
}e[2*M];
void add(int x, int y, int z)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z;
    //cout<<"add:"<<tot<<endl;
}
bool SPFA(int s,int t,int mid)
{
    memset(d, 0x3f, sizeof(d));
    memset(vis,0,sizeof(vis));
    memset(head,0,sizeof(head));
    tot=0;
    for(int i=0;i<m;i++) add(e[i].u,e[i].v,e[i].w);
    add(s,t,mid);
    queue<int> q;
    q.push(s);
    d[s]=0,vis[s]=1,cnt[s]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x];i;i=nxt[i])
        {
            int y=ver[i];
            if(d[y]>d[x]+edge[i])
            {
                d[y]=d[x]+edge[i];
                cnt[y]=cnt[x]+1;
                if(cnt[y]>=n)
                    return false;
                if(!vis[y]) q.push(y),vis[y]=1;
            }
        }
    }
    return true;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        //init
        scanf("%d%d", &n, &m);
        for (int i = 0, x, y, w; i < m; i++)
            scanf("%d%d%d", &x, &y, &w),e[i]={x,y,w};
        for (int i = 0, s, t; i < 6; i++)
        {
            scanf("%d%d", &s, &t);
            int left = -1e9;
            int right = 1e9;
            int mid;
            while (left < right)
            {
                mid = (left + right)>>1;
                //cout << "cur:" << mid << endl;
                if (SPFA(s, t, mid))
                {
                    right = mid;
                }
                else
                    left = mid+1;
            }
            printf("%d\n", left);
            e[m++]={s,t,left};
        }
    }
    //system("pause");
    return 0;
}