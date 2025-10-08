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
vector<vector<int>> edges;
vector<int> vis, ans, v1;

void dfs(int i)
{
    vis[i] = true;
    for (int u : edges[i])
        if (!vis[u])
            dfs(u);
    ans.push_back(i);
    return;
}

bool cycle(int i)
{
    v1[i] = 1;
    for (auto u : edges[i])
    {
        if (!v1[u])
        {
            if (cycle(u))
                return 1;
        }
        else if (v1[u] == 1)
            return 1;
    }
    v1[i] = 2;
    return 0;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;

    v1.assign(n + 1, 0);
    edges.assign(n + 1, {});
    vis.assign(n + 1, false);

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
    }

    ans.reserve(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (!v1[i] && cycle(i))
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
        if (!vis[i])
            dfs(i);
    }

    reverse(ALL(ans));
    for (int &x : ans)
        cout << x << " ";

    return 0;
}
