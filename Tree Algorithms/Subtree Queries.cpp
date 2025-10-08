// ^^
// <{:3
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,tune=native")
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #define int long signed long int
// #define ld long double
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;
vector<int> edges[maxn];
int v[maxn], nv[maxn], disc[maxn];
vector<int> a;
int tick;
int n, q;

struct segtree
{
    vector<ll> tree;
    segtree(int n, vector<int> A) : tree(2 * n)
    {
        for (int i = 0; i < n; ++i)
            tree[n + i] = A[i];
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
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

void dfs(int i, int p)
{
    disc[i] = tick++;
    a.push_back(v[i]);

    for (int x : edges[i])
    {
        if (x == p)
            continue;
        dfs(x, i);
    }

    nv[i] = tick - 1;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> q;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    dfs(0, 0);
    segtree tree(n, a);

    while (q-- > 0)
    {
        int typ;
        cin >> typ;

        if (typ == 1)
        {
            int s, x;
            cin >> s >> x;
            --s;
            tree.upd(disc[s], x);
        }
        else
        {
            int s;
            cin >> s;
            --s;
            cout << tree.query(disc[s], nv[s]) << "\n";
        }
    }
}