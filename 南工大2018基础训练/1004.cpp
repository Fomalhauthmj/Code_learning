#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    char str[1010];
    vector<int>result;
    while(cin>>str)
    {
        result.clear();
        char *sub=strtok(str,"5");
        while(sub!=NULL)
        {
            if(sub=="")
            {
                sub=strtok(NULL,"5");
            }
            else
            {
                int num;
                num=atoi(sub);
                result.push_back(num);
                sub=strtok(NULL,"5");
            }
        }
        sort(result.begin(),result.end());
        vector<int>::iterator it;
        for(it=result.begin();it<result.end()-1;it++) cout<<*it<<" ";
        cout<<*it<<endl;
    }
}