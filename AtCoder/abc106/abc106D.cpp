#include<iostream>
#include<cstring>
using namespace std;
#define size 505
//动态规划 暂时无法理解
int n,m,q;
int a[size][size];
int main()
{
    ios::sync_with_stdio(false);
    int q1,q2;
    while(cin>>n>>m>>q)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<m;i++) 
        {
            cin>>q1>>q2;
            a[q1][q2]++;
        }
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++) 
            {
                a[i][j]+=a[i][j-1];
                a[i][j]+=a[i-1][j];
                a[i][j]-=a[i-1][j-1];
            }
        }
        for(int i=0;i<q;i++)
        {
            cin>>q1>>q2;
            cout<<a[q1][q2]<<endl;
        }
    }
}