#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        int n;
        cin>>n;
        int p[n+1]={0};
        for(int i=1;i<=n;i++) cin>>p[i];
        int result;
        for(int i=1;i<=n;i++)
        {
            int sum=0;
            for(int j=1;j<=n;j++)
            {
                sum+=abs(p[i]-p[j]);
            }
            if(i==1) result=sum;
            else
            {
                if(sum<result) result=sum;
            }
        }
        cout<<result<<endl;
    }


}
