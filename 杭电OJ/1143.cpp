#include<iostream>
using namespace std;
int res[31]={0};
int main()
{
    res[0]=1;
    res[2]=3;
    for(int i=4;i<31;i++)
    {
        res[i]=4*res[i-2]-res[i-4];
    }
    int n;
    while(cin>>n)
    {
        if(n==-1) break;
        else cout<<res[n]<<endl;
    }

}
























// #include<iostream>
// using namespace std;
// int res[31][3]={0};
// int main()
// {
//     res[0][0]=1;
//     res[1][1]=1;
//     res[0][2]=1;
//     for(int i=2;i<=30;i++)
//     {
//         res[i][0]=res[i-2][0]+res[i-1][1]+res[i-2][2];
//         res[i][1]=res[i-1][2];
//         res[i][2]=res[i][0]+res[i-1][1];
//     }
//     int n;
//     while(cin>>n)
//     {
//         if(n==-1) break;
//         else cout<<res[n][0]<<endl;
//     }
// }