#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace __gnu_pbds;
#define pii pair<int, int>
#define inf 0x7fffffff
cc_hash_table<int, int> h;
tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>::iterator it;
tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> tr;
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int opt, x;
        scanf("%d%d", &opt, &x);
        switch (opt)
        {
        case 1:
            tr.insert({x, ++h[x]});
            break;
        case 2:
            tr.erase({x, h[x]--});
            break;
        case 3:
            printf("%d\n", tr.order_of_key({x, 1}) + 1);
            break;
        case 4:
            printf("%d\n", tr.find_by_order(x - 1)->first);
            break;
        case 5:
            it = tr.lower_bound({x, 1});
            it--;
            printf("%d\n", it->first);
            break;
        case 6:
            it = tr.upper_bound({x, inf});
            printf("%d\n", it->first);
            break;
        }
    }
    //system("pause");
    return 0;
}