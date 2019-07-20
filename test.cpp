//单数据版本,NOIP可AC,Acwing WA了,后来修改多组数据,我也不知道为什么WA了.
#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define fir(i,a,b) for(int i=a;i<=b;i++)
const int N=1110;
int n,a[N],b[N],t[N],cnt=0;
char ans[N<<1];
bool flg = 1;
bool check(int x, int bi)
{
    if(!bi)//没有数字
        return 1;
    int i;
    for(i=x+1; i<=n; i++)
        if(t[i]>t[x] && t[i]>b[bi])
            break;
    fir(j,i+1,n)
    if(t[j]<t[x])
        return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    fir(i,1,n)
    cin>>t[i];
    a[0]=b[0]=INF;
    int ai=0,bi=0,ti=1,num=1;
    cnt=0;
    flg=1;
    fir(i,1,(n<<1))//2*N,是因为压入一次,还要弹出一次
    {
        if(a[ai] == num)//A数组栈顶应该弹出了
        {
            ai--;
            num++;
            ans[++cnt] = 'b';
        }
        else if(b[bi] == num)//B数组栈顶应该弹出了
        {
            bi--;
            num++;
            ans[++cnt] = 'd';
        }
        else if(ti<=n && t[ti]<a[ai] && check(ti, bi))//都满足了
        {
            a[++ai]=t[ti++];
            ans[++cnt]='a';//放入A数组
        }
        else if(ti<=n && t[ti]<b[bi])//A数组无法放入,那么B数组看能不能放入
        {
            b[++bi]=t[ti++];
            ans[++cnt]='c';
        }
        else//都无法放入,说明无法排序
        {
            flg=0;
            break;
        }
    }
    if(!flg)
        puts("0");
    else
    {
        fir(i,1,cnt)
        printf("%c ",ans[i]);
        puts("");
    }
    return 0;
}