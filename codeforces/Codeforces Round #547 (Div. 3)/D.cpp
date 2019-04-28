#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define N 150050
int n;
string l, r;
vector<int> vl[27];
vector<int> vr[27];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> l >> r;
    for (int i = 0; i < n; i++)
    {
        if (l[i] == '?')
        {
            vl[26].push_back(i);
        }
        else
            vl[l[i] - 'a'].push_back(i);
        if (r[i] == '?')
        {
            vr[26].push_back(i);
        }
        else
            vr[r[i] - 'a'].push_back(i);
    }
    int ans = 0;
    vector<pair<int, int>> A;
    int a, b;
    for (int i = 0; i < 27; i++)
    {
        while (vl[i].size() > 0 && vr[i].size() > 0)
        {
            a = vl[i].back();
            b = vr[i].back();
            //cout << "add:"<<(char)('a'+i)<< a << " " << b << endl;
            A.push_back(make_pair(a, b));
            vl[i].pop_back();
            vr[i].pop_back();
            ans++;
        }
        while (vl[i].size() > 0 && vr[26].size() > 0)
        {
            a = vl[i].back();
            b = vr[26].back();
            A.push_back(make_pair(a, b));
            vl[i].pop_back();
            vr[26].pop_back();
            ans++;
        }
        while (vr[i].size() > 0 && vl[26].size() > 0)
        {
            a = vr[i].back();
            b = vl[26].back();
            A.push_back(make_pair(b, a));
            vr[i].pop_back();
            vl[26].pop_back();
            ans++;
        }
    }
    cout << ans << endl;
    for (auto ele : A)
    {
        cout << ele.first + 1 << " " << ele.second + 1 << endl;
    }
    //system("pause");
    return 0;
}