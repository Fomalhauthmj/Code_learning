#include<iostream>
using namespace std;
long long num;
long long x;
int n;
long long Xor(long long num)
{
    if(num%4==0) return num;
    else if(num%4==1) return 1;
    else if(num%4==2) return num+1;
    else if(num%4==3) return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        long long nim=0;
        for(int i=0;i<n;i++)
        {
            cin>>num>>x;  //注意此处数据与codeforces顺序相反
            nim^=Xor(x-1)^Xor(x+num-1);
        }
        if(nim) cout<<"Win"<<endl;//nim==0 先手必败点 其他先手必胜点
        else cout<<"Lose"<<endl;
    }
}//http://codeforces.com/problemset/problem/15/c
// i:1 1     n%4==1  1   n%4==2  n+1   n%4==3 0  n%4==0 n
// i:2 3
// i:3 0
// i:4 4
// i:5 1
// i:6 7
// i:7 0
// i:8 8
// i:9 1
// i:10 11
// i:11 0
// i:12 12
// i:13 1
// i:14 15
// i:15 0
// i:16 16
// i:17 1
// i:18 19
// i:19 0
// i:20 20
// i:21 1
// i:22 23
// i:23 0
// i:24 24
// i:25 1
// i:26 27
// i:27 0
// i:28 28
// i:29 1
// i:30 31