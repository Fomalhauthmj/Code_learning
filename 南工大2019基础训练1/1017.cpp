#include<iostream>
#include<math.h>
using namespace std;
bool vis[10];
int ans[10];
int cnt;
bool judge()
{
    for(int i=0;i<10;i++)
    {
        //枚举分割点
        long long num2=0;
        long long num3=0;
        for(int j=0;j<=i;j++)
        {
            num2=num2*10+ans[j];
        }
        for(int j=i+1;j<10;j++)
        {
            num3=num3*10+ans[j];
        }
        if(fabs(pow(num2,0.5)-pow(num3,1.0/3))<1e-6) 
        {
            cout<<num2<<" "<<num3<<endl;
            return true;
        }
    }
    return false;
}
void DFS(int depth)
{
    if(depth>=10)
    {
        if(judge())
        {
            cout<<"find!"<<endl;
            for(int i=0;i<10;i++)
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
    DFS(0);
    system("pause");
    //4761 328509 69
}