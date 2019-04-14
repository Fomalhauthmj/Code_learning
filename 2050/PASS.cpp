#include <cstring>
#include <iostream>
#include <math.h>
using namespace std;
#define M 1010
int cnt1[M];
int cnt2[M];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int n, m, k;
    while (T--)
    {
        cin >> n >> m >> k;
        int belong;
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for (int i = 1; i <= n; i++)
        {
            cin >> belong;
            if (i <= n / 2)
            {
                cnt1[belong]++;
            }
            cnt2[belong]++;
        }
        long long ans = 0;
        for (int i = 1; i <= m; i++)
        {
            int limit = (int)floor(cnt2[i]*1.0 / k);
            //cout << "m:" << i << " limit:" << limit << endl;
            if (limit >= cnt1[i])
                ans += cnt1[i];
            else
                ans += limit;
        }
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}
/*
3
6 2 2 
1 1 2 1 2 2 
8 2 2
1 1 2 1 2 2 2 2
4 2 1
1 1 1 2
*/