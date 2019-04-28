#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str;
long long num_char;
vector<int> v;
vector<int> vch[26];
int main()
{
    //预处理
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int temp = ch;
        while (temp)
        {
            vch[ch - 'a'].push_back(temp % 2);
            temp /= 2;
        }
        vch[ch - 'a'].push_back(0);
        /*
        cout << ch << endl;
        for (auto ele : vch[ch - 'a'])
        {
            cout << ele << " ";
        }
        cout << endl;
        */
    }
    cin >> str;
    long long len = str.length();
    num_char = len / 3;
    for (int i = 0; i < len; i++)
    {
        int ch = str[i] - 'a';
        for (int j = 0; j < vch[ch].size(); j++)
        {
            v.push_back(vch[ch][j]);
        }
    }
    //每6位输出 共4*n个输出
    int pos = 0;
    int v_len = v.size();
    int cnt = 0;
    for (int i = 0; i < 4 * num_char; i++)
    {
        string temp;
        while (cnt < 6 && pos < v_len)
        {
            temp.append(1, v[pos] + '0');
            cnt++;
            pos++;
        }
        bitset<6> ans(temp);
        cout << ans.to_ulong() << " ";
        cnt = 0;
    }
    //system("pause");
    return 0;
}