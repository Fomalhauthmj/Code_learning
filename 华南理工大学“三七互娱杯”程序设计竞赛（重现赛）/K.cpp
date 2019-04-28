#include <iostream>
#include <stdio.h>
using namespace std;
#define N 100010
#define MOD 1004535809
#define ll long long
int n;
//第二类斯特林数->贝尔数
ll bell[N];
ll t[N];
void Bell(int MAX)
{
    bell[0] = bell[1] = 1;
    t[0] = 1;
    for (int i = 2; i <= MAX; i++)
    {
        t[i - 1] = bell[i - 1];
        for (int j = i - 2; j >= 0; j--)
            t[j] = (t[j + 1] + t[j]) % MOD;
        bell[i] = t[0];
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    Bell(n);
    for (int m = 1; m <= n; m++)
    {
        printf("%d\n", bell[m]);
    }
    //system("pause");
    return 0;
}