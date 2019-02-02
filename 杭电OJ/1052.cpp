#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        else
        {
            int horse1[n]={0};
            int horse2[n]={0};
            for(int i=0;i<n;i++) cin>>horse1[i];
            for(int i=0;i<n;i++) cin>>horse2[i];
            sort(horse1,horse1+n);
            sort(horse2,horse2+n);
            int winnum=0;
            int losenum=0;
            int h1pos1=0,h1pos2=n-1;
            int h2pos1=0,h2pos2=n-1;
            int time=0;
            while(1)
            {
                time++;
                if(time>n) break;
                if(horse1[h1pos2]>horse2[h2pos2])
                {
                    winnum++;
                    h1pos2--;
                    h2pos2--;
                }
                else if (horse1[h1pos2]<horse2[h2pos2])
                {
                    losenum++;
                    h1pos1++;
                    h2pos2--;
                }
                else if(horse1[h1pos2]==horse2[h2pos2])
                {
                    if(horse1[h1pos1]>horse2[h2pos1])
                    {
                        winnum++;
                        h1pos1++;
                        h2pos1++;
                    }
                    else
                    {
                        if(horse1[h1pos1]<horse2[h2pos2])
                        {
                            losenum++;
                            h1pos1++;
                            h2pos2--;
                        }
                    }    
                }
            }
            cout<<200*(winnum-losenum)<<endl;
        }
    }
}   