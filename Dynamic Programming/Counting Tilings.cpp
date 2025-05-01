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
const int MOD = 1e9 + 7;
int n, m, dp[1001][11][1 << 11];

ll f(int i, int j, int mask)
{
    if (i == n)
        return 1;
    if (j == m)
        return f(i + 1, 0, mask);
    if (dp[i][j][mask] != -1)
        return dp[i][j][mask];

    if (mask & 1)
        return dp[i][j][mask] = (f(i, j + 1, (mask >> 1)) % MOD);

    ll ret = 0;
    if (j != m - 1 && !(mask & 2))
        ret = (ret + f(i, j + 2, (mask >> 2))) % MOD;
    if (i != n - 1)
        ret = (ret + f(i, j + 1, ((mask >> 1) | (1 << (m - 1))))) % MOD;

    return dp[i][j][mask] = ret;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    memset(dp, -1, sizeof dp);
    cin >> m >> n;
    cout << f(0, 0, 0);

    return 0;
}