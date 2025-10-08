// ^^
// <{:3
#include <bits/stdc++.h>
// #define int long long
using namespace std;
const int maxn = 2e5 + 5;
vector<int> edges[maxn];
int vis[maxn];
int n, ans;

void dfs(int i, int p)
{
    for (int v : edges[i])
    {
        if (p == v)
            continue;

        dfs(v, i);
        if (!vis[i] && !vis[v])
        {
            vis[i] = vis[v] = 1;
            ++ans;
        }
    }
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1, 1);

    cout << ans;
}