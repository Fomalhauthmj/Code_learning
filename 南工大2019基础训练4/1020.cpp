#include<iostream>
#include<stdio.h>
using namespace std;
struct EV
{
  int result; //计算结果 
  int n; //消耗掉的字符数 
};
struct EV evaluate(char* x)
{
  struct EV ev = {0,0};
  struct EV v1;
  struct EV v2;
  if(*x==0) return ev;  
  if(x[0]>='0' && x[0]<='9'){
    ev.result = x[0]-'0';
    ev.n = 1;
    return ev;
  }  
  v1 = evaluate(x+1);
  v2 = evaluate(x+v1.n+1); //填空位置  
  if(x[0]=='+') ev.result = v1.result + v2.result;
  if(x[0]=='*') ev.result = v1.result * v2.result;
  if(x[0]=='-') ev.result = v1.result - v2.result;
  ev.n = 1+v1.n+v2.n;
  return ev;
}
int main()
{
    EV ans=evaluate("-+3*5+261");
    cout<<ans.result<<ans.n<<endl;
    system("pause");
}