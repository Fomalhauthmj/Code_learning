//Bash Game   必胜点 ——>必败点  只能进入必胜点为必败点   终结点(cann't operate)——>必败点 
//kiki's game 大小均为奇数则起点为必败点
//取牌数量不可超过当前牌数的一半 但必须取 必败点:  2 5 11 23 ......3*2^n-1
//若取牌量小于当前牌数的一半？
//若只能取1/3/7？
// #include<iostream>
// using namespace std;
// #define size 1000000
// int N,a,b,c;
// bool n[size]={0};
// int main()
// {
//     ios::sync_with_stdio(false);
//     n[0]=0;
//     cin>>N;
//     cin>>a>>b>>c;
//     for(int i=1;i<=1000;i++)
//     {
//         if(i>=a&&n[i-a]==0) n[i]=1;
//         else if(i>=b&&n[i-b]==0) n[i]=1;
//         else if(i>=c&&n[i-c]==0) n[i]=1;
//         else n[i]=0;
//     }
//     //寻找循环节?
//     for(int i=0;i<=100;i++)
//     {
//         cout<<n[i]<<" ";
//         if(i%10==0) cout<<endl;
//     }
//     system("pause");
// }
// Nim游戏 
//Nim-Sum
//对于某个位置(x1,x2,x3) 当且仅当各部分Nim-sum==0时 位于必败点
// 
//Wythoff's Game
//1-2
//3-5
//4-7
//6-10
//8-13
//未出现的最小数x-x+n(n=1,2,3....)
//an=(int)n*(sqrt(5)+1)/2