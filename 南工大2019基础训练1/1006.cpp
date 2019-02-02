#include<iostream>
#include<set>
using namespace std;
/*
假设 a b c d e 代表1~9不同的5个数字（注意是各不相同的数字，且不含0）
能满足形如： ab * cde = adb * ce 这样的算式一共有多少种呢？
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt=0;
    //ad+bc==ae+cd bd+ae==de+bc
    set<pair<int,int>> S;
    for(int a=1;a<=9;a++)
    {
        for(int b=1;b<=9;b++)
        {
            if(a==b) continue;
            for(int c=1;c<=9;c++)
            {
                if(a==c||b==c) continue;
                for(int d=1;d<=9;d++)
                {
                    if(a==d||b==d||c==d) continue;
                    for(int e=1;e<=9;e++)
                    {
                        if(a==e||b==e||c==e||d==e) continue;
                        long long temp1=10*a*e+10*c*d+d*e+b*c;
                        long long temp2=10*b*c+10*a*d+b*d+a*e;
                        //这里不能使各项系数和相等 必须是和相等
                        if(temp1==temp2)
                        {
                            cout<<++cnt<<":"<<a<<b<<"*"<<c<<d<<e<<"="<<a<<d<<b<<"*"<<c<<e<<endl;
                            S.insert(make_pair(10*a+b,100*c+10*d+e));
                        }
                    }
                }
            }
        }
    }
    //ans=112错   142对
    cout<<S.size()<<endl;
    cout<<"end!"<<endl;
    system("pause");
}