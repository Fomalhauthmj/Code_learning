#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int m;
        cin>>m;
        int num[m]={0};
        int res=1;
        for(int i=0;i<m;i++) 
        {
            cin>>num[i];
            res=res/gcd(num[i],res)*num[i];
        }
        cout<<res<<endl;
    }
}