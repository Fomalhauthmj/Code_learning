#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 105
int n;
string strs[N * 2];
bool flag_p[N], flag_s[N];
char ans[N * 2];
int main()
{
    ios::sync_with_stdio(false);
    string max_str1 = " ";
    string max_str2 = " ";
    while (cin >> n)
    {
        memset(flag_p, 0, sizeof(flag_p));
        memset(flag_s, 0, sizeof(flag_s));
        for (int i = 1; i <= 2 * n - 2; i++)
        {
            cin >> strs[i];
            if (strs[i].length() == n - 1)
            {
                if (max_str1 == " ")
                {
                    max_str1 = strs[i];
                }
                else
                    max_str2 = strs[i];
            }
        }
        string init_str1 = max_str1 + max_str2[n-2]; //pre suf
        //cout<<init_str1<<endl;
        string init_str2 = max_str2 + max_str1[n-2]; //suf pre
        //cout<<init_str2<<endl;
        int count_1 = 0;
        int count_2 = 0;
        for (int i = 1; i <= 2 * n - 2; i++)
        {
            if (init_str1.substr(0, strs[i].length()) == strs[i]||init_str1.substr(n-strs[i].length())==strs[i])
                count_1++;
            if (init_str2.substr(0, strs[i].length()) == strs[i]||init_str2.substr(n-strs[i].length())==strs[i])
                count_2++;
        }
        string init_str;
        //cout<<init_str1<<" "<<count_1<<endl;
        //cout<<init_str2<<" "<<count_2<<endl;
        if (count_1 >= count_2)
            init_str = init_str1;
        else
            init_str = init_str2;
        for (int i = 1; i <= 2 * n - 2; i++)
        {
            int len=strs[i].length();
            if (flag_p[len]||flag_s[len])
            {
                if(flag_p[len]&&flag_s[len]) continue;
                if (flag_p[len])
                {
                    ans[i] = 'S';
                    flag_s[len]=1;
                }
                else if (flag_s[len])
                {
                    ans[i] = 'P';
                    flag_p[len]=1;
                }
                continue;
            }
            if (init_str.substr(0, len) == strs[i])
            {
                ans[i] = 'P';
                flag_p[len] = 1;
            }
            else
            {
                ans[i] = 'S';
                flag_s[len] = 1;
            }
        }
        for (int i = 1; i <= 2 * n - 2; i++)
            cout << ans[i];
        cout << endl;
    }
}