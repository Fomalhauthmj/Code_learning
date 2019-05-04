#include<iostream>
#include<cstring>
using namespace std;
#define N 11
int n;
bool judge_1r[1<<8][1<<8];//预处理数组 判断相隔一行
bool judge_2r[1<<8][1<<8];//判断相隔两行
int row[8];//存储每一行状态
int dp[2][12][1<<8][1<<8]; //dp[当前行][放置个数][前一行状态][前两行状态]
int s_cnt[1<<8];
int get_1_bit(int x)
{
    int ret=0;
    while(x>0)
    {
        x-=x&(-x);
        ret++;
    }
    return ret;//获得该状态下骑士的数量
}
void init()
{
    for(int i=0;i<(1<<8);i++)
    {
        s_cnt[i]=get_1_bit(i);
        for(int j=0;j<(1<<8);j++)//枚举相关两行的的状态
        {
            //1表示骑士 0表示空位
            //相隔一行的两位  相隔两行的一位 为不合法状态
            if((i<<1)&j) judge_2r[i][j]=1;
            if((i<<2)&j) judge_1r[i][j]=1;
            if((j<<1)&i) judge_2r[i][j]=1;
            if((j<<2)&i) judge_1r[i][j]=1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    //根据骑士的下法可知 每行的下法数量由其前两行决定
    //骑士不会对同行同列的棋子造成影响
    //递推方程
    memset(judge_1r,0,sizeof(judge_1r));
    memset(judge_2r,0,sizeof(judge_2r));
    init();
    while(T--)//t组测试数据
    {
        cin>>n;
        char ch;
        for(int i=0;i<8;i++)
        {
            row[i]=0;
            for(int j=0;j<8;j++)
            {
                cin>>ch;
                if(ch=='*')
                {
                    //皇后不可放置 设为0
                    row[i]<<=1;
                }
                else if(ch=='.')
                {
                    //空位可放置 设为1
                    row[i]=(row[i]<<1)|1;
                }
            }
            //cout<<"cur row:"<<row[i]<<endl;
        }
        memset(dp,0,sizeof(dp));//初始化
        dp[0][0][0][0]=1;//第0行放置0个状态为0 0 方案为1
        int cur=0;
        for(int i=0;i<8;i++)//当前行
        {
            for(int j=0;j<=n;j++)//已放置数量
            {
                for(int r=0;r<(1<<8);r++)//上一行状态
                {
                    for(int s=0;s<(1<<8);s++)//再上一行状态
                    {
                        if(dp[cur][j][r][s]==0) continue;//未计算
                        for(int t=0;t<(1<<8);t++)//当前行放置后状态
                        {
                            if((judge_2r[t][s]&&i>=2)||(judge_1r[t][r]&&i>=1)) continue;//出现不合法状态
                            if(s_cnt[t]+j>n) continue;//超过最大可放置数量
                            if((t&row[i])!=t) continue;
                            //TODO:假设当前行状态row[i]=11101111 0为皇后位 1为可放置位
                            //t为放置后状态 放置后状态必须为t
                            dp[cur^1][s_cnt[t]+j][t][r]+=dp[cur][j][r][s];//将当前计算结果放入下一层
                            //0^1=1 1^1=0
                        }
                    }
                }
            }
            //更新滚动数组
            memset(dp[cur],0,sizeof(dp[cur]));//cur=0上一层答案清空 准备放置下次计算结果
            cur^=1;//下一层
        }
        int ans=0;
        for(int i=0;i<(1<<8);i++)
        {
            for(int j=0;j<(1<<8);j++)
            {
                ans+=dp[cur][n][i][j];
            }
        }
        cout<<ans<<endl;
        //未使用滚动数组优化 29000+KB 接近32768K的上限
        //使用滚动数组优化   7700+KB 2/9