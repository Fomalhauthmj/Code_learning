#include<iostream>
#include<math.h>
using namespace std;
int n,m;
#define N 100010

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        if(m%n==0) cout<<m/n<<endl;//特殊情况
        else
        {
            for(int i=m/n;i>=1;i--)
            {
                if(m%i==0&&m/i>n)
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
}