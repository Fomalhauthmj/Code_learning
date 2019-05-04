/*
话说大诗人李白，一生好饮。幸好他从不开车。
一天，他提着酒壶，从家里出来，酒壶中有酒2斗。他边走边唱：
无事街上走，提壶去打酒。
逢店加一倍，遇花喝一斗。
这一路上，他一共遇到店5次，遇到花10次，已知最后一次遇到的是花，他正好把酒喝光了。 
TODO:共喝酒10斗 初始2斗  
*/
#include<iostream>
using namespace std;
int ans=0;
int flower;//1
int shop;//0
void DFS(int depth,int cur,int pre)
{
    if(cur<0) return;
    if(depth>=15)
    {
        if(cur==0&&pre==1&&flower==10&&shop==5) ans++;
        return;
    }
    if(cur<=0) return;
    shop++;
    DFS(depth+1,2*cur,0);
    shop--;

    flower++;
    DFS(depth+1,cur-1,1);
    flower--;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    flower=shop=0;
    DFS(0,2,-1);
    cout<<ans<<endl;
    system("pause");
    //ans=14
}