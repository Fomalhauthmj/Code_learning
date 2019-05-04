#include<bits/stdc++.h>
using namespace std;
int main()
{
    int dp[251][101]={0};
    dp[0][0]=1;
    int x[6]={0,1,5,10,25,50};
    for(int i=1;i<=5;i++)
    {
        for(int j=x[i];j<=250;j++)
        {
            for(int k=1;k<=100;k++)
                dp[j][k]+=dp[j-x[i]][k-1];
        }
    }
    int n;
    while(cin>>n)
    {
        int result=0;
        for(int i=0;i<=100;i++) result+=dp[n][i];
        cout<<result<<endl;
    }
}
//int main()
//{
//    int value[251][101];
//    int temp[251][101];
//    int x[6]={0,1,5,10,25,50};
//    memset(value,0,sizeof(value));
//    memset(temp,0,sizeof(temp));
//    for(int i=0;i<=100;i++) value[i][i]=1;
//    for(int i=2;i<=5;i++)
//    {
//        for(int j=0;j<=250;j++)
//        {
//            for(int k=0;j+k<=250;k+=x[i])
//            {
//                for(int l=0;l+k/x[i]<=100;l++)
//                    temp[j+k][l+k/x[i]]+=value[j][l];
//            }
//        }
//        for(int k=0;k<=250;k++)
//        {
//            for(int l=0;l<=100;l++)
//            {
//                value[k][l]=temp[k][l];
//                temp[k][l]=0;
//            }
//        }
//    }
//    int n;
//    while(cin>>n)
//    {
//        int result=0;
//        for(int i=0;i<=100;i++) result+=value[n][i];
//        cout<<result<<endl;
//    }
//
//}
