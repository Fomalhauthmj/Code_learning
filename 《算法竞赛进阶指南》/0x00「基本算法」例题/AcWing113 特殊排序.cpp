// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.
#define ll long long
class Solution {
public:
    vector<int> specialSort(int N) {
        ll left,right,mid;
        vector<int> v;
        v.push_back(1);
        for(int i=2;i<=N;i++)
        {
            left=0;
            right=v.size()-1;
            while(left<right)
            {
                mid=(left+right)>>1;
                if(compare(i,v[mid]))
                {
                    //i<mid true
                    right=mid;
                }
                else
                {
                    //i>=mid false
                    left=mid+1;
                }
            }
            if(compare(i,v[left])) v.insert(v.begin()+left,i);
            else v.insert(v.begin()+left+1,i);
        }
        return v;
    }
};