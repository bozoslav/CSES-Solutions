// ^^
// <{:3
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int pf[maxn];

inline int range(int l, int r)
{
    if (!l)
        return pf[r];
    return pf[r] - pf[l - 1];
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        pf[i] = x + pf[i - 1];
    }

    int ans = -1e18;
    multiset<int> s;

    for (int i = a; i <= n; ++i)
    {
        if (i > b)
            s.erase(s.find(pf[i - b - 1]));
        s.insert(pf[i - a]);
        ans = max(ans, pf[i] - *s.begin());
    }
    cout << ans;
}
