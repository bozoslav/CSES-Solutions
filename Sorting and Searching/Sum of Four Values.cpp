// ^^
// <{:3
#include <bits/stdc++.h>
using namespace std;

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, lf;
    cin >> n >> lf;

    vector<int> v(n);

    for (auto &x : v)
        cin >> x;

    map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            m[v[i] + v[j]].emplace_back(i + 1, j + 1);

    for (auto &[i, j] : m)
    {
        for (auto [u, v] : j)
        {
            for (auto [c, d] : m[lf - i])
            {
                set<int> tr;
                tr.insert(u);
                tr.insert(v);
                tr.insert(c);
                tr.insert(d);
                if (tr.size() == 4)
                {
                    for (int i : tr)
                        cout << i << " ";
                    exit(0);
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
}
