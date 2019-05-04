#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<string,int> m;
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        else
        {
            m.clear();
            for(int i=0;i<n;i++)
            {
                string str;
                cin>>str;
                m[str]+=1;
            }
            int max=-0x3f3f3f3f;
            string maxname;
            map<string,int>::iterator it;
            for(it=m.begin();it!=m.end();it++)
            {
                if(it->second>max)
                {
                    max=it->second;
                    maxname=it->first;
                }
            }
            cout<<maxname<<endl;
        }
    }
}