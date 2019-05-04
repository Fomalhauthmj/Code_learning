#include<iostream>
using namespace std;
#define N 100010
int n,m;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];sum+=a[i];
    }
    int left=0,right=sum;
    int mid,m1;
    while(left<right)
    {
        mid=(left+right)>>1;
        m1=m;
        int start=0,sum1=0;
        int i;
        while(m1--)
        {
            for(i=start;i<n;i++)
            {
                if(sum+a[i]<mid) sum+=a[i];
                else 
                {
                    start=i;break;
                }
            }
            if(i==n) break;
        }
        if(m1==0&&i==n)
        {
            right=mid;
        }
        else left=mid+1;
    }
    cout<<left<<endl;
    system("pause");
    return 0;
}
// #include<iostream>
// #define size 100010
// long long n,m;
// int num[100010];
// long long sum;
// using namespace std;
// bool judge(int max)
// {
//     int temp=0;
//     int linenumber=0;
//     for(int i=0;i<n;i++)
//     {
//         if(temp+num[i]<max)
//         {
//             temp+=num[i];
//         }
//         else if(temp+num[i]>=max)
//         {
//             linenumber++;
//             if(linenumber>m) return false;
//             temp=num[i];
//         }
//     }
//     return true;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     while(cin>>n>>m)
//     {
//         sum=0;
//         int left=0;
//         for(int i=0;i<n;i++) 
//         {
//             cin>>num[i];sum+=num[i];
//             left=left>num[i]?left:num[i];
//         }
//         int right=sum;
//         int mid;
//         while(left<right)
//         {
//             mid=(left+right)>>1;
//             if(judge(mid)==true) right=mid;
//             else left=mid+1;
//         }
//         cout<<left<<endl;
//     }
// }