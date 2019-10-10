#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;
const int N = 2e5 + 50;
int p[N];
set<int> S;
int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int h, n;
        scanf("%d%d", &h, &n);
        S.clear();
        for (int i = 1; i <= n; i++)
            scanf("%d", &p[i]), S.insert(p[i]);
        int cnt = 0;
        int cur = h;
        int i = 1;
        while (1)
        {
            if (cur <= 2)
                break;
            while (i <= n && cur <= p[i])
                i++;
            if (i <= n && cur >= p[i] + 2)
                cur = p[i] + 2;
            if (cur >= 3 && S.find(cur-1)!=S.end())
            {
                if (S.find(cur-2)==S.end())
                    cnt++;
                cur -= 2;
            }
            else
                cur--;
        }
        printf("%d\n", cnt);
    }
    //system("pause");
    return 0;
}