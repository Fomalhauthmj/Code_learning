#include<iostream>
using namespace std;
int num,max_num;
int deal(int num)
{
    int max_num=num;
    while(num!=1)
    {
        if(num%2!=0)
        {
            num=num*3+1;
        }
        else num=num/2;
        //cout<<num<<endl;
        if(max_num<num) max_num=num;
    }
    return max_num;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>num)
    {
        max_num=num;
        for(int i=num;i>=1;i--)
        {
            int temp=deal(i);
            if(temp>max_num) max_num=temp;
        }
        cout<<max_num<<endl;
    }
    return 0;
}