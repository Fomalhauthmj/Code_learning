#include <iostream>
#include <string>
using namespace std;
int Next[1010];
void GetNext(string s)
{
    int i = 0;
    int j = -1;
    Next[0] = -1;
    int len = s.length();
    while (i < len)
    {
        while (j != -1 && s[i] != s[j])
            j = Next[j];
        i++;
        j++;
        if (s[i] == s[j])
            Next[i] = Next[j];
        else
            Next[i] = j;
    }
    for (int i = 0; i < len; i++)
    {
        cout << Next[i] << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    GetNext("abaabcac");
    GetNext("abcaababc");
    system("pause");
    return 0;
}