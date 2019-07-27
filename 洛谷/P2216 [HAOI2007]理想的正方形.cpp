// 单调队列  维护矩阵最大值最小值
#include <deque>
#include <iostream>
using namespace std;
#define ll long long
const int N = 1005;
int mat[N][N], a, b, n;
int min_ele[N][N], max_ele[N][N], right_down_min[N][N], right_down_max[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> n;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= a; i++)
    {
        deque<int> q1, q2;
        for (int j = 1; j <= b; j++)
        {
            while (!q1.empty() && j - q1.front() >= n)
                q1.pop_front();
            while (!q1.empty() && mat[i][j] < mat[i][q1.back()])
                q1.pop_back();
            q1.push_back(j);
            min_ele[i][j] = mat[i][q1.front()];
            while (!q2.empty() && j - q2.front() >= n)
                q2.pop_front();
            while (!q2.empty() && mat[i][j] > mat[i][q2.back()])
                q2.pop_back();
            q2.push_back(j);
            max_ele[i][j] = mat[i][q2.front()];
        }
    }
    for (int j = 1; j <= b; j++)
    {
        deque<int> q1, q2;
        for (int i = 1; i <= a; i++)
        {
            while (!q1.empty() && i - q1.front() >= n)
                q1.pop_front();
            while (!q1.empty() && min_ele[i][j] < min_ele[q1.back()][j])
                q1.pop_back();
            q1.push_back(i);
            right_down_min[i][j] = min_ele[q1.front()][j];
            while (!q2.empty() && i - q2.front() >= n)
                q2.pop_front();
            while (!q2.empty() && max_ele[i][j] > max_ele[q2.back()][j])
                q2.pop_back();
            q2.push_back(i);
            right_down_max[i][j] = max_ele[q2.front()][j];
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = n; i <= a; i++)
    {
        for (int j = n; j <= b; j++)
        {
            ans = min(ans, right_down_max[i][j] - right_down_min[i][j]);
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}