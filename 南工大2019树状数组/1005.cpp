//区间更新 单点查询  离散化
#include<bits/stdc++.h>
using namespace std;
#define N 100010
int n,m;
int c[N];
int xpos[N];
int cnt;
int li[N],ri[N],ask_pos[N];
int lowbit(int x)
{
    return x&(-x);
}
void edit(int x,int val)
{
    while(x<=cnt)
    {
        c[x]+=val;
        x+=lowbit(x);
    }
}
int getSum(int x)
{
    int sum=0;
    while(x>=1)
    {
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int casenum=1;
    while(t--)
    {
        cin>>n>>m;
        memset(c,0,sizeof(c));//用差分数组解决区间更新 初值均为0
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            cin>>li[i]>>ri[i];
            xpos[cnt++]=li[i];
            xpos[cnt++]=ri[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>ask_pos[i];
            xpos[cnt++]=ask_pos[i];
        }
        sort(xpos,xpos+cnt);
        cnt=unique(xpos,xpos+cnt)-xpos;//离散化
        int l,r;
        for(int i=1;i<=n;i++)
        {
            l=lower_bound(xpos,xpos+cnt,li[i])-xpos;
            r=lower_bound(xpos,xpos+cnt,ri[i])-xpos;
            edit(l+1,1);
            edit(r+2,-1);
        }
        cout<<"Case #"<<casenum++<<":"<<endl;
        /*
        for(int i=1;i<=cnt;i++)
        {
            cout<<getSum(i)<<" ";
        }
        cout<<endl;
        */
        int pos;
        for(int i=1;i<=m;i++)
        {
            pos=lower_bound(xpos,xpos+cnt,ask_pos[i])-xpos;
            cout<<getSum(pos+1)<<endl;
        }
    }
}