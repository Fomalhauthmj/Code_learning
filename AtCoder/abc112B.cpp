#include<iostream>
using namespace std;
#define inf 0x3f3f3f3f
int main()
{
    int n,T;
    ios::sync_with_stdio(false);
    bool flag;
    int c,t;
    int ans;
    while(cin>>n>>T)
    {
        ans=inf;
        flag=false;
        for(int i=1;i<=n;i++)
        {
            cin>>c>>t;
            if(t<=T) 
            {
                flag=true;
                ans=min(ans,c);
            }
        }
        if(flag) cout<<ans<<endl;
        else cout<<"TLE"<<endl;
    }
}