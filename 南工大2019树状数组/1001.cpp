#include<bits/stdc++.h>
using namespace std;
#define N 50050
int n;
int a[N];
int c[N];
string str;
int lowbit(int x)
{
    return x&(-x);
}
int getSum(int x)
{
    //return 1-x
    int sum=0;
    while(x>=1)
    {
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}
void edit(int x,int data)
{
    //单点修改
    while(x<=n)
    {
        c[x]+=data;
        x+=lowbit(x);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    int casenum=1;
    while(T--)
    {
        cin>>n;
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
            edit(i,a[i]);
        }
        /*
        for(int i=1;i<=n;i++)
        {
            int len=i-lowbit(i)+1;
            for(int j=i;j>=len;j--)
            {
                c[i]+=a[j];
            }
        } 两种方式均可,之前WA是因为未使用memset来清空恢复  这里是离线化的操作 需要获得所有数据才可 未使用edit
        //https://www.cnblogs.com/COLIN-LIGHTNING/p/8436624.html
        */
        cout<<"Case "<<casenum++<<":"<<endl;
        while(cin>>str)
        {
            if(str[0]=='E') break;
            int i,j;
            cin>>i>>j;
            if(str[0]=='Q')
            {
                cout<<getSum(j)-getSum(i-1)<<endl;
            }
            else if(str[0]=='A')
            {
                edit(i,j);
            }
            else if(str[0]=='S')
            {
                edit(i,-j);
            }
        }
    } 
}