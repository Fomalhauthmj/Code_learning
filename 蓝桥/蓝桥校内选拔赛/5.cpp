#include<iostream>
using namespace std;
#define N 100010
int par[N];
int n;
int right_son[N];
int left_bro[N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>left_bro[i]>>right_son[i];
            if(right_son[i]!=-1) par[right_son[i]]=i;
            if(left_bro[i]!=-1) par[left_bro[i]]=par[i];
        }
        for(int i=2;i<=n;i++)
        {
            cout<<par[i]<<endl;
        }
    }
    return 0;
}