#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 6E5 + 50;
int trie[N * 24][2], tot, root[N], a[N], n, m, latest[N * 24];
void Insert(int i, int k, int p, int q)
{
    if (k < 0)
    {
        latest[q] = i;
        return;
    }
    int c = (a[i] >> k) & 1;
    if (p)
        trie[q][c ^ 1] = trie[p][c ^ 1];
    trie[q][c] = ++tot;
    Insert(i, k - 1, trie[p][c], trie[q][c]);
    latest[q] = max(latest[trie[q][0]], latest[trie[q][1]]);
}
int Ask(int now, int val, int k, int limit)
{
    if (k < 0)
        return a[latest[now]] ^ val;
    int c = (val >> k) & 1;
    if (latest[trie[now][c ^ 1]] >= limit)
        return Ask(trie[now][c ^ 1], val, k - 1, limit);
    return Ask(trie[now][c], val, k - 1, limit);
}
int main()
{
    scanf("%d%d", &n, &m);
    memset(latest, -1, sizeof(latest));//初始化
    root[0] = ++tot;
    Insert(0, 23, 0, root[0]);
    for (int i = 1, x; i <= n; i++)
    {
        scanf("%d", &x), a[i] = a[i - 1] ^ x;
        root[i] = ++tot;
        Insert(i, 23, root[i - 1], root[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        char ch[2];
        int l, r, x;
        scanf("%s", ch);
        if (ch[0] == 'A')
        {
            scanf("%d", &x);
            root[++n] = ++tot;
            a[n] = a[n - 1] ^ x;
            Insert(n, 23, root[n - 1], root[n]);
        }
        else
        {
            scanf("%d%d%d", &l, &r, &x);
            printf("%d\n", Ask(root[r - 1], x ^ a[n], 23, l - 1));
        }
    }
    //system("pause");
    return 0;
}