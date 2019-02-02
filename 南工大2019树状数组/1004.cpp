#include<bits/stdc++.h>
using namespace std;
#define N 32500
int c[N];
int ans[N];
int n;
int lowbit(int x)
{
    return x&(-x);
}
void edit(int x,int val)
{
   while(x<=N)//单点修改 a[x]+=val;
   {
       c[x]+=val;
       x+=lowbit(x);
   }
}
int getSum(int x)
{
    int sum=0;
    while(x>=1)//获得前缀和a[1]+....a[x]
    {
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        memset(c,0,sizeof(c));
        memset(ans,0,sizeof(ans));
        //点按y递增顺序给出
        int xi,yi;
        for(int i=1;i<=n;i++)
        {
            cin>>xi>>yi;
            xi++;//为什么要xi++  x可能取值0 1-n+1 整体右移
            //edit(xi,1);为什么不能先添加  
            ans[getSum(xi)]++;   //获得<=xi的数量
            edit(xi,1);//添加点
        }
        for(int i=0;i<=n-1;i++)
        {
            cout<<ans[i]<<endl;
        }
    }
}