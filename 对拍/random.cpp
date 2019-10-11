#include<bits/stdc++.h>
using namespace std;
#define ll long long
int random(int n)
{
    return (ll)rand()*rand()%n;
}
int main()
{
    freopen("data.in", "w", stdout);
    srand((unsigned)time(0));
    for(int i=1;i<=10000;i++)
    {
        printf("%c",'A'+random(2));
    }
    //system("pause");
    return 0;
}