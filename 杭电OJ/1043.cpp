#include<iostream>
#include<string>
#include<queue>
using namespace std;
char p[3][3]={'0'};
int startx,starty;
int main()
{
    string str;
    while(!cin.eof())
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>p[i][j];
                if(p[i][j]=='x')
                {
                    startx=i;starty=j;
                }
            }
        }

    }
}