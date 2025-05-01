#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        int y;
        cin >> y;
        v.push_back({y, i}); // append
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
    {
        int lf = x - v[i].first;

        int lo = 0, hi = n - 1;
        while (hi - lo > 1)
        {
            int mid = (hi + lo) / 2;

            if (v[mid].first >= lf)
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }

        if (v[lo].first == lf && lo != i)
        {
            cout << v[lo].second + 1 << " " << v[i].second + 1;
            return 0;
        }
        if (v[hi].first == lf && hi != i)
        {
            cout << v[hi].second + 1 << " " << v[i].second + 1;
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
}