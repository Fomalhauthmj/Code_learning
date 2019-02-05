#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
void StringInGrid(int width, int height, const char* s)
{
  int i,k;
  char buf[1000];
  strcpy(buf, s);
  if(strlen(s)>width-2) buf[width-2]=0;
  
  printf("+");
  for(i=0;i<width-2;i++) printf("-");
  printf("+\n");
  
  for(k=1; k<(height-1)/2;k++){
    printf("|");
    for(i=0;i<width-2;i++) printf(" ");
    printf("|\n");
  }
  
  printf("|");
  
  printf("%*s%s%*s",(width-2-strlen(buf))/2,"",buf,width-2-strlen(buf)-(width-strlen(buf)-2)/2,""); //填空
   //空白 字符 空白
  printf("|\n");
  
  for(k=(height-1)/2+1; k<height-1; k++){
    printf("|");
    for(i=0;i<width-2;i++) printf(" ");
    printf("|\n");
  }  
  
  printf("+");
  for(i=0;i<width-2;i++) printf("-");
  printf("+\n");  
}

int main()
{
  StringInGrid(20,6,"abcd12");
  cout<<"(width-2-strlen(buf))/2,\"\",buf,width-2-strlen(buf)-(width-strlen(buf)-2)/2,\"\""<<endl;
  system("pause");
  return 0;
}
