#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 6e5+50;
int n, m, tot, cnt[N], len[N], fail[N], last, son[N][27], cur;
char s[N];
long long ans = 0;
inline int new_node(int x)
{
    len[tot] = x;
    cnt[tot] = 0;
    return tot++;
}
inline int get_fail(int x, int n)
{
    while (s[n - len[x] - 1] != s[n])
        x = fail[x];
    return x;
}
inline void init()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    new_node(0);
    new_node(-1);
    fail[0] = 1;
    last = 0;
}
int alpha[26], alpha_cnt;
void DFS(int x)
{
    if (x != 0 && x != 1)
        ans += cnt[x] * alpha_cnt;
    //cout<<x<<" "<<cnt[x]<<" "<<alpha_cnt<<endl;
    for (int i = 0; i < 26; i++)
    {
        if (son[x][i])
        {
            if (!alpha[i])
                alpha_cnt++;
            alpha[i]++;
            DFS(son[x][i]);
            if (--alpha[i] == 0)
                alpha_cnt--;
        }
    }
}
int main()
{
    init();
    for (int i = 1; i <= n; i++)
    {
        int x = s[i] - 'a';
        cur = get_fail(last, i);
        if (!son[cur][x])
        {
            int nw = new_node(len[cur] + 2);
            fail[nw] = son[get_fail(fail[cur], i)][x];
            son[cur][x] = nw;
        }
        last = son[cur][x];
        cnt[last]++;
    }
    for (int i = tot - 1; i >= 0; i--)
        cnt[fail[i]] += cnt[i];
    memset(alpha, 0, sizeof(alpha));
    alpha_cnt = 0;
    //cout<<"even:"<<endl;
    DFS(0);
    memset(alpha, 0, sizeof(alpha));
    alpha_cnt = 0;
    //cout<<"odd:"<<endl;
    DFS(1);
    cout << ans << endl;
    //system("pause");
    return 0;
}