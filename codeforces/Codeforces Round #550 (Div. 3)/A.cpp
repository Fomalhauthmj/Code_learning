#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int n;
int cnt[26];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    string str;
    bool flag;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        flag = true;
        memset(cnt, 0, sizeof(cnt));
        for (auto ele : str)
        {
            cnt[ele - 'a']++;
            if (cnt[ele - 'a'] > 1)
            {
                flag = false;
                break;
            }
        }
        bool start = 0;
        bool end = 0;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] == 0)
            {
                if(start)
                    end = true;
                else
                    continue;
            }
            else
            {
                if(!start)
                    start = true;
                if(!end)
                    continue;
                else
                    flag = false;
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    //system("pause");
    return 0;
}