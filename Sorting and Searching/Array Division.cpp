// ^^
// <{:3
#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> v;
int n, k;

inline bool f(int mid)
{
    int groups = 1, tr = 0;
    for (int i : v)
    {
        if (i > mid)
            return 0;
        if (tr + i > mid)
        {
            ++groups;
            tr = i;
        }
        else
            tr += i;
    }

    return (groups <= k);
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> k;

    v.resize(n);
    for (auto &x : v)
        cin >> x;

    int lo = 0, hi = 1e16;
    while (hi != lo)
    {
        int mid = (hi + lo) / 2;
        if (f(mid))
            hi = mid;
        else
            lo = mid + 1;
    }

    cout << lo;
}