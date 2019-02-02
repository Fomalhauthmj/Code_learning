#include<iostream>
using namespace std;
struct object
{
	double a;
	double b;
	double c;
};
bool judge(object o)
{
	if(o.a+o.b<=o.c) return false;
	if(o.a+o.c<=o.b) return false;
	if(o.b+o.c<=o.a) return false;
	return true;
}
int main()
{
	int m;
	while(cin>>m)
	{
		object *ptr=new object [m];
		for(int i=0;i<m;i++) cin>>ptr[i].a>>ptr[i].b>>ptr[i].c;
		for(int i=0;i<m;i++)
		{
			if(judge(ptr[i])==true) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}
