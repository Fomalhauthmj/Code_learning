#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
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
    Solve(step + 1);
    v.push_back(step);
    Solve(step + 1);
    v.pop_back();
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