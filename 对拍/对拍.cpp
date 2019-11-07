#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int T = 1; T <= 20; T++)
    {
        cout << "cur Test #" << T << endl;
        system("C:/Users/lenovo/OneDrive/Code/random.exe"); //随机数据生成.exe
        double st = clock();
        system("C:/Users/lenovo/OneDrive/Code/sol.exe"); //我的测试程序.exe
        double ed = clock();
        system("C:/Users/lenovo/OneDrive/Code/std.exe"); //对照程序.exe
        if (system("fc data.out data.ans"))
        {
            puts("Wrong Answer");
            break;
        }
        else
            printf("Accepted, Test #%d Time: %.0lfms\n", T, ed - st);
    }
    system("pause");
    return 0;
}