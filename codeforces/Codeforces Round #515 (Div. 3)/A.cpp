#include<iostream>
using namespace std;
int L,v,l,r;
int main()
{
    ios::sync_with_stdio(false);
    int ans;
    int t;cin>>t;
    while(t--)
    {
        cin>>L>>v>>l>>r;
        ans=L/v;
        int templ=(l-1)/v;//[1,l)
        int tempr=r/v;//[1,r]
        ans-=tempr-templ;
        cout<<ans<<endl;
    }
}