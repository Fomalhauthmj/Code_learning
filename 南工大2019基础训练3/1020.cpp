#include<iostream>
#include<cstring>
using namespace std;
long long a[35][35];
double b[35][35];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++) cin>>a[i][j];
    }
    b[1][1]=a[1][1];
    for(int i=2;i<=n+1;i++)
    {
        for(int j=1;j<=i;j++)
        {
            b[i][j]=b[i-1][j]/2+b[i-1][j-1]/2+a[i][j];
        }
    }
    double max_w=0;
    double min_w=1000;
    for(int i=1;i<=n+1;i++)
    {
        cout<<b[n+1][i]<<" ";
        if(max_w<b[n+1][i]) max_w=b[n+1][i];
        if(min_w>b[n+1][i]) min_w=b[n+1][i];
    }
    long long temp=2086458231;
    long long ans=temp*1.0/min_w*max_w;
    cout<<ans<<endl;
    //72665192664
    //72664965432.070616751536796926663
    system("pause");
}