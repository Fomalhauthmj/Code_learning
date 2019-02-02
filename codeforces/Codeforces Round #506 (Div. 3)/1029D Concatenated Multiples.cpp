#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define size 200020
int n,k;
int a[size];
int len[size];
long long ans;//int 超出范围
vector<int> V[11];
long long x[11]={0,10,100,1000,10000,100000,
                    1000000,10000000,100000000,1000000000,10000000000
                };//预值 避免累乘
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>k)
    {
        for(int i=1;i<=10;i++) V[i].clear();
        for(int i=0;i<n;i++) 
        {
            cin>>a[i];
            len[i]=to_string(a[i]).length();//存储这个数字的位数
            V[len[i]].push_back(a[i]%k);//和式第一项 和式结果为0或k
        }
        for(int i=1;i<=10;i++) sort(V[i].begin(),V[i].end());//二分搜索必须有序 
        for(int i=1;i<=10;i++) x[i]%=k;//注意这里要根据k值处理乘法位数 不处理会WA
        ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=10;j++)
            {
                long long init=a[i]*x[j]%k;//和式第二项
                long long key=(k-init)%k;//这种处理方法考虑到了以下两种情况
                int num=upper_bound(V[j].begin(),V[j].end(),key)-lower_bound(V[j].begin(),V[j].end(),key);
                //if(key==0) num=upper_bound(V[j].begin(),V[j].end(),0)-lower_bound(V[j].begin(),V[j].end(),0);
                //第二项为0 和式必为0
                //else num=upper_bound(V[j].begin(),V[j].end(),k-key)-lower_bound(V[j].begin(),V[j].end(),k-key);
                //第二项不为0 和式必为k
                ans+=num;
                if(len[i]==j&&(init+a[i]%k)%k==0)//两个数位数相同 而且和式%k==0 init=a[i]*x[j]%k 和数形式为a[i]a[i]
                {
                    ans--;
                }
                //去掉相同位置组成和数的情况
            }
        }
        cout<<ans<<endl;
    }
}
