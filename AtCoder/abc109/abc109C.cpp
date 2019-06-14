#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define size 100010
int n;
long long x;
long long gcd(long long a,long long b)
{
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
int main()
{
    ios::sync_with_stdio(false);
    long long number;
    long long ans;
    while(cin>>n>>x)
    {
        cin>>number;
        ans=abs(x-number);
        for(int i=1;i<n;i++) 
        {
            cin>>number;
            ans=gcd(ans,abs(x-number));
        }
        cout<<ans<<endl;
    }
}