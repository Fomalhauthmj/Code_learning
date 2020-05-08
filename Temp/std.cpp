#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    char name[10];
    int worth;
    int age;
    bool operator<(const node &n) const
    {
        if (worth != n.worth)
            return worth > n.worth;
        if (age != n.age)
            return age < n.age;
        return strcmp(name, n.name) < 0;
    }
};
set<node> ages[205];
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, k;
    scanf("%d%d", &n, &k);
    node t;
    while (n--)
    {
        scanf("%s%d%d", t.name, &t.age, &t.worth);
        if (ages[t.age].size() < 100)
            ages[t.age].insert(t);
    }
    for (int i = 1; i <= k; i++)
    {
        set<node> temp;
        int m, amin, amax;
        scanf("%d%d%d", &m, &amin, &amax);
        for (int j = amin; j <= amax; j++)
        {
            int len = min((int)ages[j].size(), m);
            for (auto it = ages[j].begin(); it != ages[j].end(); it++)
            {
                if (len <= 0)
                    break;
                temp.insert(*it), len--;
            }
        }
        printf("Case #%d:\n", i);
        if (temp.size())
        {
            int len = min((int)temp.size(), m);
            for (auto it = temp.begin(); it != temp.end(); it++)
            {
                if (len <= 0)
                    break;
                t = *it, printf("%s %d %d\n", t.name, t.age, t.worth), len--;
            }
        }
        else
            printf("None\n");
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}