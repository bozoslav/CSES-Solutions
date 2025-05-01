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
const int MAXN = 2e5 + 25;
ll dp[MAXN], n;
vector<array<int, 3>> v;

ll f(int i)
{
    if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    return dp[i] = max(f(i + 1), f(lower_bound(v.begin(), v.end(), array{v[i][1] + 1, 0, 0}) - v.begin()) + v[i][2]);
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    memset(dp, -1, sizeof dp);

    cin >> n;

    v.assign(n, {0, 0, 0});
    for (auto &[x, y, z] : v)
        cin >> x >> y >> z;

    sort(ALL(v), [](array<int, 3> x, array<int, 3> y)
         { return x[0] < y[0]; });

    cout << f(0);

    return 0;
}