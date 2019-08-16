#include <iostream>
#include <string>
using namespace std;
const int N = 2e5 + 50;
int lm[N], rm[N]; //left_most,right_most
string s, t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    int lens = s.length();
    int lent = t.length();
    for (int i = 0, j = 0; i < lens; i++)
    {
        if (j < lent && t[j] == s[i])
            lm[j] = i, j++;
    }
    for (int i = lens - 1, j = lent - 1; i >= 0; i--)
    {
        if (j >= 0 && t[j] == s[i])
            rm[j] = i, j--;
    }
    int ans = max(lens - 1 - lm[lent - 1], rm[0]);
    for (int i = 1; i < lent; i++)
    {
        ans = max(ans, rm[i] - lm[i - 1] - 1);
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}