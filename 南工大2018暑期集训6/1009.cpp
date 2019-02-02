#include<iostream>
#include<algorithm>
using namespace std;
#define size 500050
long long N,B;
long long peo[size];
long long sub[size];
bool judge(int mid)
{
    for(int i=0;i<N;i++) sub[i]=peo[i];
    int boxnum=0;
    for(int i=0;i<N;i++)
    {
        if(sub[i]>=mid)
        {
            while(sub[i]>=mid)
            {
                sub[i]-=mid;
                boxnum++;
            }
            if(sub[i]>0&&sub[i]<mid) boxnum++;
        }
        else boxnum++;
    }
    if(boxnum>B) return false;
    else return true;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>N>>B)
    {
        if(N==-1&&B==-1) break;
        for(int i=0;i<N;i++) cin>>peo[i];
        sort(peo,peo+N);
        if(N==B)
        {
            cout<<peo[N-1]<<endl;
            continue;
        }
        int left=0;
        int right=peo[N-1];
        int mid;
        while(left<right)
        {
            mid=(right+left)/2;
            if(judge(mid)==true) right=mid;
            else left=mid+1;
        }
        cout<<left<<endl;
    }
}