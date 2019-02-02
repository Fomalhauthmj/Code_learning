#include <iostream>
using namespace std;
#define MOD 10000007
//return a^n
long long quickpow(int a, int n)
{
    if (n == 0)
        return 1;
    long long temp = quickpow(a, n >> 1) % MOD;
    if (n & 1)
        return a * temp % MOD * temp % MOD;
    else
        return temp * temp % MOD;
}
struct matrix
{
    int a11,a12,a21,a22;
};
matrix mulM(matrix m1 matrix m2)
{
    matrix ret;
    ret.a11=m1.a11*m2.a11+m1.a12*m2.a21;
    ret.a12=m1.a11*m2.a12+m1.a12*m2.a22;
    ret.a21=m1.a21*m2.a11+m1.a22*m2.a21;
    ret.a22=m1.a21*m2.a12+m1.a22*m2.a22;
    return ret;
}//可对各元素取模
matrix powM(matrix m,int n)
{
    if(n==1) return m;
    matrix temp;
    temp=powM(m,n>>1)
    if(n&1) return mulM(m,mulM(temp,temp));
    else return mulM(temp,temp);
}
//斐波那契数列的矩阵化
//fn   =   1 1    fn-1    =   1 1 ^ (n-1)   f1 
//fn-1     1 0    fn-2        1 0           f0
//fn=ret.a11+ret.a12;
//ret=1 1  ^ (n-1)
//    1 0
//若fn=Afn-1+Bfn-2+C
//三阶矩阵 fn  =    A  B  C    fn-1
//        fn-1     1  0  0    fn-2
//        1        0  0  1    1
//类似的 fn=fn-1*fn-2  取对数！
// fn=fn-1+fn-2 +n^2+k ?     -> ....  (n-1)^2+2(n-1)+k+1
int main()
{
    int a, n;
    while (cin >> a >> n)
    {
        cout << quickpow(a, n) << endl;
    }
}