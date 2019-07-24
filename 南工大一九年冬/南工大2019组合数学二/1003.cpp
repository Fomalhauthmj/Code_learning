//矩阵快速幂？ 通项公式？
#include<iostream>
#include<math.h>
#define N 20
using namespace std;
long long num;
double val_1;
long long log_fib(long long n)
{
    double temp_1=-0.5*log10(5.0);
    double temp_2=(n+1)*log10(val_1);
    //double temp_3 近似为0
    double temp_3=temp_1+temp_2-(long long)(temp_1+temp_2);
    double ans=pow(10.0,temp_3);
    while(ans<1000)
    {
        ans*=10;
    }
    return ans;
}
int fib[N];
void init()
{
    fib[0]=0,fib[1]=1;
    for(int i=2;i<20;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    val_1=(1+sqrt(5.0))/2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    while(cin>>num)
    {
        if(num<20)
        {
            cout<<fib[num]<<endl;
            continue;
        }
        cout<<log_fib(num-1)<<endl;
    }
}