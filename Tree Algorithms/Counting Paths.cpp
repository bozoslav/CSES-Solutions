#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
vector<int> edges[MAXN];
int jmp[MAXN][20], in[MAXN], out[MAXN], res[MAXN], tick;

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

void dfs2(int x, int p)
{
    for (int i : edges[x])
    {
        if (i != p)
        {
            dfs2(i, x);
            res[x] += res[i];
        }
    }
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
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    edges[0].push_back(1);
    edges[1].push_back(0);

    dfs(0, -1);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        res[a]++;
        res[b]++;
        int temp = lca(a, b);
        res[temp]--;
        res[jmp[temp][0]]--;
    }

    dfs2(0, -1);
    for (int i = 1; i <= n; ++i)
        cout << res[i] << " ";
}
