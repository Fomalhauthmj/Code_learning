#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define maxnum 6
#define PI 3.1415926
struct point
{
    int x;
    int y;
    int z;
};
int n;
point upleft;
point downright;
point p[maxnum];
int main()
{
    double ra;
    double r[maxnum]={0};
    while(cin>>n)
    {
        cin>>upleft.x>>upleft.y>>upleft.z;
        cin>>downright.x>>downright.y>>downright.z;
        for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y>>p[i].z;
        int a[n];for(int i=0;i<n;i++) a[i]=i;
        double V=0;
        do
        {
            double temp=0;
            for(int i=0;i<n;i++)
            {
                ra=min(fabs(p[a[i]].x-downright.x),fabs(p[a[i]].x-upleft.x));
                ra=min(ra,min(fabs(p[a[i]].y-downright.y),fabs(p[a[i]].y-upleft.y)));
                ra=min(ra,min(fabs(p[a[i]].z-downright.z),fabs(p[a[i]].z-upleft.z)));
                for(int j=0;j<i;j++)
                {
                    double temp=sqrt((p[a[i]].x-p[a[j]].x)*(p[a[i]].x-p[a[j]].x)+
                                     (p[a[i]].y-p[a[j]].y)*(p[a[i]].y-p[a[j]].y)+
                                     (p[a[i]].z-p[a[j]].z)*(p[a[i]].z-p[a[j]].z)
                                    );
                    ra=min(ra,max(temp-r[i],0.0));
                }
                r[i]=ra;
                temp+=4.0/3*PI*ra*ra*ra;
            }
            V=max(temp,V);
        }while(next_permutation(a,a+n));
        cout<<V<<endl;
        system("pause");
    }
}