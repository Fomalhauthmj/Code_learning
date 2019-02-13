TODO : 方法一
#include <iostream>
#include <math.h>
       using namespace std;
long long GCD(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
long long special[] = {
    0, 1, 1, 5, 1,
    21, 1, 85, 73, 341,
    89, 1365, 1, 5461, 4681,
    21845, 1, 87381, 1, 349525,
    299593, 1398101, 178481, 5592405, 1082401,
    22369621, 19173961};
long long pow2[] = {
    1, 2, 4, 8, 16,
    32, 64, 128, 256, 512,
    1024, 2048, 4096, 8192, 16384,
    32768, 65536, 131072, 262144, 524288,
    1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    long long num;
    while (q--)
    {
        cin >> num;
        bool finish = false;
        for (int i = 0; i < 27; i++)
        {
            if (num + 1 == pow2[i])
            {
                int temp = floor(log2(num));
                cout << special[temp] << endl;
                finish = true;
            }
        }
        if (finish)
            continue;
        int temp = floor(log2(num));
        cout << pow2[temp] * 2 - 1 << endl;
    }
}
