#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    int lo = 1, hi = n * n;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2, leq = 0;

        for (int i = 1; i <= n; ++i)
            leq += min(n, mid / i);

        if (leq >= (n * n + 1) / 2)
            hi = mid;
        else
            lo = mid + 1;
    }

    cout << hi;
}