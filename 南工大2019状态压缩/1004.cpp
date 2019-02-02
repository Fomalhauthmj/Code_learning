#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    long long ans;
    long long n;
    while(t--)
    {
        cin>>n;
        ans=-1;
        long long temp;
        if(n%3==0)
        {
            temp=n/3*n/3*n/3;
            if(temp>ans) ans=temp;
        }
        if(n%4==0)
        {
            temp=n/4*n/2*n/4;
            if(temp>ans) ans=temp;
        }
        cout<<ans<<endl;
    }
}