#include<iostream>
#include<set>
#include<algorithm>
#define max 100010
using namespace std;
struct object
{
    int time;
    int level;
};
object machine[max];
object task[max];
bool cmp(const object&o1,const object &o2)
{
    if(o1.time!=o2.time) return o1.time>o2.time;
    else return o1.level>o2.level;
};
multiset<int> S;
multiset<int>::iterator it;
//task's value=500*xi+2*yi
//output maxnum and maxvalue
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    int time,level;
    while(cin>>n>>m)
    {
        long long maxnum=0;
        long long maxvalue=0;
        S.clear();//注意容器的不清空导致WA
        for(int i=0;i<n;i++) cin>>machine[i].time>>machine[i].level;
        for(int i=0;i<m;i++) cin>>task[i].time>>task[i].level;
        sort(machine,machine+n,cmp);
        sort(task,task+m,cmp);
        int pos=0;
        for(int i=0;i<m;i++)
        {
            while(pos<n&&machine[pos].time>=task[i].time)
            {
                S.insert(machine[pos].level);
                pos++;
            }
            if(S.empty()) continue;
            it=S.lower_bound(task[i].level);
            if(it!=S.end())
            {
                maxnum++;
                maxvalue+=500*task[i].time+2*task[i].level;
                S.erase(it);
            }   
        }
        cout<<maxnum<<" "<<maxvalue<<endl;
    }
}