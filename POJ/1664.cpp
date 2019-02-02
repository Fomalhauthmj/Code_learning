#include<iostream>
#include<cstring>
using namespace std;
int res(int m,int n)
{
    if(m<0) return 0;
    if(m==0||n==1) return 1;
    return res(m-n,n)+res(m,n-1);
}
int main()
{
   
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        cout<<res(m,n)<<endl;
    }
}