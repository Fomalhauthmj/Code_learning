#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct course
{
	string name;
	double credit;
	double score;
};
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			int k;
			cin>>k;
			course *ptr=new course [k];
			for(int j=0;j<k;j++) cin>>ptr[j].name>>ptr[j].credit>>ptr[j].score;
			double gpa=0;
			double sum1=0;
			double sum2=0;
			for(int j=0;j<k;j++) 
			{
				sum2+=ptr[j].credit;
				if(ptr[j].score<60)
				{
					gpa=-1;
					break;
				}
				else
				{
					sum1+=ptr[j].credit*ptr[j].score;
				}
			}
			if(gpa==-1) cout<<"Sorry!"<<endl;
			else cout<<fixed<<setprecision(2)<<sum1/sum2<<endl;
			if(i!=n-1) cout<<endl;
		}
	}
}
