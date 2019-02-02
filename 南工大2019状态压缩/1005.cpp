#include<iostream>
#include<string>
using namespace std;
#define inf 0x3f3f3f3f
#define N 17
int dp[1<<N];
int len;//给定字符串长度
int cnt;
string S;//初始字符串
int Palindrome[1<<N];//存储满足回文的状态
bool is_palindrome(int str)
{
    int temp[20];
    int t_cnt=0;
    for(int i=0;i<len;i++)
    {
        if(str&(1<<i))//模式里含有此字符
        {
            temp[t_cnt++]=S[i];
        }
    }
    //判断该状态是否满足回文
    int left=0;
    int right=t_cnt-1;
    while(left<=right)
    {
        if(temp[left]!=temp[right]) return false;
        left++;
        right--;
    }
    /*
    for(int i=0;i<t_cnt;i++)
    {
        cout<<(char)temp[i];
    }
    cout<<endl;
    */
    return true;
}
int Dp(int str)
{
    if(dp[str]<inf) return dp[str];//记忆化搜索 此状态已搜索过 直接返回
    for(int i=0;i<cnt;i++)
    {
        if((Palindrome[i]&str)==Palindrome[i])//满足可删除  若空串满足回文条件 0==0 恒成立 一直递归 Dp(str)
        {
            dp[str]=min(dp[str],Dp(str-Palindrome[i]));//取最小次数
        }
    }
    dp[str]++;//做一次删除
    return dp[str];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //状态压缩 记忆化搜索
    int t;cin>>t;
    while(t--)
    {
        cin>>S;//读入字符串
        len=S.length();
        //预处理 确定每个状态是否含回文
        cnt=0;
        for(int i=1;i<(1<<len);i++)//注意i=0 也就是空串 这里不认为满足回文条件 否则运行报错
        {
            if(is_palindrome(i)) Palindrome[cnt++]=i;
        }
        //deal and output
        for(int i=0;i<(1<<len);i++) dp[i]=inf;
        dp[0]=0;//已删除完毕 需要次数为0
        cout<<Dp((1<<len)-1)<<endl;
    }
}