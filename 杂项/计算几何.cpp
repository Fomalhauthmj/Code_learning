/*
#include <iostream>
#include <cmath>
using namespace std;
struct point
{
    double x;
    double y;
    point(double i1 = 0, double i2 = 0)
    {
        x = i1;
        y = i2;
    }
};
double len(point p1, point p2)
{
    return sqrt(
        (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double scalar_product(point p1, point p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}
double angle_cos(point p1, point p2)
{
    return scalar_product(p1, p2) / len(p1, point(0, 0)) / len(p2, point(0, 0));
}
double angle(point p1, point p2)
{
    return acos(angle_cos(p1, p2));
}
//内积应用
//点到线段的最短距离
//!:对称点连线是否相交

//外积
double cross_product(point p1, point p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}
double cross_product(point p0, point p1, point p2)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
    //p0p1 X p0p2
}
//判定折线拐向 凸多边形
int dir(point p0, point p1, point p2)
{
    double temp = cross_product(p0, p1, p2);
    if (temp > 0)
    {
        //cout<<"clock wise"<<endl;//right turn   p2->p1:顺时针
        return 1;
    }
    else if (temp < 0)
    {
        //cout<<"counter clock wise"<<endl;//left turn
        return -1;
    }
    else if (temp == 0)
    {
        //cout<<"line"<<endl;
        return 0;
    }
}
bool between(point p1, point p2, point p3)
{
    if (
        p3.x >= min(p1.x, p2.x) && p3.x <= max(p2.x, p1.x) && p3.y >= min(p1.y, p2.y) && p3.y <= max(p1.y, p2.y))
        return true;
    return false;
}
void intersection(point p1, point p2, point p3, point p4)
{
    //快速判断是否相交 通过矩形对角线
    //快速排斥实验
    if (
        (min(p1.x, p2.x) <= max(p3.x, p4.x)) &&
        (min(p3.x, p4.x) <= max(p1.x, p2.x)) &&
        (min(p1.y, p2.y) <= max(p3.y, p4.y)) &&
        (min(p3.y, p4.y) <= max(p1.y, p2.y)))
    {

        int d1 = dir(p1, p2, p3), d2 = dir(p1, p2, p4);
        int d3 = dir(p3, p4, p1), d4 = dir(p3, p4, p2);
        if (d1 * d2 < 0 && d3 * d4 < 0)
        {
            cout << " + type intersection!" << endl;
        }
        else if (
            (d1 == 0 && between(p1, p2, p3)) || (d2 == 0 && between(p1, p2, p4)) || (d3 == 0 && between(p3, p4, p1)) || (d4 == 0 && between(p3, p4, p2)))
        {
            cout << " T  type intersection!" << endl;
        }
        else
        {
            cout<<"no intersection!"<<endl;
        }
    }
    else 
    {
        cout<<"no intersection!"<<endl;
    }
}
point p0, p1, p2, p3;
bool input()
{
    cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    while (input())
    {
        intersection(p0, p1, p2, p3);
    }
}
*/
// 直线  两点式
/*
struct line
{
    double a;
    double b;
    double c;
    //ax+by+c=0;
    line(double d1,double d2,double d3)
    {
        a=d1,b=d2,c=d2;
    }
};
line getline(point p1,point p2)
{
    return line(p2.y-p1.y,p1.x-p2.x,-cross_product(p1,p2));
}
*/




//!:http://codeforces.com/problemset/problem/659/D
/*
#include<iostream>
using namespace std;
#define N 1010
struct point
{
    int x;
    int y;
};
point ps[N];
int cross_product(point p0,point p1,point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
    //p0p1 X p0p2
}
int dir(point p1,point p2,point p3)
{
    int temp=cross_product(p1,p2,p3);
    if(temp>0) return 1;
    else if(temp<0) return -1;
    else if(temp=0) return 0;
}
int n;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n+1;i++)
        {
            cin>>ps[i].x>>ps[i].y;
        }
        int init_dir=dir(ps[n],ps[1],ps[2]);
        int ans=0;
        //cout<<"init_dir:"<<init_dir<<endl;
        int temp;
        for(int i=1;i<=n-1;i++)
        {
            temp=dir(ps[i],ps[i+1],ps[i+2]);
            //cout<<"cur:"<<i<<" temp:"<<temp<<endl;
            if(temp!=init_dir) ans++;
        }
        cout<<ans<<endl;
    }
}
*/

