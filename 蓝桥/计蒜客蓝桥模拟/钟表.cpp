#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int temp1=22*3600+28*60+45;
    int temp2=30*3600+24*60+26;
    int h=(temp2-temp1)/3600;
    int m=(temp2-temp1-h*3600)/60;
    int s=temp2-temp1-3600*h-60*m;
    cout<<h<<" "<<m<<" "<<s<<" "<<endl;
    system("pause");
}