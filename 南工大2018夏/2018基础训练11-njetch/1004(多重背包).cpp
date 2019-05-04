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
    for(int i=V;i>=weight;i--)//0-1逆序
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
    for(int i=weight;i<=V;i++)//完全正序
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
    if(weight*amount>=V)//如果当前的种类的数量远超V 视为完全背包
    {
        CompletePack(weight,value);
        return;
    }
    if(flag) return;
    //否则 二进制转换为O-1背包
    //二进制优化 
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
        V=total_value/2;//目标划分值
        flag=false;
        memset(dp,0,sizeof(dp));//init初始化 要求获得价值尽可能大
        for(int i=1;i<=6;i++)//分别使用前i种
        {
            MultiplePack(i,i,v[i-1]);//多重背包
            if(flag) break;
        }
        if(flag) cout<<"Can be divided."<<endl<<endl;
        else cout<<"Can't be divided."<<endl<<endl;
    }
}
