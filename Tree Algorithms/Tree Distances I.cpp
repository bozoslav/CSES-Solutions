#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("popcnt")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>

long long FLOOR(long long n, long long div) { return n >= 0 ? n / div : (n - div + 1) / div; }
long long CEIL(long long n, long long div) { return n >= 0 ? (n + div - 1) / div : n / div; }
#define UNIQUER(a) (a).resize(unique((a).begin(), (a).end()) - (a).begin())
#define UNIQUE(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define prec cout << fixed << setprecision(10)
#define ALLR(a) (a).rbegin(), (a).rend()
#define ALL(a) (a).begin(), (a).end()
// 0x3f3f3f3f
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
vector<vector<int>> edges;
int dub = 0, res[MAXN], nd;

void dfs(int tr = 1, int p = 1, int dep = 0)
{
    for (auto x : edges[tr])
    {
        if (x != p)
            dfs(x, tr, dep + 1);
    }
    if (dep > dub)
    {
        dub = dep;
        nd = tr;
    }
    return;
}

void cdist(int tr, int p, int dep = 0)
{

    for (auto x : edges[tr])
        if (x != p)
            cdist(x, tr, dep + 1);

    if (res[tr] > dep)
        return;
    res[tr] = dep;
    return;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    edges.assign(n + 1, {});
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs();
    int pnd = nd;
    dub = 0;
    dfs(pnd, pnd);
    cdist(pnd, pnd);
    cdist(nd, nd);

    for (int i = 1; i <= n; ++i)
        cout << res[i] << " ";

    return 0;
}