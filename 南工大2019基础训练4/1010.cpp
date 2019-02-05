#include <stdio.h>
#include<iostream>
//打印m列，n行的方格 
using namespace std;
void f(int m, int n)
{
  int row;
  int col;
  
  for(row=0; row<n; row++)
  {
    for(col=0; col<m; col++) printf("+---");
    printf("+\n");
    for(col=0; col<m; col++) printf("|   ");
    printf("|\n");    
  }
  
  printf("+");
  //while(m--&&printf("---+"));
  while(m--)printf("---+");
  //____________; //填空
  printf("\n");
}

int main()
{
  f(10,4);
   cout<<"while(printf(\"---+\")&&--m)";

  system("pause");
  return 0;
}