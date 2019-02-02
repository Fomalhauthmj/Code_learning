#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define N 100010
int n,m;
int p[N];
long long y[N];
vector<long long> V[N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++) V[i].clear();
        for(int i=1;i<=m;i++)
        {
            cin>>p[i]>>y[i];
            V[p[i]].push_back(y[i]);
        }
        for(int i=1;i<=n;i++) sort(V[i].begin(),V[i].end());
        string str;
        for(int i=1;i<=m;i++)
        {
            str="";
            for(int j=1;j<=6-to_string(p[i]).length();j++) str+='0';
            str+=to_string(p[i]);
            int pos=upper_bound(V[p[i]].begin(),V[p[i]].end(),y[i])-V[p[i]].begin();
            //二分查找,线性TLE
            for(int j=1;j<=6-to_string(pos).length();j++) str+='0';
            str+=to_string(pos);
            cout<<str<<endl;
        }
    }
}