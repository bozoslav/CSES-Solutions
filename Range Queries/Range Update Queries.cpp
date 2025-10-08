#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MAXN = 2e5 + 5;
ll tree[4 * MAXN], a[MAXN];

void build(ll v, ll tl, ll tr)
{
    if (tl == tr)
        tree[v] = a[tl];
    else
    {
        ll tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = 0;
    }
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll add)
{
    if (l > r)
        return;
    if (l == tl && r == tr)
        tree[v] += add;
    else
    {
        ll tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), add);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    }
}

ll get(ll v, ll tl, ll tr, ll pos)
{
    if (tl == tr)
        return tree[v];
    ll tm = (tl + tr) / 2;
    if (pos <= tm)
        return tree[v] + get(v * 2, tl, tm, pos);
    else
        return tree[v] + get(v * 2 + 1, tm + 1, tr, pos);
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    ll n, q;
    cin >> n >> q;

    for (ll i = 0; i < n; ++i)
        cin >> a[i];

    build(1, 0, n - 1);

    while (q--)
    {
        ll k;
        cin >> k;

        if (k == 1)
        {
            ll a, b, u;
            cin >> a >> b >> u;
            update(1, 0, n - 1, a - 1, b - 1, u);
            continue;
        }

        ll u;
        cin >> u;
        cout << get(1, 0, n - 1, u - 1) << "\n";
    }
}
