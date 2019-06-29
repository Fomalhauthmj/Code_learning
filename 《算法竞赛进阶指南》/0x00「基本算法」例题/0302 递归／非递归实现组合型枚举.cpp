#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> v;
void Solve(int step)
{
    if (v.size() > m || v.size() + n - step + 1 < m)
        return;
    if (step >= n + 1)
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    v.push_back(step);
    Solve(step + 1);
    v.pop_back();
    Solve(step + 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    Solve(1);
    //system("pause");
    return 0;
}