#include <iostream>
#include <string>
using namespace std;
string l;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cin >> l;
    for (int num = 1; num <= 20; num++)
    {
        int temp = 0;
        for (int i = 0; i <= num; i++)
        {
            for (int j = 0; j + i <= num; j++)
            {
                if (i + j == (i ^ j))
                {
                    //cout << i << " " << j << endl;
                    temp++;
                }
            }
        }
        cout << num << " " << temp - 1 - num * 2 << endl;
    }
    system("pause");
    return 0;
}