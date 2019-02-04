#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
  int i;
  for(i=1; i<100; i++){
    if(i%2==0) //填空
      printf("%d ", i*i/2);
    else
      printf("%d ", (i*i-1)/2);
  }
  printf("\n");
  cout<<"i%2==0"<<endl;
  system("pause");
}