#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define  N 150020
int n;
int d[N];
int ans[N];
int next_p[N];
int vis[N];
struct node
{
    int val;
    int len;
    int pos;
    node(int vval,int length,int ppos)
    {
        val=vval;len=length;pos=ppos;
    }
    bool operator<(const node& n) const
    {
        if(len!=n.len) return len>n.len;//步长短优先
        if(val!=n.val) return val<n.val;//数位大优先
        //return pos>n.pos;//前面的优先考虑  实际无需
    }
};
priority_queue<node> Q;
void BFS(int val)
{
    while(!Q.empty()) Q.pop();
    for(int i=0;i<n;i++)
    {
        if(d[i]==val) Q.push(node(val,0,i));
    }
    memset(ans,-1,sizeof(ans));
    memset(vis,-1,sizeof(vis));
    while(!Q.empty())
    {
        node now=Q.top();
        Q.pop(); 
        int n_p=next_p[now.pos];//下一点
        if(ans[now.len]==-1) ans[now.len]=now.val;//若这一层未有值
        if(now.val<ans[now.len]) continue;//当前层的数位已经小于收集解 不可行
        if(vis[now.pos]<now.len) vis[now.pos]=now.len;//如果此点访问深度小于当前深度,更新此点访问深度
        else continue;//若此点访问深度大于等于当前深度 ->同一层在同一个位置的移出队列
        /*
        2.对于链的分支而言：假如初始点A搜索到一个已经被点B搜索过的点，
        那么初始点B就不用继续搜索了（想想为什么），B就可以被移出队列。 
        TODO:因为优先队列按值由大到小搜索 A的层高于B 若访问到相同点 说明在这点前有更优的解？ B点排除
        */
        if(now.len==n-1) continue;
        Q.push(node(d[n_p],now.len+1,n_p));
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    char ch;
    int casenum=1;
    while(t--)
    {
        cin>>n;
        int max_v=0;
        for(int i=0;i<n;i++)
        {
            cin>>ch;d[i]=ch-'0';//获得数位
            next_p[i]=(int)(((long long)i*(long long)i+1)%(long long)n);//注意这里乘法可能溢出
            if(max_v<d[i]) max_v=d[i];
        }
        BFS(max_v);
        cout<<"Case #"<<casenum++<<": ";
        for(int i=0;i<n;i++)
        {
            cout<<ans[i];
        }
        cout<<endl;
    }
}