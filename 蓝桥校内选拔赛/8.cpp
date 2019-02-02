#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010
struct card
{
    int a;
    int b;
};
card cards[N];
int n;
int ele[N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>cards[i].a;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>cards[i].b;
        }
        int ans=-1;
        for(int i=1;i<=n;i++)
        {
            int cnt=0;
            ele[cnt++]=cards[i].b;
            for(int j=1;j<=n;j++)
            {
                if(j==i) continue;
                ele[cnt++]=cards[j].a;
            }
            sort(ele,ele+cnt);
            /*
            for(int j=0;j<cnt;j++)
            {
                cout<<ele[j]<<" ";
            }
            */
            int pre=1;
            int temp;
            if(ele[0]!=1) 
            {
                temp=1;
                ans=max(ans,temp);
                continue;
            }
            for(int j=1;j<cnt;j++)
            {
                if(j==cnt-1)
                {
                    if(ele[j]==pre+1)
                    {
                        temp=ele[j]+1;
                    }
                    else temp=pre+1;
                    break;
                }
                else
                {
                    if(ele[j]!=pre+1)
                    {
                        temp=pre+1;
                        break;
                    }
                    else 
                    {
                        pre++;
                        continue;
                    }
                }
            }
            //cout<<"cur:"<<temp<<endl;
            ans=max(ans,temp);
        }
        cout<<ans<<endl;
    }
    return 0;
}