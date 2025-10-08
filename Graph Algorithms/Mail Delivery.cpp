// ^^
// <{:3
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 25;
vector<pair<int, int>> edges[maxn];
bool vis[maxn];
int n, m;

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        edges[a].emplace_back(b, i);
        edges[b].emplace_back(a, i);
    }

    bool gud = true;
    for (int i = 1; i <= n; ++i)
        gud &= !((int)edges[i].size() & 1);

    if (!gud)
        cout << "IMPOSSIBLE\n";

    vector<int> path;
    stack<int> st;
    st.push(1);
    while (!st.empty())
    {
        int v = st.top();
        bool f = false;

        while (!edges[v].empty())
        {
            auto [u, i] = edges[v].back();
            edges[v].pop_back();
            if (!vis[i])
            {
                st.push(u);
                vis[i] = true;
                f = true;
                break;
            }
        }
        if (!f)
        {
            path.push_back(v);
            st.pop();
        }
    }

    if ((int)path.size() != m + 1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i : path)
        cout << i << " ";
}
