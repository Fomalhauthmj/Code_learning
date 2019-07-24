//http://codeforces.com/contest/91/problem/B
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1E5+50;
int a[N],ans[N],n;
vector<int> vpos;
vector<int> vage;
//我们希望这个队列从队头开始年龄递减
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=n;i>=1;i--)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(vpos.size()&&a[vpos.back()]<a[i])
        {
            int pos=lower_bound(vage.rbegin(),vage.rend(),a[i])-vage.rbegin();
            pos--;
            pos=vage.size()-1-pos;
            ans[i]=i-vpos[pos]-1;
        }
        else if(vpos.empty()||a[vpos.back()]>=a[i]) ans[i]=-1,vpos.push_back(i),vage.push_back(a[i]);
    }
    for(int i=n;i>=1;i--)
        cout<<ans[i]<<" ";
    cout<<endl;
    //system("pause");
    return 0;
}