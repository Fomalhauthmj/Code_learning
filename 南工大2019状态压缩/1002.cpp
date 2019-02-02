#include<iostream>
#include<string>
using namespace std;
#define N 16
#define inf  0x3f3f3f3f
int n;
struct task
{
    string name;
    int deadline;
    int need_time;
};
task ts[16];
struct Dp
{
    int cur_task;//当前任务编号
    int cur_time;//当前时间
    int cur_val;//当前罚分
};
Dp dp[1<<16];
void print(int S)//根据状态回溯
{
    if(S==0) return;
    int temp=S-(1<<dp[S].cur_task);
    print(temp);
    cout<<ts[dp[S].cur_task].name<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ts[i].name>>ts[i].deadline>>ts[i].need_time;
        }
        for(int i=0;i<(1<<n);i++)//所有状态罚时初始化
        {
            dp[i].cur_val=inf;
        }
        dp[0].cur_val=0;//初始化
        for(int i=0;i<(1<<n);i++)
        {
            if(dp[i].cur_val!=inf)//已更新过
            {
                for(int j=0;j<n;j++)
                {
                    if(i&(1<<j)) continue;//此任务已完成
                    int temp=i|(1<<j);
                    int temp_v=dp[i].cur_time+ts[j].need_time-ts[j].deadline;
                    temp_v=max(temp_v,0);//若小于0说明可在deadline前完成 val=0;
                    if(temp_v+dp[i].cur_val<dp[temp].cur_val)
                    {
                        //更新
                        dp[temp].cur_val=temp_v+dp[i].cur_val;
                        dp[temp].cur_task=j;
                        dp[temp].cur_time=dp[i].cur_time+ts[j].need_time;
                    }
                }
            }   
        }
        cout<<dp[(1<<n)-1].cur_val<<endl;//输出完成所有任务的总罚时
        print((1<<n)-1);//回溯输出
    }
}