#include <cstring>
#include <iostream>
using namespace std;
#define N 10000050
#define ll long long
/*
1≤n,1≤m,n×m≤10^7
*/
ll n, m;
ll p, q;
int land[N];
int pre[N];
void add(int i, int j, int val)
{
    if (i > n || j > m)
        return;
    land[(i - 1) * m + j] += val;
}
int query(int i, int j)
{
    if (i == 0 || j == 0)
        return 0;
    return land[(i - 1) * m + j];
}
void disp(int *a)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[(i - 1) * m + j] << "\t";
        }
        cout << endl;
    }
    cout << "---------------------" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x1, y1, x2, y2;
    while (cin >> n >> m)
    {
        cin >> p;
        memset(land, 0, sizeof(land));
        for (int i = 1; i <= p; i++)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            add(x1, y1, 1);
            add(x2 + 1, y1, -1);
            add(x2 + 1, y2 + 1, 1);
            add(x1, y2 + 1, -1);
            /*
            映射太头晕 如果超界 加强判定
            */
        }
        //disp(land);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                land[(i - 1) * m + j] += query(i - 1, j) + query(i, j - 1) - query(i - 1, j - 1);
            }
        }
        //disp(land);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (land[(i - 1) * m + j] > 0)
                    land[(i - 1) * m + j] = 1;
            }
        }
        //disp(land);
        //计算前缀和 贡献为1
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                land[(i - 1) * m + j] += query(i - 1, j) + query(i, j - 1) - query(i - 1, j - 1);
            }
        }
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            int ans = query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
            //cout << ans << endl;
            int target = (x2 - x1 + 1) * (y2 - y1 + 1);
            if (ans == target)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    //system("pause");
    return 0;
}