#include<iostream>
#include<cstring>
using namespace std;
#define N 10
#define MAX 50
int c1[MAX];
int c2[MAX];
int val[N];
int num[N];
int n,k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=0;i<k;i++)
        {
            cin>>val[i]>>num[i];//学分为val的课有num门
        }
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        //for(int i=0;i<=num[0];i++) c1[val[0]*i]=1;//初始化
        c1[0]=1;//也可这样初始化 多一层循环
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<=num[i];j++)
            {
                for(int k=0;k<MAX&&k+val[i]*j<MAX;k++)
                {
                    c2[k+j*val[i]]+=c1[k];
                }
            }
            for(int j=0;j<MAX;j++)
            {
                c1[j]=c2[j];//更新下一层
                c2[j]=0;
            }
        }
        cout<<c1[n]<<endl;
    }
}