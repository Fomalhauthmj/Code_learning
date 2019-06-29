#include <iostream>
#include <vector>
using namespace std;
const int N = 10;
int n, m;
vector<int> v;
bool vis[N];
void Solve(int step)
{
    if (step >= n + 1)
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            v.push_back(i);
            Solve(step + 1);
            vis[i] = 0;
            v.pop_back();
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    Solve(1);
    //system("pause");
    return 0;
}