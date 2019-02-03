#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=10000;i>=5;i--)
    {
        int cnt=5;
        int temp=i;
        int flag=true;
        while(cnt--)
        {
            temp++;
            if(temp%5!=0)
            {
                flag=false;
                break;
            }
            else temp=temp-temp/5;
        }
        if(!flag) continue;
        if(temp>1000) cout<<i<<endl;
    }
    system("pause");
}