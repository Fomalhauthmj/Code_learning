#include <iostream>
#include <math.h>
using namespace std;
#define N 100010
#define x first
#define y second
int n;
pair<long long, long long> pre_wind[N], start, ending,temp;
bool judge(long long mid)
{
    long long circle = mid / n;
    long long remind = mid % n;
    temp.x = circle * pre_wind[n].x + pre_wind[remind].x;
    temp.y = circle * pre_wind[n].y + pre_wind[remind].y;
    //曼哈顿距离  temp位置为消除风的影响位置 
    long long dis = abs(start.x+temp.x - ending.x) + abs(start.y+temp.y - ending.y);
    //cout << dis <<" "<<mid<< endl;
    if (dis <= mid)
        return true;
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> start.x >> start.y >> ending.x >> ending.y)
    {
        cin >> n;
        pre_wind[0].x = 0;
        pre_wind[0].y = 0;
        char ch;
        for (int i = 1; i <= n; i++)
        {
            cin >> ch;
            switch (ch)
            {
            case 'U':
                pre_wind[i].x = pre_wind[i - 1].x;
                pre_wind[i].y = pre_wind[i - 1].y + 1;
                break;
            case 'D':
                pre_wind[i].x = pre_wind[i - 1].x;
                pre_wind[i].y = pre_wind[i - 1].y - 1;
                break;
            case 'L':
                pre_wind[i].x = pre_wind[i - 1].x - 1;
                pre_wind[i].y = pre_wind[i - 1].y;
                break;
            case 'R':
                pre_wind[i].x = pre_wind[i - 1].x + 1;
                pre_wind[i].y = pre_wind[i - 1].y;
                break;
            }
        }
        //能否在k步中达到 消去风向影响的位置
        long long left = 0;
        long long right = 1e18 ;
        long long mid;
        long long ans = -1;
        bool can = false;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (judge(mid))
            {
                can = true;
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        if (can)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
}