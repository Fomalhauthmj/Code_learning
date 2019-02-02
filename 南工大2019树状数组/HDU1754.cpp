#include<bits/stdc++.h>
using namespace std;
#define N 200010
int n,m;
int c[N];
int a[N];
int lowbit(int x)
{
    return x&(-x);
}
void update(int x)
{
    int max_lowbit;
    while(x<=n)
    {
        c[x]=a[x];
        max_lowbit=lowbit(x);
        for(int i=1;i<max_lowbit;i<<=1)
        {
            c[x]=max(c[x],c[x-i]);
        }
        x+=lowbit(x);
    }
}
long long getMax(int l,int r)
{
    int res=a[r];
    while(r>=l)
    {
        res=max(res,a[r]);
        r--;
        for(;r-lowbit(r)>=l;r-=lowbit(r))
        {
            res=max(res,c[r]);
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
            update(i);
        }
        char ch;
        int A,B;
        for(int i=1;i<=m;i++)
        {
            cin>>ch>>A>>B;
            if(ch=='Q')
            {
                cout<<getMax(A,B)<<endl;
            }
            else if(ch=='U')
            {
                a[A]=B;
                update(A);
            }
        }
    }
}