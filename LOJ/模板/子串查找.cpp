//KMP https://loj.ac/problem/103
#include <iostream>
#include <string>
using namespace std;
const int N = 1e6 + 50;
int next_KMP[N];
string str, p;
void Next(string &p)
{
    int i = 0;
    int len = p.length();
    int j = next_KMP[0] = -1;
    while (i < len)
    {
        while (j != -1 && p[i] != p[j])
            j = next_KMP[j];
        next_KMP[++i] = ++j;
    }
}
int KMP(string &str, string &p)
{
    Next(p);
    int len_str=str.length();
    int lenp=p.length();
    int i=0;
    int j=0;
    int count=0;
    while(i<len_str)
    {
        while(j!=-1&&str[i]!=p[j])
            j=next_KMP[j];
        i++;j++;
        if(j>=lenp)
        {
            count++;
            j=next_KMP[j];
        }
    }
    return count;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> str >> p;
    cout << KMP(str, p) << endl;
    //system("pause");
    return 0;
}