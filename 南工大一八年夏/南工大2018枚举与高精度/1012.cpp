#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int height;
    char ch;
    for(int num=1;num<=n;num++)
    {
        cin>>ch>>height;
        int upheight;
        int downheight;
        if(height%2!=0)
        {
            upheight=downheight=(height-1)/2;
        }
        else
        {
            upheight=height/2-1;
            downheight=height/2;
        }
        int width=height/6+1;
        int middle=downheight-1;
        for(int i=1;i<=width;i++) cout<<" ";
        for(int i=1;i<=middle;i++) cout<<ch;
        cout<<endl;
        for(int i=1;i<=upheight-1;i++)
        {
            for(int j=1;j<=width;j++) cout<<ch;
            for(int j=1;j<=middle;j++) cout<<" ";
            for(int j=1;j<=width;j++) cout<<ch;
            cout<<endl;
        }
        for(int i=1;i<=width;i++) cout<<" ";
        for(int i=1;i<=middle;i++) cout<<ch;
        cout<<endl;
        for(int i=1;i<=downheight-1;i++)
        {
            for(int j=1;j<=width;j++) cout<<ch;
            for(int j=1;j<=middle;j++) cout<<" ";
            for(int j=1;j<=width;j++) cout<<ch;
            cout<<endl;
        }
        for(int i=1;i<=width;i++) cout<<" ";
        for(int i=1;i<=middle;i++) cout<<ch;
        cout<<endl;
        if(num<n) cout<<endl;
    }
}