/* 
 * Author: Hemengjie
 * Time: 2019-10-31 18:57:43
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+50;
int re[N],ro[N],ce[N],co[N];
int r[N],c[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    scanf("%d%d",&n,&q);
    re[0]=ro[0]=ce[0]=co[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&r[i]);
        ro[i]=ro[i-1],re[i]=re[i-1];
        if(r[i]&1) ro[i]++;
        else re[i]++;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
        co[i]=co[i-1],ce[i]=ce[i-1];
        if(c[i]&1) co[i]++;
        else ce[i]++;
    }
    while(q--)
    {
        int ra,ca,rb,cb;
        scanf("%d%d%d%d",&ra,&ca,&rb,&cb);
        if((r[ra]+r[rb])&1)
            printf("NO\n");
        else
        {
            bool path=false;
            if(r[ra]&1)
            {
                if(abs(ro[rb]-ro[ra])==abs(rb-ra)&&abs(co[ca]-co[cb])==abs(ca-cb))
                    path=true;
            }
            else
            {
                if(abs(re[rb]-re[ra])==abs(rb-ra)&&abs(ce[ca]-ce[cb])==abs(ca-cb))
                    path=true;
            }
            if(!path) printf("NO\n");
            else printf("YES\n");
        }
    }
    //system("pause");
    return 0;
}