#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100010
vector<int> V[N];
int n,d,k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>d>>k)
    {
        int id,ts;
        for(int i=0;i<N;i++) V[i].clear();
        for(int i=0;i<n;i++)
        {
            cin>>ts>>id;
            V[id].push_back(ts);
        }
        for(int i=0;i<N;i++) sort(V[i].begin(),V[i].end());//是否需要放入一个大数组
        for(int i=0;i<N;i++)
        {
            if(V[i].size()<k) continue;
            /*
            for(auto ele:V[i])
            {
                //int pos1=lower_bound(V[i].begin(),V[i].end(),ele)-V[i].begin();//>=ele 
                //int pos2=lower_bound(V[i].begin(),V[i].end(),ele+d)-V[i].begin(); //>=ele+D
                //贪心 时间左端点为[ele,ele+D)
                //(pos2-1) - pos1 +1
                int num=pos2-pos1;
                if(num>=k)
                {
                    cout<<i<<endl;
                    break;
                }
            }
            */ 
            int ptr_s=0;
            int ptr_e=0;
            int len=V[i].size();
            while(ptr_s<len&&ptr_e<len)
            {
                while(V[i][ptr_e]<V[i][ptr_s]+d) ptr_e++;
                if(ptr_e>=len) ptr_e=len-1;
                else ptr_e--;
                int num=ptr_e-ptr_s+1;
                if(num<k)
                {
                    //cout<<"cur ptr:"<<ptr_s<<" "<<ptr_e<<" "<<num<<endl;
                    ptr_s++;
                    continue;
                }
                else
                {
                    //cout<<"cur ptr:"<<ptr_s<<" "<<ptr_e<<" "<<num<<endl;
                    cout<<i<<endl;
                    break;
                }
            }
           //尺取？ O(n)  双指针
        }
    }
}