#include <iostream>
#include <string>
using namespace std;
int *Get_next(string &s)
{
    int len = s.length();
    int *ptr = new int[len];
    ptr[0] = 0;
    int i = 1;
    int j = 0;
    while (i < len)
    {
        if (s[i] == s[j])
        {
            ptr[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = ptr[j - 1];
            }
            else
            {
                ptr[i] = 0;
                i++;
            }
        }
    }
    return ptr;
}
int KMP(string &s, string &p)
{
    int *next = Get_next(s);
    int i = 0;
    int j = 0;
    int lens = s.length();
    int lenp = p.length();
    int ans = 0;
    while (i < lens)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
            if (j >= lenp)
            {
                //cout << "Cur:" << i - j << endl;
                ans++;
                j = next[lenp - 1];
                //为什么这里是j回到next[lenp-1]位置呢
                //当一个匹配找到时 s[i-j...i-1]==p
                //模式串j回到尾部next位置 继续下一匹配
            }
        }
        else
        {
            if (j != 0)
                j = next[j - 1];
            else
            {
                i++;
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s, p;
    while (n--)
    {
        cin >> p >> s;
        cout << KMP(s, p) << endl;
    }
    system("pause");
    //return 0;
}