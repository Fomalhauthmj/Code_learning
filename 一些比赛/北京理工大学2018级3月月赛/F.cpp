#include <iostream>
using namespace std;
const int N = 1e5 + 50;
int n, m;
int v[N];
bool Judge(int mid)
{
    int cur = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cur + v[i] > mid)
        {
            cnt++;
            cur = v[i];
        }
        else
            cur += v[i];
    }
    if (cur > 0)
        cnt++;
    return cnt <= m;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int left = 1;
    int right = 1e9;
    int mid;
    while (left < right)
    {
        mid = (left + right) >> 1;
        //cout << mid << endl;
        if (Judge(mid))
        {
            right = mid;
        }
        else
            left = mid + 1;
    }
    cout << left << endl;
    //system("pause");
    return 0;
}