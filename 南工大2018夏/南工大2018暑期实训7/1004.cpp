#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    int t,j;
    while(cin>>n>>m)
    {
        int ans=0;
        for(int i=0;i<n;i++) 
        {
            cin>>t>>j;
            ans=ans^(abs(t-j)-1);  //对于两棋子中间的格数进行异或 例如 4 5 格数为0
        }
        if(ans==0) cout<<"BAD LUCK!"<<endl;
        else cout<<"I WIN!"<<endl;
    }
}