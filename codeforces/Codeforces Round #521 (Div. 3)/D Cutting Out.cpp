#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 200020
int s[N];
int n,k;
int a[N];//记录每个数出现次数
vector<pair<int,int>> V;
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
    return p1.second>p2.second;
}
vector<int> ans;
vector<int> temp_ans;
bool judge(int mid)
{
    temp_ans.clear();
    bool flag=false;
    for(auto ele:V)
    {
        int temp=ele.second;
        while(temp>=mid)
        {
            temp_ans.push_back(ele.first);
            temp-=mid;
            if(temp_ans.size()==k) 
            {
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    //cout<<"cur:"<<mid<<" bool:"<<flag<<endl;
    return flag;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>k)
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            a[s[i]]++;
        }
        V.clear();
        for(int i=1;i<N;i++)
        {
            if(a[i]!=0) V.push_back(make_pair(i,a[i]));//i及i的出现次数
        }
        sort(V.begin(),V.end(),cmp);//按出现次数由大到小排序
        /*
        for(auto ele:V)
        {
            cout<<ele.first<<" "<<ele.second<<endl;
        }
        */
        //二分搜索t
        int left=1;
        int right=N;
        int mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(judge(mid))
            {
                left=mid+1;
                ans=temp_ans;
            }
            else right=mid-1;
            //cout<<"next:"<<left<<" "<<right<<endl;
        }
        int len=ans.size();
        for(int i=0;i<len;i++)
        {
            if(i!=len-1) cout<<ans[i]<<" ";
            else cout<<ans[i]<<endl;
        }
    }
}