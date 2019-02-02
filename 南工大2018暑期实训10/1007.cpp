#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define size 100010
int n,k;
int a[size];
int low[size];
bool LIS()
{
    int ans=1;
    memset(low,0,sizeof(low));
    low[1]=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>low[ans])
        {
            low[++ans]=a[i];
        }
        else
        {
            int pos=lower_bound(low+1,low+ans+1,a[i])-low;
            low[pos]=a[i];
        }
    }
    //cout<<ans<<endl;
    if(ans+k>=n) return true; //注意这里要>=   ==：WA
    else return false;//ans+k<n false 非单调
}
int main()
{
    ios::sync_with_stdio(false);
    int t;cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>a[i];
        if(LIS()==true) cout<<"A is a magic array."<<endl;
        else 
        {
            reverse(a,a+n);
            if(LIS()==true) cout<<"A is a magic array."<<endl;
            else cout<<"A is not a magic array."<<endl;
        }
    }
}