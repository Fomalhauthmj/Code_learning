#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x[27];
    int value[51];
    int temp[51];

    while(n--)
    {
        memset(value,0,sizeof(value));
        memset(temp,0,sizeof(temp));
        for(int i=1;i<=26;i++) cin>>x[i];
        for(int i=0;i<=50&&i<=x[1];i++) value[i]=1;
        for(int i=2;i<=26;i++)
        {
            for(int j=0;j<=50;j++)
            {
                for(int k=0;k+j<=50&&k<=x[i]*i;k+=i)
                {
                    temp[k+j]+=value[j];
                }
            }
            for(int l=1;l<=50;l++)
            {
                value[l]=temp[l];
                temp[l]=0;
            }
        }
        int result=0;
        for(int i=1;i<=50;i++) result+=value[i];
        cout<<result<<endl;
    }
}
