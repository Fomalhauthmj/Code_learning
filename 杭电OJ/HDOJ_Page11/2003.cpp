#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main() 
{
	double number;
	while(cin>>number)
	{
		cout<<fixed<<setprecision(2)<<fabs(number)<<endl;
	}
	return 0;
}
