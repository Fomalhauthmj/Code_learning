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
    int i;
    int ok_cnt = 0;
    for (i = 0; i < len; i++)
    {
        if (vis[word[i]])
            break;
        else
        {
            ok_cnt = 1;
            continue;
        }
    }
    for (; i < len; i++)
    {
        if (vis[word[i]])
        {
            ok_cnt = 2;
            continue;
        }
        else
            break;
    }
    for (; i < len; i++)
    {
        if (vis[word[i]])
            break;
        else
        {
            ok_cnt = 3;
            continue;
        }
    }
    for (; i < len; i++)
    {
        if (vis[word[i]])
        {
            ok_cnt = 4;
            continue;
        }
        else
            break;
    }
    if (i == len && ok_cnt == 4)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    //system("pause");
    return 0;
}