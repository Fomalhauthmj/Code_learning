#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
long long n;
#define size 100000
int prime[size];
bool isprime[size];
int prime_num;
int main()
{
    ios::sync_with_stdio(false);
    prime_num=0;
    memset(isprime,0,sizeof(isprime));
    for(int i=2;i<size;i++)
    {
        if(isprime[i]==0)
        {
            prime[prime_num++]=i;
            for(int j=2;j*i<size;j++) isprime[i*j]=1;
        }
    }//埃氏筛法
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    
        cin>>n;
        int each_num;
        int all_num=1;
        for(int i=0;i<prime_num;i++)
        {
            if(prime[i]>sqrt(n)) break;
            each_num=0;
            while(n%prime[i]==0)
            {
                each_num++;
                n/=prime[i];
            }
            all_num*=(1+2*each_num);  //二项式 n:(1+each_num)   n^2:(1+2each_num)
        }
        if(n>1) all_num*=(1+2*1); //最后剩余的因数大于sqrt(n) 且只有一个
        cout<<"Scenario #"<<i<<":"<<endl; 
        cout<<(all_num+1)/2<<endl<<endl;  //必有一对相同的 x=y  又x<=y 重复计算了一次
    }
}
//令y=n+k 解方程 x=n^2/k + n;
//即求k的个数  