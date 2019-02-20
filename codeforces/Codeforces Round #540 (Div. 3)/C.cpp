#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define N 22
long long n;
int a[N * N];
int matrix[N][N];
struct node
{
    int val;
    int num;
    node(int v, int n)
    {
        val = v;
        num = n;
    }
    bool operator<(const node &n) const
    {
        return num < n.num; //数量多的优先
    }
};
map<int, int> M;
set<int> S;
bool solve()
{
    priority_queue<node> Q;
    for (auto ele : S)
    {
        Q.push(node(ele, M[ele]));
    }
    memset(matrix, -1, sizeof(matrix));
    if (n & 1) //处理奇数
    {
        bool centre = false;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                node now = Q.top();
                Q.pop();
                //cout << "cur:" << now.val << " " << now.num << endl;
                if ((now.num & 1) && !centre)
                {
                    centre = 1;
                    matrix[n / 2][n / 2] = now.val;
                    now.num--;
                }
                if (now.num & 1 || now.num < 4)
                    return false;
                matrix[i][j] = now.val;
                matrix[n - 1 - i][n - 1 - j] = now.val;
                matrix[i][n - 1 - j] = now.val;
                matrix[n - 1 - i][j] = now.val;
                if (now.num - 4 > 0)
                {
                    Q.push(node(now.val, now.num - 4));
                    //cout << "will add:" << now.val << " " << now.num - 4 << endl;
                }
            }
        }
        for (int i = 0; i < n / 2; i++)
        {
            node now = Q.top();
            Q.pop();
            //cout << "cur:" << now.val << " " << now.num << endl;
            if ((now.num & 1) && !centre)
            {
                centre = 1;
                matrix[n / 2][n / 2] = now.val;
                now.num--;
            }
            if ((now.num & 1) && centre)
                return false;
            if (now.num < 2)
                return false;
            matrix[i][n / 2] = matrix[n - 1 - i][n / 2] = now.val;
            if (now.num - 2 > 0)
            {
                Q.push(node(now.val, now.num - 2));
                //cout << "will add:" << now.val << " " << now.num - 2 << endl;
            }
        }
        for (int i = 0; i < n / 2; i++)
        {
            node now = Q.top();
            Q.pop();
            //cout << "cur:" << now.val << " " << now.num << endl;
            if ((now.num & 1) && !centre)
            {
                centre = 1;
                matrix[n / 2][n / 2] = now.val;
                now.num--;
            }
            if ((now.num & 1) && centre)
                return false;
            if (now.num < 2)
                return false;
            matrix[n / 2][i] = matrix[n / 2][n - 1 - i] = now.val;
            if (now.num - 2 > 0)
            {
                Q.push(node(now.val, now.num - 2));
                //cout << "will add:" << now.val << " " << now.num - 2 << endl;
            }
        }
        //重判中心点
        if (!centre)
        {
            node now = Q.top();
            Q.pop();
            matrix[n / 2][n / 2] = now.val;
        }
    }
    else //处理偶数
    {
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                node now = Q.top();
                Q.pop();
                if (now.num & 1 || now.num < 4)
                    return false;
                matrix[i][j] = now.val;
                matrix[n - 1 - i][n - 1 - j] = now.val;
                matrix[i][n - 1 - j] = now.val;
                matrix[n - 1 - i][j] = now.val;
                if (now.num - 4 > 0)
                    Q.push(node(now.val, now.num - 4));
            }
        }
    }
    return true;
}
void output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1)
                cout << matrix[i][j] << " ";
            else
                cout << matrix[i][j] << endl;
        }
    }
}
/*
12321
46764
58985
46764
12321

1221
3443
3443
1221

*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        M.clear();
        S.clear();
        for (int i = 0; i < n * n; i++)
        {
            cin >> a[i];
            S.insert(a[i]); //元素种类数
            M[a[i]]++;      //元素个数
            //优先排数量少的元素
        }
        if (n == 1)
        {
            cout << "YES" << endl;
            cout << a[0] << endl;
            continue;
        }
        if (solve())
        {
            cout << "YES" << endl;
            output();
        }
        else
            cout << "NO" << endl;
    }
}