#include<iostream>
#include<algorithm>
using namespace std;
#define size 505
int a[size],b[size],c[size];
long long ab[size*size];
int num;
bool search(long long key)
{
    int left=0;
    int right=num-1;
    int mid;
    while(left<=right)
    {
        mid=(left+right)>>1;
        if(ab[mid]==key) return true;
        else if(ab[mid]>key) right=mid-1;
        else left=mid+1;
    }
    return false;
}
int main()
{
    int la,lb,lc,s;
    int casenum=1;
    while(cin>>la>>lb>>lc)
    {
        num=0;
        for(int i=0;i<la;i++) scanf("%d",&a[i]);
        for(int i=0;i<lb;i++) scanf("%d",&b[i]);
        for(int i=0;i<lc;i++) scanf("%d",&c[i]);
        for(int i=0;i<la;i++)
        {
            for(int j=0;j<lb;j++)
            {
                ab[num++]=a[i]+b[j];
            }
        }
        sort(ab,ab+num);
        sort(c,c+lc);
        scanf("%d",&s);
        long long x;
        printf("Case %d:\n",casenum++);
        while(s--)
        {
            scanf("%I64d",&x);
            if(x<ab[0]+c[0]||x>ab[num-1]+c[lc-1])
            {
                printf("NO\n");
            }
            else
            {
                long long temp;
                int i;
                for(i=0;i<lc;i++)
                {
                    temp=x-c[i];
                    if(search(temp))
                    {
                        printf("YES\n");
                        break;
                    }
                }
                if(i==lc) printf("NO\n");
            }
        }
    }
}

// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N = 505;
// long long ab[N * N];
// int a[N], b[N], c[N];
// int num;
// bool search(long long x)
// {
//     int f = 0, l = num - 1;
//     int mid;
//     while (f <= l)
//     {
//         mid = (f + l) / 2;
//         if (ab[mid] == x)
//             return true;
//         else if (ab[mid] < x)
//             f = mid + 1;
//         else if (ab[mid] > x)
//             l = mid - 1;
//     }
//     return false;
// }
// int main()
// {
//     int n, m, l, flag = 0, s;
//     long long x;
//     while (cin >> n >> m >> l)
//     {
//         flag++;
//         num = 0;
//         for (int i = 0; i < n; i++)
//             scanf("%d", &a[i]);
//         for (int i = 0; i < m; i++)
//             scanf("%d", &b[i]);
//         for (int i = 0; i < l; i++)
//             scanf("%d", &c[i]);

//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < m; j++)
//                 ab[num++] = a[i] + b[j];
//         sort(ab, ab + num);
//         sort(c, c + l);
//         scanf("%d", &s);
//         printf("Case %d:\n", flag);
//         while (s--)
//         {
//             scanf("%I64d", &x);
//             if (x < ab[0] + c[0] || x > ab[num - 1] + c[l - 1])
//                 printf("NO\n");
//             else
//             {
//                 long long p;
//                 int j;
//                 for (j = 0; j < l; j++)
//                 {
//                     p = x - c[j];
//                     if (search(p))
//                     {
//                         printf("YES\n");
//                         break;
//                     }
//                 }
//                 if (j == l)
//                     printf("NO\n");
//             }
//         }
//     }
//     return 0;
// }
// #include<iostream>
// #include<set>
// using namespace std;
// int a[505];
// int b[1010];
// set<int> S;
// int main()
// {
//     ios::sync_with_stdio(false);
//     int l,n,m;
//     int s;
//     int d=0;
//     while(cin>>l>>n>>m)
//     {
//         d++;
//         S.clear();
//         for(int i=0;i<l;i++) cin>>a[i];
//         for(int i=0;i<n;i++) cin>>b[i];
//         for(int i=0;i<l;i++)
//         for(int j=0;j<n;j++)
//         {
//             S.insert(a[i]+b[j]);
//         }
//         for(int i=0;i<m;i++) cin>>a[i];
//         cin>>s;
//         for(int i=0;i<s;i++) cin>>b[i];
//         cout<<"Case "<<d<<":"<<endl;
//         for(int i=0;i<s;i++)
//         {
//             int flag=0;
//             for(int j=0;j<m;j++)
//             {
//                 if(S.find(b[i]-a[j])!=S.end())
//                 {
//                     flag=1;break;
//                 }
//             }
//             if(flag==1) cout<<"YES"<<endl;
//             else cout<<"NO"<<endl;
//         }
//     }
// }1100+ms 9800KB