#include<iostream>
#include<stdio.h>
using namespace std;
#define  BUF_N 100
void pop(int s, int* buf, int c, FILE* fp)
{ // s:0 -c buf 1 c buf 
  int i;
  if(s)
  {
    fprintf(fp, "%d %d ", c, *buf);
  }
  else
  {
    fprintf(fp, "%d ", -c);
    for(i=0; i<c; i++)
    {
      fprintf(fp, "%d ", buf[i]);
    }
  }
}
void dopack(FILE* r, FILE* w)
{
  int buf[BUF_N];
  int pos = 0; // 下一个数字在buf中将要存放的位置
  int c = 0; // 当前段已读入的整数个数
  int pst; 
  int cst;
  while(fscanf(r, "%d", buf+pos)==1)
  {
    if(c==0)
    {
      c = pos = 1;
      continue;
    }
    if(c==1)
    {
      pst = buf[0] == buf[1];
      pos = pos + 1 - pst;
      c = 2;
      continue;
    }    
    cst = buf[pos-1] == buf[pos];
    if(pst && !cst)
    {
      pop(pst, buf, c, w);
      buf[0] = buf[1];
      c = pos = 1;
      pst = cst;
    }
    else if(!pst && cst || pos == BUF_N-1)
    {
      pop(pst, buf, c-1, w);
      buf[0] = buf[pos-1];
      c = 2;
      if(!cst)
      {
        buf[1] = buf[pos];
        pos = 2;
      }
      else
      {
        pos = 1;
        pst = 1; // 填空1  ?cst=1 pst=1
      }
    }
    else
    {
      c++;
      if(!pst) pos++;
    }
  } // while
  if(c>0) pop(pst,buf,c,w); // 填空2
}
int main()
{
  FILE* rfp;
  FILE* wfp;
  if((rfp=fopen("RFILE.txt", "r")) == NULL)
  {
    printf("can not open %s!\n", "RFILE.txt");
    exit(1);
  }
  if((wfp=fopen("WFILE.txt", "w")) == NULL)
  {
    printf("can not open %s!\n", "WFILE.txt");
    fclose(rfp);
    exit(2);
  }
  dopack(rfp, wfp);
  fclose(wfp);
  fclose(rfp);
}