#include<iostream>
#include<algorithm>
using namespace std;
long long x[100010];
long long k;
bool cmp(long long x1,long long x2)
{
    return x1<x2;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    int n;
    cin>>t;
    long long ans;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>x[i];
        sort(x,x+n,cmp);
        ans=0;
        int pos;
        for(int i=0;i<n;i++)
        {
            pos=upper_bound(x,x+n,x[i]+k)-x;
            ans+=pos-1-i;
        }
        cout<<ans<<endl;
    }
}