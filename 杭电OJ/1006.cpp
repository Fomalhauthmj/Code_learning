#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
double ts_m=10./59.;
double ts_h=120./719.;
double tm_h=120./11.;
double Ts_m=3600./59.;
double Ts_h=43200./719.;
double Tm_h=43200./11.;
double work(double d)
{
    double sum=0;
    double start1=d*ts_m;
    double start2=d*ts_h;
    double start3=d*tm_h;
    double end1=Ts_m-start1;
    double end2=Ts_h-start2;
    double end3=Tm_h-start3;
    double happys=max(max(start1,start2),start3);
    double happye=min(min(end1,end2),end3);
    while(happys<=43200&&happye<=43200)
    {
        if(happys<happye)
        {
            sum+=happye-happys;
        }
        if(happye==end1)
        {
            start1+=Ts_m;end1+=Ts_m;
        }
        else if(happye==end2)
        {
            start2+=Ts_h;end2+=Ts_h;
        }
        else if(happye==end3)
        {
            start3+=Tm_h;end3+=Tm_h;
        }
        happys=max(max(start1,start2),start3);
        happye=min(min(end1,end2),end3);
    }
    return sum/432;
}

int main()
{
    double d;
    while(cin>>d)
    {
        if(d==-1) break;
        else
        {
            cout<<fixed<<setprecision(3)<<work(d)<<endl;
        }
    }
}