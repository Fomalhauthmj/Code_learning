#include<iostream>
using namespace std;
char* prefix(char* haystack_start, char* needle_start)
{
  char* haystack = haystack_start;
  char* needle = needle_start;  
  while(*haystack && *needle){
    if(*haystack++!=*needle++) return NULL; //填空
  }  
  if(*needle) return NULL;  
  return haystack_start;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char *str1="abcd1234";
    char *str2="abc";
    cout<<prefix(str1,str2)<<endl;
    system("pause");
}