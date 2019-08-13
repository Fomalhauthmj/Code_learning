#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
const int N = 2e5 + 50;
int n;
int a[N];
set<int> s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] - 1 >= 1 && !s.count(a[i] - 1))
            s.insert(a[i] - 1);
        else if (!s.count(a[i]))
            s.insert(a[i]);
        else if (!s.count(a[i] + 1))
            s.insert(a[i] + 1);
    }
    cout << s.size() << endl;
    //system("pause");
    return 0;
}