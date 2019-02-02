#include<iostream>
using namespace std;
int main()
{
    int k;
    while(cin>>k)
    {
        if(k%2==0)
        {
            cout<<k*k/4<<endl;  //偶数
        }
        else
        {
            cout<<(k-1)*(k+1)/4<<endl;//奇数  k+1/2 奇     k-1/2 偶
        }
    }
}