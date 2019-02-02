#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int pre=2;
    for(int i=1;i<=10;i++)
    {
        cout<<i<<" "<<pre*2-1<<endl;
        pre=pre*2-1;
    }
    system("pause");//1025
}