//http://codeforces.com/contest/546/problem/C
#include <iostream>
#include <deque>
#include<map>
using namespace std;
deque<int> q1,q2;
int n,k1,k2;
#define pss pair<string,string>
map<pss,bool> m;
string Get(deque<int> &q)
{
    string ret="";
    for(auto it:q)
    {
        ret+=char(it-1+'0');
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n ;
    cin>>k1;
    int num;
    for(int i=0;i<k1;i++)
    {
        cin>>num;
        q1.push_back(num);
    }
    cin>>k2;
    for(int i=0;i<k2;i++)
    {
        cin>>num;
        q2.push_back(num);
    }
    int turns=0;
    bool flag=true;
    pss next=make_pair(Get(q1),Get(q2));
    m[next]=1;
    while(q1.size()&&q2.size())
    {
        int t1=q1.front(),t2=q2.front();
        q1.pop_front();q2.pop_front();
        if(t1>t2)
        {
            q1.push_back(t2);
            q1.push_back(t1);
        }
        else
        {
            q2.push_back(t1);
            q2.push_back(t2);
        }
        pss next=make_pair(Get(q1),Get(q2));
        //cout<<next.first<<" "<<next.second<<endl;
        if(m[next])
        {
            flag=false;
            break;
        }
        else m[next]=1;
        turns++;
    }
    if(flag) cout<<turns<<" "<<(q1.empty()?2:1)<<endl;
    else cout<<-1<<endl;
    //system("pause");
    return 0;
}