#include <iostream>
#include <string>
using namespace std;
int r[9], c[9], k[9];
int cnt[512], num[512], x[81], y[81], s[81];
int tot;
char str[81];
int lowbit(int x)
{
    return x & (-x);
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
void Init()
{
    for (int i = 0; i < 9; i++)
    {
        r[i] = c[i] = k[i] = (1 << 9) - 1;
    }
}
inline int Get(int x, int y)
{
    return r[x] & c[y] & k[x / 3 * 3 + y / 3];
}
inline void Fill(int x, int y, int val)
{
    r[x] ^= val;
    c[y] ^= val;
    k[x / 3 * 3 + y / 3] ^= val;
}
bool DFS(int now)
{
    if (!now)
        return true;
    int pos,temp = 0;
    int choice = 10;
    for (int i = 0; i < 81; i++)
    {
        if (s[i])
            continue;
        temp = Get(x[i], y[i]);
        if (cnt[temp] < choice)
        {
            choice = cnt[temp];
            pos=i;
        }
    }
    temp = Get(x[pos], y[pos]);
    while (temp)
    {
        int val = lowbit(temp);
        Fill(x[pos], y[pos], val);
        s[pos]= num[val];
        if (DFS(now - 1))
            return true;
        Fill(x[pos], y[pos], val);
        temp -= val;
        s[pos] = 0;
    }
    return false;
}
int main()
{
    for (int i = 0; i < (1 << 9); i++)
        cnt[i] = Count(i);
    for (int i = 0; i < 9; i++)
        num[1 << i] = i + 1;
    for (int i = 0; i < 81; i++)
        x[i] = i / 9, y[i] = i % 9;
    while (cin >> str && str[0] != 'e')
    {
        Init();
        int val;
        tot = 0;
        for (int i = 0; i < 81; i++)
            if (str[i] != '.')
            {
                s[i] = str[i] - '0';
                Fill(x[i], y[i], 1 << (s[i] - 1));
            }
            else
                s[i] = 0, tot++;
        DFS(tot);
        for (int i = 0; i < 81; i++)
            cout << s[i];
        cout << endl;
    }
    return 0;
}