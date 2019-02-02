#include<iostream>
using namespace std;
int C(int a,int b)
{
    if(b==0) return 1;
    int res1=1;
    int res2=1;
    for(int i=a;i>=a-b+1;i--) res1*=i;
    for(int i=1;i<=b;i++) res2*=i;
    return res1/res2;
}
int step(int n)
{
    if(n==0) return 1;
    int res=1;
    for(int i=1;i<=n;i++) res*=i;
    return res;
}
int result(int m,int n)
{
    return step(m)*step(n)*(C(m+n,m)-C(m+n,m+1));
}
int main()
{
    int m,n;
    int num=1;
    while(cin>>m>>n)
    {
        if(m==0&&n==0) break;
        else
        {
            cout<<"Test #"<<num++<<":"<<endl;
            cout<<result(m,n)<<endl;
        }
    }

}