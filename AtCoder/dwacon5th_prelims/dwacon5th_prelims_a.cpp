#include<iostream>
#include<math.h>
using namespace std;
#define N 105
int sum;
int n;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        double avg=sum*1.0/n;
        double min_diff=100;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            double temp=fabs(avg-a[i]);
            if(min_diff>temp)
            {
                ans=i;
                min_diff=temp;
            }
        }
        cout<<ans<<endl;
    }
}