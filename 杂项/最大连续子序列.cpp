#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxnum 100010
int n;
int num[maxnum];
int maxseg(int a[],int left,int right)
{
    int mid=(left+right)>>1;
    if(left==right) return a[left];
    int max1=maxseg(a,left,mid);
    int max2=maxseg(a,mid+1,right);
    int ret=max(max1,max2);
    int temp1,temp2,ret1,ret2;
    temp1=ret1=a[mid];
    for(int i=mid-1;i>=0;i--)
    {
        temp1+=a[i];
        if(temp1>ret1)
        {
            ret1=temp1;
        }
    }
    temp2=ret2=a[mid+1];
    for(int i=mid+2;i<n;i++)
    {
        temp2+=a[i];
        if(temp2>ret2)
        {
            ret2=temp2;
        }
    }
    ret=max(ret,ret1+ret2);
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        memset(num,0,sizeof(num));
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>num[j];
        }
        cout<<"Case "<<i<<":"<<endl;
        int ans=maxseg(num,0,n);
        cout<<ans<<endl;
        if(i!=t) cout<<endl;
    }//全负数？？？？？
}