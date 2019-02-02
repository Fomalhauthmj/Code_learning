#include<iostream>
using namespace std;
int a,b,k;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>a>>b>>k)
    {
        for(int i=1;i<=k;i++)
        {
            if(i%2!=0)
            {
                if(a%2!=0)
                {
                    a-=1;
                }
                a/=2;
                b+=a;
            }
            else
            {
                if(b%2!=0)
                {
                    b-=1;
                }
                b/=2;
                a+=b;
            }
        }
        cout<<a<<" "<<b<<endl;
    }
}