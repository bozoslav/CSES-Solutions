// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")
// #pragma GCC target("popcnt")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>

long long FLOOR(long long n, long long div) { return n >= 0 ? n / div : (n - div + 1) / div; }
long long CEIL(long long n, long long div) { return n >= 0 ? (n + div - 1) / div : n / div; }
#define UNIQUER(a) (a).resize(unique((a).begin(), (a).end()) - (a).begin())
#define UNIQUE(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define prec cout << fixed << setprecision(10)
#define ALLR(a) (a).rbegin(), (a).rend()
#define ALL(a) (a).begin(), (a).end()
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// 0x3f3f3f3f
using namespace std;
using ll = long long;
using ld = long double;
const int MAXN = 1005;
ll x[MAXN], y[MAXN];

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    x[n] = x[0];
    y[n] = y[0];

    ll povrsina = 0;
    for (int i = 0; i < n; ++i)
    {
        povrsina += x[i] * y[i + 1];
        povrsina -= y[i] * x[i + 1];
    }

    cout << abs(povrsina);

    return 0;
}