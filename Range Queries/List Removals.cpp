// 0x3f3f3f3f ^
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    int tick = -1, x;
    ord_set<pair<int, int>> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        s.insert({++tick, x});
    }

    while (n--)
    {
        cin >> x;
        auto pos = s.find_by_order(x - 1);
        cout << pos->second << " ";
        s.erase(pos);
    }
}
