//Disjoint Set
//HDU并查集 1198 1213 1232 1272
//针对于树的结构 无环结构 通过结构/数组实现
//路径压缩 在查找中进行 将查找路径上的结点父节点均设置为最终结点  rank->1;
//并查集的初始化 各结点的父结点设为自身
#include <iostream>
#include <algorithm>
using namespace std;
#define size 1010
int n, m;
//int n, m, u, v;
//int edge[size][2];风险
struct node
{
    int data;
    int parent;
    int rank; //当前为树的高度 若改为集合的数量？f.rank+=c.rank;注意构造函数 数量或高度的初始化
};
node uf[size];
int Find1(int x)
{
    if (uf[x].parent == x)
        return x;
    uf[x].parent = Find1(uf[x].parent); //采用路径压缩 右值为返回根节点
    return Find1(uf[x].parent);         //未进行路径压缩
}
// 考虑递归次数,以下为循环写法
int Find2(int x)
{
    int k = x;
    int next;
    while (uf[k].parent != k)
    {
        k = uf[k].parent;
    }
    //修改路径 压缩
    while (x != uf[x].parent)
    {
        next = uf[x].parent;
        uf[x].parent = k;
        x = next; //向上修改
    }
    return k;
}
int Union(int x, int y)
{
    x = Find1(x);
    y = Find1(y);
    if (x != y)
    {
        if (uf[x].rank < uf[y].rank)
            uf[x].parent = y;
        else
        {
            uf[y].parent = x;
            if (uf[y].rank == uf[x].rank)
            {
                uf[x].rank++;
            }
        }
        return 0;
    }
    return 1;
}
void init()
{
    for (int i = 0; i < n; i++)
        uf[i].parent = i;
}
//风险度量
//联通则合并
// int main()
// {
//     ios::sync_with_stdio(false);
//     int x, y;
//     while (cin >> n >> m)
//     {
//         int ans=0;
//         init();
//         for (int i = 0; i < m; i++)
//         {
//             cin >> x >> y;
//             edge[i][0]=x;
//             edge[i][1]=y;//保存
//             Union(x, y);
//         }
//         cin >> u >> v; //删点重构并查集
//         if(Find1(u)!=Find1(v))
//         {
//             cout<<-1<<endl;
//             continue;
//         }
//         for(int i=0;i<n;i++)
//         {
//             init();
//             if(i==u||i==v) continue;
//             for(int j=0;j<m;j++)
//             {
//                 if(edge[j][0]==i||edge[j][1]==i) continue;
//                 else Union(edge[j][0],edge[j][1]);
//             }
//             if(Find1(u)!=Find1(v)) ans++;
//         }
//         cout<<ans<<endl;//O(n^2)
//     }
// }
//国王的烦恼
// int num_of_UF()
// {
//     int ans=0;
//     for(int i=0;i<n;i++)
//     {
//         if(i==Find1(i)) ans++;
//     }
//     return ans;
// }
// //ans==1  ans>1 ans>preans 抗议
//如果从天数由低到高重复遍历构造则TLE
//unique()  对天数高->低 构造1次 逐渐恢复通路 如何判断是否抗议？当前两点加边前不通 加边后通->抗议(同时判断今天有无抗议)
// struct road
// {
//     int start;
//     int end;
//     int time;
//     bool operator <(const road & r) const
//     {
//         return time>r.time;
//     }
// };
// road R[size];
// int main()
// {
//     ios::sync_with_stdio(false);
//     while(cin>>n>>m)
//     {
//         int ans=0;
//         init();
//         for(int i=0;i<m;i++) cin>>R[i].start>>R[i].end>>R[i].time;
//         sort(R,R+n);
//         int pret=-1;
//         for(int i=0;i<m;i++)
//         {
//             int x=R[i].start;
//             int y=R[i].end;
//             int t=R[i].time;
//             if(Find1(x)!=Find1(y))
//             {
//                 if(t!=pret)
//                 {
//                     ans++;
//                     pret=t;
//                 }
//             }
//             Union(x,y);
//         }
//         cout<<ans<<endl;
//     }
// }
//强盗问题 朋友的朋友是朋友 敌人的敌人是朋友 都是朋友为团伙 问最大团伙数
//6 4
//E 1 4
//F 3 5
//F 4 6
//E 1 2
//ans：3
//维护两个并查集 朋友与敌人? 带权并查集?
//0-朋友   1-敌人
//如何合并？？？如何查找？？？
//寻找关系图
//u-F'u r1
//v-F'v r2
//u-v   r3
//F'u-F'v==r1^r2^r3
//查找压缩r=r1^r2
//https://agatelee.cn/2017/05/%E5%B8%A6%E6%9D%83%E5%B9%B6%E6%9F%A5%E9%9B%86/ POJ 1182 食物链 三种状态的带权并查集
// struct node
// {
//     int data;
//     int parent;
//     int rank;
//     int rel;//0-朋友   1-敌人 与父节点关系
//     node():rank(1),rel(0){};
// };
// node uf[size];
// int Find(int x)
// {
//     if(x==uf[x].parent) return x;
//     int pa=uf[x].parent;
//     uf[x].parent=Find(uf[x].parent);
//     uf[x].rel=uf[x].rel^uf[pa].rel;
//     return uf[x].parent;
// }
// int Find1(int x)
// {
//     int k=x,k1;
//     int idx[size],cnt=0;
//     while(k!=uf[k].parent)
//     {
//         idx[cnt++]=k;
//         k=uf[k].parent;
//     }
//     //记录路径点 由根到子逐渐压缩
//     for(int i=cnt-2;i>=0;i--)
//     {
//         uf[idx[i]].rel=uf[idx[i]].rel^uf[idx[i-1]].rel;
//         uf[idx[i]].parent=k;
//     }
// }
// void Union(int u,int v,int rel)
// {
//     int x=Find(u);
//     int y=Find(v);
//     if(x!=y)
//     {
//         if(uf[x].rank<uf[y].rank)
//         {
//             uf[x].parent=y;
//             uf[x].rel=r^uf[u].rel^uf[v].rel;
//         }
//         else
//         {
//             uf[y].parent=x;
//             uf[y].rel=r^uf[u].rel^uf[v].rel;
//             if(uf[x].rank==uf[y].rank) uf[x].rank++;
//         }
//     }
// }
//PLAN B：
// 如F x y 则U(x,y)
// 如E x y 则U(x,y+n) U(y,x+n)  res=1-n分布在哪些集合中
int root[size]={0};
int main()
{
    ios::sync_with_stdio(false);
    char ch;
    int x,y;
    while(cin>>n>>m)
    {
        for(int i=1;i<=2*n;i++) uf[i].parent=i;//注意初始化
        for(int i=0;i<m;i++)
        {
            cin>>ch>>x>>y;
            if(ch=='E')
            {
                Union(x+n,y);
                Union(y+n,x);
            }
            else if(ch=='F')
            {
                Union(x,y);
            }
        }
        int k;
        for(int i=1;i<=n;i++)
        {
            k=Find1(i);
            root[i]=k;
        }
        sort(root+1,root+1+n);
        cout<<(unique(root+1,root+1+n)-root-1)<<endl;
    }
}//同样的可以用类似的方法来处理上文的食物链 1-n  n+1-n+n(吃n)  2n+1-2n+n(被n吃)  可行？  