#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int a[9];
bool vis[9];
vector<vector<int> > v;
bool judge()
{
    int temp = a[0] + a[1] + a[2];
    if ((a[3] + a[4] + a[5]) != temp)
        return false;
    if ((a[6] + a[7] + a[8]) != temp)
        return false;
    if ((a[0] + a[3] + a[6]) != temp)
        return false;
    if ((a[1] + a[4] + a[7]) != temp)
        return false;
    if ((a[2] + a[5] + a[8]) != temp)
        return false;
    if ((a[0] + a[4] + a[8]) != temp)
        return false;
    if ((a[2] + a[4] + a[6]) != temp)
        return false;
    return true;
}
void Search(int step)
{
    if (step >= 9)
    {
        if (judge())
        {
            vector<int> temp;
            for (int i = 0; i < 9; i++)
                temp.push_back(a[i]);
            v.push_back(temp);
        }
        return;
    }
    for (int i = 0; i < 9; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            a[step] = i + 1;
            Search(step + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
    v.clear();
    Search(0);
    /*
    for (auto ele : v)
    {
        for (int i = 0; i < ele.size(); i++)
        {
            cout << ele[i];
            if (i % 3 != 2)
                cout << " ";
            else
                cout << endl;
        }
    }
    cout << v.size() << endl;//共8组
    */
    for (int i = 0; i < 9; i++)
        cin >> a[i];
    int ans_cnt = 0;
    int ans_pos = -1;
    for (int i = 0; i < v.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < 9; j++)
        {
            if (a[j] != v[i][j] && a[j] != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans_cnt++;
            ans_pos = i;
        }
    }
    if (ans_cnt == 1)
    {
        for (int i = 0; i < 9; i++)
        {
            cout << v[ans_pos][i];
            if (i % 3 == 2)
                cout << endl;
            else
                cout << " ";
        }
    }
    else
        cout << "Too Many" << endl;
    //system("pause");
    return 0;
}