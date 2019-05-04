#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a[15];
    bool vis[15];
    for (int i = 0; i < 15; i++)
        a[i] = i + 1;
    for (int i = 1; i < 15; i++)
    {
        double e;
        long long num = 0;
        do
        {
            memset(vis, 0, sizeof(vis));
            long long temp = 0;
            for (int j = 0; j < i; j++)
            {
                if (!vis[j])
                {
                    temp++;
                    for (int k = j + 1; k < i; k++)
                    {
                        if (a[k] < a[j])
                            vis[k] = 1;
                    }
                }
            }
            num += temp;
        } while (next_permutation(a, a + i));
        long long all_kinds = 1;
        for (int j = 1; j <= i; j++)
            all_kinds *= j;
        cout << i << " " << num << " " << all_kinds << endl;
        //e = num * 1.0 / all_kinds;
        //cout << fixed << setprecision(4) << e << endl;
    }
    system("pause");
    /*
    S(n, 0)=0, S(1, 1)=1, S(n, n)=1
    S(n, k)=S(n-1, k-1)+(n-1)S(n-1, k)
    num=S(n-1,2)=S(n-2,1)+(n-2)S(n-2,2)
                =(n-3)!+(n-2)[S(n-3,1)+(n-3)S(n-3,2)]
                =(n-3)!+(n-2)(n-4)!+(n-3)(n-5)!+...+3!1!
    */
}