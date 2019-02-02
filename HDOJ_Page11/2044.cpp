#include<iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
	    int a[n][2]={0};
	    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	    long long res[50]={0};  
	    res[1]=1;
	    res[2]=2;
	    for(int i=3;i<50;i++)
	    {
		    res[i]=res[i-1]+res[i-2];
	    }
	    for(int i=0;i<n;i++) cout<<res[a[i][1]-a[i][0]]<<endl;
	}
}
