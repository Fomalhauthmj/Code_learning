#include<iostream>
#include<map>
using namespace std;
#define N 200010
int n;
int a[N];
map<long long,int> M;
long long sum;
int ans[N];
int cnt;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        sum=0;
        M.clear();
        cnt=0;
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
            M[a[i]]++;
            sum+=a[i];
        }
        for(int i=1;i<=n;i++)
        {
            long long need_find=(sum-a[i]);
            if(need_find&1) continue;
            need_find/=2;
            if(need_find==a[i]&&M[need_find]>1)
            {
                ans[cnt++]=i;
            }
            else if(need_find!=a[i]&&M[need_find]>0)
            {
                ans[cnt++]=i;
            }
        }
        if(cnt==0) cout<<0<<endl<<endl;
        else
        {
            cout<<cnt<<endl;
            for(int i=0;i<cnt;i++)
            {
                if(i!=cnt-1) cout<<ans[i]<<" ";
                else cout<<ans[i]<<endl;
            }
        }
    }
}