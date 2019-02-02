#include<iostream>
#include<algorithm>
using namespace std;
char op[4]={'+','-','*','/'};
int  a[5]={0};
int  myop[4]={0};
int main()
{
    int p,f,q,y;
    for(int i=0;i<5;i++) cin>>a[i];
    cin>>y;
    for(myop[0]=0;myop[0]<4;myop[0]++)
    for(myop[1]=0;myop[1]<4;myop[1]++)
    for(myop[2]=0;myop[2]<4;myop[2]++)
    for(myop[3]=0;myop[3]<4;myop[3]++)
    {  
        p=0;q=a[0];f=1;
        for(int i=0;i<4;i++)
        {
            switch(op[myop[i]])
            {
                case'+':
                    p+=q*f;
                    f=1;
                    q=a[i+1];
                    break;
                case'-':
                    p+=q*f;
                    f=-1;
                    q=a[i+1];
                    break;
                case'*':
                    q*=a[i+1];
                    break;
                case'/':
                    if(a[i+1]!=0)
                    {
                        q/=a[i+1];
                    }
                    else exit(0);
                    break;
                default:
                    break;
            }
        }
        p+=q*f;
        if(p==y)
        {
            cout<<a[0]<<" ";
            for(int i=0;i<4;i++) cout<<op[myop[i]]<<" "<<a[i+1]<<" ";
            cout<<endl;
        }
    }
    system("pause");
}