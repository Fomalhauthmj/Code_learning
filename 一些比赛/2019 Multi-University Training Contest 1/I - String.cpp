#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#define pii pair<int, int>
const int N = 1E5 + 50;
char str[N], ans[N];
int nxt[N][26], cnt[N][26], used[26], len,k;
pii p[26];
/*
构造固定长度的字典序最小的字符串子序列 使其满足所有限制
贪心 逐位考虑
nxt[i][26] i开始的后缀各字符最早出现位置
cnt[i][26] i开始的后缀各字符个数
*/
bool Judge(int pos,int cur_tot)
{
    int max_len=0;
    int need_len=0;
    for(int i=0;i<26;i++)
    {
        if(used[i]+cnt[pos][i]<p[i].first) return false;
        max_len+=used[i]+min(p[i].second-used[i],cnt[pos][i]);
        //已添加的字符数+剩余最大可添加字符数
        need_len+=max(p[i].first-used[i],0);
        //最少仍需添加字符数
    }
    if(max_len<k) return false;
    if(need_len+cur_tot>k) return false;
    return true;
}
int main()
{
    while (scanf("%s %d", str, &k) != EOF)
    {
        for (int i = 0; i < 26; i++)
            scanf("%d%d", &p[i].first, &p[i].second);
        len = strlen(str);
        memset(nxt, -1, sizeof(nxt));
        memset(cnt, 0, sizeof(cnt));
        memset(used,0,sizeof(used));
        for (int i = len - 1; i >= 0; i--)
        {
            for (int j = 0; j < 26; j++)
                nxt[i][j] = nxt[i + 1][j], cnt[i][j] = cnt[i + 1][j];
            nxt[i][str[i] - 'a'] = i, cnt[i][str[i] - 'a']++;
        }
        int pos = 0,tot=0;
        bool finish = true;
        while(pos<len&&tot<k)
        {
            bool flag = false;
            for (int i = 0; i < 26; i++)
            {
                if(nxt[pos][i]!=-1&&used[i]<p[i].second)
                {
                    used[i]++;
                    if(Judge(nxt[pos][i]+1,tot+1))
                    {
                        flag=true;
                        ans[tot++]='a'+i;
                        pos=nxt[pos][i]+1;
                        break;
                    }
                    used[i]--;
                }
            }
            if(!flag)
            {
                finish = false;
                break;
            }
        }
        ans[k]='\0';
        if (finish)
            printf("%s\n", ans);
        else
            printf("-1\n");
    }
    //system("pause");
    return 0;
}