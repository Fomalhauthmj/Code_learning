#include<iostream>
using namespace std;
#define N 32
long long C[N*2][N*2];
long long h[N];
void init()
{
    C[0][0]=1;
    for(int i=1;i<2*N;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
        {
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    h[0]=1;
    for(int i=1;i<N;i++)
    {
        h[i]=C[2*i][i]-C[2*i][i+1];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    init();
    while(cin>>n)
    {
        if(n==0) break;
        else cout<<h[n]<<endl;//W入栈  H出栈  卡特兰数的应用
    }
}