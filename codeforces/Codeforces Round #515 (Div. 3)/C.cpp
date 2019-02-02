#include<iostream>
#include<algorithm>
using namespace std;
#define N 200010
int q;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    char ch;
    int id;
    int ans;
    while(cin>>q)
    {
        int left,right;
        left=right=0;
        cin>>ch>>id;
        a[id]=0;
        left=-1,right=1;
        //我们假设一个无限长的数轴 以原点x=0为放第一本书的坐标 以left,right 分别表示当前左右可放的下一位置
        //以a[id] 记录书放置的坐标
        //init:left=right=0,放第一本书后:left=-1,right=1; 
        for(int i=2;i<=q;i++)
        {
            cin>>ch>>id;
            if(ch=='L')
            {
                a[id]=left;//放在左边
                left--;
            }
            else if(ch=='R')
            {
                a[id]=right;//放在右边
                right++;
            }
            else if(ch=='?')
            {
                //计算最小坐标差，注意-1 因为是left,right都是下一坐标
                ans=min(a[id]-left,right-a[id])-1;
                //cout<<"left:"<<a[id]-left-1<<endl;
                //cout<<"right:"<<right-a[id]-1<<endl;
                cout<<ans<<endl;
            }
        }
    }
}