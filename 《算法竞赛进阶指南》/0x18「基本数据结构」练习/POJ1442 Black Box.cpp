#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
const int N=3E4+50;
#define ll long long
int m,n;
ll a[N];
priority_queue<ll,vector<ll>,greater<ll> > pq1;//小根堆
priority_queue<ll> pq2;//大根堆
int main()
{
    cin>>m>>n;
    for(int i=0;i<m;i++) scanf("%lld",&a[i]);
    int num,pos=0;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        while(pos<num)
        {
            pq1.push(a[pos]);
            if(pq2.size()&&pq1.top()<pq2.top())
            {
                int temp1=pq1.top();
                int temp2=pq2.top();
                pq1.pop();pq2.pop();
                pq1.push(temp2);
                pq2.push(temp1);
            }
            pos++;
        }
        //cout<<pq1.size()<<" "<<pq2.size()<<endl;
        cout<<pq1.top()<<endl;
        int temp=pq1.top();
        pq1.pop();
        pq2.push(temp);
    }
    system("pause");
    return 0;
}