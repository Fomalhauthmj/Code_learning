#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
bool vis[21];
int ans[5];
int cnt=0;
bool legal()
{
    double temp=1.0/ans[0]+1.0/ans[1]+1.0/ans[2]+1.0/ans[3];
    if(fabs(temp-1)<=1e-6) return true;
    else return false;
}
void DFS(int step,int pre)
{
    if(step>=4)
    {
        if(legal())
        {
            for(int i=0;i<5;i++)
            {
                if(i!=4) cout<<ans[i]<<",";
                else cout<<ans[i]<<endl;
            }
        }
        return;
    }
    for(int i=1;i<=21;i++)
    {
        if(!vis[i]&&i<pre)
        {
            vis[i]=1;
            ans[cnt++]=i;
            DFS(step+1,i);
            cnt--;
            vis[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ans[4]=0;
    cnt=0;
    memset(vis,0,sizeof(vis));
    DFS(0,0x3f3f3f3f);
    system("pause");
    /*
    cout<<"12,6,4,2,0"<<endl;
cout<<"15,10,3,2,0"<<endl;
cout<<"18,9,3,2,0"<<endl;
cout<<"20,5,4,2,0";
    */

}