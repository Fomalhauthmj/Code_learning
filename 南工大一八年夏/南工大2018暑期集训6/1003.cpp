//--RR= -RRR+-BRR
//--RB= -RRB+
//--BR= -RBR+
//       RR RB  BR  
//-RR==  1  0   1   RR    N= M^N-2    2阶
//-RB    1  0   0   RB
//-BR    0  1   0   BR
#include<iostream>
#include<cstring>
using namespace std;
#define mod 1000000007
struct matrix
{
    long long a[3][3];
};
matrix Ma;
matrix mulM(matrix m1,matrix m2)
{
    matrix res;
    memset(res.a,0,sizeof(res.a));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                res.a[i][j]=(res.a[i][j]+m1.a[i][k]*m2.a[k][j])%mod;
            }
        }
    }
    return res;
}
matrix quickM(matrix m,long long n)
{
    matrix res;
    memset(res.a,0,sizeof(res.a));
    res.a[0][0]=res.a[1][1]=res.a[2][2]=1;
    while(n)
    {
        if(n&1) res=mulM(res,m);
        m=mulM(m,m);
        n>>=1;
    }
    return res;
}
long long n;//!!!!!!!!!!!注意long long
int main()
{
    memset(Ma.a,0,sizeof(Ma.a));
    Ma.a[0][0]=Ma.a[0][2]=Ma.a[1][0]=Ma.a[2][1]=1;
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==2) cout<<3<<endl; 
        else
        {
            matrix res=quickM(Ma,n-2);
            long long ansrr=(res.a[0][0]+res.a[0][1]+res.a[0][2])%mod;
            long long ansrb=(res.a[1][0]+res.a[1][1]+res.a[1][2])%mod;
            long long ansbr=(res.a[2][0]+res.a[2][1]+res.a[2][2])%mod;
            long long ans=(ansrr+ansrb+ansbr)%mod;
            cout<<ans<<endl;
        }
    }
}