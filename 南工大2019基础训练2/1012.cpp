#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=100;i++)
    {
        int temp=i;
        int cnt=0;
        while(cnt<15)
        {
            vector<int> v;
            while(temp)
            {
                v.push_back(temp%10);
                temp/=10;
            }
            temp=0;
            for(auto ele:v)
            {
                temp+=ele*ele;
            }
            cout<<temp<<" ";
            cnt++;
        }
        cout<<endl;
    }
    system("pause");
}//145