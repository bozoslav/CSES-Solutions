#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
const int MAXN = 1e5 + 5;
int col[MAXN], vis[MAXN];
bool gud = true;

void dfs(int i, int curr)
{
    col[i] = curr;

    for (int x : edges[i])
        if (!col[x])
            dfs(x, (curr == 1 ? 2 : 1));
}

void check(int i)
{
    vis[i] = 1;
    for (int x : edges[i])
    {
        if (col[x] == col[i])
        {
            gud = false;
            return;
        }
        if (!vis[x])
            check(x);
    }
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    edges.assign(n + 1, {});

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        edges[a].emplace_back(b);
        edges[b].emplace_back(a);
    }

    for (int i = 1; i <= n; ++i)
        if (!col[i])
            dfs(i, 1);
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
            check(i);
        if (!gud)
            break;
    }

    if (!gud)
        cout << "IMPOSSIBLE";
    else
        for (int i = 1; i <= n; ++i)
            cout << col[i] << " ";
}