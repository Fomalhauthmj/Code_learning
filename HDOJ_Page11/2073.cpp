#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
struct point
{
	int x;
	int y;
};
int main()
{
	double res[201]={0};
    for(int i=0;i<201;i++) res[i]=sqrt(i*i+(i+1)*(i+1));
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			point p1;
			point p2;
			cin>>p1.x>>p1.y>>p2.x>>p2.y;
			double sum1=0;
			double sum2=0;
		    if(p1.x+p1.y>p2.x+p2.y) swap(p1,p2);
			if(p1.x==p2.x&&p1.y==p2.y) sum1=sum2=0;
			else
			{
				for(int i=0;i<p1.x+p1.y;i++) sum1+=res[i]+i*sqrt(2);
				for(int i=0;i<p2.x+p2.y;i++) sum2+=res[i]+i*sqrt(2);
				sum1+=p1.x*sqrt(2);
				sum2+=p2.x*sqrt(2);
			}
			cout<<fixed<<setprecision(3)<<sum2-sum1<<endl;
		}
	}
}
