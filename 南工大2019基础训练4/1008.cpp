#include<iostream>
using namespace std;
void f(char* from, char* to)
{
  char* p_from = from;
  char* p_to = to;  
  while(*p_from==' ' || *p_from=='\t' || *p_from=='\n') p_from++;  //去掉首空白
  do{
        if(*p_from==' ' || *p_from=='\t' || *p_from=='\n')
        { 
            do{
                p_from++;
            } while(*p_from==' ' || *p_from=='\t' || *p_from=='\n');
            if(*p_from)  //填空  未到结束位置
            *p_to++ = ' '; //替换为一个空格
        }
  }while(*p_to++ = *p_from++);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char *s1=" \t\n2   \t3\t\n \n4";
    char *s2=new char[30];
    f(s1,s2);
    cout<<s2<<endl;
    system("pause");
}