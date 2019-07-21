#include<iostream>
#include<stdio.h>
using namespace std;
const int N=2e5+50;
#define P 131
#define ull unsigned long long
int n,m,q,cnt[N];
char s[N],t[N];
ull hs[N],ht[N],p[N];
void Init()
{
    int temp=max(n,m);
    p[0]=1;hs[0]=ht[0]=0;
    for(int i=1;i<=temp;i++) p[i]=p[i-1]*P;
    for(int i=1;i<=n;i++) hs[i]=hs[i-1]*P+s[i];
    for(int i=1;i<=m;i++) ht[i]=ht[i-1]*P+t[i];
}
ull Hash(int left,int right)
{
    return hs[right]-hs[left-1]*p[right-left+1];
}
int Match(int pos)
{
    int left=0;
    int right=m;
    int mid;
    while(left<right)
    {
        mid=(left+right+1)>>1;
        if(pos+mid-1<=n&&Hash(pos,pos+mid-1)==ht[mid])
            left=mid;
        else right=mid-1;
    }
    return left;
}
int main()
{
    cin>>n>>m>>q;
    scanf("%s",s+1);
    scanf("%s",t+1);
    Init();
    for(int i=1;i<=n;i++)
        cnt[Match(i)]++;
    int x;
    while(q--)
    {
        cin>>x;
        cout<<cnt[x]<<endl;   
    }
    system("pause");
    return 0;
}