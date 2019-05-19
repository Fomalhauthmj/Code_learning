#include<iostream>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<math.h>
using namespace std;
#define N 500010
double a[N];
double b[N];
long long n,s;
void print()
{
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>s)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        double e=1.0*s/n;
        memset(b,0,sizeof(b));
        sort(a+1,a+n+1);
        int ptr=1;
        double need_pay=s;
        while(need_pay>0)
        {
            int r_p=n-ptr;//剩余人数
            if(a[ptr]>e)
            {
                need_pay-=(r_p+1)*e;
                for(int i=ptr;i<=n;i++) 
                {
                    a[i]-=e;
                    b[i]+=e;
                }
                e=1.0*need_pay/(r_p+1);
                //cout<<endl<<" avg:"<<e<<" need_pay:"<<need_pay<<endl;
            }
            else
            {
                int temp=a[ptr];
                need_pay-=(r_p+1)*a[ptr];
                for(int i=ptr;i<=n;i++) 
                {
                    a[i]-=temp;
                    b[i]+=temp;
                    //a[i]-=a[ptr];!:这种写法是错误的 因为会对ptr值造成修改 i=ptr a[ptr]=0;
                    //b[i]+=a[ptr];
                }
                //更新e
                e=1.0*need_pay/r_p;
                ptr++;
                //cout<<endl<<" avg:"<<e<<" need_pay:"<<need_pay<<endl;
            }
        }
        double ans=0;
        for(int i=1;i<=n;i++) ans+=b[i]*b[i];
        ans/=n;
        double temp=1.0*s*s/n/n;
        //cout<<temp<<endl;
        cout<<fixed<<setprecision(4)<<sqrt(ans-temp)<<endl;
    }
}