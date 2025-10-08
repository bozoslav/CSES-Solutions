#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

const int mod = 1e9 + 7;
const ll inf = 3e18 + 5;

bool bio[100500];
vi adj[100500];
int d[100500], dp[100500], p[100500];
stack<int> stk;

void dfs(int u)
{
    bio[u] = 1;
    for (int v : adj[u])
    {
        if (bio[v])
            continue;
        dfs(v);
    }
    stk.push(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -mod;
        if (bio[i])
            continue;
        dfs(i);
    }
    dp[1] = 0;

    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();
        for (int v : adj[u])
        {
            if (dp[v] < dp[u] + 1)
            {
                dp[v] = max(dp[v], dp[u] + 1);
                p[v] = u;
            }
        }
    }

    if (dp[n] < 0)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> res;
    for (int x = n; x != 1; x = p[x])
        res.push_back(x);

    res.push_back(1);
    reverse(res.begin(), res.end());
    cout << res.size() << "\n";
    for (int x : res)
        cout << x << " ";
}