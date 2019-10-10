#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 1e5 + 50;
int cnt[N];
vector<int> v;
int main()
{
    int q, n, r;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &n, &r);
        int pos;
        v.clear();
        for (int i = 1; i <= n; i++)
            scanf("%d", &pos), cnt[pos]++, v.push_back(pos);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int delta = 0;
        int ans = 0;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int pos = v[i];
            if (cnt[pos] > 0 && pos - delta <= 0)
                cnt[pos] = 0;
            else if (cnt[pos] > 0)
                ans++, cnt[pos] = 0, delta += r;
        }
        printf("%d\n", ans);
    }
    //system("pause");
    return 0;
}