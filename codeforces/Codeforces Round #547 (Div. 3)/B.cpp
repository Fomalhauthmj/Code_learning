#include <iostream>
using namespace std;
#define N 200010
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max_length = 0;
    int temp = 0;
    int pos;
    for (int i = 0; i < 2 * n; i++)
    {
        if (i >= n)
            pos = i % n;
        else
            pos = i;
        if (a[pos] == 1)
        {
            temp++;
        }
        else
        {
            max_length = max(max_length, temp);
            temp = 0;
        }
    }
    cout << max_length << endl;
    //最大连续子段长问题 环形
    return 0;
    //system("pause");
}