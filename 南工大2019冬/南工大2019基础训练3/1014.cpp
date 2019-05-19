// !:12!/3!4!5!*12 =2310 WA  因为有左右对称的情况 这仅是不考虑翻转的圆排列
// 与圆排列不同 可以翻转
//               A
//          A         A
//          B         B
//          B         B
//          C         C
//          C         C
//               C
// C[5][2]*C[3][2]=10*3=30 (2310-30)/2+30翻转无影响=1140+30=1170
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str="aaabbbbccccc";
    int kinds=0;
    vector<string> v;
    do
    {
        bool flag=false;
        for(auto ele:v)
        {
            if(ele.find(str)!=string::npos)
            {
                flag=true;
                break;
            }
        }
        if(flag) continue;
        string s1=str+str;
        v.push_back(s1);
        reverse(s1.begin(),s1.end());
        v.push_back(s1);
        kinds++;
    } while(next_permutation(str.begin(),str.end()));
    cout<<kinds<<endl;
    system("pause");
}