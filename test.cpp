#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, int> m;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string line;
    while (1)
    {
        getline(cin, line);
        if (line == "break")
            break;
        m[line]++;
    }
    int sum = 0;
    vector<pair<int, string>> v;
    for (auto ele : m)
    {
        cout << ele.first << " " << ele.second << endl;
        sum += ele.second;
        v.push_back(make_pair(ele.second, ele.first));
    }
    cout << "SUM:" << sum << endl;
    sort(v.begin(), v.end());
    for (auto ele : v)
    {
        cout << ele.first << " " << ele.second << endl;
    }
    return 0;
}