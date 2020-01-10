#include <cstring>
#include <iostream>
#include <string>
using namespace std;
string word;
bool vis[1000];
int main()
{
    memset(vis, 0, sizeof(vis));
    vis['a'] = vis['e'] = vis['i'] = vis['o'] = vis['u'] = true;
    cin >> word;
    int len = word.length();
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < len; i++)
    {
        if (vis[word[i]])
            cnt1++;
        else
            cnt2++;
    }
    cout << cnt1 << endl;
    cout << cnt2 << endl;
    //system("pause");
    return 0;
}