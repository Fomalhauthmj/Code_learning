#include<iostream>
using namespace std;
//v - w^2 + x^3 - y^4 + z^5 = target 
int result(int v,int w,int x,int y,int z)
{
    return v-w*w+x*x*x-y*y*y*y+z*z*z*z*z;
}
int main()
{
    int target;
    string line;
    string max;
    int flag;
    while(cin>>target>>line)
    {
        if(target==0&&line=="END") break;
        max="00000";
        flag=0;
        for(int i1=0;i1<line.length();i1++)
        for(int i2=0;i2<line.length();i2++)
        for(int i3=0;i3<line.length();i3++)
        for(int i4=0;i4<line.length();i4++)
        for(int i5=0;i5<line.length();i5++)
        {
            string temp="00000";
            if(result(line[i1]-64,line[i2]-64,line[i3]-64,line[i4]-64,line[i5]-64)==target)
            {
                if(i1==i2||i1==i3||i1==i4||i1==i5||i2==i3||i2==i4||i2==i5||i3==i4||i3==i5||i4==i5) continue;
                flag=1;
                temp[0]=line[i1];
                temp[1]=line[i2];
                temp[2]=line[i3];
                temp[3]=line[i4];
                temp[4]=line[i5];
                if(temp>max) max=temp;
                else continue;
            }
        }
        if(flag==0) cout<<"no solution"<<endl;
        else cout<<max<<endl;
    }
    
}