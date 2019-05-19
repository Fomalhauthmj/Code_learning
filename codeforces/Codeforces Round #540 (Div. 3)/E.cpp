/*
#include <iostream>
using namespace std;
#define N 200020
long long n, k;
//配对：最多C[k][2]*2种二元有序对 max=k*k(k-1)/2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> k)
    {
        long long max_kinds = k * (k - 1);
        if (n > max_kinds)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            cout << "YES" << endl;
            int cnt = 0;
            int dis = 1; //代表间距
            int left = 1;
            int right;
            bool flag = false;
            pair<int, int> pre;
            while (cnt < n)
            {
                right = left + dis;
                if (left <= k && right <= k && left > 0 && right > 0 && left != right)
                {
                    flag = pre.first == left || pre.second == right;
                    if (flag)
                        cout << right << " " << left << endl;
                    else
                        cout << left << " " << right << endl;
                    cnt++;
                    if (cnt >= n)
                        break;
                    if (!flag)
                    {
                        cout << right << " " << left << endl;
                        pre.first = right;
                        pre.second = left;
                    }
                    else
                    {
                        cout << left << " " << right << endl;
                        pre.first = left;
                        pre.second = right;
                    }
                    cnt++;
                    if (cnt >= n)
                        break;
                }
                else
                {
                    //溢出范围
                    //修改间距
                    left = 0;
                    dis++;
                }
                left++;
            }
        }
    }
}
*/
//!:题解
#include <iostream>
using namespace std;
long long n, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> k)
    {
        if (n > k * (k - 1))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            int cur = 0;
            for (int i = 0; i < n; i++)
            {
                cur += (i % k == 0);
                cout << i % k + 1 << " " << (cur + i % k) % k + 1 << endl;
                //左边循环是1.2...k的重复循环 右边循环是+cur%k的循环
            }
        }
    }
}