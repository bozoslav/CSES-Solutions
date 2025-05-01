#include <bits/stdc++.h>

long long FLOOR(long long n, long long div) { return n >= 0 ? n / div : (n - div + 1) / div; }
long long CEIL(long long n, long long div) { return n >= 0 ? (n + div - 1) / div : n / div; }
#define UNIQUER(a) (a).resize(unique((a).begin(), (a).end()) - (a).begin())
#define UNIQUE(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define prec cout << fixed << setprecision(10)
#define ALLR(a) (a).rbegin(), (a).rend()
#define ALL(a) (a).begin(), (a).end()
// 0x3f3f3f3f
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int dp[MAXN][101];
int v[MAXN], n, m;

ll f(int i, ll prosli)
{
    if (dp[i][prosli] != -1)
        return dp[i][prosli];
    if (i >= n)
        return 1;

    if (v[i] == 0)
    {
        ll res = 0;
        res = (res + f(i + 1, prosli)) % MOD;
        if (prosli + 1 <= m)
            res = (res + f(i + 1, prosli + 1)) % MOD;
        if (prosli - 1 > 0)
            res = (res + f(i + 1, prosli - 1)) % MOD;
        return dp[i][prosli] = res;
    }
    else if (abs(v[i] - prosli) > 1)
        return 0;

    return dp[i][prosli] = (f(i + 1, v[i]) % MOD);
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    memset(dp, -1, sizeof dp);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    if (v[0])
    {
        cout << f(1, v[0]);
        return 0;
    }

    ll ans = 0;
    for (int i = 1; i <= m; ++i)
        ans = (ans + f(1, i)) % MOD;
    cout << ans;

    return 0;
}
