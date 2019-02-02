#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010
int a[N];
int b[N];
int c[N];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        sort(c,c+n);
        long long ans=0;
        for(int i=0;i<n;i++)//枚举b
        {
            int c1=lower_bound(a,a+n,b[i])-a;//第一个大于等于b[i] 0 1 2
            if(c1<=0) continue;
            int c2=upper_bound(c,c+n,b[i])-c;//第一个大于
            if(n-c2<=0) continue;
            ans+=(n-c2)*c1;//注意long long 
        }
        cout<<ans<<endl;
    }
}