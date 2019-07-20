#include<cstring>
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
const int N=1E6+50;
char a[N*2],b[N*2];
int Solve(char *a)
{
    int n=strlen(a);
    for(int i=0;i<n;i++) a[i+n]=a[i];
    int i=0,j=1,k;
    while(i<n&&j<n)
    {
        for(k=0;k<n&&a[i+k]==a[j+k];k++);
        if(k==n-1) break;
        if(a[i+k]<a[j+k]) 
        {
            j=j+k+1;
            if(i==j) j++;
        } 
        if(a[i+k]>a[j+k])
        {
            i=i+k+1;
            if(i==j) i++;
        }
    }
    return min(i,j);
}
int main()
{
    scanf("%s",a);
    int n=strlen(a);
    int pa=Solve(a);
    a[pa+n]=0;
    scanf("%s",b);
    int pb=Solve(b);
    b[pb+n]=0;
    if(!strcmp(a+pa,b+pb))
    {
        cout<<"Yes"<<endl;
        cout<<a+pa<<endl;
    }
    else cout<<"No"<<endl;
    //system("pause");
    return 0;
}