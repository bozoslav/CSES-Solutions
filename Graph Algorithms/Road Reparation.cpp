#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 1;
int p[MAXN], sz[MAXN];

int f(int i)
{
    if (i == p[i])
        return i;
    return p[i] = f(p[i]);
}

inline void u(int a, int b)
{
    a = f(a);
    b = f(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        sz[a] += sz[b];
        p[b] = a;
    }
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        p[i] = i;
        sz[i] = 1;
    }

    vector<tuple<int, int, int>> edges;
    edges.assign(m, {});
    for (auto &[c, a, b] : edges)
    {
        cin >> a >> b >> c;
        --a;
        --b;
    }

    sort(edges.begin(), edges.end());
    ll res = 0;
    for (auto [c, a, b] : edges)
    {
        a = f(a);
        b = f(b);
        if (a != b)
        {
            u(a, b);
            res += c;
        }
    }

    int lf = f(1), gud = 1;
    for (int i = 1; i < n; ++i)
        if (f(i) != lf)
            gud = 0;

    cout << (gud ? to_string(res) : "IMPOSSIBLE");

    return 0;
}