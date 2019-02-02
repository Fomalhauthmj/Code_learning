#include<iostream>
#include<algorithm>
using namespace std;
#define N 15
int p[N];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        int max_p=0;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
            ans+=p[i];
            max_p=max(max_p,p[i]);
        }
        cout<<ans-max_p/2<<endl;
    }
}