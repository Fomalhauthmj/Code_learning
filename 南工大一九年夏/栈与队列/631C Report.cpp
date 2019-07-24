//http://codeforces.com/contest/631/problem/C
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 2e5 + 50;
#define pii pair<int, int>
int n, m;
int a[N], temp[N];
//对于最后的序列来说 只受最后处理的影响
//我们希望维护一个操作范围递减的处理序列
pii stack[N];
int top;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ti, ri;
    top = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> ti >> ri;
        if (top > 0 && ri < stack[top].second)
        {
            stack[++top] = make_pair(ti, ri);
        }
        else
        {
            while (top > 0 && ri >= stack[top].second)
            {
                top--;
            }
            stack[++top] = make_pair(ti, ri);
        }
    }
    for (int i = 1; i <= stack[1].second; i++)
    {
        temp[i] = a[i];
    }
    sort(temp + 1, temp + 1 + stack[1].second);
    int left = 1, right = stack[1].second;
    stack[top + 1] = make_pair(0,0);
    for (int i = 2; i <= top+1; i++)
    {
        if (stack[i-1].first==1)
        {
            //升序
            for (int j = stack[i-1].second; j > stack[i].second; j--)
            {
                a[j] = temp[right--];
            }
        }
        else
        {
            //降序
            for (int j = stack[i - 1].second; j > stack[i].second; j--)
            {
                a[j] = temp[left++];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    //system("pause");
    return 0;
}