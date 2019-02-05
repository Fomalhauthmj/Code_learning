// 生成next数组 
#include<iostream>
#include<stdio.h>
using namespace std;

int* make_next(int pa[], int pn)
{
  int* next = (int*)malloc(sizeof(int)*pn);
  next[0] = -1;
  int j = 0;
  int k = -1;
  while(j < pn-1){
    if(k==-1 || pa[j]==pa[k]){
      j++;
      k++;
      next[j] = k;
    }
    else
      k = next[k];
  }
  
  return next;
}

// da中搜索pa， da的长度为an, pa的长度为pn 
int find(int da[], int an, int pa[], int pn)
{
  int rst = -1;
  int* next = make_next(pa, pn);
  int i=0; // da中的指针 
  int j=0; // pa中的指针
  int n = 0;
  while(i<an){
    n++;
    if(da[i]==pa[j] || j==-1){
      i++;
      j++;
    }
    else
      j=next[j]; //填空位置
    
    if(j==pn) {
      rst = i-pn;
      break;
    }
  }
  
  free(next);
    
  return rst;
}

int main()
{
  int da[] = {1,2,1,2,1,1,2,1,2,1,1,2,1,1,2,1,1,2,1,2,1,1,2,1,1,2,1,1,1,2,1,2,3};
  int pa[] = {1,2,1,1,2,1,1,1,2};
  //21
  int n = find(da, sizeof(da)/sizeof(int), pa, sizeof(pa)/sizeof(int));
  printf("%d\n", n);
  system("pause");
  return 0;
}