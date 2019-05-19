#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e5 + 50;
int n;
long long a[N];
int ans[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 2*n; i >=1; i--)
    {
        if (a[i] > 1)
        {
            ans[i]=1;
            //必胜
            int j = i;
            while (a[j] == 1 && j <= i + n - 1)
            {
                ans[j] = !ans[j + 1];
                j++;
            }
            i = j - 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i])
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
    //system("pause");
    return 0;
}
/*
这题一开始想的是给出n堆石子，每次从左边拿，求必胜必败态。后面感觉可以直接出成一个环，思路还是一样的。
考虑n堆石子，每次从左边拿
如果最左边的石子数目为1，那么只能拿1个石子，那么它的必胜必败态就和下一个位置的必胜必败态相反
*/
//!:如果最左边的石子数目大于1，那么可以全部拿掉，可以拿得只剩下1个，这两种状态一定存在一个必败态，所以它是必胜态。
//!: 对于最左边，全部拿掉后假设落入必败态，则全拿
//!: 全部拿掉后假设落入必胜态，则拿得只剩一个 此时为必败态
/*
如果是环的话，那就直接变成2∗n−1长度的链来做也是一样的，逆序扫一遍即可
*/