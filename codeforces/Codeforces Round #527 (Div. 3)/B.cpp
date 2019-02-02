#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
#define N 105
int n;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        int ans=0;
        for(int i=1;i<n;i+=2)
        {
            ans+=abs(a[i]-a[i+1]);
        }
        cout<<ans<<endl;
    }
}