#include<iostream>
using namespace std;
#define N 200010
long long a[N];
int n;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        //检查初始是否满足
        bool flag=true;
        long long pre;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(flag)
            {
                if(i==1) 
                {
                    pre=a[i];
                }
                else if(pre!=a[i])
                {
                    flag=false;
                }
            }
        }
        if(flag)
        {
            cout<<"YES"<<endl;
            continue;
        }
        //
    }
}