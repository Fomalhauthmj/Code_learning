#include<iostream>
#include<math.h>
using namespace std;
long long p;
long long quickpow(long long a,long long n)
{
    if (n == 0)
        return 1;
    long long temp = quickpow(a, n >> 1) % p;
    if (n & 1)
        return a * temp % p * temp % p;
    else
        return temp * temp % p;
}
bool judge(long long p)
{
    int flag=0;
    for(int i=2;i<=sqrt(p);i++)  //i*i<=p 优化！！！
    {
        if(p%i==0) 
        {
            flag=1;
            break;
        }
    }
    if(flag==1) return false;
    return true;
}
int main()
{
    long long a;
    while(cin>>p>>a)
    {
        if(p==0&&a==0) break;
        if(judge(p)) 
        {
            cout<<"no"<<endl;
            continue;
        }
        else
        {
            long long res=quickpow(a,p);
            if(res==a) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
    }
}