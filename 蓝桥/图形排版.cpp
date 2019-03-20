#include <iostream>
#include <vector>
using namespace std;
#define N 100010
int n, m;
vector<pair<int, int>> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    int wi, hi;
    for (int i = 0; i < n; i++)
    {
        cin >> wi >> hi;
        v.push_back(make_pair(wi, hi));
    }
}