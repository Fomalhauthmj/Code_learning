#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 50;
int cnt[14];
bool vis[14];
#define pii pair<int, int>
#define piii pair<pair<int, int>, int>
int Royal_Straight()
{
    if (vis[10] && vis[11] && vis[12] && vis[13] && vis[1])
        return 1;
    return 0;
}
int Straight()
{
    for (int i = 9; i >= 1; i--)
    {
        bool flag = true;
        for (int j = i; j < i + 5; j++)
            if (!vis[j])
                flag = false;
        if (flag)
            return i + 4;
    }
    return 0;
}
pii Four()
{
    for (int i = 13; i >= 1; i--)
    {
        if (cnt[i] >= 4)
        {
            for (int j = 13; j >= 1; j--)
            {
                if ((i == j && cnt[i] == 5) || (i != j && cnt[j] == 1))
                    return make_pair(i, j);
            }
        }
    }
    return make_pair(0, 0);
}
pii FullHouse()
{
    for (int i = 13; i >= 1; i--)
    {
        if (cnt[i] >= 3)
        {
            for (int j = 13; j >= 1; j--)
            {
                if ((cnt[j] == 2 && i != j) || (i == j && cnt[i] == 5))
                    return make_pair(i, j);
            }
        }
    }
    return make_pair(0, 0);
}
pii Three()
{
    for (int i = 13; i >= 1; i--)
    {
        if (cnt[i] >= 3)
        {
            int temp = 0;
            for (int j = 1; j <= 13; j++)
            {
                if (i == j && cnt[j] - 3 > 0)
                    temp += (cnt[j] - 3) * j;
                else if (cnt[j] && i != j)
                    temp += cnt[j] * j;
            }
            return make_pair(i, temp);
        }
    }
    return make_pair(0, 0);
}
piii TwoPairs()
{
    for (int i = 13; i >= 1; i--)
    {
        if (cnt[i] >= 2)
        {
            for (int j = 13; j >= 1; j--)
            {
                if (i != j && cnt[j] >= 2)
                {
                    for (int k = 13; k >= 1; k--)
                    {
                        if ((i == k || j == k) && cnt[k] - 2 > 0)
                            return make_pair(make_pair(i, j), k);
                        else if (cnt[k])
                            return make_pair(make_pair(i, j), k);
                    }
                }
            }
        }
    }
    return make_pair(make_pair(0, 0), 0);
}
pii Pair()
{
    for (int i = 13; i >= 1; i--)
    {
        if (cnt[i] >= 2)
        {
            int temp = 0;
            for (int j = 1; j <= 13; j++)
                if (cnt[j] && i != j)
                    temp += cnt[j] * j;
                else if (cnt[j] - 2 > 0 && i == j)
                    temp += (cnt[j] - 2) * j;
            return make_pair(i, temp);
        }
    }
    return make_pair(0, 0);
}
int HighCard()
{
    int temp = 0;
    for (int i = 1; i <= 13; i++)
    {
        if (cnt[i])
            temp += cnt[i] * i;
    }
    return temp;
}
struct player
{
    char name[15];
    int flag1, flag2;
    pii flag3, flag4, flag5;
    piii flag6;
    pii flag7;
    int flag8;
    void Init()
    {
        flag1 = Royal_Straight();
        flag2 = Straight();
        flag3 = Four();
        flag4 = FullHouse();
        flag5 = Three();
        flag6 = TwoPairs();
        flag7 = Pair();
        flag8 = HighCard();
    }
} p[N];
bool cmp(const player &p1, const player &p2)
{
    if (p1.flag1 != p2.flag1)
        return p1.flag1 > p2.flag1;
    if (p1.flag2 != p2.flag2)
        return p1.flag2 > p2.flag2;
    if (p1.flag3 != p2.flag3)
        return p1.flag3 > p2.flag3;
    if (p1.flag4 != p2.flag4)
        return p1.flag4 > p2.flag4;
    if (p1.flag5 != p2.flag5)
        return p1.flag5 > p2.flag5;
    if (p1.flag6 != p2.flag6)
        return p1.flag6 > p2.flag6;
    if (p1.flag7 != p2.flag7)
        return p1.flag7 > p2.flag7;
    if (p1.flag8 != p2.flag8)
        return p1.flag8 > p2.flag8;
    return strcmp(p1.name, p2.name) < 0;
}
char card[15];
inline void read()
{
    int len = strlen(card);
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < len; i++)
    {
        if (card[i] == '0')
            continue;
        if (card[i] == 'A')
            vis[1] = 1, cnt[1]++;
        else if (card[i] == 'J')
            vis[11] = 1, cnt[11]++;
        else if (card[i] == 'Q')
            vis[12] = 1, cnt[12]++;
        else if (card[i] == 'K')
            vis[13] = 1, cnt[13]++;
        else
        {
            int num = card[i] - '0';
            if (num == 1)
                num = 10;
            vis[num] = 1, cnt[num]++;
        }
    }
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            //cin >> p[i].name >> card;
            scanf("%s %s", p[i].name, card);
            read();
            p[i].Init();
        }
        sort(p, p + n, cmp);
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", p[i].name);
        }
    }
    //system("pause");
    return 0;
}
/*
3
Alice AAA109
Bob 678910
Boa 678910
3
a 678910
b 109867
c 789610
*/