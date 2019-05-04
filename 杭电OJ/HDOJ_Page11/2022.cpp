#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		int score[m][n]={0};
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>score[i][j];
			}
		}
		int maxrpos=0;
		int maxcpos=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(abs(score[i][j])>abs(score[maxrpos][maxcpos]))
				{
					maxrpos=i;
					maxcpos=j;
				}
			}
		}
		cout<<maxrpos+1<<" "<<maxcpos+1<<" "<<score[maxrpos][maxcpos]<<endl;
	}
}
