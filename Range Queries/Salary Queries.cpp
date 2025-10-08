// ^^
// <{:3
#include <bits/stdc++.h>
// #define int long long
#define ll long long
using namespace std;
vector<int> vals;

int conv(int x)
{
    return (lower_bound(vals.begin(), vals.end(), x) - vals.begin());
}

struct segtree
{
    vector<ll> tree;
    segtree(int n) : tree(2 * n) {}
    void upd(int i, ll x)
    {
        i += tree.size() / 2;
        tree[i] = x;
        while (i >>= 1)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        return;
    }
    ll query(int i, int j)
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
    ll operator[](int i) { return tree[i + tree.size() / 2]; }
};

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (auto &x : v)
    {
        cin >> x;
        vals.push_back(x);
    }

    vector<tuple<char, int, int>> queries;
    while (q-- > 0)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        queries.emplace_back(c, a, b);
        vals.push_back(a);
        vals.push_back(b);
    }

    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());

    segtree s((int)vals.size());
    for (auto &x : v)
    {
        x = conv(x);
        s.upd(x, s[x] + 1);
    }

    for (auto [c, a, b] : queries)
    {
        if (c == '!')
        {
            --a;
            b = conv(b);
            s.upd(v[a], s[v[a]] - 1);
            v[a] = b;
            s.upd(b, s[b] + 1);
        }
        else
        {
            cout << s.query(conv(a), conv(b)) << "\n";
        }
    }
}
