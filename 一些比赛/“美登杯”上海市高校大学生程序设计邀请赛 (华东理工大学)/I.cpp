#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int sum = 0;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        sum += num;
    }
    cout << min((sum >= a ? sum - b : sum), (sum >= c ? sum - d : sum)) << endl;
    //system("pause");
    return 0;
}
/*
5 10 5 15 10
1 2 3 4 5
5 20 20 30 30
1 2 3 4 5
5 5 5 10 5
1 2 3 4 5
*/