#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int sum[100];
    sum[0]=0;
    for(int i=1;i<=100;i++)
    {
        sum[i]=sum[i-1]+i;
    }
    for(int i=0;i<100;i++)
    {
        for(int j=i+1;j<100;j++)
        {
            if(sum[j]-sum[i]==236)
            {
                cout<<sum[i]<<" "<<sum[j]<<endl;
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    system("pause");
    //ans=26
}