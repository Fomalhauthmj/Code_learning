#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int x[n+1]={0};
        for(int i=1;i<=n;i++)  cin>>x[i];
        x[0]=100;
        int max=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(max<(x[i]-x[j])*(x[i]-x[j]))
                    max=(x[i]-x[j])*(x[i]-x[j]);
                else continue;
            }
        }
        cout<<max<<endl;
    }
}
