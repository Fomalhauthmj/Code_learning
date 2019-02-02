#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //啤酒每罐2.3元，饮料每罐1.9元。小明买了若干啤酒和饮料，一共花了82.3元。
    //我们还知道他买的啤酒比饮料的数量少，请你计算他买了几罐啤酒。
    for(int i=0;i<=100;i++)
    {
        for(int j=i+1;j<=100;j++)
        {
            if(23*i+19*j==823)
            {
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    system("pause");
}