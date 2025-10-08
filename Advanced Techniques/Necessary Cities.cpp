// ^^
// <{:3
#include <bits/stdc++.h>
// #define int long long
const int maxn = 1e5 + 5;
using namespace std;
vector<int> edges[maxn];
int tin[maxn], low[maxn];
bool vis[maxn];
set<int> ans;
int n, m;
int tick;

void dfs(int v, int p)
{
    vis[v] = true;
    tin[v] = low[v] = ++tick;

    int kids = 0;
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
        if (low[to] >= tin[v] && p != 0)
            ans.insert(v);
        ++kids;
    }

    if (p == 0 && kids > 1)
        ans.insert(v);
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
    for (int i : ans)
        cout << i << " ";
}