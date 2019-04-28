#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define N 200050
int a[N]; //[0,2*10^5]
int n;
int belong[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> up;
    up.push_back(-1);
    vector<int> down;
    down.push_back(0x3f3f3f3f);
    memset(belong, 0, sizeof(belong));
    for (int i = 0; i < n; i++)
    {
        if (a[i] > up.back() && a[i] < down.back())
        {
            if (i + 1 < n)
            {
                if (a[i + 1] > a[i])
                {
                    up.push_back(a[i]);
                }
                else
                {
                    down.push_back(a[i]);
                    belong[i] = 1;
                }
            }
        }
        else if (a[i] > up.back() && a[i] >= down.back())
        {
            up.push_back(a[i]);
        }
        else if (a[i] <= up.back() && a[i] < down.back())
        {
            down.push_back(a[i]);
            belong[i] = 1;
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
        /*
        for (auto ele : up)
        {
            cout << ele << " ";
        }
        cout << endl;
        for (auto ele : down)
        {
            cout << ele << " ";
        }
        cout << endl;
        */
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << belong[i] << " ";
    }
    cout << endl;
    //system("pause");
    return 0;
}