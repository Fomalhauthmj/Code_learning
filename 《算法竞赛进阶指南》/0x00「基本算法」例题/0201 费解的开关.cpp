#include <iostream>
using namespace std;
int mat[5][5];
int n;
int Solve()
{
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
                cin >> mat[i][j];
        }
        cout << Solve() << endl;
    }
    system("pause");
    return 0;
}