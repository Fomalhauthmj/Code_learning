#include<iostream>
using namespace std;
int n,k;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    char ch='a';
    while(t--)
    {
        cin>>n>>k;
        int fre=n/k;
        if(fre*k!=n)
        {
            int temp=n-k*fre;
            for(int i=0;i<temp;i++) cout<<ch;
        }
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<fre;j++)
            {
                cout<<(char)(ch+i);
            }
        }
        cout<<endl;
    }
    //system("pause");
}