//http://codeforces.com/problemset/problem/416/D
#include<iostream>
using namespace std;
#define N 200020

long long n;
long long a[N]; //注意int 的溢出！
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long ans=0;
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
        }
        long long d;
        for(int i=1;i<=n;)
        {
            ans++;
            long long start=i;
            while(a[start]==-1&&start<=n) start++;
            if(start==n+1) break;//全部为-1
            long long end=start+1;
            while(a[end]==-1&&end<=n) end++;
            if(end==n+1) break; //只有一个不是-1
            long long dis=end-start;
            if((a[end]-a[start])%dis!=0) //start-end 无法构成等差数列  选取start-end-1
            {
                i=end;continue;//从end位开始寻找
            }
            else//可以构成等差数列
            {
                d=(a[end]-a[start])/dis;
                if(d>0&&a[start]-(start-i)*d<=0)//计算公差 若为递增则检验起点位的值是否为正
                {
                    i=end;continue; //不符合
                }
                long long newi=end+1;//向后扩展 计算结束位作为新起点
                while(newi<=n)  
                {
                    long long expectvalue=a[end]+(newi-end)*d;
                    if(a[newi]!=expectvalue&&a[newi]!=-1) break;
                    if(expectvalue<=0) break;
                    newi++;
                }
                i=newi;
            }
        }
        cout<<ans<<endl;
    }
}
//(a[j]-a[i])%(j-i)==0 可构成等差 公差为 /  前推 后推到不可位置再次开始
// #include <iostream>
// #include <vector>

// #define FOR(i, a, b) for(int i = a; i < b ; ++i)
// #define FORD(i, a, b) for(int i = a; i >= b; --i)

// using namespace std;

// template <typename T> vector<T> readVector(int n) { vector<T> res(n); for (int i = 0 ; i < n ; i++) cin >> res[i]; return res; }

// int main() {
// 	int n; cin >> n;
// 	auto a = readVector<long long>(n);
	
// 	int res = 0;
// 	for (int l = 0 ; l < n ; ) {
// 		res++;

// 		int i1 = l;
// 		while (i1 < n && a[i1] == -1) i1++;
		
// 		if (i1 == n) break; // there are no more fixed elements
		
// 		int i2 = i1 + 1;
// 		while (i2 < n && a[i2] == -1) i2++;
		
// 		if (i2 == n) break; // there is only one fixed element
		
// 		int dist = i2 - i1;
// 		if ((a[i2] - a[i1]) % dist) {
// 			l = i2;
// 			continue;
// 		}
		
// 		auto step = (a[i2] - a[i1]) / dist;
// 		if (step > 0 && a[i1] - step * (i1 - l) <= 0) {
// 			l = i2;
// 			continue;
// 		}

// 		int r = i2 + 1;
// 		while (r < n) {
// 			auto expectedValue = a[i2] + step * (r - i2);
			
// 			if (a[r] != -1 && a[r] != expectedValue) break;
// 			if (expectedValue <= 0) break;
// 			r++;
// 		}
// 		l = r;
// 	}
	
// 	cout << res;
// }