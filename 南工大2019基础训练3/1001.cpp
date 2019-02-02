#include<iostream>
using namespace std;
//excel救不了我
bool judge(int year)
{
    if(year%400==0||(year%4==0&&year%100!=0)) return true;
    return false;
}
int md[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //1 1777 5 1
    int year=1777;
    int month=4;
    int day=30;
    for(int i=1;i<=10000;i++)
    {
        if(i==5343||i==8113) cout<<year<<" "<<month<<" "<<day<<endl;
        if(day==29&&month==2)
        {
            day=1;
            month=3;
            continue;
        }
        if(day==28&&month==2)
        {
            if(judge(year))
            {
                day++;
            }
            else
            {
                month=3;
                day=1;
            }
            continue;
        }
        if(day==31&&month==12)
        {
            year++;
            month=1;
            day=1;
            continue;
        }
        if(day==31&&md[month]==31)
        {
            month++;
            day=1;
            continue;
        }
        if(day==30&&md[month]==30)
        {
            month++;
            day=1;
            continue;
        }
        day++;
    }
    system("pause");//1799 7 16
}