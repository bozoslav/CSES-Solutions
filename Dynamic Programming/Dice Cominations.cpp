#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7, maxn = 1e6 + 16;
int n, dp[maxn];

int f(int i)
{
    if (i > n)
        return 0;
    if (i == n)
        return 1;
    if (dp[i] != -1)
        return dp[i];

    int ans = 0;
    for (int j = 1; j <= 6; ++j)
        ans = (ans + f(i + j)) % mod;

    dp[i] = ans;
    return dp[i];
}

signed main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    cout << f(0);