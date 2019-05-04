#include<iostream>
using namespace std;
int C[9]={0};
int subC[9]={0};
int res[9]={0};
int main()
{
    int min=40;
    for(int i=0;i<9;i++) 
    {
        cin>>C[i];
        subC[i]=C[i];
    }
    for(int i1=0;i1<4;i1++)
    for(int i2=0;i2<4;i2++)
    for(int i3=0;i3<4;i3++)
    for(int i4=0;i4<4;i4++)
    for(int i5=0;i5<4;i5++)
    for(int i6=0;i6<4;i6++)
    for(int i7=0;i7<4;i7++)
    for(int i8=0;i8<4;i8++)
    for(int i9=0;i9<4;i9++)
    {
        subC[0]=(subC[0]+i1+i2+i4)%4;
        subC[1]=(subC[1]+i1+i2+i3+i5)%4;
        subC[2]=(subC[2]+i2+i3+i6)%4;
        subC[3]=(subC[3]+i1+i4+i5+i7)%4;
        subC[4]=(subC[4]+i1+i3+i5+i7+i9)%4;
        subC[5]=(subC[5]+i3+i5+i6+i9)%4;
        subC[6]=(subC[6]+i4+i7+i8)%4;
        subC[7]=(subC[7]+i5+i7+i8+i9)%4;
        subC[8]=(subC[8]+i6+i8+i9)%4;
        int sumc=0;
        int now=i1+i2+i3+i4+i5+i6+i7+i8+i9;
        for(int i=0;i<9;i++) sumc+=subC[i];
        if(sumc==0&&now<min)
        {
            res[0]=i1;
            res[1]=i2;
            res[2]=i3;
            res[3]=i4;
            res[4]=i5;
            res[5]=i6;
            res[6]=i7;
            res[7]=i8;
            res[8]=i9;
            min=now;
        }
        else
        {
            for(int i=0;i<9;i++) subC[i]=C[i];
        }
    }
    for(int i=0;i<9;i++)
    {
        if(res[i]==0) continue;
        else
        {
            for(int j=1;j<=res[i];j++) cout<<i+1;
        }
    }
    cout<<endl;
    system("pause");
}