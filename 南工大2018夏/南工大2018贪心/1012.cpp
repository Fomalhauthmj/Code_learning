#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
#define max 100010
// 2

// 4 22

// 5 7

// 3 6

// 3 21

// 正确答案是2
struct card
{
    long long h;
    long long w;
};
bool cmp(const card &c1,const card &c2)
{
    if(c1.h==c2.h) return c1.w<c2.w;
    return c1.h<c2.h;
}
card a[max];
card b[max];
multiset<long long> S;
multiset<long long>::iterator it;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        S.clear();
        for(int i=0;i<n;i++)
        {
            cin>>a[i].h>>a[i].w;
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i].h>>b[i].w;
        }
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);//从小到大
        int ans=0;
        int pos=0;
        for(int i=0;i<n;i++)
        {
            while(a[i].h>=b[pos].h&&pos<n)
            {
                S.insert(b[pos].w);
                pos++;//只插入一次
            }
            if(S.empty()) continue;
            it=S.upper_bound(a[i].w);
            if(S.size()>0&&it!=S.begin()) it--;
            if(S.size()>0&&*it<=a[i].w)
            {
                ans++;
                S.erase(it);
            }
        }
        cout<<ans<<endl;
    }
}