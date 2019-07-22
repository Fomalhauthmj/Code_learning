#include <cstring>
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
int s[9][9];
int r[9], c[9], k[9];
int lowbit(int x)
{
    return x & (-x);
}
void Init()
{
    for (int i = 0; i < 9; i++)
    {
        r[i] = c[i] = k[i] = (1 << 9) - 1;
    }
}
int Get(int depth)
{
    int x = depth / 9;
    int y = depth % 9;
    int temp = r[x] & c[y] & k[x / 3 * 3 + y / 3];
    return temp;
}
int Count(int temp)
{
    int cnt = 0;
    while (temp)
    {
        temp -= lowbit(temp);
        cnt++;
    }
    return cnt;
}
struct node
{
    int depth;
    bool operator<(const node &n) const
    {
        return Count(Get(depth)) > Count(Get(n.depth));
    }
};
priority_queue<node> pq;
bool DFS()
{
    if (pq.empty())
        return true;
    if (pq.size())
    {
        node now = pq.top();
        pq.pop();
        //cout << "now fill" << now.depth / 9 << " " << now.depth % 9 << endl;
        int temp = Get(now.depth);
        while (temp)
        {
            int val = lowbit(temp);
            temp -= val;
            int x = now.depth / 9;
            int y = now.depth % 9;
            r[x] -= val;
            c[y] -= val;
            k[x / 3 * 3 + y / 3] -= val;
            s[x][y] = log2(val) + 1;
            if (DFS())
                return true;
            r[x] += val;
            c[y] += val;
            k[x / 3 * 3 + y / 3] += val;
            s[x][y] = 0;
        }
        pq.push(now);
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Init();
        char ch;
        int val;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                cin >> ch;
                s[i][j] = val = ch - '0';
                if (val)
                {
                    r[i] -= (1 << (val - 1));
                    c[j] -= (1 << (val - 1));
                    k[i / 3 * 3 + j / 3] -= (1 << (val - 1));
                }
            }
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (!s[i][j])
                    pq.push({i * 9 + j});
        DFS();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << s[i][j];
            }
            cout << endl;
        }
    }
    //system("pause");
    return 0;
}