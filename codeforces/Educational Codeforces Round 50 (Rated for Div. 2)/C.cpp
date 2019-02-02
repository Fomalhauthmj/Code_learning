#include<iostream>
#include<string>
using namespace std;
long long l,r;
int t;
long long ans;
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    string ls,rs;
    while(t--)
    {
        ans=0;
        cin>>l>>r;
        ls=to_string(l);
        rs=to_string(r);
        for(int i=ls.length()+1;i<=rs.length()-1;i++)
        {
            ans+=9+81*(i-1)+729*(i-1)*(i-2)/2;
        }
        for(long long lnum=l;lnum<=)
    }
}