#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 1010
int n;
long long h;
long long a[N];
vector<long long> f;
bool judge()
{
    priority_queue<long long> temp;
    for (auto ele : f)
    {
        temp.push(ele);
    }
    long long H = h;
    long long first;
    long long second;
    while (!temp.empty())
    {
        if (H <= 0)
            return false;
        first = temp.top();
        temp.pop();
        if (!temp.empty())
        {
            second = temp.top();
            temp.pop();
            //cout << first << " " << second << endl;
            H -= max(first, second);
        }
        else
        {
            //cout << first << endl;
            H -= first;
        }
        //cout << "cur:" << H << endl;
    }
    if (H < 0)
        return false;
    else
        return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> h;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        f.push_back(a[i]);
        if (judge())
        {
            continue;
        }
        else
        {
            f.pop_back();
            break;
        }
    }
    cout << f.size() << endl;
    //system("pause");
    return 0;
}