#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int n,ans;
char s[N];
stack<char> f,q;
int main()
{
    scanf("%s",s);
    n=strlen(s);
    for (int i=0; i<n; i++)
    {
        f=q;
        for (int j=i; j<n; j++)
        {
            if (s[j]=='(') 
                f.push(')');//那么接下来的字符应该是),才能保证配对
            else if (s[j] == '[') 
                f.push(']');
            else if (s[j] == '{') 
                f.push('}');
            else if (f.empty() || s[j]!=f.top()) //发现f是空的,或者我们当前的字符不是我们理论上应该匹配的符号
                break;
            //f存储应该匹配的符号
            else
            {
                f.pop();
                if (f.empty()) //所有的字符都匹配了,说明[i,j]区间内的字符都是合法的.
                    ans=max(ans,j-i+1);//统计答案
            }
        }
    }
    cout<<ans<<endl;
    system("pause");
}
