#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
const int SIZE = 1E5 + 50;
#define inf 0x7fffffff
#define ull unsigned long long
#define P 131
ull BASE[SIZE];
void Init()
{
    BASE[0]=1;
    for(int i=1;i<SIZE;i++)
        BASE[i]=BASE[i-1]*P;
}
struct Treap
{
    int l, r;
    int val, dat;
    int cnt, size,ch;
    ull hash;
} a[SIZE];
int tot, root, n;
int New(int val,int ch)
{
    a[++tot].val = val, a[tot].dat = rand(), a[tot].cnt = a[tot].size = 1;
    a[tot].ch=ch;
    return tot;
}
void Update(int p)
{
    a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt;
    a[p].hash=a[p].ch*BASE[a[a[p].r].size]+a[a[p].l].hash*BASE[a[a[p].r].size+1]+a[a[p].r].hash;
}
void Build()
{
    New(-inf,0), New(inf,0), root = 1, a[1].r = 2, Update(root);
}
int GetRankByVal(int p, int val)
{
    if (p == 0)
        return 0;
    if (val == a[p].val)
        return a[a[p].l].size + 1;
    if (val < a[p].val)
        return GetRankByVal(a[p].l, val);
    return GetRankByVal(a[p].r, val) + a[a[p].l].size + a[p].cnt;
}
int GetValByRank(int p, int rank)
{
    if (p == 0)
        return inf;
    if (a[a[p].l].size >= rank)
        return GetValByRank(a[p].l, rank);
    if (a[a[p].l].size + a[p].cnt >= rank)
        return a[p].val;
    return GetValByRank(a[p].r, rank - a[a[p].l].size - a[p].cnt);
}
void Zag(int &p)
{
    int q = a[p].r;
    a[p].r = a[q].l, a[q].l = p, p = q, Update(a[p].l), Update(p);
}
void Zig(int &p)
{
    int q = a[p].l;
    a[p].l = a[q].r, a[q].r = p, p = q, Update(a[p].r), Update(p);
}
void Insert(int &p, int val,int ch)
{
    if (p == 0)
    {
        p = New(val,ch);
        return;
    }
    if (val == a[p].val)
    {
        a[p].cnt++, Update(p);
        return;
    }
    if (val < a[p].val)
    {
        Insert(a[p].l, val,ch);
        if (a[p].dat < a[a[p].l].dat)
            Zig(p);
    }
    else
    {
        Insert(a[p].r, val,ch);
        if (a[p].dat < a[a[p].r].dat)
            Zag(p);
    }
    Update(p);
}
int GetPre(int val)
{
    int ans = 1, p = root;
    while (p)
    {
        if (val == a[p].val)
        {
            if (a[p].l > 0)
            {
                p = a[p].l;
                while (a[p].r > 0)
                    p = a[p].r;
                ans = p;
            }
            break;
        }
        if (a[p].val < val && a[p].val > a[ans].val)
            ans = p;
        p = val < a[p].val ? a[p].l : a[p].r;
    }
    return a[ans].val;
}
int GetNext(int val)
{
    int ans = 2, p = root;
    while (p)
    {
        if (val == a[p].val)
        {
            if (a[p].r > 0)
            {
                p = a[p].r;
                while (a[p].l > 0)
                    p = a[p].l;
                ans = p;
            }
            break;
        }
        if (a[p].val > val && a[p].val < a[ans].val)
            ans = p;
        p = val < a[p].val ? a[p].l : a[p].r;
    }
    return a[ans].val;
}
void Remove(int &p, int val)
{
    if (p == 0)
        return;
    if (val == a[p].val)
    {
        if (a[p].cnt > 1)
        {
            a[p].cnt--, Update(p);
            return;
        }
        if (a[p].l || a[p].r)
        {
            if (a[p].r == 0 || a[a[p].l].dat > a[a[p].r].dat)
                Zig(p), Remove(a[p].r, val);
            else
                Zag(p), Remove(a[p].l, val);
            Update(p);
        }
        else
            p = 0;
        return;
    }
    val < a[p].val ? Remove(a[p].l, val) : Remove(a[p].r, val);
    Update(p);
}
char str[SIZE];
int main()
{
    scanf("%s",str+1);
    Build();
    n=strlen(str+1);
    for(int i=1;i<=n;i++)
        Insert(root,i,str[i]-'a');
    int M;
    scanf("%d",&M);
    while(M--)
    {
        char opt[2];
        scanf("%s",opt);
        if(opt[0]=='Q')
        {
            int x,y;
            scanf("%d%d",&x,&y);
        }
        else if(opt[0]=='R')
        {
            int x;
            char d[2];
            scanf("%d %s",&x,d);
        }
        else if(opt[0]=='I')
        {
            int x;
            char d[2];
            scanf("%d %s",&x,d);
        }
    }
    system("pause");
    return 0;
}