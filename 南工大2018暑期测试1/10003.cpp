#include<iostream>
#include<string>
using namespace std;
string solve(string number)
{
    string max="0";
    string::iterator it=number.begin();
    while(*it=='0')
    {
        number.erase(it);
        it=number.begin();
    }
    string temp;
    for(int i=0;i<number.length()-1;i++)
    {
        temp=number;
        if((temp[i]-'0')%2==0)
        {
            swap(temp[i],temp[number.length()-1]);
            if(temp>max) max=temp;
        }
        else continue;
    }
    return max;
}
int main()
{
    int t;
    cin>>t;
    string number;
    while(t--)
    {
        cin>>number;
        string res=solve(number);
        if(res=="0") cout<<-1<<endl;
        else cout<<res<<endl;
    }
}
// 思路：首先看整个数中有没有偶数，没有则直接输出-1，如有，从最高位往下遍历，如果碰到一个数字是偶数并且比最后一个数小，交换，
// 然后break，所得到的必定是最大的偶数，如果前面的偶数都比最后一个数大，那么用最后一个偶数与最后一个数交换。