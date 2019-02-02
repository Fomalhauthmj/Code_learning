//指数型母函数?
//由于n过大 尝试寻找循环节?
//泰勒级数公式推导
//母函数fx=(1+x^1/1!+x^2/2!+x^3/3!....)^2*(1+x^2/2!+x^4/4!....)^2
//前者为BD 后者为AC
//e^x=1+x^1/1!+x^2/2!+.... e^x的麦克劳林展开
//e^(-x)=1-x^1/1!+x^2/2!-x^3/3!+....
//fx=e^2x *[(e^x+e^-x)/2]^2=>e^2x*[e^2x+e^-2x+2]/4=>(e^4x+1+2e^2x)/4
//而e^4x=1+4x^1/1!.....   x^n系数为4^n
//同理 可得 x^n系数=(4^n+2*2^n)/4=>4^n-1+2^n-1

#include<iostream>
using namespace std;
#define mod 100
long long n;
long long quick_pow(long long a,long long b)
{
    if(b==0)    return 1;
    long long temp=quick_pow(a,b>>1);
    if(b&1)    return a%mod*temp%mod*temp%mod;
    else    return temp%mod*temp%mod;//快速幂
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    while(cin>>T)
    {
        if(T==0) break;
        for(int casenum=1;casenum<=T;casenum++)
        {
            cin>>n;//长度为n    
            long long ans=quick_pow(4,n-1)+quick_pow(2,n-1);
            ans%=mod;
            cout<<"Case "<<casenum<<": "<<ans<<endl;//输出
            if(casenum==T) cout<<endl;
        }
    }
}