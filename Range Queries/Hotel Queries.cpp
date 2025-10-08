// ^^
// <{:3
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct segtree
{
    vector<ll> tree;
    segtree(int n, vector<int> A) : tree(2 * n)
    {
        for (int i = 0; i < n; ++i)
            tree[n + i] = A[i];
        for (int i = n - 1; i > 0; --i)
            tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }
    void upd(int i, ll x)
    {
        i += tree.size() / 2;
        tree[i] = x;
        while (i >>= 1)
            tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
        return;
    }
    ll query(int i, int j)
    {
        i += tree.size() / 2;
        j += tree.size() / 2;
        ll mx = -1e9;
        while (i <= j)
        {
            if (i & 1)
                mx = max(mx, tree[i++]);
            if (!(j & 1))
                mx = max(mx, tree[j--]);
            i >>= 1;
            j >>= 1;
        }
        return mx;
    }
    ll operator[](int i) { return tree[i + tree.size() / 2]; }
};

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> damix(n);
    for (auto &x : damix)
        cin >> x;

    segtree s(n, damix);

    while (q-- > 0)
    {
        int x;
        cin >> x;

        int lo = 0, hi = n;
        while (lo < hi)
        {
            int mi = (lo + hi) / 2;
            if (s.query(0, mi) < x)
                lo = mi + 1;
            else
                hi = mi;
        }

        if (lo != n)
        {
            cout << lo + 1 << " ";
            s.upd(lo, s[lo] - x);
            continue;
        }
        cout << "0 ";
    }
}
