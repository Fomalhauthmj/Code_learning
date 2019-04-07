#include <iostream>
using namespace std;
#define N 505
int A[N][N];
int B[N][N];
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> B[i][j];
        }
    }
    bool yn = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (A[i][j] != B[i][j])
            {
                A[i][j] = !A[i][j];
                A[0][j] = !A[0][j];
                A[0][0] = !A[0][0];
                A[i][0] = !A[i][0];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i][0] != B[i][0])
        {
            yn = false;
            break;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (A[0][j] != B[0][j])
        {
            yn = false;
            break;
        }
    }
    if (yn)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    //system("pause");
    return 0;
}