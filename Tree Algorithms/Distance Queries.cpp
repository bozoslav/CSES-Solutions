#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
vector<int> edges[MAXN];
int jmp[MAXN][20], in[MAXN], out[MAXN], d[MAXN], tick;

void dfs(int x, int p)
{
    in[x] = ++tick;
    for (int i = 1; i < 20; ++i)
        jmp[x][i] = jmp[jmp[x][i - 1]][i - 1];

    for (int i : edges[x])
    {
        if (i != p)
        {
            jmp[i][0] = x;
            d[i] = d[x] + 1;
            dfs(i, x);
        }
    }
    out[x] = ++tick;
}

inline bool ia(int x, int y)
{
    return (in[y] >= in[x] && out[y] <= out[x]);
}

int lca(int i, int j)
{
    if (ia(i, j))
        return i;
    if (ia(j, i))
        return j;
    for (int k = 19; k >= 0; --k)
        if (!ia(jmp[i][k], j))
            i = jmp[i][k];
    return jmp[i][0];
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(0, -1);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        cout << d[a] + d[b] - 2 * d[lca(a, b)] << "\n";
    }
}
