#include<iostream>
using namespace std;
#define N 105
int a[N];
int n;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(a[i]==0)
            {
                if(a[i-1]==1&&a[i+1]==1)
                {
                    a[i+1]=0;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}