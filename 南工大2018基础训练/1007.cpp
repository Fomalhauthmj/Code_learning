#include<iostream>
#include<map>
#include<math.h>
using namespace std;
map<string,int> m;
string in[6];
int main()
{
    m["zero"]=0;
    m["one"]=1;
    m["two"]=2;
    m["three"]=3;
    m["four"]=4;
    m["five"]=5;
    m["six"]=6;
    m["seven"]=7;
    m["eight"]=8;
    m["nine"]=9;
    m["+"]=-1;
    m["="]=-1;
    while(1)
    {
        int inpos=0;
        int pluspos=0;
        while(1)
        {
            cin>>in[inpos++];
            if(in[inpos-1]=="+") pluspos=inpos-1;
            if(in[inpos-1]=="=") break;
        }
        if(in[0]=="zero"&&in[1]=="+"&&in[2]=="zero"&&in[3]=="=") break;
        int num1=0;
        int num2=0;
        int p=0;
        for(int i=pluspos-1;i>=0;i--)
        {
            if(m[in[i]]>=0) num1+=m[in[i]]*pow(10,p++);
        }
        p=0;
        for(int i=inpos-2;i>pluspos;i--)
        {
            if(m[in[i]]>=0) num2+=m[in[i]]*pow(10,p++);
        }
        cout<<num1+num2<<endl;
    }
    return 0;
}























// #include<iostream>
// #include<cstring>
// using namespace std;
// string num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
// int main()
// {
//     string line;
//     while(getline(cin,line)&&line!="zero + zero =")
//     {
//         int res1[2]={0};
//         int res2[2]={0};
//         int pluspos=line.find("+");
//         int equalpos=line.find("=");
//         string front=line.substr(0,pluspos-1);
//         string back=line.substr(pluspos+2,equalpos-pluspos-3);
//         int blankpos=front.find(" ");
//         if(blankpos!=-1)
//         {
//             string str1=front.substr(0,blankpos);
//             string str2=front.substr(blankpos+1,front.size()-blankpos-1);
//             for(int i=0;i<10;i++)
//             {
//                 if(num[i]==str1) res1[0]=i;
//                 if(num[i]==str2) res1[1]=i;
//             }
//         }
//         else
//         {
//             for(int i=0;i<10;i++)
//             {
//                 if(num[i]==front) res1[1]=i;
//             }
//         }
//         blankpos=back.find(" ");
//         if(blankpos!=-1)
//         {
//             string str1=back.substr(0,blankpos);
//             string str2=back.substr(blankpos+1,back.size()-blankpos-1);
//             for(int i=0;i<10;i++)
//             {
//                 if(num[i]==str1) res2[0]=i;
//                 if(num[i]==str2) res2[1]=i;
//             }
//         }
//         else
//         {
//             for(int i=0;i<10;i++)
//             {
//                 if(num[i]==back) res2[1]=i;
//             }
//         }
//         int fnum;
//         int bnum;
//         fnum=10*res1[0]+res1[1];
//         bnum=10*res2[0]+res2[1];
//         cout<<fnum+bnum<<endl;
//     }
// }