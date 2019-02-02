#include<iostream>
using namespace std;
#define max 21
long long res[max][max]={0};
int main()
{
    for(int i=1;i<max;i++) res[i][0]=1;
    for(int i=1;i<max;i++)
    {
        for(int j=1;j<=i;j++)
        {
            res[i][j]=res[i-1][j]+res[i][j-1];
        }
    }
    int m,n;
    while(cin>>m>>n)
    {
        cout<<res[m][n]<<endl;
    }
}