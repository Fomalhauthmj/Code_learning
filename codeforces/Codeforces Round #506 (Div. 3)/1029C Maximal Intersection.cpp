#include<iostream>
#include<set>
using namespace std;
#define size 300030
int n;
pair<int,int> seg[size];
multiset<int> L;
multiset<int> R;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        L.clear();R.clear();
        for(int i=0;i<n;i++) 
        {
            cin>>seg[i].first>>seg[i].second;
            L.insert(seg[i].first);
            R.insert(seg[i].second);
        }
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            //L.erase(seg[i].first);
            //R.erase(seg[i].second);//错误 这里删除了所有值为seg[i].first seg[i].second 的元素
            L.erase(L.find(seg[i].first));
            R.erase(R.find(seg[i].second));//只删除一个
            //cout<<"L max:"<<*L.rbegin()<<" R min:"<<*R.begin()<<endl;
            //cout<<"nowlen:"<<*R.begin()-*L.rbegin()<<endl;
            maxlen=max(maxlen,(*R.begin()-*L.rbegin()));
            L.insert(seg[i].first);
            R.insert(seg[i].second);
        }
        cout<<maxlen<<endl;
    }
}