#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define size 500050
int city[size];
int low[size];
int answer;
int n;
int betterLIS()
{
    memset(low,0,sizeof(low));
    answer=1;//最大长度
    low[1]=city[1];
    for(int i=2;i<=n;i++)
    {
        if(city[i]>low[answer]) 
        {
            low[++answer]=city[i];
        }
        else
        {
            int repos=upper_bound(low+1,low+answer+1,city[i])-low;//lower upper均可
            low[repos]=city[i];
        }
    }
    return answer;
}
int main()
{
    ios::sync_with_stdio(false);
    int casenum=0;
    int poor,rich;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>poor>>rich;
            city[poor]=rich;
        } 
        cout<<"Case "<<++casenum<<":"<<endl;
        int count=betterLIS();
        if(count==1)
        {
            cout<<"My king, at most "<<count<<" road can be built."<<endl<<endl;
        }
        else cout<<"My king, at most "<<count<<" roads can be built."<<endl<<endl;
    }
}