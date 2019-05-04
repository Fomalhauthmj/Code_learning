#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 50050 
//N<2^16 实际在找两组不同二元组 满足 a<b Aa<Ab
int n;
long long c[N];
long long a[N];
long long suf[N];
long long lowbit(long long x)
{
    return x&(-x);
}
long long getNum(long long x)
{
    long long ans=0;
    while(x>=1)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
void edit(int x,long long val)
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
    cin.tie(0);
    int T;cin>>T;
    while(T--)
    {
        cin>>n;
        memset(c,0,sizeof(c));
        memset(suf,0,sizeof(suf));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];//读入
        }
        for(int i=n;i>=1;i--)
        {
            suf[i]=suf[i+1]+(n-i-getNum(a[i]));//i~end之间的正序对=i+1~end之间的正序对+...
            //n-i 表示a[i]后面还有几个数  总数-逆序数=正序数
            //getNum(a[i]) 表示获得a[i]~end之间的逆序对==获得在a[i]之前小于a[i]的数 因为倒序 即为在原序列后面小于其的数 即为逆序对
            edit(a[i],1);
        }//后缀和
        memset(c,0,sizeof(c));
        long long ans=0;//结果
        for(int i=1;i<=n;i++)
        {
            //正序  比上面容易理解
            ans+=getNum(a[i])*suf[i+1];//获得在a[i]前面比其小的数*正序对后缀和
            edit(a[i],1);//为什么要+1?  处理<=的情况 因为这题序列所有数不同 所以无需
        }
        cout<<ans<<endl;
    }
}
//https://www.cnblogs.com/COLIN-LIGHTNING/p/8621294.html