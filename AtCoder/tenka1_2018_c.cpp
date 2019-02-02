#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010
int a[N];
//• p1 ≥ p2 ≤ p3 ≥ ...
//• p1 ≤ p2 ≥ p3 ≤ ...
//两种情况下计算值独立
//ans1;ans2
int n;
long long deal()
{
    long long ans1=0;
    long long ans2=0;
    if(n%2==0)//偶数
    {
        //正影响：2*(n/2-1) 1*1
        //负影响：-2*(n/2-1) -1*1
        //两种模式下处理相同
        int i;
        for(i=1;i<=n/2-1;i++) ans1-=2*a[i];
        ans1-=a[i];
        i++;ans1+=a[i];
        i++;
        for(;i<=n;i++) ans1+=2*a[i];
        return ans1;
    }
    else//奇数
    {
        //正影响：1* 2  2*(n-3)/2
        //负影响：     -2*(n-1)/2
        //两种模式下处理不同,以下第一种
        int i;
        for(i=1;i<=(n-1)/2;i++) ans1-=2*a[i];
        ans1+=a[i];
        i++;
        ans1+=a[i];
        i++;
        for(;i<=n;i++)  ans1+=2*a[i];
        //以下第二种
        for(i=1;i<=(n-3)/2;i++) ans2-=2*a[i];
        ans2-=a[i];
        i++;
        ans2-=a[i];
        i++;
        for(;i<=n;i++) ans2+=2*a[i];
        return max(ans1,ans2);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        cout<<deal()<<endl;
    }
}
