#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int sum[50];
    sum[0]=0;
    for(int i=1;i<=49;i++)
    {
        sum[i]=sum[i-1]+i;
    }
    for(int i=1;i<=48;i++)
    {
        for(int j=1;j<=48;j++)
        {
            if(i==j||abs(i-j)==1) continue;
            int temp=sum[49]-i-(i+1)-j-(j+1);
            temp+=i*(i+1)+j*(j+1);
            if(temp==2015) cout<<i<<" "<<j<<endl;
        }
    }
    system("pause");//16
}