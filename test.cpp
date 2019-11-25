#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> a, b;
    a.insert(a.begin(), 1);
    a.insert(a.begin(), 12);
    a.insert(a.end(), 3);
    for (auto it : a)
        cout << it << " ";
    cout << endl;
    b.insert(b.begin(), 11);
    b.insert(b.begin(), 112);
    b.insert(b.end(), 33);
    for (auto it : b)
        cout << it << " ";
    cout << endl;
    a.merge(b);
    for (auto it : a)
        cout << it << " ";
    cout << endl;
    system("pause");
    return 0;
}