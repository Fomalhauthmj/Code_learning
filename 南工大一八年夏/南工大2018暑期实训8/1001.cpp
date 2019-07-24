//中国剩余定理
#include<iostream>
using namespace std;
long long inv(long long a,long long m)
{
    return a==1?1:((m-m/a)*inv(m%a,m))%m;
}
int b[]={2,3,2};
int m[]={3,5,7};
int n;
long long Chinese_Remainder(int b[],int m[],int n)
{
    long long ret=0;
    long long M=1;
    for(int i=1;i<=n;i++)
    {
        M*=m[i];
    }
    for(int i=1;i<=n;i++)
    {
        int temp=M/m[i];
        ret=((ret+b[i]*temp*inv(temp,m[i]))%M+M)%M;//确保正数
    }
}
int main()
{
    while(cin>>n)
    {
        cout<<Chinese_Remainder(b,m,n)<<endl;
    }
}
