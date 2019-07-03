#include<iostream>
using namespace std;
#define ll long long
#define eps 1e-6
const ll N=1e5+50;
int n,l;
double a[N];
double d[N];
double sum[N];
bool judge(double mid)
{
    for(int i=0;i<n;i++)
    {
        d[i]=a[i]-mid;
    }
    for(int i=0;i<n;i++)
    {
        if(i) sum[i]=sum[i-1]+d[i];
        else sum[i]=d[i];
    }
    double ans=sum[l-1];
    double min_val=1e10;
    for(int i=l-1;i<n;i++)
    {
        if(i-l>=0) min_val=min(min_val,sum[i-l]);
        else min_val=min(min_val,0.0);
        //0参与比较 即为所有数都选择 针对最后一个样例
        if(i!=l-1) ans=max(ans,sum[i]-min_val);
    }
    return ans>=0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>l;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    double left=-1e6;
    double right=1e6;
    double mid;
    while(right-left>eps)
    {
        mid=(left+right)/2;
        if(judge(mid))  left=mid;
        else right=mid;
    }
    cout<<(ll)(right*1000)<<endl;
    //system("pause");
    return 0;
}