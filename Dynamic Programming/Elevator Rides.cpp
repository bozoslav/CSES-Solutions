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
const int MAXN = 21;
pair<int, int> dp[(1 << MAXN)];
int n, k, v[MAXN];

pair<int, int> f(int m)
{
    if (!m)
        return {1, 0};
    if (dp[m] != pair<int, int>(0, 0))
        return dp[m];

    pair<int, int> mx(21, (rand() % 0x3f3f3f3f));
    for (int i = 0; i < n; ++i)
    {
        if (m & (1 << i))
        {
            pair<int, int> r = f(m ^ (1 << i));
            if ((r.second += v[i]) > k)
            {
                r.second = v[i];
                ++r.first;
            }

            mx = min(mx, r);
        }
    }

    return dp[m] = mx;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> i[v];

    cout << f((1 << n) - 1).first;

    return 0;
}