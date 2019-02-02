#include<iostream>
#include<cstring>
using namespace std;
long long k,b,n,M;
//矩阵快速幂 
/*
ans =f[g[0]]+f[g[1]]+...+f[g[n-1]]
    =f[b]+f[k+b]+f[2k+b]+...+f[(n-1)k+b]
    =f[b]+A^kf[b]+A^2kf[b]+...+A^(n-1)kf[b]
其中A   =【1 1】  斐波那契矩阵化 f[n+1]=【1 1】 f[n]  =  A^n f[1]=1
         【1 0】                f[n]   【1 0】 f[n-1]       f[0]=0
ans =A^(b-1)【E+A^k+A^2k+A^3k+...+A^(n-1)k】
令B=A^k  ans=f[b]【E+B+B^2+B^3+...+B^(n-1)】     
如何求上式右边一项的和？
TODO:构造矩阵【B E】*【B E】=【B^2 B+E】 => 【B^3 E+B+B^2】
            【0 E】 【0 E】 【0 E】        【0 E】
            令该矩阵为X X^N=[B^N E+B+B^2+...+B^(N-1)]
                            [ 0  E]
*/
struct matrix_2x2
{
    long long a[2][2];
};
matrix_2x2 E_2x2;
matrix_2x2 matrix_mul(matrix_2x2 m1,matrix_2x2 m2)
{
    matrix_2x2 ans;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            ans.a[i][j]=0;
            for(int k=0;k<2;k++)
            {
                ans.a[i][j]=(ans.a[i][j]+m1.a[i][k]*m2.a[k][j])%M;
            }
        }
    }
    return ans;
}
struct matrix_4x4
{
    long long a[4][4];
};
matrix_4x4 E_4x4;
matrix_2x2 matrix_pow(matrix_2x2 m,long long n)
{
    if(n==0) return E_2x2;
    if(n==1) return m;
    matrix_2x2 temp;
    temp=matrix_pow(m,n>>1);
    if(n&1) return matrix_mul(m,matrix_mul(temp,temp));
    return matrix_mul(temp,temp);
}
matrix_4x4 matrix_mul(matrix_4x4  m1,matrix_4x4 m2)
{
    matrix_4x4 ans;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            ans.a[i][j]=0;
            for(int k=0;k<4;k++)
            {
                ans.a[i][j]=(ans.a[i][j]+m1.a[i][k]*m2.a[k][j])%M;
            }
        }
    }
    return ans;
}
matrix_4x4 matrix_pow(matrix_4x4 m,long long n)
{
    if(n==0) return E_4x4;
    if(n==1) return m;
    matrix_4x4 temp;
    temp=matrix_pow(m,n>>1);
    if(n&1) return matrix_mul(m,matrix_mul(temp,temp));
    return matrix_mul(temp,temp);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    matrix_2x2 A;
    A.a[0][0]=A.a[0][1]=A.a[1][0]=1;
    A.a[1][1]=0;//斐波那契数列的矩阵化
    int f0=0;
    int f1=1;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(i==j) E_2x2.a[i][j]=1;
            else E_4x4.a[i][j]=0;
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(i==j) E_4x4.a[i][j]=1;
            else E_4x4.a[i][j]=0;
        }
    }
    while(cin>>k>>b>>n>>M)
    {
        matrix_2x2 fb=matrix_pow(A,b);
        matrix_2x2 B=matrix_pow(A,k);
        matrix_4x4 X;
        memset(X.a,0,sizeof(X.a));
        X.a[0][0]=B.a[0][0];
        X.a[0][1]=B.a[0][1];
        X.a[1][0]=B.a[1][0];
        X.a[1][1]=B.a[1][1];
        X.a[0][2]=X.a[1][3]=X.a[2][2]=X.a[3][3]=1;
        X=matrix_pow(X,n);
        B.a[0][0]=X.a[0][2];
        B.a[0][1]=X.a[0][3];
        B.a[1][0]=X.a[1][2];
        B.a[1][1]=X.a[1][3];
        matrix_2x2 ans=matrix_mul(fb,B);
        /*
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                cout<<ans.a[i][j]<<" ";
            }
            cout<<endl;
        }
        */
       cout<<ans.a[0][1]%M<<endl;
    }
}