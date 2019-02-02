#include<bits/stdc++.h>
using namespace std;
#define N 100010
int n;
int c[N];
int lowbit(int x)
{
    return x&(-x);
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
void edit(int x,int data)
{
    while(x<=n)
    {
        c[x]+=data;
        x+=lowbit(x);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        if(n==0) break;
        //memset(d,sizeof(d),0); //原数组均为0 差分数组也均为0
        memset(c,0,sizeof(c));//树状数组前缀和c  c[i]=d[1]+...+d[i]=a[i]
        int x,y;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            edit(x,1);
            edit(y+1,-1);
        }
        for(int i=1;i<=n;i++)
        {
            if(i==n) cout<<getSum(i)<<endl;
            else cout<<getSum(i)<<" ";
        }
    }
}