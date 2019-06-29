#include<iostream>
using namespace std;
#define ll long long
//积性函数
ll Solve(ll n)
{
    ll ans=1;
    ll temp;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            temp=i;
            while(n%i==0)
            {
                temp*=i;
                n/=i;
            }
            ans*=(temp-1)/(i-1);
        }
    }
    if(n>1) ans*=(n+1);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    cout<<Solve(n)-1-n<<endl;
    //system("pause");
    return 0;
}