#include <bits/stdc++.h>
#include<windows.h>
using namespace std;

int n, m, q;
//list<int> ls;
deque<int> ls;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, i, j, k;
    cin >> T;
    while (T--)
    {
        ls.clear();
        cin >> n >> m >> q;
        for (i = n; i >= 1; i--)
        {
            ls.push_front(i);
            for (j = 1; j <= m; j++)
                ls.push_front(ls.back()), ls.pop_back();
            for(auto it:ls)
                cout << it << " ";
            cout << endl;
        }
        for (j = 1; j <= m; j++)
            ls.push_back(ls.front()), ls.pop_front();
        /*
        for (i = 1; i <= q; i++)
        {
            cin >> k;
            cout << ls[k - 1] << endl;
        }
        */
    }
    system("pause");
    return 0;
}

/*
100
5 2 1
40000000 3 1
5 1 2
5 2 1
*/
