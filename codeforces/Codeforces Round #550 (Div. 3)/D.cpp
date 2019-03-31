#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
#define N 200020
int a[N];
int n;
map<int, int> M;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    M.clear();
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        M[a[i]]++;
    }
    int max_cnt = 0;
    int max_val;
    for (auto ele : M)
    {
        if (ele.second >= max_cnt)
        {
            max_cnt = ele.second;
            max_val = ele.first;
        }
    }
    int startpos;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == max_val)
        {
            startpos = i;
            break;
        }
    }
    cout << n - max_cnt << endl;
    for (int i = startpos - 1; i >= 0; i--)
    {
        if (a[i] > max_val)
        {
            cout << 2 << " " << i + 1 << " " << i + 2 << endl;
        }
        else if (a[i] < max_val)
        {
            cout << 1 << " " << i + 1 << " " << i + 2 << endl;
        }
    }
    for (int i = startpos + 1; i < n; i++)
    {
        if (a[i] > max_val)
        {
            cout << 2 << " " << i + 1 << " " << i << endl;
        }
        else if (a[i] < max_val)
        {
            cout << 1 << " " << i + 1 << " " << i << endl;
        }
    }
    //system("pause");
    return 0;
}