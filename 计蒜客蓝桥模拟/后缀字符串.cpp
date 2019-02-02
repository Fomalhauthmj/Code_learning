#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
#define N 100010
string strs[N];
map<string,int> M;
int main()
{
    int n;
    while(cin>>n)
    {
        M.clear();
        for(int i=0;i<n;i++)
        {
            cin>>strs[i];
            int len=strs[i].length();
            for(int j=0;j<len;j++)
            {
                M[strs[i].substr(j,len-j)]++;//strs[i].substr(j);j为开始位置
            }
        }
        for(int i=0;i<n;i++)
        {
            /*
            int cnt=1;
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                int temp=strs[j].length()-strs[i].length();
                if(temp<0) continue;
                if(strs[j].find(strs[i],temp)==temp) cnt++;
            }
            printf("%d\n",cnt);
            */
           cout<<M[strs[i]]<<endl;
        }
    }
}