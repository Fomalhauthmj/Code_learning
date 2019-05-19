#include <algorithm>
#include <iostream>
using namespace std;
#define N 105
int a[N];
int n, m;
bool judge(int day)
{
	int cur = 0;
	//取最大的k个元素为 每天第一杯
	//取次大的k个元素为 每天第二杯
	//如此往复
	//根据从大到小的顺序
	//a0 ak ...
	//a1 ak+1 ...
	//a2 ak+2 ...
	//ak-1 ak+3 ...
	for (int i = 0; i < n; i++)
	{
		cur += max(0, a[i] - i / day); //k个一组
	}
	if (cur >= m)
		return true;
	else
		return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		//一天可以喝多杯 但效果递减直到效果降为0 等待第二天 求最少天数
		//贪心 先喝效果最好的喝到没效果 等第二天？ 但是会浪费一部分效果  不如留到第二天充分发挥
		//dp? 递推方程怎么写? !:根据tag  并非dp而是贪心 为何？
		//贪心角度来考虑，一天要写尽可能多的页数 如何应对样例345
		//有可行解
		//根据题解 n不超过100 枚举每一天能否写完即可
		sort(a, a + n, greater<int>());
		int ans = N;
		int finish = false;
		for (int i = 1; i <= n; i++) //最多n天
		{
			if (judge(i))
			{
				ans = min(ans, i);
				finish = true;
                break;//找到就退出
            }
		}
		if (finish)
			cout << ans << endl;
		else
			cout << -1 << endl;
	}
}