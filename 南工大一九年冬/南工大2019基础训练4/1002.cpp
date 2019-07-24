#include<iostream>
#include<stdio.h>
int to_day(int y, int m, int d)
{
  int mon[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  int day = 0;
  int i;
  for(i=1; i<y; i++){
    day += (i%4==0 && i%100!=0 || i%400==0)? 366 : 365;
  }
  
  if(y%4==0 && y%100!=0 || y%400==0) mon[2]++;
  
  for(i=1; i<m; i++){
    //_____________________; //填空位置
    day+=mon[i];
  }
  
  return day + d;
}

int diff(int y1, int m1, int d1, int y2, int m2, int d2)
{
  int a = to_day(y1, m1, d1);
  int b = to_day(y2, m2, d2);
  return b-a;
}
int main()
{
  int n = diff(1864,12,31,1865,1,1);
  printf("%d\n", n);
  system("pause");
  return 0;
}