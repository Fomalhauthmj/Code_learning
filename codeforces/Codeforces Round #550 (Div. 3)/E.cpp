#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
// return a+b
vector<int> get(string &s)
{
    int len = s.length();
    vector<int> res(len + 1); //多一个进位
    for (int i = 0; i < len; i++)
    {
        res[i + 1] = s[i] - 'a';
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> vs = get(s);
    vector<int> vt = get(t);
    for (int i = n; i >= 1; i--)
    {
        vs[i] += vt[i];
        if (i >= 1)
        {
            vs[i - 1] += vs[i] / 26;
            vs[i] %= 26;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        int rem = vs[i] % 2;
        vs[i] /= 2;
        if (i + 1 <= n)
            vs[i + 1] += rem * 26;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << (char)(vs[i] + 'a');
    }
    cout << endl;
    //system("pause");
}