#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1010
vector<int> V[N];
int n,k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num;
    while(cin>>n>>k)
    {
        for(int i=0;i<k;i++) V[i].clear();
        for(int i=0;i<n;i++)
        {
            cin>>num;
            V[num%k].push_back(num);
        }
        for(int i=0;i<k;i++) sort(V[i].begin(),V[i].end(),greater<int>()) ;
        int ans=-1;
        for(int i=0;i<k;i++)
        {
            if(V[i].size()<3||(i*3)%k!=0) continue;
            int temp=V[i][0]+V[i][1]+V[i][2];
            ans=max(ans,temp);
        }
        for(int i=0;i<k;i++)
        {
            if(V[i].size()<2) continue;
            if(V[(2*k-2*i)%k].size()==0) continue;
            else 
            {
                int temp=V[i][0]+V[i][1]+V[(2*k-2*i)%k][0];
                ans=max(ans,temp);
            }
        }
        for(int i=0;i<k;i++)
        {
            if(V[i].size()==0) continue;
            for(int j=0;j<k;j++)
            {
                if(V[j].size()==0||i==j) continue;
                if(V[(2*k-i-j)%k].size()==0) continue;
                else 
                {
                    int temp=V[i][0]+V[j][0]+V[(2*k-i-j)%k][0];
                    ans=max(ans,temp);
                }
            }
        }
        cout<<ans<<endl;
    }
}