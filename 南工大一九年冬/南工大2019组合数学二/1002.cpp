#include<iostream>
using namespace std;
#define N 25
int n;
long long f[N];
void init()
{
    f[0]=f[1]=1;
    for(int i=2;i<N;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
}
//!:对于每头刚出生的小猪，在他生下第二头小猪后立马被杀掉，卖到超市里=>f[i]只收到前两天的影响
//假设在创业的第一天，0068只买了一头刚出生的小猪 f[1]=1=f[0];
//他养的猪一出生第二天开始就能每天中午生一只小猪，而且生下来的竟然都是母猪。
//在第N天晚上，0068的养猪场里还存有多少头猪？   f[i]=f[i-1]+f[i-2] 前一天出生的+前两天出生的
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    init();
    while(T--)
    {
        cin>>n;
        cout<<f[n]<<endl;
    }
}