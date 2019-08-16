#include <iostream>
using namespace std;
const int N = 1e6 + 50;
const int M = 1e6 + 50;
#define inf 0x3f3f3f3f
int head[N], ver[M], nxt[M], tot;
int n, f[N][2], fa[N], t[N][2], tcnt, ban;
void add(int x, int y)
{
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}
int Find(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = Find(fa[x]);
}
void DP(int x)
{
    int num = inf;
    f[x][0] = 0;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (y != ban)
            DP(y);
        f[x][0] += max(f[y][0], f[y][1]);
        num = min(num, max(f[y][0], f[y][1]) - f[y][0]);
    }
    f[x][1] = f[x][0] + 1 - num;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1, ai; i <= n; i++)
    {
        scanf("%d", &ai);
        int fi = Find(i), fai = Find(ai);
        if (fi == fai)
        {
            //成环边 记录
            t[++tcnt][0] = i;
            t[tcnt][1] = ai;
        }
        else
            add(ai, i), fa[fi] = fai; //内向基环树难以遍历 反向处理
    }
    int ans = 0;
    for (int i = 1; i <= tcnt; i++)
    {
        ban = 0;
        DP(t[i][1]);//对外向基环树先以被控制点为根进行DP
        ban = t[i][1];//避免重复
        DP(t[i][0]);//再以控制点为根进行DP
        int temp = f[t[i][0]][1];//控制点被投放的情况下
        f[t[i][1]][1] = f[t[i][1]][0] + 1;//控制点不被投放 被控制点可以直接加入
        DP(t[i][0]);//重新DP
        ans += max(temp, f[t[i][0]][0]);//选择更优
    }
    cout << ans << endl;
    system("pause");
    return 0;
}