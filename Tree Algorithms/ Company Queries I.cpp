#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
vector<int> edges[MAXN];
int jmp[MAXN][20];

void dfs(int x, int p)
{
    jmp[x][0] = (p != -1 ? p : x);
    for (int i = 1; i < 20; ++i)
        jmp[x][i] = jmp[jmp[x][i - 1]][i - 1]; // skok za 2^i = dva skoka za 2^(i-1)

    for (int y : edges[x])
    {
        if (y == p)
            continue;
        dfs(y, x);
    }
}

inline int f(int x, int k)
{
    for (int i = 19; i >= 0; --i)
    {
        if (k - (1 << i) >= 0)
        {
            x = jmp[x][i];
            k -= 1 << i;
        }
    }
    return x;
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
        int x, k;
        cin >> x >> k;
        --x;
        if (!f(x, k - 1))
            cout << "-1\n";
        else
            cout << f(x, k) + 1 << "\n";
    }
}