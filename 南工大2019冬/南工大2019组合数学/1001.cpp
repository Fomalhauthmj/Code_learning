#include<iostream>
using namespace std;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--)
    {
        cin>>n;
        long long sum=0;
        long long max_kind=0;
        long long num;
        for(int i=0;i<n;i++)
        {
            cin>>num;
            if(num>max_kind) max_kind=num;
            sum+=num;
        }
        sum-=max_kind;
        if(sum>=max_kind-1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }   
}
/*
TODO:Vector 模拟 TLE
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> V;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--)
    {
        V.clear();
        cin>>n;
        int num;
        for(int i=0;i<n;i++)
        {
            cin>>num;
            V.push_back(num);
        }
        sort(V.begin(),V.end());
        int min_num;
        while(V.size()>1)
        {
            min_num=V[0];
            int len=V.size();
            for(int i=0;i<len;i++)
            {
                V[i]-=min_num;
                if(V[i]==0) V[i]=-1;
            }
            int k=upper_bound(V.begin(),V.end(),-1)-V.begin();
            V.erase(V.begin(),V.begin()+k);
        }
        if(V.size()==0) 
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(V[0]!=1) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}
*/