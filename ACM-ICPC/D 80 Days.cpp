#include<iostream>
using namespace std;
#define size 1000010
int n;
long long c;
struct node
{
    long long a;
    long long b;
};
node ns[size];
long long dp[size];//dp[i] 表示以i为出发点
long long sum;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        for(int i=1;i<=n;i++) 
        {
            cin>>ns[i].a;
        }
        for(int i=1;i<=n;i++) 
        {
            cin>>ns[i].b;
        }
        int ans=-1;
        sum=0;
        for(int i=1;i<=n;i++) //找出最小满足起点
        {
            sum=c;
            int start=i-1;
            while(sum>=0)
            {
                start++;
                if(start==(i+n)) break;
                if(start>n)
                {
                    sum+=ns[start-n].a;
                    sum-=ns[start-n].b;
                }
                else
                {
                    sum+=ns[start].a;
                    sum-=ns[start].b;
                }
            }
            if(start!=(i+n)) continue;
            else
            {
                ans=i;break;
            }
        }
        cout<<ans<<endl;
    }
}
//https://hihocoder.com/problemset/problem/1831
/*
100
3 0
3 4 5
5 4 3

3 0
5 4 3
3 4 5  

3 120
-3 -4 -5
30 40 50

3 0
6 4 5
5 7 3

6 1
1 4 3 -10 8 -7
0 0 0 0 0 0

1 0
3
0

1 1
-1
0

2 1
-1 1
0 0

2 0
-1 0
0 0

4 2
0 -2 1 -2
0 0 0 0

4 5
-2 1 -5 2
0 0 0 0



2
1
-1
3
5
1
1
1
-1
-1
2
*/