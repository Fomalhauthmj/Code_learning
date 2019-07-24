#include<bits/stdc++.h>
using namespace std;
#define N 100010
int n,x,y;
//原始序列  有序
//树状数组
int c[N];
int order[N];
//离散化
struct node
{
    int val;
    int pos;
};
node ns[N];
bool cmp(node &n1,node &n2)
{
    if(n1.val==n2.val) return n1.pos<n2.pos;
    else return n1.val<n2.val;
}
//https://blog.csdn.net/m0_38033475/article/details/80330157
//https://blog.csdn.net/ssimple_y/article/details/53744096
int lowbit(int x)
{
    return x&(-x);
}
int getSum(int x) //获得1-x范围内的Inversions数量
{
    int ans=0;
    while(x>=1)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
void edit(int x,int val)
{
    while(x<=n)
    {
        c[x]+=val;
        x+=lowbit(x);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    //swap 交换相邻的元素
    while(cin>>n>>x>>y)
    {
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++) 
        {
            cin>>ns[i].val;
            ns[i].pos=i;
        }
        sort(ns+1,ns+1+n,cmp);//排序  获得离散化的相同逆序对下标
        int cnt=1;
        for(int i=1;i<=n;i++)
        {
            if(ns[i].val!=ns[i-1].val&&i!=1) cnt++;
            order[ns[i].pos]=cnt;
        }
        long long ans=0;
        for(int i=1;i<=n;i++)//对于插入的每个数查询它之前有没有比它大的数
        {
            edit(order[i],1);
            ans+=i-getSum(order[i]);
        }
        ans=ans*min(x,y);
        cout<<ans<<endl;
    }
}