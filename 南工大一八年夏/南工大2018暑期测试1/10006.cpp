#include<iostream>
#include<cstring>
using namespace std;
#define size 100010
long long a[size];
long long b[size];
long long n,m,w;
bool judge(long long mid)
{
    memset(b,0,sizeof(b));
    long long waternum=0;
    long long temp;
    for(int i=1;i<=n;i++)
    {
        if(a[i]+b[i]>=mid) continue;
        else
        {
            if(a[i]+b[i]+m<mid) return false;
            temp=mid-a[i]-b[i];
            waternum+=temp;
            for(int j=0;j<w&&i+j<=n;j++) b[i+j]+=temp;
        }//注意超时！Time limit exceeded on test 20 on codeforce？？
    }
    if(waternum>m) return false;
    else return true;
}
bool betterjudge(long long mid)
{
    memset(b,0,sizeof(b));
    long long waternum=0;
    long long temp=0;
    for(int i=1;i<=n;i++)
    {
       temp-=(i>=w?b[i-w]:0);//重点！！！减掉淋不到的
       if(mid>a[i]+temp)
       {
           b[i]=mid-temp-a[i];;//当前这个位置浇的次数
           temp+=b[i];
           waternum+=b[i];
       }
    }
    if(waternum>m) return false;
    else return true;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>w;
        long long left=1;
        long long right=1e14;
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
        }
        long long mid;
        long long ans;
        while(left<=right)  //控制循环跳出条件
        {
            mid=(left+right)/2;
            if(betterjudge(mid)==true) 
            {
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        cout<<ans<<endl;
    }
}