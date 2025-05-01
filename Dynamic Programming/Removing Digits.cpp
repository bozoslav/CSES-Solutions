#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int dp[maxn];

int f(int i)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int tr = i;
    int nb = 1e9;
    while (tr)
    {
        int zn = tr % 10;
        if (zn)
            nb = min(nb, 1 + f(i - zn));
        tr /= 10;
    }

    dp[i] = nb;
    return dp[i];
}

int main()
{
    for (int i = 0; i < maxn; ++i)
        dp[i] = -1;

    int n;
    cin >> n;
    cout << f(n);
}