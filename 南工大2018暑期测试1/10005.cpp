#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#define size 100010
int n;
long long a[size];
long long pow2[32];
int main()
{
    for(int i=0;i<32;i++) pow2[i]=pow(2,i);
    ios::sync_with_stdio(false);
    //int t;
    //cin>>t;
    while(cin>>n)
    {
        //cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        long long num=0;
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<32;j++)
            {
                long long temp=pow2[j]-a[i];
                if(temp>0) 
                {
                    // cout<<a[i]<<" "<<pow2[j]<<" "<<temp<<endl;
                    // cout<<upper_bound(a+i+1,a+n,temp)-lower_bound(a+i+1,a+n,temp)<<endl;
                    num+=upper_bound(a+i+1,a+n,temp)-lower_bound(a+i+1,a+n,temp);//>->=
                }
                else continue;
            }
        }
        cout<<num<<endl;
    }
}
//或者用map？
// map[a[i]]++;
// ans+=map[i<<1-it->first];