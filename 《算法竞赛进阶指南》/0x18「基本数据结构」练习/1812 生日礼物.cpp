#include<iostream>
#include<queue>
using namespace std;
const int N=1E5+50;
#define ll long long
#define inf 0x3f3f3f3f
int n,m;
ll a[N],b[N],c[N],cnt=0;
int nxt[N],pre[N];
bool vis[N];
struct node
{
    int ptr;
    bool operator<(const node &one) const
    {
        return c[ptr]>c[one.ptr];
    }
    node(int pp):ptr(pp){}
};
priority_queue<node> pq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    ll pre_num=0;
    int p=0,q=0;
    for(int i=0;i<n;i++)
    {
        if(a[i])
        {
            if(!pre_num||(pre_num<0&&a[i]<0)||(pre_num>0&&a[i]>0)) pre_num+=a[i];
            else 
            {
                if(!cnt&&pre_num<0) pre_num=a[i];
                else (pre_num>0)?p++:q++,b[cnt++]=pre_num,pre_num=a[i];
            }
        }
    }
    if(pre_num>0) b[cnt++]=pre_num,p++;
    ll ans=0;
    for(int i=0;i<cnt;i++) if(b[i]>0) ans+=b[i];
    if(p>m)
    {
        for(int i=0;i<cnt;i++)
        {
            c[i+1]=abs(b[i]);
            nxt[i+1]=i+2;
            pre[i+1]=i;
            pq.push(node(i+1));
        }
        c[0]=inf;
        c[cnt+1]=inf;
        for(int i=0;i<p-m;i++)
        {
            node now=pq.top();
            pq.pop();
            while(vis[now.ptr])
            {
                now=pq.top();
                pq.pop();
            }
            //cout<<"cur:"<<c[now.ptr]<<endl;
            ans -= c[now.ptr];
            c[now.ptr] = c[pre[now.ptr]] + c[nxt[now.ptr]] - c[now.ptr];
            vis[pre[now.ptr]] = 1;
            vis[nxt[now.ptr]] = 1;
            pre[now.ptr] = pre[pre[now.ptr]];
            nxt[now.ptr] = nxt[nxt[now.ptr]];
            pre[nxt[now.ptr]] = now.ptr;
            nxt[pre[now.ptr]] = now.ptr;
            pq.push(node(now));
        }
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
/*
10 1
-2 -1 0 1 2 0 -1 2 3 -2
 */