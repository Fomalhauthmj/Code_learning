#include<iostream>
using namespace std;
bool vis[10];
int ans[10];
int cnt=1;
int kinds=0;
bool judge()
{
    int temp1=100*ans[1]+10*ans[2]+ans[3];
    int temp2=100*ans[4]+10*ans[5]+ans[6];
    int temp3=100*ans[7]+10*ans[8]+ans[9];
    if(temp1+temp2==temp3) return true;
    else return false;
}
void DFS(int d)
{
    if(d>=9)
    {
        if(judge())
        {
            for(int i=1;i<=9;i++) cout<<ans[i]<<" ";
            cout<<endl;
            kinds++;
        }
        return;
    }
    for(int i=1;i<=9;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ans[cnt++]=i;
            DFS(d+1);
            cnt--;
            vis[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    DFS(0);
    cout<<kinds<<endl;//336
    system("pause");
}