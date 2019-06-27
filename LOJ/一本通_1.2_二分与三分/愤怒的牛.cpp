#include <iostream>
#include<algorithm>
using namespace std;
#define ll long long
const int N = 1E5 + 50;
ll n, m;
ll x[N];
bool judge(int mid)
{
    ll temp=m-1;
    ll key=x[0]+mid;
    while(temp>0)
    {
        int pos=lower_bound(x,x+n,key)-x;
        //cout<<"pos:"<<pos<<endl;
        if(pos>=n||pos<=0) return false;
        key=x[pos]+mid;
        temp--;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    sort(x,x+n);
    ll left,mid,right;
    ll ans;
    left=1;
    right=1e10+50;
    while(left<right)
    {
        mid=(left+right)>>1;
        //cout<<"cur:"<<mid<<endl;
        if(judge(mid))
        {
            ans=mid;
            left=mid+1;
        }
        else
        {
            right=mid;
        }
        
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}