// ^^
// <{:3
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,tune=native")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #define int long signed long int
#define ld long double
using namespace std;
const int maxn = 1e3;
ld dp[maxn][maxn];

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cout << fixed << setprecision(6);

    int n, a, b;
    cin >> n >> a >> b;

    dp[0][0] = 1.0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 6 * n; ++j)
        {
            for (int k = 1; k <= 6; ++k)
                if (j - k >= 0)
                    dp[i][j] += (j - k >= 0 ? dp[i - 1][j - k] : 0);
            dp[i][j] /= 6;
        }
    }

    ld ans = 0;
    for (int i = a; i <= b; ++i)
        ans += dp[n][i];

    /*
    ans *= 1e6;
    ans = llround(ans);
    ans /= 1e6;
    */

    cout << ans;
}