#include<iostream>
using namespace std;
#define mod 998244353
//斐波那契数列的矩阵化
//fn+1   =   1 1    fn  =   1 1 ^ (n-1)   f2 
//fn         1 0    fn-1    1 0           f1
//fn+1=ret.a11+ret.a12;
//ret=1 1  ^ (n-1)
//    1 0
struct matrix
{
    long long a11,a12,a21,a22;
};
matrix M={1,1,1,0};
matrix mulM(matrix m1,matrix m2)
{
    matrix ret;
    ret.a11=(m1.a11*m2.a11%mod+m1.a12*m2.a21%mod)%mod;
    ret.a12=(m1.a11*m2.a12%mod+m1.a12*m2.a22%mod)%mod;
    ret.a21=(m1.a21*m2.a11%mod+m1.a22*m2.a21%mod)%mod;
    ret.a22=(m1.a21*m2.a12%mod+m1.a22*m2.a22%mod)%mod;
    return ret;
}
matrix powM(matrix m,long long n)
{
    if(n==1) return m;
    matrix temp;
    temp=powM(m,n>>1);
    if(n&1) return mulM(m,mulM(temp,temp));
    else return mulM(temp,temp);
}
int main()
{
    ios::sync_with_stdio(false);
    long long k;
    while(cin>>k)
    {
        matrix res=powM(M,2*k+1);
        long long ans=(res.a11+res.a12)%mod;
        cout<<(ans-1)%mod<<endl;
    }
}