//!:求点关于直线的对称点
//数学推导即可
//!:管道问题

//!:多边形 判断一点是否在多边形内部 -> 线段是否在多边形内部
//PNPoly
/*
int pnpoly(int nvert, float *vertx, float *verty, float testx, float testy)
{
  int i, j, c = 0;
  for (i = 0, j = nvert-1; i < nvert; j = i++) {
    if ( ((verty[i]>testy) != (verty[j]>testy)) &&
	 (testx < (vertx[j]-vertx[i]) * (testy-verty[i]) / (verty[j]-verty[i]) + vertx[i]) )
       c = !c;
  }
  return c;
}
*/
//https://www.cnblogs.com/anningwang/p/7581545.html
/*
bool PNPoly(int n,double[] vx,double[] vy,double x,double y)
{
    int j=n;
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        if(i!=1) j=i-1;
        if((y>vy[i])==(y>vy[j])) continue;
        if(x<(vx[j]-vx[i])*(y-vy[i])/(vy[j]-vy[i])+vx[i]);
        {//根据直线一般式在其一侧
            flag=!flag;
        }
    }
    return flag; //奇数次 在内部 偶数次 在外部
}
*/
//http://codeforces.com/problemset/problem/166/B
/*
#include<iostream>
using namespace std;
#define N 100010
#define M 20010
int n,m;
long long pax[N];
long long pay[N];
bool PNPoly(int n,long long vx[],long long vy[],long long x,long long y)
{
    int j=n;
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        if(i!=1) j=i-1;
        if((vy[j]-vy[i])*x+(vx[i]-vx[j])*y-vx[i]*vy[j]+vx[j]*vy[i]==0) return false;
        //这是一个强判定 直接判测试点在测试边上的情况非法 对于此题TLE 需要TODO:凸包
        if((y>vy[i])==(y>vy[j])) continue;
        double temp=(vx[j]-vx[i])*(y-vy[i])*1.0/(vy[j]-vy[i])+vx[i];
        if(x<temp)
        {//根据直线一般式在其一侧
            flag=!flag;
        }
    }
    return flag; //奇数次 在内部 偶数次 在外部
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>pax[i]>>pay[i];
        }
        cin>>m;
        bool is_in=true;
        long long test_x,test_y;
        for(int i=1;i<=m;i++)
        {
            cin>>test_x>>test_y;
            if(!is_in) continue;
            if(!PNPoly(n,pax,pay,test_x,test_y))
            {
                is_in=false;
            }
        }
        if(is_in) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
*/


//!:多边形 面积
//对于三角形 已知点 海伦公式 计算量大 精度损失
//ABxAC=1/2*S  左手系负面积 右手系正面积  通过三角形面积确定两线段或直线交点 
//在处理凹多边形面积时 可以求和有向面积 (由凸多边形面积推广)
//Area=∑S△   推广:p0设为坐标原点

//!:http://codeforces.com/problemset/problem/340/B
/*
#include<iostream>
#include<math.h>
#include<algorithm>
#include<iomanip>
using namespace std;
#define N 305
struct point
{
    int x;
    int y;
    bool operator!= (point &p1) const
    {
        if(x==p1.x&&y==p1.y) return false;
        else return true;
    }
};
point ps[N];
int n;
int cross_product(point p0,point p1,point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
    //p0p1 X p0p2
}
int dir(point p0,point p1,point p2)
{
    int temp=cross_product(p0,p1,p2);
    if(temp>0) return 1;
    else if(temp<0) return -1;
    else if(temp=0) return 0;
}
double area(point p1,point p2,point p3)
{
    return cross_product(p1,p2,p3)*1.0/2;
}
double ans(point p1,point p2)
{
    double positive_area_max=0;
    double negative_area_max=0;
    int p_count=0;
    int n_count=0;
    for(int i=1;i<=n;i++)
    {
        if(ps[i]!=p1&&ps[i]!=p2)
        {
            if(dir(p1,p2,ps[i])<0)
            {
                p_count++;
                //cout<<"p cur:"<<area(p1,ps[i],p2)<<endl;
                positive_area_max=max(positive_area_max,area(p1,ps[i],p2));
            }
            else if(dir(p1,p2,ps[i])>0)
            {
                n_count++;
                //cout<<"n cur:"<<area(p1,ps[i],p2)<<endl;
                negative_area_max=max(negative_area_max,-area(p1,ps[i],p2));
            }
        }
    }
    if(p_count==0||n_count==0) return 0;
    return positive_area_max+negative_area_max;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>ps[i].x>>ps[i].y;
        }
        double max_area=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)//枚举对角线
            {
                max_area=max(max_area,ans(ps[i],ps[j]));
            }
        }
        cout<<fixed<<setprecision(6)<<max_area<<endl;
    }
}
*/




