#include <iostream>
#include <set>
#include <string>
using namespace std;
string str;
bool judge(string s)
{
    //判断回文串
    int len = s.length();
    int left = 0;
    int right = len - 1;
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> str)
    {
        int len = str.length();
        set<char> s;
        for (int i = 0; i < len; i++)
        {
            s.insert(str[i]);
        }
        int cnt = s.size();
        if (cnt < 2) //只有1种显然无解
        {
            cout << "Impossible" << endl;
            continue;
        }
        //最少切1-2
        //cut=1
        bool finish = false;
        for (int i = 1; i <= len / 2; i++)
        {
            string temp = str.substr(i, len - i) + str.substr(0, i);
            //cout << temp << endl;
            if (judge(temp) && temp != str)
            {
                cout << 1 << endl;
                finish = true;
                break;
            }
        }
        if (finish)
            continue;
        //cut=2
        for (int i = 1; i <= len / 2; i++)
        {
            string temp = str.substr(len - i, i) + str.substr(i, len - 2 * i) + str.substr(0, i);
            //cout << temp << endl;
            if (judge(temp) && temp != str)
            {
                cout << 2 << endl;
                finish = true;
                break;
            }
        }
        if (finish)
            continue;
        else
            cout << "Impossible" << endl;
    }
}