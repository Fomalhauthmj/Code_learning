#include<iostream>
#include<set>
using namespace std;
bool legal(int n1,int n2)
{
    int temp=n1*n2;
    multiset<int> s1;
    while(n1)
    {
        s1.insert(n1%10);
        n1/=10;
    }
    s1.insert(n1%10);
    multiset<int> ts;
    while(temp)
    {
        ts.insert(temp%10);
        temp/=10;
    }
    ts.insert(temp%10);
    for(auto ele:ts)
    {
        if(s1.find(ele)!=s1.end()) continue;
        else return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //999999/6=170000
    //分别用2 3 4 5 6去乘它，
    //得到的仍然是6位数，并且乘积中所包含的数字与这个6位数完全一样！只不过是它们的顺序重新排列了而已。
    for(int i=100000;i<170000;i++)
    {
        int flag=0;
        for(int j=2;j<=6;j++)
        {
            if(legal(i,j))
            {
                flag++;
            }
            else break;
        }
        if(flag==5)
        {
            cout<<i<<endl;
        }
    }
    system("pause");

    //ans=142857
}