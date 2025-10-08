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
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
vector<vector<int>> edges, redges;
ll p[MAXN], dp[MAXN];

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;

    redges.assign(n + 1, {});
    edges.assign(n + 1, {});
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        redges[b].push_back(a);
        ++p[b];
    }

    dp[1] = 1;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (!p[i])
            q.push(i);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : edges[u])
        {
            p[v]--;
            if (p[v] == 0)
                q.push(v);
        }

        for (int prev : redges[u])
            dp[u] = (dp[u] + dp[prev]) % MOD;
    }

    cout << dp[n];

    return 0;
}