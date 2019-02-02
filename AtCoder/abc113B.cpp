#include<iostream>
#include<math.h>
using namespace std;
#define N 1010
#define inf 0x3f3f3f3f
int n;
double a,t;
double h[N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>t>>a)
    {
        double temp;
        int ans=1;
        double min_abs=inf;
        for(int i=1;i<=n;i++)
        {
            cin>>temp;
            h[i]=fabs(t-temp*0.006-a);
            //cout<<h[i]<<endl;
            if(h[i]<min_abs)
            {
                ans=i;
                min_abs=h[i];
            }
        }
        cout<<ans<<endl;
    }
}