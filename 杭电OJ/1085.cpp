// #include<iostream>
// #include<cstring>
// using namespace std;
// #define maxn 8001
// int value[maxn];
// int temp[maxn];
// int main()
// {
//     int num[4]={0};
//     int x[4]={0,1,2,5};
//     while(cin>>num[1]>>num[2]>>num[3])
//     {
//         if(num[1]==0&&num[2]==0&&num[3]==0) break;
//         else
//         {
//             memset(value,0,sizeof(value));
//             memset(temp,0,sizeof(temp));
//             for(int i=0;i<=num[1];i++) value[i]=1;
//             for(int i=2;i<=3;i++)
//             {
//                 for(int j=0;j<=maxn;j++)
//                 {
//                     for(int k=0;k<=num[i]&&(j+k*x[i]<=maxn);k++)
//                     {
//                         temp[j+k*x[i]]+=value[j];
//                     }

//                 }
//                 for(int j=0;j<=maxn;j++)
//                 {
//                     value[j]=temp[j];
//                     temp[j]=0;
//                 }
//             }
//             for(int i=1;i<=maxn;i++)
//             {
//                 if(value[i]==0)
//                 {
//                     cout<<i<<endl;
//                     break;
//                 }
//             }
//         }
//     }
// }
#include<iostream>
#include<cstring>
using namespace std;
#define maxvalue 8001
int dp[maxvalue]={0};
int main()
{
    int x[4]={0,1,2,5};
    int num[4]={0};
    while(cin>>num[1]>>num[2]>>num[3])
    {
        if(num[1]==0&&num[2]==0&&num[3]==0) break;
        else
        {
            memset(dp,0,sizeof(dp));
            dp[0]=1;
            for(int i=1;i<=3;i++)
            {
                for(int j=maxvalue;j>=0;j--)
                {
                    for(int k=1;k<=num[i]&&(j-k*x[i]>=0);k++)
                    {
                        dp[j]+=dp[j-k*x[i]];
                    }
                }
            }
            for(int i=0;i<=maxvalue;i++)
            {
                if(dp[i]==0)
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
}