#include<iostream>
#include<algorithm>
using namespace std;
#define size 200020
long long a[size];
int n;
int ans;
int res()
{
    ans=1;
    for(int i=0;i<n;i++)
    {
        //cout<<"now:"<<i<<endl;
        int j=i;
        while(j+1<n&&a[j+1]<=2*a[j]) j++;
        ans=max(ans,j-i+1);
        i=j;
        //cout<<"end:"<<i<<endl;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<res()<<endl;
    }
}