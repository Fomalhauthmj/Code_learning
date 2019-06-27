#include <iostream>
#include <iomanip>
using namespace std;
const int N = 1E5 + 50;
const double eps = 1e-9;
struct node
{
    int a, b, c;
    double cal(double x)
    {
        return 1.0 * a * x * x + 1.0 * b * x + 1.0 * c;
    }
};
node ns[N];
int n;
double f(double x)
{
    double ans=ns[0].cal(x);
    for(int i=1;i<n;i++)
    {
        ans=max(ans,ns[i].cal(x));
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ns[i].a >> ns[i].b >> ns[i].c;
        }
        double left, right, mid1,mid2;
        left=0;
        right=1000;
        while (right - left >= eps)
        {
            mid1=left+(right-left)/3;
            mid2=right-(right-left)/3;
            if(f(mid1)>f(mid2))
            {
                //right=mid2;
                left=mid1;
            }
            else
            {
                //left=mid1;
                right=mid2;
            }
        }
        cout<<fixed<<setprecision(4)<<f(left)<<endl;
    }
    //system("pause");
    return 0;
}