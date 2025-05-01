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
const int MOD = 1e9 + 7, MAXN = ((501 * 502) / 2);
ll lf, dp[MAXN][505];
int n;

ll f(ll s, int i)
{
    if (i > n)
        return (s == lf - s);
    if (dp[s][i] != -1)
        return dp[s][i];

    return dp[s][i] = (f(s + i, i + 1) + f(s, i + 1)) % MOD;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    memset(dp, -1, sizeof dp);

    cin >> n;

    lf = ((n * (n + 1)) / 2);
    cout << f(1, 2);

    return 0;
}