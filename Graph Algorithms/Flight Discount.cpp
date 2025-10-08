// ^^
// <{:3
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
vector<pair<int, int>> edges[maxn];
int d[maxn][2];

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].emplace_back(b, c);
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> box;
    box.emplace(0, 1, 0);
    while (!box.empty())
    {
        auto [h, x, discount] = box.top();
        box.pop();

        if (d[x][discount])
            continue;
        d[x][discount] = h;

        for (auto [u, hx] : edges[x])
        {
            if (!discount)
                box.emplace((hx / 2) + h, u, 1);
            box.emplace(hx + h, u, discount);
        }
    }

    cout << d[n][1];
}
