#include<iostream>
#include<string>
using namespace std;
int m;
//新放砝码那一侧的砝码重量总和较大
int cur_l;
int cur_r;
string str;
bool DFS(int k,int pre,int prew)
{
    if(k>=m)
    {
        return true;
    }
    if(pre==0)
    {
        for(int i=1;i<=10;i++)
        {
            if(str[i-1]=='1'&&cur_l+i>cur_r&&i!=prew)
            {
                cur_l+=i;
                if(DFS(k+1,1,i)) return true;
                cur_l-=i;
            }
        }
        return false;
    }
    else if(pre==1)
    {
         for(int i=1;i<=10;i++)
        {
            if(str[i-1]=='1'&&cur_r+i>cur_l&&i!=prew)
            {
                cur_r+=i;
                if(DFS(k+1,0,i)) return true;
                cur_r-=i;
            }
        }
        return false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>str>>m;
        cur_l=0;
        cur_r=0;
        if(DFS(0,0,0))// pre:0 右  1 左
        {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}