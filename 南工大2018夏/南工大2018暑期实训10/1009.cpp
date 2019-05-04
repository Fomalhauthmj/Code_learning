#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define size 110
int dp[size][size];
int print[size][size];
string a,b;
void printLCS(int r,int c)
{
    if(r==0&&c==0) return;
    if(print[r][c]==1)
    {
        printLCS(r-1,c-1);
        cout<<a[r-1];
    }
    else if(print[r][c]==2)
    {
        printLCS(r-1,c);
        cout<<a[r-1];
    }
    else if(print[r][c]==3)
    {
        printLCS(r,c-1);
        cout<<b[c-1];
    }
}
void LCS()
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=a.length();i++) print[i][0]=2;
    for(int i=1;i<=b.length();i++) print[0][i]=3;
    for(int i=0;i<a.length();i++)
    {
        for(int j=0;j<b.length();j++)
        {
            if(a[i]==b[j])
            {
                dp[i+1][j+1]=dp[i][j]+1;
                print[i+1][j+1]=1;
            }
            else
            {
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                if(dp[i][j+1]>=dp[i+1][j]) print[i+1][j+1]=2;
                else print[i+1][j+1]=3;
            }
        }
    }
    printLCS(a.length(),b.length());
    cout<<endl;
}
int main()
{
    while(cin>>a>>b)
    {
        LCS();
        for(int i=0;i<=a.length();i++)
        {
            for(int j=0;j<=b.length();j++)
            {
                cout<<dp[i][j];
            }
            cout<<endl;
        }
        for(int i=0;i<=a.length();i++)
        {
            for(int j=0;j<=b.length();j++)
            {
                cout<<print[i][j];
            }
            cout<<endl;
        }
    }
}






//TODO:先找出LCS 然后填上两个字符串各自两个相邻字符位置之间的字符串 TODO:未实现！
/*
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
#define size 110
int dp[size][size];
string a,b;
string res;
set<string> setofLCS;
void DFS(int i,int j,string lcs)
{
    if(!setofLCS.empty()) return;//只取1个LCS
    if(i==0||j==0)
    {
        reverse(lcs.begin(),lcs.end());
        setofLCS.insert(lcs);//根据反馈注意判断长度
        res=lcs;
        return;
    }
    if(a[i-1]==b[j-1])//针对dp[i][j]
    {
        lcs.push_back(a[i-1]);
        DFS(i-1,j-1,lcs);
    }
    else
    {
        //观察前两个来源
        if(dp[i-1][j]>dp[i][j-1]) DFS(i-1,j,lcs);
        else if(dp[i-1][j]<dp[i][j-1]) DFS(i,j-1,lcs);
        else
        {
            DFS(i-1,j,lcs);DFS(i,j-1,lcs);
        }
    }
}
void LCS()
{
    memset(dp,0,sizeof(dp));
    setofLCS.clear();
    int lena=a.length();
    int lenb=b.length();
    for(int i=0;i<lena;i++)
    {
        for(int j=0;j<lenb;j++)
        {
            if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j]+1;
            else
            {
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    DFS(lena,lenb,"");
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>a>>b)
    {
        LCS();
        //cout<<res<<endl;此时res即为LCS

    }
}
*/