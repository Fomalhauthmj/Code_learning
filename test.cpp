#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a[5];
    memset(a,0xcf,sizeof(a));
    cout<<a[0]<<endl;
    system("pause");
    return 0;
}