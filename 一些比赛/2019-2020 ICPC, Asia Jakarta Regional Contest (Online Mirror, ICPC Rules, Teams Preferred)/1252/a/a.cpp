/* 
 * Author: Hemengjie
 * Time: 2019-10-31 18:42:36
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+50;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]+1<=n)
            printf("%d ",a[i]+1);
        else printf("%d ",1);
    }
    printf("\n");
    //system("pause");
    return 0;
}