//!:多边形重心

//对于三角形
//在平面直角坐标系中，重心的坐标是顶点坐标的算术平均数，
//即其坐标为[(X1+X2+X3)/3,(Y1+Y2+Y3)/3]

//对于任意多边形 加权平均 
//Σ(xi,yi)*wi/C
/*
#include<iostream>
using namespace std;
#define N 105
struct point
{
    double x;
    double y;
};
point ps[N];
int n;
double cross_product(point p0,point p1,point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
    //p0p1 X p0p2
}
double area(point p1,point p2,point p3)
{
    return cross_product(p1,p2,p3)*1.0/2;
}
void centroid()
{
    double C=0;
    point zero,P;
    zero.x=zero.y=0;
    P.x=P.y=0;
    double temp;
    for(int i=1;i<=n;i++)
    {
        temp=area(zero,ps[i],ps[i+1]);
        C+=temp;
        P.x+=(ps[i].x+ps[i+1].x)*temp;
        P.y+=(ps[i].y+ps[i+1].y)*temp;
    }
    C+=area(zero,ps[n],ps[1]);
    P.x=P.x/3/C;
    P.y=P.y/3/C;
    cout<<P.x<<"  "<<P.y<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>ps[i].x>>ps[i].y;//注意输入点顺序 逆时针
        }
        centroid();
    }
}
*/



//!:凸包
//Graham Scan
/*
#include<iostream>
#include<algorithm>
using namespace std;
#define N 1005
struct point
{
    int x;
    int y;
};
point ret[N];//存放结果集
point p0;//极左下点 基准点
int n,top;
int cross_product(point p1,point p2,point p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);
}
double dis(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
bool cmp(const point &p1,const point &p2)
{
    //完成与基准点夹角的比较
    int temp=cross_product(p0,p1,p2);
    //p0p1 X p0p2 >0 逆时针 <0 顺时针
    if(temp>0) return true;
    else if(temp==0)// p1,p2共线
    {
        if(dis(p0,p1)<dis(p0,p2)) return true;
        else return false;
    }
    return false;
}
void Graham_Scan(point pol[],int n)
{
    int min_index=1;
    for(int i=1;i<=n;i++)
    {
        if((pol[i].y<pol[min_index].y)||
        (pol[i].y==pol[min_index].y&&pol[i].x<pol[min_index].x))
        {
            min_index=i;
        }
        //寻找左下基准点
    }
    swap(pol[1],pol[min_index]);
    p0=pol[1];
    sort(pol+2,pol+n+1,cmp);
    //按基准点排序

    //模拟栈
    top=3;
    ret[1]=pol[1];
    ret[2]=pol[2];
    ret[3]=pol[3];
    point p_top,p_next_top,p_cur;
    for(int i=4;i<=n;i++)
    {
        while(1)
        {
            p_top=ret[top];
            p_next_top=ret[top-1];
            p_cur=pol[i];
            cout<<"cur top:"<<top<<"  temp X:"<<cross_product(p_next_top,p_top,p_cur)<<endl;
            if(cross_product(p_next_top,p_top,p_cur)>0)
            {
                break;
            }
            else top--;//不满足出栈
        }
        ret[++top]=pol[i];//逆时针方向加入此点
    }
}
point ps[N];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>ps[i].x>>ps[i].y;
        }
        Graham_Scan(ps,n);
        cout<<"Convex Hull:"<<endl;
        for(int i=1;i<=top;i++)
        {
            cout<<ret[i].x<<" "<<ret[i].y<<endl;
        }
    }
}
*/

