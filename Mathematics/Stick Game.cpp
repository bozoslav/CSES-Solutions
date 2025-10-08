#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
const int maxn = 1e6 + 6;
using namespace std;
vector<int> v;
int dp[maxn];
int n, k;

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    dp[0] = 1;

    cin >> n >> k;

    for (int i = 0; i < k; ++i)
    {
        int x;
        cin >> x;
        v.push_back(x);
        dp[x] = 1;
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            if (i - v[j] < 0)
                break;
            if (!dp[i - v[j]])
                dp[i] = 1;
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << (dp[i] ? "W" : "L");
}