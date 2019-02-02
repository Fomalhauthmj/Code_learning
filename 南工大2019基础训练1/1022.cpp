#include<iostream>
using namespace std;
int ans;
void DFS(int step,int cur)
{
    if(step>39) return;
    if(step==39)
    {
        if(cur&1) return;
        else ans++;
        return;
    }
    DFS(step+1,cur+1);
    DFS(step+2,cur+1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ans=0;
    DFS(0,0);
    cout<<ans<<endl;
    system("pause");//51167078
}