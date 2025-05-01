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
const int MAXN = 1e6 + 16;
ll dp[MAXN][2];

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 1; i < MAXN - 10; ++i)
    {
        dp[i + 1][0] = (dp[i + 1][0] + 2 * dp[i][0]) % MOD;
        dp[i + 1][1] = (dp[i + 1][1] + 4 * dp[i][1]) % MOD;
        dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % MOD;
        dp[i + 1][0] = (dp[i + 1][0] + dp[i][1]) % MOD;
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        ll ans = dp[n][0] + dp[n][1];
        cout << ans % MOD << "\n";
    }

    return 0;
}