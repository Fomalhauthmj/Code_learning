#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int num[n+1]={0};
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>num[i];
            sum+=num[i];
        }
        cout<<sum-n<<endl;
    }
}
