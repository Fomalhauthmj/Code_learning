#include <bits/stdc++.h>
using namespace std;
const int N=3e4+10;
priority_queue<int> q;
priority_queue<int, vector<int> ,greater<int> > q2;
int num[N],n,m,x;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&num[i]);
    int k=1;
    for(int i=1; i<=m; i++)
    {
        scanf("%d",&x);
        while(k<=x)
        {
            q2.push(num[k]);
            cout<<"min push "<<num[k]<<endl;
            if(!q.empty() && q.top()>q2.top())
            {
                int t=q.top();
                q.pop();
                cout<<"max pop "<<t<<endl;
                q2.push(t);
                cout<<"min push "<<t<<endl;
                t=q2.top();
                q2.pop();
                cout<<"min pop "<<t<<endl;
                q.push(t);
                cout<<"max push "<<t<<endl;
            }
            k++;
        }
        printf("%d\n",q2.top());
        int t=q2.top();
        q2.pop();
        cout<<"min pop "<<t<<endl;
        q.push(t);
        cout<<"max push "<<t<<endl;
    }
    system("pause");
    return 0;
}