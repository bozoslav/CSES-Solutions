#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<int> v;
int n;

ll f(int x)
{
    ll res = 0;
    for (auto y : v)
        res += abs(x - y);
    return res;
}

int gd(int lo, int hi)
{
    while (lo < hi)
    {
        int rx = (lo + hi + 1) / 2;
        int lx = rx - 1;

        if (f(lx) < f(rx))
            hi = lx;
        else
            lo = rx;
    }

    return lo;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    int l = 1e9, h = -1;

    for (int i = 0; i < n; ++i)
    {
        int _;
        cin >> _;
        v.emplace_back(_);
        if (_ > h)
            h = _;
        if (_ < l)
            l = _;
    }

    cout << f(gd(l, h));
}