#include<iostream>
using namespace std;
int a[6];
int b[]={0,0, 0, 8, 8, 8};
int c[]={1 ,1, 4 ,5, 6 ,7 };
int ans[6];
double p=0;
void game()
{
    int temp=0;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            for(int k=0;k<6;k++)
            {
                if(a[i]==b[j]||a[i]==c[k]||b[j]==c[k]) continue;
                int min_num=min(min(a[i],b[j]),c[k]);
                int max_num=max(max(a[i],b[j]),c[k]);
                if(max_num==a[i]) temp++;
            }
        }
    }
    double tp=temp*1.0/(6*6*6);
    if(tp>p)
    {
        p=tp;
        cout<<tp<<"|";
        for(int i=0;i<6;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
}
void DFS(int depth)
{
    if(depth>=6)
    {
        int temp=0;
        for(int i=0;i<6;i++) temp+=a[i];
        if(temp!=24) return;
        game();
        return;
    }
    for(int i=0;i<9;i++)
    {
        a[depth]=i;
        DFS(depth+1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    DFS(0);
    system("pause");
}