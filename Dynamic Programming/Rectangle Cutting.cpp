#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int dp[505][505];

int f(int a, int b)
{
    if (a == b)
        return 0;
    if (dp[a][b] != -1)
        return dp[a][b];
    if (dp[b][a] != -1)
        return dp[b][a];

    int res = INF;
    for (int i = 1; i < a; ++i)
        res = min(res, f(i, b) + f(a - i, b) + 1);
    for (int i = 1; i < b; ++i)
        res = min(res, f(a, i) + f(a, b - i) + 1);

    return dp[a][b] = res;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    memset(dp, -1, sizeof dp);

    int a, b;
    cin >> a >> b;
    cout << f(a, b);
}