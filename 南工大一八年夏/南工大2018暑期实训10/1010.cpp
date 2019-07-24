#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define size 1010
string a,b,c;
bool dp[size][size];
//!:dp[i][j]= (dp[i-1][j]&&(a[i]==c[i+j]))||(dp[i][j-1]&&(b[j]==c[i+j]))  a的前i位b的前j位
//如果A、B可以组成C，那么，C最后一个字母，必定是 A 或 B 的最后一个字母组成。
//C去除除最后一位，就变成是否可以求出 A-1和B 或者 A与B-1 与 是否可以构成 C-1
int main()
{
    ios::sync_with_stdio(false);
    int t;
    while(cin>>t)
    {
        for(int casenum=1;casenum<=t;casenum++)
        {
            cin>>a>>b>>c;
            for(int i=0;i<a.length();i++)
            {
                if(a[i]==c[i]) dp[i+1][0]=1;
                else dp[i+1][0]=0;
            }
            for(int i=0;i<b.length();i++)
            {
                if(b[i]==c[i]) dp[0][i+1]=1;
                else dp[0][i+1]=0;
            }
            for(int i=0;i<a.length();i++)
            {
                for(int j=0;j<b.length();j++)
                {
                    if((dp[i][j+1]&&a[i]==c[i+j+1])||(dp[i+1][j]&&b[j]==c[i+j+1])) dp[i+1][j+1]=1;
                    else dp[i+1][j+1]=0;
                }
            }
            if(dp[a.length()][b.length()]) cout<<"Data set "<<casenum<<": yes"<<endl;
            else cout<<"Data set "<<casenum<<": no"<<endl;
        }
    }
}