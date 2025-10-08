#include <bits/stdc++.h>
#define int long long
using namespace std;
int const MAXN = 2005, MOD = 1e9 + 7, MAXT = 2e6 + 5;
int dp[MAXN], tree[MAXT][26];
int nextNode = 1;
bool word[MAXT];
string s;
int k;

void add(string cs)
{
    int cn = 0;
    for (int i = 0; i < cs.size(); ++i)
    {
        if (tree[cn][cs[i] - 'a'] == 0)
            tree[cn][cs[i] - 'a'] = nextNode++;
        cn = tree[cn][cs[i] - 'a'];
    }
    word[cn] = true;
}

void f(int start)
{
    int cn = 0, sol = 0;
    for (int i = start; i < s.size(); ++i)
    {
        if (tree[cn][s[i] - 'a'] == 0)
        {
            dp[start] = sol;
            return;
        }

        cn = tree[cn][s[i] - 'a'];

        if (word[cn])
        {
            sol += dp[i + 1];
            sol %= MOD;
        }
    }
    dp[start] = sol;
}

void solve()
{
    cin >> s >> k;

    memset(dp, -1, sizeof(dp));
    dp[s.size()] = 1;

    while (k--)
    {
        string x;
        cin >> x;
        add(x);
    }

    for (int i = s.size() - 1; i > -1; --i)
        f(i);

    cout << dp[0];
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    solve();
    return 0;
}