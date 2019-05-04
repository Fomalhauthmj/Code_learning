#include<iostream>
#include<math.h>
using namespace std;
long long a[100010];
int main()
{
    a[1]=1;
    int pos=2;
    while(a[pos]<2147483648)
    {
        a[pos]=a[pos-1]+pos;
        pos++;
    }
    long long k,n;
    cin>>k;
    while(k--)
    {
        cin>>n;
        int next=lower_bound(a+1,a+1+pos,n)-a;
        int number=(n-a[next-1])%9;
        if(number==0) cout<<9<<endl;
        else cout<<number<<endl;
    }
}
//求根公式
// #include<iostream>
// #include<math.h>
// using namespace std;
// double solve(long long n)
// {
//     return (sqrt(1+8*n)-1)/2;
// }
// int main()
// {
//     long long k;
//     cin>>k;
//     long long n;
//     while(k--)
//     {
//         cin>>n;
//         long long down=solve(n-1);
//         n-=down*(down+1)/2;
//         if(n%9==0) cout<<9<<endl;
//         else cout<<n%9<<endl;
//     }
// }