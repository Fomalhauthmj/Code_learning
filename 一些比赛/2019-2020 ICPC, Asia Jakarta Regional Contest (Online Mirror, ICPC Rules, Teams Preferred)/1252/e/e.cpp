/* 
 * Author: Hemengjie
 * Time: 2019-11-08 20:52:42
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e5 + 50;
int a[MAX], b[MAX];
int low[MAX], high[MAX];
int N, L, R, K;
void Init(int i)
{
    if (i == N)
        low[i] = L, high[i] = R;
    else
    {
        if (a[i] < a[i + 1])
            low[i] = max(L, low[i + 1] - K), high[i] = high[i + 1] - 1;
        else if (a[i] == a[i + 1])
            low[i] = low[i + 1], high[i] = high[i + 1];
        else if (a[i] > a[i + 1])
            low[i] = low[i + 1] + 1, high[i] = min(R, high[i + 1] + K);
    }
}
//[l1,r1] [l2,r2] 交集最小
int GetMinVal(int l1,int r1,int l2,int r2)
{
    if(l2>=l1)
        return l2;
    if(l1>l2)
        return l1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> L >> R >> K;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = N; i >= 1; i--)
        Init(i);
    bool flag = true;
    for (int i = 1; i <= N; i++)
        if (low[i] > R || high[i] < L)
            flag = false;
    b[1]=low[1];
    for (int i = 2; i <= N; i++)
    {
        if(a[i]>a[i-1]) b[i]=GetMinVal(b[i-1]+1,b[i-1]+K,low[i],high[i]);
        else if(a[i]==a[i-1]) b[i]=b[i-1];
        else if(a[i]<a[i-1]) b[i]=GetMinVal(b[i-1]-K,b[i-1]-1,low[i],high[i]);
    }
    if (flag)
    {
        for (int i = 1; i <= N; i++)
            cout << b[i] << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;
    //system("pause");
    return 0;
}