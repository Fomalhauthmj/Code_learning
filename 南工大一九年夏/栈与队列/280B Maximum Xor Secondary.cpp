//http://codeforces.com/contest/280/problem/B
#include <iostream>
#include<stack>
using namespace std;
const int N = 1E5 + 20;
int a[N];
int n;
stack<int> s;
/*
维护区间最大次大
单调递减栈 存放次大数 出栈时比较  从左到右 从右到左各一遍
 */
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        while(s.size()&&s.top()<=a[i])
        {
            ans=max(ans,a[i]^s.top());
            s.pop();
        }
        s.push(a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        while(s.size()&&s.top()<=a[i])
        {
            ans=max(ans,a[i]^s.top());
            s.pop();
        }
        s.push(a[i]);
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}