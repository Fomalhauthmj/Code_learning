//TODO:http://poj.org/problem?id=1014
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool flag;
int v[6];
int V;
int dp[60010];
void ZeroOnePack(int weight,int value)
{
    for(int i=V;i>=weight;i--)
    {
        dp[i]=max(dp[i],dp[i-weight]+value);
        if(dp[i]==V)
        {
            flag=true;
            return;
        }
    }
    return;
}
void CompletePack(int weight,int value)
{
    for(int i=weight;i<=V;i++)
    {
        dp[i]=max(dp[i],dp[i-weight]+value);
        if(dp[i]==V)
        {
            flag=true;
            return;
        }
    }
    return;
}
void MultiplePack(int weight,int value,int amount)
{
    if(weight*amount>=V)
    {
        CompletePack(weight,value);//数量远超过V
        return;
    }
    if(flag) return;
    /* 二进制优化 */
    int k=1;
    while(k<amount)
    {
        ZeroOnePack(k*weight,k*value);
        if(flag) return;
        amount-=k;
        k*=2;
    }
    ZeroOnePack(amount*weight,amount*value);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    int total_value;
    int casenum=1;
    while(cin>>v[0]>>v[1]>>v[2]>>v[3]>>v[4]>>v[5])
    {
        total_value=0;
        for(int i=0;i<6;i++) total_value+=v[i]*(i+1);
        if(total_value==0) break;
        cout<<"Collection #"<<casenum++<<":"<<endl;
        if(total_value%2!=0)
        {
            cout<<"Can't be divided."<<endl<<endl;continue;
        }
        V=total_value/2;
        flag=false;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=6;i++)
        {
            MultiplePack(i,i,v[i-1]);
            if(flag) break;
        }
        if(flag) cout<<"Can be divided."<<endl<<endl;
        else cout<<"Can't be divided."<<endl<<endl;
    }
}






























/*//TODO:有个奇怪的优化 >=8 处 不优化TLE
#include<iostream>
#include<cstring>
using namespace std;
#define N 60010
int v[6];
int dp[6][N];
int main()
{
    ios::sync_with_stdio(false);
    int casenum=1;
    int sum_number;
    int sum_value;
    while(cin>>v[0]>>v[1]>>v[2]>>v[3]>>v[4]>>v[5])
    {
        sum_value=0;
        sum_number=0;
        for(int i=0;i<6;i++)
        {
            if(v[i]>=8)
            {
                if(v[i]%2==0) v[i]=12;
                else v[i]=11;
            }
            sum_number+=v[i];
            sum_value+=(i+1)*v[i];
        }
        if(sum_value==0||sum_number==0) break;
        cout<<"Collection #"<<casenum++<<":"<<endl;
        if(sum_value%2!=0)
        {
            cout<<"Can't be divided."<<endl<<endl;continue;
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=v[0];i++) dp[0][i]=1;
        for(int i=0;i<6;i++) dp[i][0]=1;
        for(int i=1;i<6;i++)
        {
            for(int k=0;k<=v[i];k++)
            {
                for(int j=0;j+k*(i+1)<=sum_value/2;j++)
                    dp[i][j+k*(i+1)]+=dp[i-1][j];
            }
        }
        //cout<<sum_value/2<<endl;
        //cout<<dp[5][sum_value/2]<<endl;
        if(dp[5][sum_value/2]>0) cout<<"Can be divided."<<endl<<endl;
        else cout<<"Can't be divided."<<endl<<endl;
    }
    return 0;
}
*/