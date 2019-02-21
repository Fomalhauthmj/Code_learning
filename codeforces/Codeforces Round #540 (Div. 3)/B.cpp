/*
#include <iostream>
using namespace std;
#define N 200020
long long n;
int a[N];
long long odd[N];
long long even[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        int ecnt = 1;
        int ocnt = 1;
        even[0] = odd[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i % 2 == 0)
            {
                even[ecnt] = even[ecnt - 1] + a[i];
                ecnt++;
            }
            else
            {
                odd[ocnt] = odd[ocnt - 1] + a[i];
                ocnt++;
            }
        }
        long long ans = 0;
        ocnt--;
        ecnt--;
        //ocnt=n/2+n%2  ecnt=n/2
        for (int i = 1; i <= n; i++)
        {
            if (i & 1) //奇数  此数之后的偶数变为奇数 奇数变为偶数 1 2 3 4 5 6
            {
                if (odd[i / 2] + even[ecnt] - even[i / 2] == odd[ocnt] - odd[i / 2 + 1] + even[i / 2])
                    ans++;
            }
            else //偶数 此数之后的奇数变为偶数 偶数变为奇数
            {
                if (odd[i / 2] + even[ecnt] - even[i / 2] == odd[ocnt] - odd[i / 2] + even[i / 2 - 1])
                    ans++;
            }
        }
        cout << ans << endl;
    }
}
*/
//TODO:更好的思路
#include<iostream>
using namespace std;
#define N 200020
long long n;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long pre_even, pre_odd, suf_even, suf_odd;
    while(cin>>n)
    {
        pre_even = pre_odd = suf_even = suf_odd = 0;
        for (int i = 1; i <= n;i++)
        {
            cin >> a[i];
            if(i&1)
                suf_odd += a[i];
            else
                suf_even += a[i];
        }
        long long ans = 0;
        for (int i = 1; i <= n;i++)
        {
            if(i&1)
                suf_odd -= a[i];
            else
                suf_even -= a[i];
            if(pre_even+suf_odd==pre_odd+suf_even)
                ans++;
            if(i&1)
                pre_odd += a[i];
            else
                pre_even += a[i];
        }
        cout << ans << endl;
    }
}