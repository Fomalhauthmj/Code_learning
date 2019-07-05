#include <iostream>
using namespace std;
#define ll long long
const ll N = 5E5 + 50;
ll n, a[N], b[N];
ll ans;
void merge(int left, int right)
{
    int mid;
    if (left == right)
        return;
    else
    {
        mid = (left + right) >> 1;
        merge(left, mid);
        merge(mid + 1, right);
    }
    int i = left, j = mid + 1;
    for (int k = left; k <= right; k++)
    {
        if (j > right || (i <= mid && a[i] <= a[j]))
            b[k] = a[i++];
        else
        {
            b[k] = a[j++];
            ans += mid - i + 1;
        }
    }
    for (int k = left; k <= right; k++)
        a[k] = b[k];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ans = 0;
        merge(0, n - 1);
        cout << ans << endl;
        cin >> n;
    }
    //system("pause");
    return 0;
}