#include<iostream>
#include<vector>
using namespace std;
#define N 300030
#define MOD 998244353
int n, k;
int a[N];
vector<int> V[N];
vector<int> DFS(int start,int pre,int depth)
{
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>k)
    {
        for (int i = 1; i <= n;i++)
        {
            cin >> a[i];
        }
        int u, v;
        for (int i = 0; i < n - 1;i++)
        {
            cin >> u >> v;
            V[u].push_back(v);
            V[v].push_back(u);//建图
        }
        ans = 0;
        cout << ans << endl;
    }
}