#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<string>
using namespace std;
map<char,int> m1;
map<char,int> m2;
multiset<int> s1;
multiset<int> s2;
string a,b;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>a>>b)
    {
        m1.clear();m2.clear();
        s1.clear();s2.clear();
        int lena=a.length();
        int lenb=b.length();
        for(int i=0;i<lena;i++) m1[a[i]]++;
        for(int i=0;i<lenb;i++) m2[b[i]]++;
        map<char,int>::iterator it;
        for(it=m1.begin();it!=m1.end();it++) s1.insert(it->second);
        for(it=m2.begin();it!=m2.end();it++) s2.insert(it->second);
        multiset<int>::iterator it1,it2;
        bool flag=1;
        for(it1=s1.begin(),it2=s2.begin();it1!=s1.end(),it2!=s2.end();it1++,it2++)
        {
            if(*it1!=*it2)
            {
                flag=0;break;
            }
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}