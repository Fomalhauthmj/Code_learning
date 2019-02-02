#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define max 5010
struct node
{
    int len;
    int wei;
    bool isprocessed;
};
bool cmp(const node & n1,const node &n2)
{
    if(n1.len==n2.len) return n1.wei>n2.wei;
    return n1.len>n2.len;
}
node w[max];
int main()
{
    int t;
    cin>>t;
    int len;
    int wei;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>w[i].len>>w[i].wei;
            w[i].isprocessed=0;
        }
        sort(w+1,w+1+n,cmp);
        int prewei=99999;
        int res=0;
        for(int i=1;i<=n;i++)
        {
            if(w[i].isprocessed==0)
            {
                prewei=w[i].wei;
                res++;
                for(int j=i;j<=n;j++)
                {
                    if(w[j].wei<=prewei&&w[j].isprocessed==0)
                    {
                        prewei=w[j].wei;
                        w[j].isprocessed=1;
                    }
                }
            }
        }
        cout<<res<<endl;
    }
}