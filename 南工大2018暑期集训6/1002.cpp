#include<iostream>
#include<cstring>
using namespace std;
long long L;
int M;
struct matrix
{
    long long a[4][4];
};
matrix Ma;
//fn     = 1 0 1 1    fn-1  = M^2  fn-2 =  M^n-3 f3 f2 f1 f0
//fn-1     1 0 0 0    fn-2
//fn-2     0 1 0 0    fn-3
//fn-3     0 0 1 0    fn-4 
matrix mulM(matrix m1,matrix m2,int mod)
{
    matrix res;
    memset(res.a,0,sizeof(res.a));
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                res.a[i][j]=(res.a[i][j]+m1.a[i][k]*m2.a[k][j])%mod;
            }
        }
    }
    return res;
}
matrix quickM(matrix m,long long n,int mod)
{
    if(n==1) return m;
    matrix temp;
    temp=quickM(m,n>>1,mod);
    if(n&1) return mulM(m,mulM(temp,temp,mod),mod);
    else return mulM(temp,temp,mod);
}
int main()
{
    memset(Ma.a,0,sizeof(Ma.a));
    Ma.a[0][0]=Ma.a[0][2]=Ma.a[0][3]=Ma.a[1][0]=Ma.a[2][1]=Ma.a[3][2]=1;
    // Ma.a[0]={1,0,1,1};
    // Ma.a[1]={1,0,0,0};
    // Ma.a[2]={0,1,0,0};
    // Ma.a[3]={0,0,1,0};
    while(cin>>L>>M)
    {
        if(L==0) cout<<1%M<<endl;
        else if(L==1) cout<<2%M<<endl;
        else if(L==2) cout<<4%M<<endl;
        else if(L==3) cout<<6%M<<endl; 
        else
        {
            matrix res=quickM(Ma,L-3,M);
            long long ans=(res.a[0][0]*6%M+res.a[0][1]*4%M+res.a[0][2]*2%M+res.a[0][3]*1%M)%M;
            cout<<ans<<endl;
        }
    }
}
// #include<iostream>
// #include<math.h>
// #define FOR(k) for(int (k)=0;(k)<2;(k)++)
// using namespace std;
// int main()
// {
//     int Onum=0;//fmf fff
//     int Enum=0;
//     string ch[2]={"f","m"};
//     FOR(i1) FOR(i2) FOR(i3) FOR(i4) FOR(i5) FOR(i6) FOR(i7)
//     {
//         string str;
//         str.append(ch[i1]);
//         str.append(ch[i2]);
//         str.append(ch[i3]);
//         str.append(ch[i4]);
//         str.append(ch[i5]);
//         str.append(ch[i6]);
//         str.append(ch[i7]);
//         if(str.find("fmf")!=string::npos||str.find("fff")!=string::npos) 
//         {
//             Onum++;cout<<str<<endl;
//         }
//     }
//     cout<<pow(2,7)-Onum<<endl;
//     system("pause");
// }
//L E
//0 1
//1 2
//2 4
//3 6
//4 9
//5 15
//6 25
//7 40
//fn=fn-1+fn-3+fn-4;