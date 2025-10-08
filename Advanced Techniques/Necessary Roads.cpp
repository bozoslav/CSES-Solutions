// ^^
// <{:3
#include <bits/stdc++.h>
// #define int long long
const int maxn = 1e5 + 5;
using namespace std;
// set<pair<int, int>> exist;
vector<pair<int, int>> ans;
int tin[maxn], low[maxn];
vector<int> edges[maxn];
bool vis[maxn];
int n, m;
int tick;

void dfs(int v, int p)
{
    vis[v] = true;
    tin[v] = low[v] = ++tick;

    for (int to : edges[v])
    {
        if (to == p)
            continue;
        if (vis[to])
        {
            low[v] = min(low[v], tin[to]);
            continue;
        }

        dfs(to, v);
        low[v] = min(low[v], low[to]);
        if (low[to] > tin[v])
            ans.emplace_back(v, to);
    }
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    dfs(1, 0);

    cout << ans.size() << "\n";
    for (auto [x, y] : ans)
        cout << x << " " << y << "\n";
}
