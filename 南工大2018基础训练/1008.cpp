#include<iostream>
#include<set>
#include<map>
using namespace std;
struct node
{
    double score;
    string name;
};
set<string> winner;
map<string,double> m;
node c[1010];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        m.clear();
        for(int i=0;i<n;i++) 
        {
            cin>>c[i].name>>c[i].score;
        }
        for(int i=0;i<n;i++) 
        {
            m[c[i].name]+=c[i].score;
        }
        double max=-0x3f3f3f3f;
        map<string,double>::iterator it;
        for(it=m.begin();it!=m.end();it++)
        {
            if(it->second>max)
            {
                max=it->second;
                winner.clear();
            }
            if(max==it->second) winner.insert(it->first);
        }
        m.clear();
        for(int i=0;i<n;i++)
        {
            m[c[i].name]+=c[i].score;
            if(winner.count(c[i].name)&&m[c[i].name]>=max)
            {
                 cout<<c[i].name<<endl;
                 break;
            }
        }
    }
}