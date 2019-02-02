#include<iostream>
using namespace std;
int answer;
void DFS(int depth,int pre)  //depth表示和
{
    if(depth==0) 
    {
        answer++;
        return;
    }
    if(depth<pre) pre=depth;  //剩余数和已经小于上一个加数
    for(int i=pre;i>=1;i--)
    {
        //cout<<depth<<" "<<depth-i<<" "<<i<<endl;
        DFS(depth-i,i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        answer=0;
        DFS(n,125);
        cout<<answer<<endl;
    }
}// TLE 