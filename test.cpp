#include<bits/stdc++.h>
using namespace std;
const int maxn = 16;
vector<pair<pair<int,long long>, int>> ans[1<<maxn];
map<long long,int> color;
vector<int>a[maxn];
long long sum[maxn];
int k;
int dp[1<<maxn];
int main(){
    scanf("%d",&k);
    long long all_sum = 0;
    for(int i=0;i<k;i++){
        int n;scanf("%d",&n);
        for(int j=0;j<n;j++){
            long long x;scanf("%lld",&x);
            a[i].push_back(x);
            all_sum+=x;
            sum[i]+=x;
            color[a[i][j]]=i;
        }
    }
    if(all_sum%k!=0){
        puts("NO");
        return 0;
    }
    all_sum/=k;
    for(int i=0;i<k;i++){
        for(int j=0;j<a[i].size();j++){
            long long cur = a[i][j];
            int used = 0;
            bool isOk = true;
            vector<pair<pair<int,long long>, int>> an;
            do{
                int cl = 0;
                auto it = color.find(cur);
                if(it!=color.end()){
                    cl = it->second;
                }else{
                    isOk = false;
                    break;
                }
                if(used&(1<<cl)){
                    isOk = false;
                    break;
                }
                used|=(1<<cl);
                cur = cur + (all_sum - sum[cl]);
                auto cl2 = color.find(cur);
                if(cl2!=color.end()){
                    an.push_back({{cl2->second,cur},cl});
                }
                // cout<<cur<<endl;
                // cout<<cur<<" "<<cl<<" "<<cl2<<endl;
            }while(cur!=a[i][j]);
            if(isOk){
                // cout<<"made! " << used << endl;
                dp[used]=1;
                ans[used] = std::move(an);
            }
            // cout<<"------"<<endl;
        }
    }

    for(int i=0;i<(1<<k);i++){
        if(dp[i])continue;
        for(int j=i;j>0;j=(j-1)&i){
            if(dp[j]&&dp[i&(~j)]){
                dp[i]=1;
                ans[i]=ans[j];
                for(auto&x : ans[i&(~j)]){
                    ans[i].push_back(x);
                }
                break;
            }
        }
    }
    // for(int i=0;i<(1<<k);i++){
    //     cout<<dp[i]<<endl;
    // }
    int x = (1<<k) - 1;
    if (dp[x]) {
        cout<<"Yes"<<endl;
        sort(ans[x].begin(),ans[x].end());
        for(auto a:ans[x]){
            cout<<a.first.second<<" "<<a.second+1<<endl;;
        }
    } else {
        cout<<"No"<<endl;
    }
}