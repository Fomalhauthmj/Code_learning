#include <iostream>
using namespace std;
#define N 500050
//http://acm.hdu.edu.cn/showproblem.php?pid=6521
int n, m;
int l[N];
int r[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m)
    {
        for (int i = 0; i < m; i++)
        {
            cin >> l[i] >> r[i];
        }
    }
    system("pause");
    return 0;
}