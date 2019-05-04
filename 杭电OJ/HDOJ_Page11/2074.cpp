#include<bits/stdc++.h>
using namespace std;
void print(int n,char ch1,char ch2)
{
    char s[n+1][n+1]= {'0'};
    int c=(n+1)/2;
    s[c][c]=ch1;
    for(int i=1; i<=c-1; i++)
    {
        s[c+i][c]=s[c-i][c]=s[c][c+i]=s[c][c-i]=(s[c][c-i+1]==ch1)?ch2:ch1;
        char ch=s[c+i][c];
        for(int j=c-i; j<=c+i; j++)
        {
            s[j][c-i]=s[j][c+i]=s[c-i][j]=s[c+i][j]=ch;
        }
    }
    s[1][1]=s[n][n]=s[1][n]=s[n][1]=' ';
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<s[i][j];
        }
        cout<<endl;
    }

}
int main()
{
    int n;
    char ch1;
    char ch2;
    int flag=0;
    while(cin>>n>>ch1>>ch2)
    {
        if(flag==1)
            cout<<endl;
        else
            flag=1;
        if(n!=1)
            print(n,ch1,ch2);
        else
            cout<<ch1<<endl;
    }
}
