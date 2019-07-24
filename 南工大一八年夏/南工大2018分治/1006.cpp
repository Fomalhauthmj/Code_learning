#include<iostream>
using namespace std;
long long quickpow(long long a,long long b,long long mod)
{
    if(b==0) return 0;
    long long ret=1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
int main()
{
    int t;
    cin>>t;
    int casenum=1;
    long long x,m,k,c;
    while(t--)
    {
        cin>>x>>m>>k>>c;
        // int mod=9*k;
        cout<<"Case #"<<casenum++<<":"<<endl;
        // long long res=quickpow(10,m,mod);
        // if((res-1)*x%mod==9*c) cout<<"Yes"<<endl;
        // else cout<<"No"<<endl;
        
        int mod=9*k;
        long long res=(quickpow(10,m,mod)-1)*x%mod/9;
        if(res==c) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        //逆元？
    }
}






















// #include<iostream>
// using namespace std;
// //return a^n
// int t,x,k,c;
// long long m;
// long long quickpow(long long a,long long n,int mod)
// {
//     long long ret=1;
//     while(n)
//     {
//         if(n&1) ret=ret*a%mod;
//         a=a*a%mod;
//         n>>=1;
//     }
//     return ret;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin>>t;
//     int casenum=1;
//     while(t--)
//     {
//         cin>>x>>m>>k>>c;
//         int mod=9*k;
//         long long ans=quickpow(10,m,mod);
//         cout<<"Case #"<<casenum++<<":"<<endl;
//         if((ans-1)*x%mod==9*c) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//     }
// }