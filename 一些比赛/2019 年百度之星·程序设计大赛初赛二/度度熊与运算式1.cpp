#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> ret;
bool vis[30];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;
        int len = str.length();
        int temp_cnt = 0, xor_cnt = 0;
        ret.clear();
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '?')
                temp_cnt++;
            else
            {
                if (temp_cnt)
                    ret.push_back(temp_cnt + 1), temp_cnt = 0;
                xor_cnt++;
            }
        }
        if (temp_cnt)
            ret.push_back(temp_cnt + 1);
        sort(ret.begin(), ret.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < ret.size(); i++)
        {
            bool flag = false;
            for (int j = 25; j >= 1; j--)
            {
                int temp = pow(2, j);
                if (temp <= ret[i] && !vis[j])
                {
                    vis[j] = 1;
                    ans += temp;
                    //cout << "add:" << temp << endl;
                    ret[i] -= temp;
                    flag = true;
                }
            }
            if (ret[i] == 1)
                xor_cnt++;
            else if (ret[i] > 1)
                xor_cnt += ret[i] - 1;
            if (flag)
                xor_cnt--;
        }
        xor_cnt++;
        if (xor_cnt & 1)
            cout << (ans ^ 1) << endl;
        else
            cout << ans << endl;
    }
    //system("pause");
    return 0;
}