// ^^
// <{:3
#include <bits/stdc++.h>
#define int long long
using namespace std;
int sol[20], dp[20][10][2];
int a, b, len;
string s;

int f(int i, int last, bool hs)
{
    if (i == len)
        return 1;
    if (dp[i][last][hs] != -1)
        return dp[i][last][hs];

    int ret = 0;
    for (int j = 0; j <= (hs ? 9 : s[i] - '0'); ++j)
    {
        bool nhs = false;
        if (j < s[i] - '0')
            nhs = true;
        if (j != last)
            ret += f(i + 1, j, max(hs, nhs));
    }

    return dp[i][last][hs] = ret;
}

int solve(int x)
{
    memset(dp, -1, sizeof dp);
    if (x <= 0)
        return !x;
    s = to_string(x);
    len = s.size();

    int ans = 0;
    for (int i = 0; i < len; ++i)
        ans += sol[i];

    ans += f(0, 0, 0);
    return ans;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    sol[0] = 1;
    for (int i = 1; i < 20; ++i)
        sol[i] = sol[i - 1] * 9;

    cin >> a >> b;
    cout << solve(b) - solve(a - 1);
}
