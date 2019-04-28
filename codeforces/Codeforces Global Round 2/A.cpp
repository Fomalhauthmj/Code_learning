#include <iostream>
using namespace std;
#define N 300050
int n;
long long c[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    int temp_val = c[0];
    int end_pos;
    for (int i = 1; i < n; i++)
    {
        if (c[i] != temp_val)
        {
            end_pos = i;
        }
    }
    temp_val = c[n - 1];
    int start_pos;
    for (int i = n - 2; i >= 0; i--)
    {
        if (c[i] != temp_val)
        {
            start_pos = i;
        }
    }
    cout << max(n - start_pos - 1, end_pos) << endl;
    //system("pause");
    return 0;
}