//TODO:最大多子段和
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000010
#define inf 0x3f3f3f3f
int s[N];
int m,n;
int pre[N];//pre[i],cur[i]:前j个元素的多段最大和 滚动数组优化 处理未知范围的m
int cur[N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>m>>n)
    {
        for(int i=1;i<=n;i++) cin>>s[i];
        memset(cur,0,sizeof(cur));//当前段
        memset(pre,0,sizeof(pre));//上一段
        int cur_max;//记录一段的最大和
        for(int i=1;i<=m;i++)//共m段
        {
            cur_max=-inf;//每一段最大和初始化-inf
            for(int j=i;j<=n;j++)//注意这里从i开始循环 因为每个子序列最少1个元素 
            {
                if(i==j) cur[j]=pre[j-1]+s[j];//第i个元素只能是第i个子序列的首位
                else cur[j]=max(pre[j-1],cur[j-1])+s[j];
                //pre[j-1]+s[j]:前j-1个数分成i-1组的最大和,第j个数成为第i组
                //cur[j-1]+s[j]:前j-1个数分成i组,第j个数加入第i组
                //其中pre[j-1] 是上一段[1,j-1]中的最大和  cur[j-1]是当前段的前一位最大和
                pre[j-1]=cur_max;//不能更新pre[j](会被当前段循环使用),更新下一段pre[j-1] cur_max为前一位的最大和
                cur_max=max(cur_max,cur[j]);//更新当前段中最大和供下一位使用
            }
        }
        cout<<cur_max<<endl;//最后cur_max保存的恰为第m层中最大和==answer
    }
}