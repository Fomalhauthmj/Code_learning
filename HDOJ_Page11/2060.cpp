#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int left,score_p,score_o;
        cin>>left>>score_p>>score_o;
        int sum=0;
        if(left>6){
                for(int i=1;i<=left-6;i++) sum+=8;
                for(int i=2;i<=7;i++) sum+=i;
        }
        else{
                for(int i=7;i>=8-left;i--) sum+=i;

        }
        if(sum+score_p>=score_o) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}
