#include<iostream>
#include<cstring>
using namespace std;
#define N 30
int n;
long long res[N/2];//res[i]表示n个元素错排的的方案数
long long C[N][N];//组合数
void init()
{
    res[1]=0;
    res[2]=1;
    for(int i=3;i<N/2;i++)
    {
        res[i]=(i-1)*(res[i-1]+res[i-2]);
    }
    memset(C,0,sizeof(C));
    C[0][0]=1;
    for(int i=1;i<N;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
        {
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    while(cin>>n)
    {
        //求错排方案数  答对一半或以上 错排元素数<=1/2*n 总方案数累加和
        if(n==0) break;
        long long ans=1;//全部猜对
        for(int i=1;i<=n/2;i++)
        {
            ans+=C[n][i]*res[i];//i为错排数量
        }
        cout<<ans<<endl;
    }
}
