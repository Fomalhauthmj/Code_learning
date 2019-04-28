#include <cstring>
#include <iostream>
#include <string>
#define N 1010
using namespace std;
bool va[N];
bool vb[N];
char chs[] = {'a', 'e', 'i', 'o', 'u'};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    while (cin >> a >> b)
    {
        int lena = a.length();
        int lenb = b.length();
        if (lena != lenb)
        {
            cout << "No" << endl;
            continue;
        }
        memset(va, 0, sizeof(va));
        memset(vb, 0, sizeof(vb));
        for (int i = 0; i < lena; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (a[i] == chs[j])
                {
                    va[i] = 1;
                    break;
                }
            }
            for (int j = 0; j < 5; j++)
            {
                if (b[i] == chs[j])
                {
                    vb[i] = 1;
                    break;
                }
            }
        }
        bool flag = false;
        for (int i = 0; i < lena; i++)
        {
            if (va[i] != vb[i])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
}