//http://codeforces.com/problemset/problem/166/B  Mix up A and B   
/*
#include<iostream>
#include<algorithm>
#include<math.h>
#include<set>
using namespace std;
#define N 120010
struct point
{
    long long x;
    long long y;
    bool belong;
};
point ret[N];//存放结果集
point p0;//极左下点 基准点
int n,top;
long long cross_product(point p1,point p2,point p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);
}
bool cmp(const point &p1,const point &p2)
{
    //完成与基准点夹角的比较
    long long temp=cross_product(p0,p1,p2);
    //p0p1 X p0p2 >0 逆时针 <0 顺时针
    if(temp>0) return true;
    else if(temp==0)// p1,p2共线
    {
        if(p1.y<p2.y||(p1.y==p2.y&&p1.x<p2.x)) return true;
        else return false;
    }
    return false;
}
bool on_line(point p1,point p2,point p3)
{
    long long A=p2.y-p1.y;
    long long B=p1.x-p2.x;
    long long C=p1.y*p2.x-p1.x*p2.y;
    if(p1.x>p2.x) swap(p1,p2);
    //判断p3在p1p2上
    if(p3.x<p1.x||p3.x>p2.x) return false;
    if(A*p3.x+B*p3.y+C==0) 
    {
        //cout<<p1.x<<" "<<p1.y<<endl;
        //cout<<p2.x<<" "<<p2.y<<endl;
        //cout<<p3.x<<" "<<p3.y<<endl;
        return true;
    }
    return false;
}
void Graham_Scan(point pol[],int n)
{
    int min_index=1;
    for(int i=1;i<=n;i++)
    {
        if((pol[i].y<pol[min_index].y)||
        (pol[i].y==pol[min_index].y&&pol[i].x<pol[min_index].x))
        {
            min_index=i;
        }
        //寻找左下基准点
    }
    swap(pol[1],pol[min_index]);
    p0=pol[1];
    sort(pol+2,pol+n+1,cmp);
    //按基准点排序

    //模拟栈
    top=3;
    ret[1]=pol[1];
    ret[2]=pol[2];
    ret[3]=pol[3];
    point p_top,p_next_top,p_cur;
    for(int i=4;i<=n;i++)
    {
        while(top)
        {
            p_top=ret[top];
            p_next_top=ret[top-1];
            p_cur=pol[i];
            if(cross_product(p_next_top,p_top,p_cur)>=0)
            {
                break;
            }
            else top--;//不满足出栈
        }
        ret[++top]=pol[i];//逆时针方向加入此点
    }
}
point ps[N];
point ps_B[20010];
set<pair<long long,long long>> S;
int main()
{
    ios::sync_with_stdio(false);
    int a,b;
    while(cin>>a)
    {
        S.clear();
        for(int i=1;i<=a;i++)
        {
            cin>>ps[i].x>>ps[i].y;
            ps[i].belong=true;//A
            S.insert(make_pair(ps[i].x,ps[i].y));
        }
        cin>>b;
        n=a+b;
        bool repeat=false;
        for(int i=a+1;i<=a+b;i++)
        {
            cin>>ps[i].x>>ps[i].y;
            ps[i].belong=false;//B
            ps_B[i-a]=ps[i];
            if(S.count(make_pair(ps[i].x,ps[i].y)))
            {
                repeat=true;
            }
        }
        if(repeat)//出现重复点
        {
            cout<<"NO"<<endl;
            continue;
        }
        Graham_Scan(ps,n);
        if(top>a) //超过预期的凸包大小
        {
            cout<<"NO"<<endl;
            continue;
        }
        bool flag=true;
        for(int i=1;i<=top;i++)//凸包中是否有B点
        {
            if(!ret[i].belong)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            for(int i=1;i<=b;i++)//是否有B点在最后一条线(p0,ret[top])上
            {
                if(on_line(p0,ret[top],ps_B[i]))
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
*/




