#include<iostream>
#include<math.h>
using namespace std;
//1-10^9
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    long long n;
    long long sum;
    while(t--)
    {   
        cin>>n;
        sum=(1+n)*n/2;
        long long num;
        for(int pos=0;;pos++)
        {
            num=pow(2,pos);
            if(num>n) break;
            else
            {
                sum-=2*num;
            }
        }
        cout<<sum<<endl;
    }
}