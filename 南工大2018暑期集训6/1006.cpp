#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
double  r, R, H, V;
bool judge(double mid)
{
    double radius=mid*(R-r)/H+r;  //相似！！
    //double radius=(mid*R+r*H)/(H+mid);精度有误！！！
    double temp=pi*mid*(r*r+radius*radius+r*radius)/3;
    if(temp>=V) return true;
    else return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>r>>R>>H>>V;
        double left=0.0;
        double right=100;
        double mid;
        while(right-left>eps)
        {
            mid=(left+right)/2;
            if(judge(mid)==true) right=mid;
            else left=mid;
        }
        cout<<fixed<<setprecision(6)<<left<<endl;
    }
}