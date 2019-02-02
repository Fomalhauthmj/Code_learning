#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int len;
    int num;
    node(int i1,int i2)
    {
        len=i1;
        num=i2;
    }
    bool operator<(const node &n) const
    {
        return num<n.num;
    }
};
priority_queue<node> Q;
int main()
{
    int n;
    long long m;
    long long res;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        else
        {
            res=0;
            int len,num;
            while(!Q.empty()) Q.pop();
            for(int i=1;i<=n;i++)
            {
                cin>>len>>num;
                Q.push(node(len,num));
            }
            while(!Q.empty())
            {
                node now=Q.top();
                Q.pop();
                if(m>=now.len)
                {
                    m-=now.len;
                }
                else if(m>0&&m<now.len)
                {
                    now.len-=m;
                    m=0;
                    res+=now.len*now.num;
                }
                else if(m==0)
                {
                    res+=now.len*now.num;
                }
            }
            cout<<res<<endl;
        }

    }

}