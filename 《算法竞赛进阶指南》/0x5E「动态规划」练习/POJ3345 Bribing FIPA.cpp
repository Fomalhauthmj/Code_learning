#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
const int N = 205;
#define ll long long
int n, m;
map<string, int> name;
vector<int> son[N];
ll dia[N];
ll dp[N][N];
/*
    dp[i][j] 以i为根的子树中已经获取j个国家的支持的 最少花费
*/
void DP(int rt)
{
    for (int i = 0; i < son[rt].size(); i++) //分组
    {
        int s = son[rt][i];
        DP(s);
        for (int j = n; j >= 0; j--) //已获得支持j
        {
            for (int k = 0; k <= j; k++) //子树中获得支持k
            {
                if (j >= k)
                    dp[rt][j] = min(dp[rt][j], dp[rt][j - k] + dp[s][k]);
            }
        }
    }
    //比较
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    string fname, sname, str;
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> fname >> dia[i];
            name[fname] = i;
            getline(cin, str);
            cout << str.length() << endl;
        }
    }
    system("pause");
    return 0;
}