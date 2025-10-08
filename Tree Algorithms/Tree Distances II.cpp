#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 5;
vector<int> edges[MAXN];
int n, dp[MAXN], ans[MAXN];

void dfs(int i, int p, int dep)
{
    ans[0] += dep;
    dp[i] = 1;
    for (int j : edges[i])
    {
        if (j == p)
            continue;
        dfs(j, i, dep + 1);
        dp[i] += dp[j];
    }
}

void dfs2(int i, int p)
{
    for (int j : edges[i])
    {
        if (j == p)
            continue;
        ans[j] = ans[i] + n - 2 * dp[j];
        dfs2(j, i);
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
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(0, -1, 0);
    dfs2(0, -1);
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    return 0;
}
