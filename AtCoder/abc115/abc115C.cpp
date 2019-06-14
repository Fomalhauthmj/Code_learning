#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010
#define inf 0x3f3f3f3f
int n,k;
int h[N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>k)
    {
        for(int i=0;i<n;i++) cin>>h[i];
        sort(h,h+n);
        int ans=inf;
        for(int i=0;i<=n-k;i++)
        {
            ans=min(ans,h[i+k-1]-h[i]);
            //cout<<"cur ans:"<<ans<<endl;
        }
        cout<<ans<<endl;
    }
}