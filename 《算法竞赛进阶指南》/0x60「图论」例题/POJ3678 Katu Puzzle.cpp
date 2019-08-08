#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1E3 + 50;
const int M = 1e6 + 50;
int n,m;
int head[2 * N], ver[4 * M], nxt[4 * M], tot;
void add(int u, int v)
{
    ver[++tot] = v, nxt[tot] = head[u], head[u] = tot;
}
/*
assume:
0...n-1:0
n...2n-1:1
 */
int dfn[2*N],low[2*N],num,stack[2*N],top,cnt,color[2*N];
bool in_stack[2*N];
void Tarjan(int x)
{
    dfn[x]=low[x]=++num;
    stack[++top]=x,in_stack[x]=true;
    for(int i=head[x];i;i=nxt[i])
    {
        int y=ver[i];
        if(!dfn[y])
        {
            Tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(in_stack[y])
            low[x]=min(low[x],dfn[y]);
    }
    if(dfn[x]==low[x])
    {
        cnt++;
        int y;
        do
        {
            y=stack[top--],color[y]=cnt,in_stack[y]=false;
        } while (y!=x);
    }
}
void SCC()
{
    for(int i=0;i<2*n;i++)
        if(!dfn[i]) Tarjan(i);
}
int main()
{
    scanf("%d%d", &n, &m);
    char op[4];
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d%s", &a, &b, &c, op);
        if (op[0] == 'A')
        {
            if (c)
                add(a, a + n), add(b, b + n);
            else
                add(a + n, b), add(b + n, a);
        }
        else if (op[0] == 'O')
        {
            if (c)
                add(a, b + n), add(b, a + n);
            else
                add(a + n, a), add(b + n, b);
        }
        else if (op[0] == 'X')
            if (c)
                add(a, b + n), add(a + n, b), add(b, a + n), add(b + n, a); //原命题与逆否命题成对出现
            else
                add(a, b), add(b, a), add(b + n, a + n), add(a + n, b + n);
    }
    SCC();
    bool flag=true;
    for(int i=0;i<n;i++)
        if(color[i]==color[i+n])
        {
            flag=false;
            break;
        }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    system("pause");
    return 0;
}