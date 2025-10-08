// 0x3f3f3f3f ^
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int MAXN = 2505;
vector<tuple<int, int, int>> edges;
int dist[MAXN], p[MAXN], n, vis[MAXN];

inline int f()
{
    for (int i = 1; i < n; ++i)
    {
        for (auto [u, v, c] : edges)
        {
            if (dist[u] + c < dist[v])
            {
                dist[v] = dist[u] + c;
                p[v] = u;
            }
        }
    }

    for (auto [u, v, c] : edges)
        if (dist[u] + c < dist[v])
            return v;

    return -1;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    p[1] = 1;

    int m;
    cin >> n >> m;

    edges.assign(m, {});
    for (auto &[u, v, c] : edges)
        cin >> u >> v >> c;

    int x = f();
    if (x == -1)
        cout << "NO";
    else
    {
        vector<int> cycle;
        while (!vis[x])
        {
            vis[x] = 1;
            cycle.push_back(x);
            x = p[x];
        }

        reverse(cycle.begin(), cycle.end());
        cout << "YES\n"
             << x << ' ';
        for (int i : cycle)
        {
            cout << i << ' ';
            if (i == x)
                break;
        }
    }

    return 0;
}