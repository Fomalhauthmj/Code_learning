#include<iostream>
using namespace std;
bool ans[11];
int cnt=0;
void DFS(int step,int cur,int score)
{
    if(step>=10)
    {
        if(score==100)
        {
            for(int i=1;i<=10;i++)
                cout<<ans[i];
            cout<<endl;
        }
        return;
    }

    ans[cur]=1;
    DFS(step+1,cur+1,score*2);

    ans[cur]=0;
    DFS(step+1,cur+1,score-cur);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    DFS(0,1,10);
    system("pause");
    /*
    "1011010000"
    "0111010000"
    "0010110011"字典序
    */
}