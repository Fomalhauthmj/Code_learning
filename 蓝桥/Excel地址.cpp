#include <iostream>
#include <map>
#include <stack>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<int, char> m;
    char ch = 'A';
    for (int i = 1; i <= 26; i++)
    {
        m[i] = ch++;
    } //建立映射
    long long num;
    cin >> num;
    stack<char> s;
    while (num > 0)
    {
        int temp = num % 26;
        if (temp == 0)
            temp = 26;
        s.push(m[temp]);
        num = (num - temp) / 26;
        cout << num << endl;
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    system("pause");
    return 0;
}