// 0x3f3f3f3f ^
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> tree;

inline void update(int i, ll x)
{
    i += (tree.size() / 2);
    tree[i] = x;
    while (i /= 2)
        tree[i] = tree[i * 2] + tree[(i * 2) | 1];
}

inline ll query(int i, int j)
{
    i += tree.size() / 2;
    j += tree.size() / 2;
    ll mx = 0;
    while (i <= j)
    {
        if (i & 1)
            mx += tree[i++];
        if (!(j & 1))
            mx += tree[j--];
        i >>= 1;
        j >>= 1;
    }

    return mx;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    tree.assign(2 * n, 0);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        tree[i + n] = x;
    }

    for (int i = n - 1; i > 0; --i)
        tree[i] = tree[i * 2] + tree[i * 2 | 1];

    while (q--)
    {
        int t, i, x;
        cin >> t >> i >> x;

        if (t == 1)
            update(i - 1, x);
        else
            cout << query(i - 1, x - 1) << "\n";
    }
}
