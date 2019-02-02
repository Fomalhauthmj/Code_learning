#include<iostream>
#include<math.h>
using namespace std;
int resa[1005]={0};
int resb[1005]={0};
int resc[1005]={0};
int main()
{
    resa[1]=0;
    resb[1]=1;
    resc[1]=1;
    for(int i=2;i<=1000;i++)
    {
        resa[i]=(resb[i-1]+resc[i-1])%10000;
        resb[i]=(resa[i-1]+resc[i-1])%10000;
        resc[i]=(resa[i-1]+resb[i-1])%10000;
    }
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        else
        {
            if(n==1) cout<<0<<endl;
            else cout<<resa[n]<<endl;
        }
    }
}