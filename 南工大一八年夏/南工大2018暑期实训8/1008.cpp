#include<iostream>
#include<string>
using namespace std;
int n,L;
string res;
int current;
bool judge(char ch)//判断添加字符是否合法
{
    //cout<<"nowres:"<<res<<endl;
    for(int i=1;i<=res.length()/2;i++)
    {
        string sub1=res.substr(res.length()-i,i);
        //cout<<"sub1:"<<sub1<<endl;
        string sub2=res.substr(res.length()-2*i,i);
        //cout<<"sub2:"<<sub2<<endl;
        if(sub1==sub2) return false;
    }
    return true;
}
void DFS()
{
    if(current>=n)//生成的第n个字符串
    {
        return;
    }
    int initlen=res.length();
    for(char i='A';i<'A'+L;i++)
    {
        res.push_back(i);//添加字符
        if(judge(i))
        {
            current++;//记录生成数 
            if(current>=n) return;  //已经到达第n个字符串  提前结束
            DFS();//下一层
            if(current>=n) return;
        }
        res.erase(initlen);//!:删除所有上一层添加的字符 只保留刚进入这一层时的字符串(0-initlen-1)
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>L)
    {
        if(n==0&&L==0) break;
        res.clear();
        current=0;
        DFS();//以长度为关键字进行深度搜索
        for(int i=0;i<res.length();i++)
        {
            cout<<res[i];
            if((i+1)%4==0&&(i+1)%64!=0&&i!=res.length()-1) 
            {
                cout<<" ";
            }
            else if((i+1)%64==0)
            {
                cout<<endl;
            }
        }
        cout<<endl<<res.length()<<endl;
    }
}