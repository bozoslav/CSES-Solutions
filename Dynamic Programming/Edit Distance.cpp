#include <bits/stdc++.h>

using namespace std;
const int MAXN = 5001;
int dp[MAXN][MAXN];
string s1, s2;

int f(int i, int j)
{
    if (i >= s1.length() || j >= s2.length())
        return (s1.length() - i + s2.length() - j);

    if (dp[i][j] != 1e9)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = f(i + 1, j + 1);

    return dp[i][j] = min({f(i + 1, j + 1) + 1, f(i + 1, j) + 1, f(i, j + 1) + 1});
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> s1 >> s2;

    for (int i = 0; i < s1.size(); ++i)
        for (int j = 0; j < s2.size(); ++j)
            dp[i][j] = 1e9;

    cout << f(0, 0);
}