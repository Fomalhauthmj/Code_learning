#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //abcd+efgb=efcbh
    for(int e=1;e<=9;e++)
    {
        for(int f=0;f<=9;f++)
        {
            if(e==f) continue;
            for(int c=0;c<=9;c++)
            {
                if(e==c||f==c) continue;
                for(int b=0;b<=9;b++)
                {
                    if(e==b||f==b||c==b) continue;
                    for(int h=0;h<=9;h++)
                    {
                        if(e==h||f==h||c==h||b==h) continue;
                        long long temp_1=10000*e+1000*f+100*c+10*b+h;
                        for(int g=0;g<=9;g++)
                        {
                            long long temp_2=1000*e+100*f+10*g+b;
                            if(temp_1-temp_2>=10000) continue;
                            int bit_1,bit_2,bit_3,bit_4;
                            bit_1=(temp_1-temp_2)/1000;//a
                            bit_2=((temp_1-temp_2)/100)%10;//b
                            bit_3=((temp_1-temp_2)/10)%10;//c
                            bit_4=(temp_1-temp_2)%10;//d
                            if(bit_1==b||bit_1==c||bit_1==bit_4||bit_1==e||bit_1==f||bit_1==g||bit_1==h) continue;
                            if(bit_4==b||bit_4==c||bit_4==e||bit_4==f||bit_4==g||bit_4==h) continue;
                            if(bit_2==b&&bit_3==c)
                            {
                                cout<<temp_1-temp_2<<endl;
                                cout<<temp_2<<endl;
                                cout<<temp_1<<endl;
                                cout<<"---"<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
    //ans=1085
    system("pause");
}