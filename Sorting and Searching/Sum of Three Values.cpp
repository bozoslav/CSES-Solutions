#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a;

    for (int i = 1; i <= n; ++i)
    {
        int _;
        cin >> _;
        a.push_back({_, i});
    }

    sort(a.begin(), a.end());
    bool gud = false;

    vector<int> val, ind;

    for (auto [f, s] : a)
    {
        val.push_back(f);
        ind.push_back(s);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int lf = x - (val[i] + val[j]);
            auto [lx, rx] = equal_range(val.begin(), val.end(), lf);

            if (lx == val.end())
                continue;

            --rx;
            int idx = rx - val.begin();
            if (idx > j && val[idx] == lf)
            {
                cout << ind[i] << " " << ind[j] << " " << ind[idx] << "\n";
                exit(0);
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}