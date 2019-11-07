#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1010
const int inf = 1e9;
map<int,bool> used;
int random(int n)
{
    return (ll)rand() * rand() % n;
}
int R[MAX];
int main()
{
    freopen("data.in", "w", stdout);
    srand((unsigned)time(0));
    int N,M,Q;
    N=1000;
    M=1000;
    Q=100;
    cout<<N<<" "<<M<<" "<<Q<<endl;
    for(int i=1;i<=N;i++)
    {
        int val=random(inf);
        while(used.find(val)!=used.end())
            val=random(inf);
        cout<<val<<" ";
        used[val]=true;
    }
    cout<<endl;
    for(int i=1;i<=M;i++)
    {
        R[i]=random(N-1)+1;
        cout<<R[i]<<" ";
        for(int j=1;j<=R[i];j++)
        {
            int val=random(inf);
            while(used.find(val)!=used.end())
                val=random(inf);
            cout<<val<<" ";
            used[val]=true;
        }
        cout<<endl;
    }
    for(int i=1;i<=Q;i++)
    {
        int x=random(M)+1;
        int y=random(R[x])+1;
        int val=random(inf);
        while(used.find(val)!=used.end())
            val=random(inf);
        cout<<x<<" "<<y<<" "<<val<<endl;
        used[val]=true;
    }
    //system("pause");
    return 0;
}