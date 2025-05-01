#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 1005;
int dp[MAXN];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    dp[0] = 1;
    int ans = 0;

    while (n--)
    {
        int x;
        cin >> x;

        for (int i = 1e5; i > -1; --i)
        {
            if (dp[i])
            {
                if (!dp[i + x])
                    ++ans;
                dp[i + x] = 1;
            }
        }
    }

    cout << ans << "\n";
    for (int i = 1; i <= 1e5; ++i)
        if (dp[i])
            cout << i << " ";
}
