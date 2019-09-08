#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int a[105],n;
bool Judge(int M)
{
    stack<int> s;
    deque<int> q;
    for(int i=0;i<n;i++) q.push_back(a[i]);
    while(q.size())
    {
        s.push(q.front());
        q.pop_front();
        for(int i=1;i<=M;i++)
        {
            q.push_back(q.front());
            q.pop_front();
        }
    }
     for(int i=n;i>=1;i--)
        if(s.top()!=i) return false;
        else s.pop();
    return true;
}
int main()
{
    int m;
    cin>>n>>m;
    for(int i=0;i<n;i++) a[i]=i+1;
    do
    {
        if(Judge(m))
        {
            cout<<"legal:"<<endl;
            for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
    } while (next_permutation(a,a+n));
    system("pause");
    return 0;
}