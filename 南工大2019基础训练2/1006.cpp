#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
bool vis[10];
int ans[10];
int cnt;
int kinds;
bool judge()
{
    for(int i=0;i<4;i++)
    {
        //枚举分割点
        long long num2=0;
        long long num3=0;
        for(int j=0;j<=i;j++)
        {
            num2=num2*10+ans[j];
        }
        for(int j=i+1;j<4;j++)
        {
            num3=num3*10+ans[j];
        }
        long long ret=num2*num3;
        vector<int> v1;
        vector<int> v2;
        while(ret/10)
        {
            v2.push_back(ret%10);
            ret/=10;
        }
        v2.push_back(ret%10);
        for(int j=0;j<4;j++) v1.push_back(ans[j]);
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int temp_cnt=0;
        for(int j=0;j<4;j++)
        {
            if(v1[j]!=v2[j]) break;
            else temp_cnt++;
        }
        if(temp_cnt==4) return true;
    }
    return false;
}
void DFS(int depth)
{
    if(depth>=4)
    {
        if(judge())
        {
            kinds++;
            for(int i=0;i<4;i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int i=0;i<10;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ans[cnt++]=i;
            DFS(depth+1);
            vis[i]=0;
            cnt--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cnt=0;
    kinds=0;
    memset(vis,0,sizeof(vis));
    DFS(0);
    cout<<kinds<<endl;
    system("pause");//24/2
    //如果满足乘法交换律的算式算作同一种情况，
}