#include<iostream>
using namespace std;
#define max 33000
int dp[max];
int unit[3]={1,2,3};
int main()
{
    dp[0]=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<max;j++)
        {
            dp[j]+=dp[j-unit[i]];
        }
    }
    int n;
    while(cin>>n)
    {
        cout<<dp[n]<<endl;
    }
}



























// #include<iostream>
// #include<cstring>
// using namespace std;
// #define max 33000
// int value[max];
// int temp[max];
// int unit[3]={1,2,3};
// int main()
// {
//     memset(value,0,sizeof(value));
//     memset(temp,0,sizeof(temp));
//     for(int i=0;i<max;i++) value[i]=1;
//     for(int i=1;i<=2;i++)
//     {
//         for(int j=0;j<max;j++)
//         {
//             for(int k=0;k*unit[i]+j<max;k++)
//             {
//                 temp[k*unit[i]+j]+=value[j];
//             }
//         }
//         for(int j=0;j<max;j++)
//         {
//             value[j]=temp[j];
//             temp[j]=0;
//         }
//     }
//     int n;
//     while(cin>>n)
//     {
//         cout<<value[n]<<endl;
//     }
// }