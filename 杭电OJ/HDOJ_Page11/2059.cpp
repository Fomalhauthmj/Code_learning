#include<iostream>
using namespace std;
int main()
{
	double L;
	int N;
	double C,T;
	double vr,vt1,vt2;
	double timer=0;
	while(cin>>L>>N>>C>>T>>vr>>vt1>>vt2)
	{
		double *p=new double [N+2];
		double dp[N+2]={0}; dp[0]=0; 
		for(int i=1;i<=N;i++) cin>>p[i];
		p[0]=0;p[N+1]=L;
		timer=L/vr;
		for(int i=1;i<=N+1;i++)
		{
			double time;
			dp[i]=10000000000;
			for(int j=0;j<i;j++)
			{
				double len=p[i]-p[j];
				if(len>C)
				{
					time=C/vt1+(len-C)/vt2;
				}
				else time=len/vt1;
				time+=dp[j];
				if(j>0) time+=T;
				dp[i]=min(dp[i],time); 
			} 
		}
		if(timer<dp[N+1]) cout<<"Good job,rabbit!"<<endl;
		else cout<<"What a pity rabbit!"<<endl;
	}
}
