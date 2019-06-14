#include<iostream>
#include<math.h>
using namespace std;
#define size 100010
long long x[size];
int n,k;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>k)
    {
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
        }
        long long ans=0x3f3f3f3f;
        int left,right;
        int temp1,temp2;
        for(int i=0;i<(n-k+1);i++)
        {
            left=i;
            right=i+k-1;
            temp1=abs(x[left])+abs(x[right]-x[left]);
            temp2=abs(x[right])+abs(x[right]-x[left]);
            if(ans>temp1) ans=temp1;
            if(ans>temp2) ans=temp2;
        }
        cout<<ans<<endl;
    }
}