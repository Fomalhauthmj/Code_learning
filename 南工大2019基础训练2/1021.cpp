#include<iostream>
#include<math.h>
using namespace std;
bool vis[10];
int ans[10];
int kinds=0;
int cnt=0;
bool legal()
{
    if(abs(ans[0]-ans[1])==1) return false;
    if(abs(ans[0]-ans[3])==1) return false;
    if(abs(ans[0]-ans[4])==1) return false;
    if(abs(ans[0]-ans[5])==1) return false;
    if(abs(ans[1]-ans[2])==1) return false;
    if(abs(ans[1]-ans[4])==1) return false;
    if(abs(ans[1]-ans[5])==1) return false;
    if(abs(ans[1]-ans[6])==1) return false;
    if(abs(ans[2]-ans[5])==1) return false;
    if(abs(ans[2]-ans[6])==1) return false;
    if(abs(ans[3]-ans[4])==1) return false;
    if(abs(ans[3]-ans[7])==1) return false;
    if(abs(ans[3]-ans[8])==1) return false;
    if(abs(ans[4]-ans[5])==1) return false;
    if(abs(ans[4]-ans[7])==1) return false;
    if(abs(ans[4]-ans[8])==1) return false;
    if(abs(ans[4]-ans[9])==1) return false;
    if(abs(ans[5]-ans[6])==1) return false;
    if(abs(ans[5]-ans[8])==1) return false;
    if(abs(ans[5]-ans[9])==1) return false;
    if(abs(ans[6]-ans[9])==1) return false;
    if(abs(ans[7]-ans[8])==1) return false;
    if(abs(ans[8]-ans[9])==1) return false;
    return true;
}
void DFS(int step)
{
    if(step>=10)
    {
        if(legal()) kinds++;
        return;
    }
    for(int i=0;i<10;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ans[cnt++]=i;
            DFS(step+1);
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
    cout<<kinds<<endl;//1580
    system("pause");
}