#include<iostream>
#include<algorithm>
using namespace std;
#define N 1010
int n,r;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>r)
    {
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
        }
        int ans=0;
        int last_warmed_pos=0;//初始最后加热点
        while(last_warmed_pos<n)
        {
            int next_h_pos=-1;
            //这里这个条件用来限定h的范围//如果在最后加热点右侧没有合适的h 那就只能在其左侧找且不能为上一个所选h
            for(int i=n;i>max(0,last_warmed_pos-r+1);i--)//!:大于！！！！
            {
                if(a[i]==1&&i-r<=last_warmed_pos)//找到最右端的h使加热范围覆盖进入last_warmed_pos
                //注意这里的i-r<=last_warmed_pos 所找h的最左未加热部分要确保已加热
                //等价于i-r+1<=last_warmed_pos+1 所找h的最左加热起点要小于等于下一个加热点
                //而不是i-r+1<=last_warmed_pos 错误！！！
                {
                    next_h_pos=i;
                    //cout<<"next h:"<<next_h_pos<<endl;
                    break;
                }
            }
            if(next_h_pos==-1)
            {
                ans=-1;
                break;//找不到符合的h
            }
            ans++;
            last_warmed_pos=next_h_pos+r-1;//更新最后加热点
        }
        cout<<ans<<endl;
    }
}