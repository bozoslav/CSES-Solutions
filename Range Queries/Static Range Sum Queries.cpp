#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN = 2e5 + 5;
ll n, q, v[MAXN], pf[MAXN];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> q;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    pf[0] = v[0];
    for (int i = 1; i < n; ++i)
        pf[i] = pf[i - 1] + v[i];

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        if (!l)
            cout << pf[r] << '\n';
        else
            cout << pf[r] - pf[l - 1] << '\n';
    }

    return 0;
}
