#include<iostream>
#include<set>
#include<math.h>
using namespace std;
#define N 100010
#define MAX 450
int n;
bool can;
set<int> S[MAX];
set<int>::iterator it;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        can=false;
        int k;//分成k个集合 每个集合k-1个元素
        for(int i=1;i<=sqrt(2*n);i++)
        {
            if(i*(i+1)==2*n)
            {
                k=i+1;
                can=true;
                break;
            }
        }
        if(!can)
        {
            cout<<"No"<<endl;
            continue;
        }
        else
        {
            //构造集合输出...
            cout<<"Yes"<<endl;
            cout<<k<<endl;//k个集合
            for(int i=1;i<=k;i++) S[i].clear();
            int cnt=1;
            for(int i=1;i<=k;i++)
            {
                for(int j=i+1;j<=k;j++)//按第i个集合与之后集合相同的数进行插入值 见下方注释
                {
                    S[i].insert(cnt);
                    S[j].insert(cnt);
                    cnt++;
                }
                //边添加边输出 也可以全部添加完毕后逐个输出
                cout<<S[i].size();
                for(it=S[i].begin();it!=S[i].end();it++)
                {
                    cout<<" "<<*it;
                }
                cout<<endl;
            }
        }
    }
}
/*
For example, when k = 4,
• There is an element contained in S1 and S2. Let’s call it A.
• There is an element contained in S1 and S3. Let’s call it B.
• There is an element contained in S1 and S4. Let’s call it C.
• There is an element contained in S2 and S3. Let’s call it D.
• There is an element contained in S2 and S4. Let’s call it E.
• There is an element contained in S3 and S4. Let’s call it F.
Then we get S1 = {A, B, C}, S2 = {A, D, E}, and so on (and somehow assign the letters to integers
between 1 and N).
*/