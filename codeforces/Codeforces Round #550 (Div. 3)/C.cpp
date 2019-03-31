#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define N 200050
int a[N];
int n;
map<int, int> M;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    bool flag = true;
    M.clear();
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        M[a[i]]++;
        if (M[a[i]] > 2)
        {
            flag = false;
        }
    }
    if (!flag)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        vector<int> va;
        vector<int> vb;
        for (auto ele : M)
        {
            if (ele.second == 2)
            {
                va.push_back(ele.first);
                vb.push_back(ele.first);
            }
            else
            {
                va.push_back(ele.first);
            }
        }
        cout << va.size() << endl;
        for (auto ele : va)
        {
            cout << ele << " ";
        }
        cout << endl;
        cout << vb.size() << endl;
        sort(vb.begin(), vb.end(), greater<int>());
        for (auto ele : vb)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    //system("pause");
    return 0;
}