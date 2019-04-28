#include <iostream>
#include <string>
using namespace std;
int judge(string s)
{
    int len = s.length();
    if (s.find("LOL") != string::npos)
        return -1;
    if (s.find("*") == string::npos)
        return 0;
    int balance = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '*')
        {
            s[i] = 'L';
            switch (judge(s))
            {
            case -1:
                return 1;
            case 0:
                balance = 1;
            }
            s[i] = 'O';
            switch (judge(s))
            {
            case -1:
                return 1;
            case 0:
                balance = 1;
            }
            s[i] = '*';
        }
    }
    if (balance)
        return 0;
    else
        return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string str;
    while (n--)
    {
        cin >> str;
        cout << judge(str) << endl;
    }
    return 0;
    //system("pause");
}