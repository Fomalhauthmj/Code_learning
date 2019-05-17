#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 20;
const int M = 3e5 + 20;
#define inf 0x3f3f3f3f
class Tree
{
    //倍增维护的最小生成树
private:
    vector<pair<int, long long>> G[N];
    //无向图
    int par[N][18];
    //祖先
    long long max_edge[N][18];
    //最大边
    long long sub_max[N][18];
    //次大边
    int depth[N];
    //深度
public:
    void Init()
    {
        depth[0] = 0;
        //初始化
    }
    void AddEdge(int u, int v, long long w)
    {
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
        //无向图加边
    }
    void DFS(int cur, int pre)
    {
        //DFS预处理par max_edge sub_max
        depth[cur] = depth[pre] + 1;
        par[cur][0] = pre;
        sub_max[cur][0] = -inf;
        //初始化次大值
        for (int i = 1; (1 << i) <= depth[cur]; i++)
        {
            par[cur][i] = par[par[cur][i - 1]][i - 1];
            long long temp[4] = {
                max_edge[cur][i - 1],
                max_edge[par[cur][i - 1]][i - 1],
                sub_max[cur][i - 1],
                sub_max[par[cur][i - 1]][i - 1]};
            sort(temp, temp + 4);
            max_edge[cur][i] = temp[3];
            //最大值
            int ptr = 2;
            while (ptr >= 0 && temp[ptr] == temp[3])
            {
                ptr--;
            }
            sub_max[cur][i] = (ptr >= 0 ? temp[ptr] : -inf);
            //严格次大值
        }
        for (auto ele : G[cur])
        {
            if (ele.first != pre)
            {
                max_edge[ele.first][0] = ele.second;
                //初始化最大值
                DFS(ele.first, cur);
            }
        }
    }
    int LCA(int u, int v)
    {
        //倍增法求LCA
        if (depth[u] < depth[v])
        {
            swap(u, v);
        }
        for (int i = 17; i >= 0; i--)
        {
            if (depth[par[u][i]] >= depth[v])
            {
                u = par[u][i];
            }
        }
        if (u == v)
            return u;
        for (int i = 17; i >= 0; i--)
        {
            if (par[u][i] != par[v][i])
            {
                u = par[u][i];
                v = par[v][i];
            }
        }
        return par[u][0];
    }
    long long Query(int u, int v, long long val)
    {
        //查询最小生成树上u-v的路径上，边权最大值（严格小于val）
        long long res = -inf;
        for (int i = 17; i >= 0; i--)
        {
            if (depth[par[u][i]] >= depth[v])
            {
                if (val != max_edge[u][i])
                {
                    res = max(res, max_edge[u][i]);
                }
                else
                    res = max(res, sub_max[u][i]);
                u = par[u][i];
            }
        }
        return res;
    }
};
Tree tree;
struct Edge
{
    int u, v;
    long long w;
    bool operator<(Edge e) const
    {
        return w < e.w;
        //注意这里的小于 用于排序
    }
    Edge(int uu, int vv, long long ww) : u(uu), v(vv), w(ww)
    {
    }
    Edge()
    {
    }
};
Edge es[M];
int fa[N];
//用于并查集
bool vis[M];
//标记是否使用
long long Find(long long x)
{
    if (fa[x] == -1)
        return x;
    else
        return fa[x] = Find(fa[x]);
}
int n; //点
int m; //边
long long sum;
//最小生成树的权值和
long long Kruskal()
{
    memset(fa, -1, sizeof(fa));
    memset(vis, 0, sizeof(vis));
    long long cnt = 0;
    long long ans = 0;
    long long fu, fv;
    sort(es, es + m);
    for (int i = 0; i < m; i++)
    {
        fu = Find(es[i].u);
        fv = Find(es[i].v);
        if (fu != fv)
        {
            //cout<<"add:"<<es[i].u<<" "<<es[i].v<<" "<<es[i].w<<endl;
            ans += es[i].w;
            fa[fu] = fv;
            tree.AddEdge(es[i].u, es[i].v, es[i].w);
            //加入最小生成树
            cnt++;
            vis[i] = 1;
        }
        if (cnt >= n - 1)
            break;
    }
    if (cnt < n - 1)
        return -1;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int u, v;
    long long w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        es[i] = Edge(u, v, w);
    }
    sum = Kruskal();
    tree.DFS(1, 0);
    //DFS预处理
    long long end_ans = -1;
    for (int i = 0; i < m; i++)
    {
        if (!vis[i])
        //未使用
        {
            int temp = tree.LCA(es[i].u, es[i].v);
            //找到路径上不等于 e[i].val 的最大边权
            long long tempa = tree.Query(es[i].u, temp, es[i].w);
            long long tempb = tree.Query(es[i].v, temp, es[i].w);
            //cout<<es[i].u<<" "<<temp<<" "<<es[i].v<<" "<<tempa<<" "<<tempb<<endl;
            if (max(tempa, tempb) > -inf)
            {
                //存在此类边
                if (end_ans == -1)
                    end_ans = sum - max(tempa, tempb) + es[i].w;
                else
                    end_ans = min(end_ans, sum - max(tempa, tempb) + es[i].w);
            }
        }
    }
    cout << end_ans << endl;
    //system("pause");
    return 0;
}
/*
5 6 
1 2 1 
1 3 2 
2 4 3 
3 5 4 
3 4 3 
4 5 6 
*/