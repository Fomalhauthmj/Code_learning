#include<iostream>
using namespace std;
string str;
int main()
{
    int pos=0;
    int j=1;
    while(pos<=2147483647)
    {
        for(int i=1;i<=j;i++)
        {
            string app=to_string(i);
            str.append(app);
            pos+=app.length();
        }
        j++;
    }
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            int num;
            cin>>num;
            cout<<str[num-1]<<endl;
        }
    }
}