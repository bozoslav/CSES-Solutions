// ^^
// <{:3
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2505, inf = 1e18;
vector<pair<int, int>> redges[maxn];
vector<tuple<int, int, int>> edges;
int dist[maxn], newdist[maxn];
bool changed[maxn], vis[maxn];
int p[maxn];
int n, m;

void dfs(int i)
{
    vis[i] = 1;

    for (auto [u, hx] : redges[i])
    {
        if (!vis[u])
        {
            dfs(u);
            p[u] = i;
        }
    }
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    fill(newdist, newdist + maxn, inf);
    fill(dist, dist + maxn, inf);

    cin >> n >> m;

    edges.resize(m);
    for (auto &[a, b, c] : edges)
    {
        cin >> a >> b >> c;
        c = -c;
        redges[b].emplace_back(a, c);
        if (n == 1 && m == 1)
        {
            if (c == 1)
                cout << 0;
            else
                cout << -1;
            return 0;
        }
    }

    dist[1] = 0;
    for (int i = 1; i < n; ++i)
        for (auto [u, v, c] : edges)
            if (dist[u] + c < dist[v])
                dist[v] = dist[u] + c;

    int prvikraj = dist[n];

    for (auto [u, v, c] : edges)
    {
        if (dist[u] + c < dist[v])
        {
            changed[v] = 1;
            dist[v] = dist[u] + c;
        }
    }

    bool gud = true;

    dfs(n);
    int tr = 1;
    for (int i = tr; i != n; i = p[i])
        if (changed[i])
            gud = false;

    newdist[1] = 0;
    for (int i = 0; i < n + 100; ++i)
        for (auto [u, v, c] : edges)
            if (newdist[u] + c < newdist[v])
                newdist[v] = newdist[u] + c;

    if (newdist[n] == prvikraj && gud)
        cout << -dist[n];
    else
        cout << -1;
}