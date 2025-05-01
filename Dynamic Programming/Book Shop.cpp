#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1001, MAXX = 1e5 + 1;
int dp[MAXN][MAXX];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    vector<int> page(n), price(n);

    for (auto &x : price)
        cin >> x;

    for (auto &x : page)
        cin >> x;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= x; ++j)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= price[i - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + page[i - 1]);
        }
    }

    cout << dp[n][x];
}
