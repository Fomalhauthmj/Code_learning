#include<iostream>
using namespace std;
int main()
{
    long long dp[37][37]={0};
    for(int i=0;i<=35;i++) dp[i][0]=1;
    for(int i=1;i<=35;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i!=j) dp[i][j]=dp[i-1][j]+dp[i][j-1];
            else dp[i][i]=dp[i][i-1];
        }
    }
    int i=1;
    int n;
    while(cin>>n)
    {
        if(n==-1) break;
        else cout<<i++<<" "<<n<<" "<<2*dp[n][n]<<endl;
    }
}
//int main()
//{
//    long long res[36]={0};
//    res[0]=1;
//    res[1]=1;
//    for(int i=2;i<=35;i++)
//    {
//       for(int j=0;j<=i-1;j++)
//        res[i]+=res[j]*res[i-1-j];
//    }
//    int i=1;
//    int n;
//    while(cin>>n)
//    {
//        if(n==-1) break;
//        else cout<<i++<<" "<<n<<" "<<2*res[n]<<endl;
//    }
//}
