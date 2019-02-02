#include<iostream>
using namespace std;
int result(string str,int pos)
{
    if(pos==str.length()-1) return str[pos]-'a';
    return result(str,pos+1)+;
}
int main()
{

}
// a-z 26
// ab-az 25
// bc-bz 24
// cd-cz 23
// de-dz 22
// ef-ez 21
// .....
// xy-xz 2
// yz 1