#include<iostream>
#include<string>
using namespace std;
bool judge(string str1,string str2)
{
    if(str1[0]!=str2[0]) return false;
    if(str1[str1.length()-1]!=str2[1]) return false;
    if(str1[1]!=str1[4]) return false;
    if(str1[2]==str1[3]) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=100;i<=999;i++)
    {
        int temp=i*i;
        string str_1=to_string(temp);
        string str_2=to_string(i);
        if(str_1.length()!=6) continue;
        if(judge(str_1,str_2)) cout<<i<<" "<<temp<<endl;
    }
    system("pause");//897
}