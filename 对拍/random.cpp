#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1010
const int inf = 1e9;
int main()
{
    freopen("data.in", "w", stdout);
    srand((unsigned)time(0));
    int N = 100000;
    cout << N << endl;
    for (int i = 0; i < N; i++)
    {
        if (i)
            cout << " ";
        cout << (rand() % 100 + 1) / 100.0;
    }
    cout << endl;
    //system("pause");
    return 0;
}