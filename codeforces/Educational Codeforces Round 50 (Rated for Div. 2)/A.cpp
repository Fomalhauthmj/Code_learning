#include<iostream>
using namespace std;
long long n,k;
int main()
{
    ios::sync_with_stdio(false);
    long long ans;
    while(cin>>n>>k)
    {
        if(n>=k) cout<<1<<endl;
        else
        {
            ans=0;
            ans+=k/n;
            ans+=(k%n==0)?0:1;
            cout<<ans<<endl;
        }
    }
}