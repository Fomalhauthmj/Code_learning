#include <algorithm>
#include <iostream>
using namespace std;
#define N 16
int a[N];
int n;
bool judge(int left, int right)
{
    int *temp = new int[right - left + 1];
    for (int i = 0; i < right - left + 1; i++)
    {
        temp[i] = a[left + i];
    }
    sort(temp, temp + right - left + 1);
    for (int i = 0; i < right - left + 1; i++)
    {
        if (temp[i] != a[left + i])
            return false;
    }
    return true;
}
int Solve(int left, int right)
{
    if (judge(left, right))
        return right - left + 1;
    if (left == right)
        return 1;
    int mid = (left + right) >> 1;
    return max(Solve(left, mid), Solve(mid + 1, right));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << Solve(0, n - 1) << endl;
    //system("pause");
    return 0;
}