#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
vector<int> edges[MAXN];
int jmp[MAXN][20], ulaz[MAXN], izlaz[MAXN];
int tick;

void dfs(int x, int p)
{
    ulaz[x] = tick++;
    jmp[x][0] = (p != -1 ? p : x);
    for (int i = 1; i < 20; ++i)
        jmp[x][i] = jmp[jmp[x][i - 1]][i - 1]; // skok za 2^i = dva skoka za 2^(i-1)

    for (int y : edges[x])
    {
        if (y == p)
            continue;
        dfs(y, x);
    }
    izlaz[x] = tick++;
}

inline bool is_ancestor(int x, int y)
{
    // ako smo u x prije usli a u y prije izasli onda je x predak od y
    return (ulaz[y] >= ulaz[x] && izlaz[y] <= izlaz[x]);
}

int lca(int x, int y)
{
    if (is_ancestor(x, y))
        return x;
    for (int i = 19; i >= 0; --i)
        if (!is_ancestor(jmp[x][i], y))
            x = jmp[x][i];
    return jmp[x][0];
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; ++i)
    {
        int x;
        cin >> x;
        --x;
        edges[x].push_back(i);
    }

    dfs(0, -1);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        cout << lca(x, y) + 1 << "\n";
    }
}