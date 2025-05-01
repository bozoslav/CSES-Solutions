#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1;
int cnt[MAXN] = {};

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    int tr = 0;
    ll res = 0;
    cnt[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        int _;
        cin >> _;
        tr += _;
        tr %= n;
        tr += n;
        res += cnt[tr %= n];
        ++cnt[tr];
    }

    cout << res << '\n';
}