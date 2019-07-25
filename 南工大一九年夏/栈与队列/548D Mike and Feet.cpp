//http://codeforces.com/contest/548/problem/D
#include <iostream>
using namespace std;
const int N = 2E5 + 50;
int n;
int ans[N], a[N];
int l[N], r[N];
int s[N], top;
//不同长度的非空连续子段最小值的最大值
//转换求 每个数作为区间内的最小数 区间长度？
//维护一个递增的单调栈
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    top = 0;
    s[0]=0;
    for (int i = 1; i <= n; i++)
    {
        while (top > 0 && a[i] <= a[s[top]])
        {
            top--;
        }
        l[i] = s[top];
        s[++top] = i;
    }
    top = 0;
    s[0]=n+1;
    for (int i = n; i >= 1; i--)
    {
        while (top > 0 && a[i] <= a[s[top]])
        {
            top--;
        }
        r[i] = s[top];
        s[++top] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        //cout << l[i] << " " << r[i] << endl;
        int len=r[i]-l[i]-1;
        ans[len]=max(ans[len],a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        ans[i]=max(ans[i],ans[i+1]);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    //system("pause");
    return 0;
}