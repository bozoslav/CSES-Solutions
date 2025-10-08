// ^^
// <{:3
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
vector<pair<int, int>> edges[maxn];
int cnt[maxn];

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].emplace_back(b, c);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> box;
    box.emplace(0, 1);
    while (!box.empty())
    {
        auto [h, x] = box.top();
        box.pop();

        if (cnt[x] >= k)
            continue;
        if (x == n)
            cout << h << " ";
        ++cnt[x];

        for (auto [u, hx] : edges[x])
            box.emplace(hx + h, u);
    }
}