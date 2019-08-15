#include<iostream>
using namespace std;
const int MOD=1e6+3;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n)
    {
        if(n>=MOD) cout<<0<<endl;
        else
        {
            ll ans=1;
            for(int i=2;i<=n;i++)
                ans=ans*i%MOD;
            cout<<ans<<endl;
        }
    }
    //system("pause");
    return 0;
}