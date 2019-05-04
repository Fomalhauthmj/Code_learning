#include<iostream>
#include<string>
using namespace std;
struct person
{
    string name;
    int score;
};
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        else
        {
            string allname[2*n];
            for(int i=0;i<2*n;i++) cin>>allname[i];
            int pos=0;
            person p[2*n];
            for(int i=0;i<2*n;i++)
            {
                int flag=0;
                for(int j=0;j<i;j++)
                {
                    if(allname[j]==allname[i])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    p[pos].name=allname[i];
                    p[pos].score=0;
                    pos++;
                }
            }
            for(int i=0;i<2*n;i+=2)
            {
                int losepos=0;
                for(int j=0;j<pos;j++)
                {
                    if(p[j].name==allname[i+1])
                    {
                        losepos=j;
                        break;
                    }
                }
                p[losepos].score=-1;
            }
            int maxnum=0;
            for(int i=0;i<pos;i++)
            {
                if(p[i].score==0) maxnum++;
            }
            if(maxnum==1) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }

}
