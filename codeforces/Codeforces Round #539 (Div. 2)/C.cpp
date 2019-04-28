#include <cstring>
#include <iostream>
using namespace std;
#define N 300030
long long n;
int a[N]; //0-2^20->10^6
int cnt[2][1 << 21];
void Solve()
{
    //两种情况 左奇 右偶  或者 左偶 右奇
    //统计
    long long res = 0;//结果
    long long xors = 0;//前缀异或值
    cnt[0][0] = 1;//初始化 对应样例是2 2 异或值为0时存在一组解 所以cnt[0][0]=1
    //cnt[1][0]无需 因为只有2  不存在解
    for (int i = 1; i <= n; i++)
    {
        xors ^= a[i];//更新异或值
        res += cnt[i%2][xors];//结果增加 之前的同奇偶同异或值计数值
        //对应xors[i-1]==xors[j] 所以同奇偶
        cnt[i % 2][xors]++;//更新计数值
    }
    cout << res << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        Solve(); //O(n)
    }
}