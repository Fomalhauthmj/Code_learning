#include <iostream>
#include <map>
using namespace std;
const int N = 1E4 + 50;
#define p pair<int, int>
int n, i, h, r;
map<p, bool> m;
int d[N];
int c[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> i >> h >> r;
    int a, b;
    for (int i = 0; i < r; i++)
    {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (!m[make_pair(a, b)])
        {
            m[make_pair(a, b)] = 1;
            d[a + 1]--;
            d[b]++;
        }
    }
    c[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        c[i] = c[i - 1] + d[i];
        cout << c[i] + h << endl;
    }
    //system("pause");
    return 0;
}