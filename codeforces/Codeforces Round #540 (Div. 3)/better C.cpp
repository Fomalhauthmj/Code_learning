#include <iostream>
#include <map>
#include <queue>
using namespace std;
#define N 22
int matrix[N][N];
int n;
map<int, int> M;
priority_queue<pair<int, int>> Q;
int rev(int i)
{
    return n - 1 - i;
}
void no()
{
    cout << "NO" << endl;
    exit(0); //强制退出
}
void put(vector<pair<int, int>> v)
{
    pair<int, int> now = Q.top();
    Q.pop();
    if (now.first < v.size())
    {
        no();
    }
    for (auto ele : v)
    {
        matrix[ele.first][ele.second] = now.second;
    }
    Q.push(make_pair(now.first - v.size(), now.second));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        M.clear();
        int ai;
        for (int i = 0; i < n * n; i++)
        {
            cin >> ai;
            M[ai]++;
        }
        while (!Q.empty())
            Q.pop();
        for (auto ele: M)
        {
            Q.push(make_pair(ele.second,ele.first)); //第一元素为次数，第二元素为值
        }
        int mid = n / 2;
        for (int i = 0; i < mid; i++)
        {
            for (int j = 0; j < mid; j++)
            {
                put({{i, j}, {i, rev(j)}, {rev(i), j}, {rev(i), rev(j)}});
            }
        }
        if(n&1)//奇数
        {
            for (int i = 0; i < mid;i++)
            {
                put({{i, mid}, {rev(i), mid}});
                put({{mid, i}, {mid, rev(i)}});
            }
            put({{mid, mid}});
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j != n - 1)
                    cout << matrix[i][j] << " ";
                else
                    cout << matrix[i][j] << endl;
            }
        }
    }
}