#include <iostream>
using namespace std;
#define N 1010
long long n, C;
long long a[N], b[N], c[N];
int ans;
int cnt;
//如何降低回溯复杂度
void Search(long long cur_x, int pre)
{
    if (cur_x <= 0)
    {
        ans = max(ans, cnt);
        return;
    }
    for (int i = pre + 1; i < n; i++)
    {
        cnt++;
        Search(min(cur_x, b[i]) - a[i] + c[i], i);
        cnt--;
        Search(cur_x + c[i], i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> C;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
        }
        //读入数据
        //DP? 体力X
        cnt = 0;
        ans = 0;
        Search(C, -1);
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}