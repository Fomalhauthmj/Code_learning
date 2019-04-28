#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#define N 20
#define M 1010
int n, m;
int a[N];
int b[M];
struct line
{
    int min_max; //0:min 1:max
    int tp0;     //0:a  1:b
    int id0;
    int tp1;
    int id1;
};
line ls[M];
long long fac(int num)
{
    if (num == 0)
        return 1;
    else
        return fac(num - 1) * num;
}
long long cal()
{
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            cnt1++;
    }
    return fac(cnt1) * fac(n - cnt1);
}
bool judge()
{
    int num_left;
    int num_right;
    for (int i = 0; i < m; i++)
    {
        if (!ls[i].tp0)
        {
            num_left = a[ls[i].id0 - 1];
        }
        else
        {
            num_left = b[ls[i].id0];
        }
        if (!ls[i].tp1)
        {
            num_right = a[ls[i].id1 - 1];
        }
        else
        {
            num_right = b[ls[i].id1];
        }
        if (ls[i].min_max)
        {
            b[i + 1] = max(num_left, num_right);
        }
        else
        {
            b[i + 1] = min(num_left, num_right);
        }
    }
    if (b[m])
        return true;
    return false;
}
long long temp;
void Search(int step, int num0, int num1)
{
    if (step >= n)
    {
        if (judge())
        {
            /*
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
            */
            temp += cal();
        }
        return;
    }
    if (num0 > 0)
    {
        a[step] = 0;
        Search(step + 1, num0 - 1, num1);
    }
    if (num1 > 0)
    {
        a[step] = 1;
        Search(step + 1, num0, num1 - 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m)
    {
        string str;
        char ch;
        for (int i = 0; i < m; i++)
        {
            cin >> str;
            ls[i].min_max = (str == "min") ? 0 : 1;
            cin >> ch;
            ls[i].tp0 = (ch == 'a') ? 0 : 1;
            cin >> ls[i].id0;
            cin >> ch;
            ls[i].tp1 = (ch == 'a') ? 0 : 1;
            cin >> ls[i].id1;
            /*
            字符串比较耗时过大 注意这里的处理
            */
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            temp = 0;
            Search(0, i - 1, n - i + 1);
            //cout << i << " " << temp << endl;
            ans += temp;
        }
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}