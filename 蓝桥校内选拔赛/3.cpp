#include<iostream>
using namespace std;
long long num;
bool deal(long long num)
{
    int ret;
    int time=0;
    while(1)
    {
        time++;
        ret=0;
        while(num/10)
        {
            int temp=num%10;
            ret+=temp*temp;
            num/=10;
        }
        ret+=num*num;
        //cout<<"cur:"<<ret<<endl;
        if(ret==1) return true;
        else num=ret;
        if(time>=20) return false;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>num)
    {
        if(num==-1) break;
        else
        {
            if(num%10==0||num==1)
            {
                cout<<"true"<<endl;
                continue;
            }
            if(deal(num)) cout<<"true"<<endl;
            else cout<<"false"<<endl;
        }
    }
    //system("pause");
    return 0;
}
// 一个正整数 其各数字位平方和 加起来所得数需要为 1 10 100 1000(不可能)
