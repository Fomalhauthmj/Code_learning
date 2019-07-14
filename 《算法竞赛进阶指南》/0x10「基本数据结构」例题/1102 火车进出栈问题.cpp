/*
 * File Created: Sunday, 14th July 2019 8:32:41 pm
 * Author: 北落师门 (NJTech_hemengjie@qq.com)
 * Last Modified: Sunday, 14th July 2019 10:25:42 pm
 * Copyright (c) 2019 北落师门
 */
#include<iostream>
#include<cstring>
using namespace std;
const int N=60050;
#define ll unsigned long long
/*
搜索->动态规划->递推->卡特兰数
下为递推
 */
int n;
ll ret[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ret[0]=ret[1]=1;
    for(int i=2;i<=n;i++)
    {
        ret[i]=0;
        for(int j=1;j<=i;j++)
        {
            ret[i]+=ret[j-1]*ret[i-j];
        }
    }
    cout<<ret[n]<<endl;
    //system("pause");
    return 0;
}