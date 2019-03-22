#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string str;
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
                j = ptr[j - 1];
            else
            {
                ptr[i] = 0;
                i++;
            }
        }
    }
    return ptr;
}
int KMP(string s, string p)
{
    int *next = Get_next(p);
    int i = 0;
    int j = 0;
    int lens = s.length();
    int lenp = p.length();
    while (i < lens)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
            if (j >= lenp)
                return i - j;
        }
        else
        {
            if (j != 0)
                j = next[j - 1];
            else
                i++;
        }
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    int len = str.length();
    int i;
    int pos;
    for (i = 1; i <= len; i++)
    {
        //X>=0 X=0 k=1 X>0 k=3
        //按三段计算显然找到最长的前后缀即可
        //加上middle段 长度需为奇数
        string temp = str.substr(len - i, i);
        reverse(temp.begin(), temp.end());
        int temp_pos = KMP(str, temp);
        if (temp_pos != -1)
        {
            pos = temp_pos;
            //cout << temp << endl;
        }
        else
            break;
    }
    i--;
    if (len - i > pos + i - 1)
    {
        cout << 3 << endl;
        cout << pos + 1 << " " << i << endl;
        cout << pos + i + 1 << " " << 1 << endl;
        cout << len - i + 1 << " " << i << endl;
    }
    else
    {
        cout << 1 << endl;
        cout << pos + 1 << " " << i << endl;
    }

    /*
    AB middle C 
    A prefix B middle C suffix
    */
    //system("pause");
    //5%
    return 0;
}