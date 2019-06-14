#include<bits/stdc++.h>
using namespace std;
#define ran 100010
vector<int> E[ran];
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            E[b-1].push_back(a);
        }
        int sum=0;
        int pre=-1;
        for(int i=1;i<=n;i++)
        {
            for(auto j:E[i])
            {
                if(j>pre)
                {
                    pre=i;
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
}
