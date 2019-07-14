/*
 * File Created: Friday, 12th July 2019 10:47:20 am
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Saturday, 13th July 2019 11:50:30 pm
 * Copyright (c) 2019 北落师门
 */
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 505;
int c, n;
int sum[N][N];
int xpos[N], xcnt;
int ypos[N], ycnt;
pair<int, int> p[N];
int area(int r1, int c1, int r2, int c2)
{
    return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
    //包括边界
}
bool judge(int mid)
{
    int i1, j1;
    for (int i = xcnt; i >=1; i--)
    {
        for (int j = ycnt;j>=1; j--)
        {
            i1 = lower_bound(xpos + 1, xpos + xcnt + 1, xpos[i] - mid+1) - xpos;
            j1 = lower_bound(ypos + 1, ypos + ycnt + 1, ypos[j] - mid+1) - ypos;
            if (area(i1,j1,i,j)>= c)
                return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n;
    memset(sum, 0, sizeof(sum));
    xcnt = ycnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
        xpos[++xcnt] = p[i].first;
        ypos[++ycnt] = p[i].second;
    }
    sort(xpos + 1, xpos + xcnt + 1);
    sort(ypos + 1, ypos + ycnt + 1);
    xcnt = unique(xpos + 1, xpos + xcnt + 1) - xpos-1;
    ycnt = unique(ypos + 1, ypos + ycnt + 1) - ypos-1;
    //相对位置
    int r, c;
    for (int i = 0; i < n; i++)
    {
        r = lower_bound(xpos + 1, xpos + xcnt + 1, p[i].first) - xpos;
        c = lower_bound(ypos + 1, ypos + ycnt + 1, p[i].second) - ypos;
        //全局位置
        sum[r][c]++;
    }
    for (int i = 1; i <= xcnt+1; i++)
    {
        for (int j = 1; j <= ycnt+1; j++)
        {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    int left = 1;
    int right = 10000;
    int mid;
    while (left < right)
    {
        mid = (left + right) >> 1;
        //cout<<"cur "<<mid<<endl;
        if (judge(mid))
            right = mid;
        else
            left = mid + 1;
    }
    cout << left << endl;
    //system("pause");
    return 0;
}
/*
better another for this problem:
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 505;
const int M = 10050;
int c, n;
int sum[N][N], x[N], y[N];
int xpos[M], xcnt;
int ypos[M], ycnt;
pair<int, int> p[N];
int area(int r1, int c1, int r2, int c2)
{
    return sum[r2][c2] - sum[r2][c1] - sum[r1][c2] + sum[r1][c1];
}
bool judge(int mid)
{
    int i1,j1;
    for(int i=xpos[mid];i<=xcnt;i++)
    {
        for(int j=ypos[mid];j<=ycnt;j++)
        {
            //右上(i,j)
            //左下(i1,j1)
            i1=j1=0;
            if(x[i]>=mid) i1=xpos[x[i]-mid];
            if(y[j]>=mid) j1=ypos[y[j]-mid];
            if(area(i1,j1,i,j)>=c) return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n;
    memset(sum, 0, sizeof(sum));
    memset(xpos, 0, sizeof(xpos));
    memset(ypos, 0, sizeof(ypos));
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
        xpos[p[i].first] = 1;
        ypos[p[i].second] = 1;
    }
    xcnt = ycnt = 0;
    for (int i = 1; i <= 10000; i++)
    {
        if (xpos[i])
            x[++xcnt] = i;
        xpos[i] = xcnt;
        if (ypos[i])
            y[++ycnt] = i;
        ypos[i] = ycnt;
    }
    for (int i = 0; i < n; i++)
        sum[xpos[p[i].first]][ypos[p[i].second]]++;
    for (int i = 1; i <= xcnt; i++)
    {
        for (int j = 1; j <= ycnt; j++)
        {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    int left = 1;
    int right = 10000;
    int mid;
    while (left < right)
    {
        mid = (left + right) >> 1;
        //cout << "cur " << mid << endl;
        if (judge(mid))
            right = mid;
        else
            left = mid + 1;
    }
    cout << left << endl;
    //system("pause");
    return 0;
}
 */