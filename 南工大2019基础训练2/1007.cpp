#include<iostream>
#include<math.h>
using namespace std;
int ans[10];
bool vis[10];//1-9
int cnt;
int kinds;
bool judge()
{
    double temp=0;
    temp+=ans[1];
    temp+=1.0*ans[2]/ans[3];
    int temp1=100*ans[4]+10*ans[5]+ans[6];
    int temp2=100*ans[7]+10*ans[8]+ans[9];
    temp+=1.0*temp1/temp2;
    if(fabs(temp-10)<1e-9) return true;
    else return false;
}
void DFS(int depth)
{
    if(depth>=9)
    {
        if(judge())
        {
            kinds++;
            for(int i=1;i<=9;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=9;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ans[cnt++]=i;
            DFS(depth+1);
            cnt--;
            vis[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cnt=1;
    kinds=0;
    DFS(0);
    cout<<kinds<<endl;
    system("pause");//29
}