//长度为10的等差素数列，其公差最小值是多少？
#include<iostream>
#include<cstring>
using namespace std;
#define N 1000100
int prime[N];
bool check[N];
int tot;
void gPrime() //欧拉筛法
{
    memset(check,0,sizeof(check));
    tot=0;
    for(int i=2;i<N;i++)
    {
        if(!check[i])
        {
            prime[tot++]=i;
        }
        for(int j=0;j<tot;j++)
        {
            if(prime[j]*i>=N) break;
            check[prime[j]*i]=1;
            if(i%prime[j]==0) break; //最小质因子筛
        }
    }
}
bool find(int d)
{
    bool flag=false;
    for(int i=0;i<tot-10;i++)
    {
        int cnt=1;
        for(int j=1;j<10;j++)
        {
            if(prime[i]+d*j>=N) break;
            if(check[prime[i]+d*j]) break;//非素数
            else cnt++;
        }
        if(cnt==10)
        {
            flag=true;
            //cout<<prime[i]<<endl;
            break;
        }
    }
    if(flag) 
    {
        return true;
    }
    else return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(check,0,sizeof(check));
    gPrime();
    for(int i=1;i<1e6;i++)
    {
        //cout<<"cur:"<<i<<endl;
        if(find(i))
        {
            cout<<i<<endl;//210
            //break;
        }
    }
    system("pause");
}