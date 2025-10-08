// 0x3f3f3f3f ^
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 1;
vector<vector<int>> edges;
int v[MAXN], vis[MAXN];

int dfs(int i)
{
    int res = 0;
    vis[i] = 1;

    for (int x : edges[i])
        if (!vis[x])
            res += dfs(x);

    return v[i] = ++res;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    edges.assign(n + 1, {});
    for (int i = 2; i <= n; ++i)
    {
        int x;
        cin >> x;
        edges[x].push_back(i);
        edges[i].push_back(x);
    }

    dfs(1);
    for (int i = 1; i <= n; ++i)
        cout << v[i] - 1 << " ";

    return 0;
}
