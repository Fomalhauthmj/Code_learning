#include <iostream>
#include <string>
using namespace std;
string str;
int n, q;
int solve(int left, int right)
{
    int len = right - left + 1;
    long long num_all = len * (len + 1) / 2;
    return num_all;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    cin >> str;
    int l, r;
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }
    //system("pause");
    return 0;
}