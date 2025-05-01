// ^^
// <{:3
#include <bits/stdc++.h>
// #define int long long
using namespace std;
const int maxn = 2e5 + 5;
int idx[maxn], v[maxn];

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        idx[v[i]] = i;
    }

    int ans = 1;
    for (int i = 1; i < n; ++i)
        ans += (idx[i] > idx[i + 1]);

    set<pair<int, int>> p;
    while (m--)
    {
        p.clear();
        int x, y;
        cin >> x >> y;

        if (v[x] + 1 <= n)
            p.insert({v[x], v[x] + 1});
        if (v[x] - 1 >= 1)
            p.insert({v[x] - 1, v[x]});
        if (v[y] + 1 <= n)
            p.insert({v[y], v[y] + 1});
        if (v[y] - 1 >= 1)
            p.insert({v[y] - 1, v[y]});

        for (auto [l, r] : p)
            ans -= (idx[l] > idx[r]);
        swap(v[x], v[y]);
        idx[v[x]] = x;
        idx[v[y]] = y;
        for (auto [l, r] : p)
            ans += (idx[l] > idx[r]);

        cout << ans << "\n";
    }