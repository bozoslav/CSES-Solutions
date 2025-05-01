#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

long long FLOOR(long long n, long long div) { return n >= 0 ? n / div : (n - div + 1) / div; }
long long CEIL(long long n, long long div) { return n >= 0 ? (n + div - 1) / div : n / div; }
#define UNIQUER(a) (a).resize(unique((a).begin(), (a).end()) - (a).begin())
#define UNIQUE(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define prec cout << fixed << setprecision(10)
#define ALLR(a) (a).rbegin(), (a).rend()
#define ALL(a) (a).begin(), (a).end()
// 0x3f3f3f3f
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ord_set;
using ll = long long;
ord_set v;
int k = 1;

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        v.insert(i);

    int ind = k % n;
    while (n--)
    {
        auto pos = v.find_by_order(ind);
        cout << *pos << " ";
        v.erase(pos);
        if (n)
            ind = (ind % n + k) % n;
    }

    return 0;
}
