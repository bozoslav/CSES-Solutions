#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1;
vector<vector<int>> edges;
int dub = 0, nd;

void dfs(int tr, int p, int dep)
{
    for (auto x : edges[tr])
    {
        if (x != p)
            dfs(x, tr, dep + 1);
    }
    if (dep > dub)
    {
        dub = dep;
        nd = tr;
    }
    return;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    edges.assign(n + 1, {});

    while (--n)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1, 1, 0);
    dub = 0;
    dfs(nd, nd, 0);

    cout << dub;
}