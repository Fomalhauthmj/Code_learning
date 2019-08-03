#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
#define ll long long
const int N=1e5+50;
int n,m,t,L[N],R[N],pos[N];
ll a[N],sum[N],add[N];
void change(int l,int r,ll d)
{   
    int p=pos[l],q=pos[r];
    if(p==q)
    {
        for(int i=l;i<=r;i++) a[i]+=d;
        sum[p]+=d*(r-l+1);
    }
    else
    {
        for(int i=p+1;i<=q-1;i++)
            add[i]+=d;
        for(int i=l;i<=R[p];i++)
            a[i]+=d;
        sum[p]+=d*(R[p]-l+1);
        for(int i=r;i>=L[q];i--)
            a[i]+=d;
        sum[q]+=d*(r-L[q]+1);
    }
}
ll ask(int l,int r)
{
    ll ret=0;
    int p=pos[l],q=pos[r];
    if(p==q)
    {
        for(int i=l;i<=r;i++) ret+=a[i];
        ret+=(r-l+1)*add[p];
    }
    else
    {
        for(int i=p+1;i<=q-1;i++)
            ret+=sum[i]+add[i]*(R[i]-L[i]+1);
        for(int i=l;i<=R[p];i++)
            ret+=a[i];
        ret+=add[p]*(R[p]-l+1);
        for(int i=r;i>=L[q];i--)
            ret+=a[i];
        ret+=add[q]*(r-L[q]+1);
    }
    return ret;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    //分块
    t=sqrt(n);
    for(int i=1;i<=t;i++)
    {
        L[i]=(i-1)*t+1;
        R[i]=i*t;
    }
    if(R[t]<n) t++,L[t]=R[t-1]+1,R[t]=n;
    //预处理
    for(int i=1;i<=t;i++)
    {
        for(int j=L[i];j<=R[i];j++)
        {
            sum[i]+=a[j];
            pos[j]=i;
        }
    }
    while(m--)
    {
        char op[3];
        int l,r,d;
        scanf("%s%d%d",op,&l,&r);
        if(op[0]=='C')
        {
            scanf("%d",&d);
            change(l,r,d);
        }
        else
        {
            printf("%lld\n",ask(l,r));
        }
    }
    //system("pause");
    return 0;
}