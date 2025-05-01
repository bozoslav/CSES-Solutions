#include <bits/stdc++.h>

long long FLOOR(long long n, long long div) { return n >= 0 ? n / div : (n - div + 1) / div; }
long long CEIL(long long n, long long div) { return n >= 0 ? (n + div - 1) / div : n / div; }
#define UNIQUER(a) (a).resize(unique((a).begin(), (a).end()) - (a).begin())
#define UNIQUE(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define prec cout << fixed << setprecision(10)
#define ALLR(a) (a).rbegin(), (a).rend()
#define ALL(a) (a).begin(), (a).end()
// 0x3f3f3f3f
using namespace std;
using ll = long long;
const int MAXN = 5005;
ll dp[MAXN][MAXN];
vector<int> v;
int n;

ll f(int l, int r, bool t)
{
    if (l > r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    return dp[l][r] = (t ? max(f(l + 1, r, 0) + v[l], f(l, r - 1, 0) + v[r]) : min(f(l + 1, r, 1), f(l, r - 1, 1)));
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    memset(dp, -1, sizeof dp);

    cin >> n;

    v.assign(n, 0);
    for (auto &x : v)
        cin >> x;

    cout << f(0, n - 1, 1);

    return 0;
}
